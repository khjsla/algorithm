//12163291 ������ �˰��򼳰� HW1

#include <cuda_runtime.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <cuda.h>

using namespace std;

/* Every thread gets exactly one value in the unsorted array. */
#define THREADS 256 //16, 128, 128, 256
#define BLOCKS 16384 //512, 4096, 8192, 16384
#define NUM_VALS THREADS*BLOCKS //���ĵǴ� element�� ����

void print_elapsed(clock_t start, clock_t stop) //�ɸ� �ð� ��� �Լ�
{
    double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("\nCUDA BITONIC MERGE\n�ҿ�ð� : %.3fs\n", elapsed);
}

void array_print(int* arr, int length) //���ĵ� ����� ���
{
    int i;
    for (i = 0; i < length; ++i) {
        printf("%d ", arr[i]);
        if ((i + 1) % 16 == 0){ //16�� ���� endl
            cout << endl;
        }
    }
    printf("\n");
}

void array_fill(int* arr, int length) //NUM_VALS ũ���� �迭�� ���� ������ ä���ֱ�
{
    srand((int)time(NULL));

    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % 100;
    }
}

__global__ void bitonic_sort_step(int* dev_values, int j, int k)
{
    unsigned int i, ixj; // Sorting ��Ʈ�ʵ��� : i and ixj */
    i = threadIdx.x + blockDim.x * blockIdx.x;
    ixj = i ^ j;

    // The threads with the lowest ids sort the array. */
    if ((ixj) > i) {
        if ((i & k) == 0) {
            /* Sort �������� */
            if (dev_values[i] > dev_values[ixj]) {
                int temp = dev_values[i];
                dev_values[i] = dev_values[ixj];
                dev_values[ixj] = temp;
            }
        }
        if ((i & k) != 0) {
            /* Sort �������� */
            if (dev_values[i] < dev_values[ixj]) {
                int temp = dev_values[i];
                dev_values[i] = dev_values[ixj];
                dev_values[ixj] = temp;
            }
        }
    }
}

/**
 * Inplace bitonic sort using CUDA.
 */
void bitonic_sort(int* values)
{
    int* dev_values;
    size_t size = NUM_VALS * sizeof(int); //����� size_t�� 

    cudaMalloc((void**)&dev_values, size); //malloc = �Ҵ��Ѵ� 
    cudaMemcpy(dev_values, values, size, cudaMemcpyHostToDevice);

    dim3 blocks(BLOCKS, 1);    /* �������� �ռ� ������ �־��� Number of ���� ���� */
    dim3 threads(THREADS, 1);  /* Number of ������ ���� */

    int j, k;
    /* �߿��� �κ� */
    for (k = 2; k <= NUM_VALS; k <<= 1) {
        /* Minor */
        for (j = k >> 1; j > 0; j = j >> 1) {
            bitonic_sort_step << <blocks, threads >> > (dev_values, j, k); //�ռ� �����ص� ���� sort����
        }
    }
    cudaMemcpy(values, dev_values, size, cudaMemcpyDeviceToHost); //values�鿡 ���ĵ� �� cp���ִ� ��
    cudaFree(dev_values); //Ǯ���ֱ�
}

int main(void)
{
    cout << "12163291\n������\n";
    clock_t start, stop;

    int* values = (int*)malloc(NUM_VALS * sizeof(int));
    array_fill(values, NUM_VALS);

    start = clock();
    bitonic_sort(values); /* Inplace */
    stop = clock();
    //array_print(values, NUM_VALS);

    print_elapsed(start, stop);
}

//https://github.com/snowacat/cuda-bitonic-sorting/blob/master/bitonic.cu
//��ó�� ���� �����ϴ�.
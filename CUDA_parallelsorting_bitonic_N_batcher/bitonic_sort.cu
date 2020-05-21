//12163291 강현지 알고리즘설계 HW1

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
#define NUM_VALS THREADS*BLOCKS //정렬되는 element의 숫자

void print_elapsed(clock_t start, clock_t stop) //걸린 시간 출력 함수
{
    double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("\nCUDA BITONIC MERGE\n소요시간 : %.3fs\n", elapsed);
}

void array_print(int* arr, int length) //정렬된 결과값 출력
{
    int i;
    for (i = 0; i < length; ++i) {
        printf("%d ", arr[i]);
        if ((i + 1) % 16 == 0){ //16개 마다 endl
            cout << endl;
        }
    }
    printf("\n");
}

void array_fill(int* arr, int length) //NUM_VALS 크기의 배열에 랜덤 정수들 채워넣기
{
    srand((int)time(NULL));

    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % 100;
    }
}

__global__ void bitonic_sort_step(int* dev_values, int j, int k)
{
    unsigned int i, ixj; // Sorting 파트너들은 : i and ixj */
    i = threadIdx.x + blockDim.x * blockIdx.x;
    ixj = i ^ j;

    // The threads with the lowest ids sort the array. */
    if ((ixj) > i) {
        if ((i & k) == 0) {
            /* Sort 오름차로 */
            if (dev_values[i] > dev_values[ixj]) {
                int temp = dev_values[i];
                dev_values[i] = dev_values[ixj];
                dev_values[ixj] = temp;
            }
        }
        if ((i & k) != 0) {
            /* Sort 내림차로 */
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
    size_t size = NUM_VALS * sizeof(int); //사이즈를 size_t로 

    cudaMalloc((void**)&dev_values, size); //malloc = 할당한다 
    cudaMemcpy(dev_values, values, size, cudaMemcpyHostToDevice);

    dim3 blocks(BLOCKS, 1);    /* 맨위에서 앞서 설정해 주었던 Number of 블럭의 개수 */
    dim3 threads(THREADS, 1);  /* Number of 스레드 개수 */

    int j, k;
    /* 중요한 부분 */
    for (k = 2; k <= NUM_VALS; k <<= 1) {
        /* Minor */
        for (j = k >> 1; j > 0; j = j >> 1) {
            bitonic_sort_step << <blocks, threads >> > (dev_values, j, k); //앞서 설정해둔 과정 sort실행
        }
    }
    cudaMemcpy(values, dev_values, size, cudaMemcpyDeviceToHost); //values들에 정렬된 값 cp해주는 것
    cudaFree(dev_values); //풀어주기
}

int main(void)
{
    cout << "12163291\n강현지\n";
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
//출처는 위와 같습니다.
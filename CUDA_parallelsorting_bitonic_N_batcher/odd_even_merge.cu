////12163291 ������ �˰��򼳰� HW1
//#pragma warning(disable: 4819) //��� ����
//
//#include<stdio.h>
//#include<iostream>
//#include <cuda_runtime.h>
//#include <cuda.h>
//#include <time.h> //for����
//#include <math.h>
//
//using namespace std;
//
//#define DATASIZE 1048576 //2048 131072 262144 1048576���� �ȵƴµ� ���� �����÷ο� ���� ���� ���ִ� ����
//#define BLOCK_SIZE 2048  //1024 2048 2048 2048
////524288 1024 �����ɷ��� �׷��� �Ǳ��� 2097152 �� //80��,,
////1048576 1024 �ƹ�����ٷ���..
////1048576 2048 4194304�� 0.21�� 0.204�� ����
////1048576 4089 0.211�ʵ�� �켱 2048�̶� �����̴� ����
//
//void print_elapsed(clock_t start, clock_t stop) //�ð���¿�
//{
//    double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC;
//    printf("CUDA ODD EVEN MERGE\n�ҿ�ð� : %.3fs\n", elapsed);
//}
//
//__global__ void oddevensort(int* input, unsigned int len, int i)
//{
//    //���� ���� ��ǥ
//    unsigned int tx = threadIdx.x;
//
//    //��ü �̹����� ��ǥ
//    unsigned int x = tx + blockDim.x * blockIdx.x;
//    //�̵��� �� �ӽ� ����
//    int temp;
//
//    //�ڷ��� ���̸�ŭ �����µ�, �ε���(i)�� ¦���̸� �������� ¦���ڸ��� �� ���� ���ڸ� ��.
//    //�ε����� Ȧ���̸� �������� Ȧ���ڸ��� �� ���� ���ڸ� ���ؼ� �����Ѵ�.
//    if (i % 2 == 0)
//    {
//        // ���̸� ���������ָ� ���� �����ִ� �ڸ��� �ִ� �ڷᰡ Ƣ��� �� ������ ����.
//        if (input[x] > input[x + 1] && x < len && x % 2 == 0)
//        {
//            temp = input[x + 1];
//            input[x + 1] = input[x];
//            input[x] = temp;
//        }
//    }
//    else
//    {
//        if (input[x] > input[x + 1] && x < len && x % 2 != 0)
//        {
//            temp = input[x + 1];
//            input[x + 1] = input[x];
//            input[x] = temp;
//        }
//    }
//    __syncthreads();
//}
//
//void array_print(int* arr, int length)
//{
//    int i;
//    for (i = 0; i < length; ++i) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//void array_fill(int* arr, int length)
//{
//    srand((int)time(NULL));
//
//    for (int i = 0; i < length; ++i) {
//        arr[i] = rand() % 100;
//    }
//}
//
//__global__ void bitonic_sort_step(int* dev_values, int j, int k)
//{
//    unsigned int i, ixj; /* Sorting partners: i and ixj */
//    i = threadIdx.x + blockDim.x * blockIdx.x;
//    ixj = i ^ j;
//
//    /* The threads with the lowest ids sort the array. */
//    if ((ixj) > i) {
//        if ((i & k) == 0) {
//            /* Sort ascending */
//            if (dev_values[i] > dev_values[ixj]) {
//                /* exchange(i,ixj); */
//                int temp = dev_values[i];
//                dev_values[i] = dev_values[ixj];
//                dev_values[ixj] = temp;
//            }
//        }
//        if ((i & k) != 0) {
//            /* Sort descending */
//            if (dev_values[i] < dev_values[ixj]) {
//                /* exchange(i,ixj); */
//                int temp = dev_values[i];
//                dev_values[i] = dev_values[ixj];
//                dev_values[ixj] = temp;
//            }
//        }
//    }
//}
//
//clock_t start, stop = 0;
//int TestInput[DATASIZE], TestOutput[DATASIZE];
//
//int main(){
//    cout << "12163291\n������\n";
//
//    srand(time(NULL));
//
//    for (int i = 0; i < DATASIZE; i++) {
//        TestInput[i] = rand() % 100; //�����������ݴϴ�.
//    }
//
//    //device ����
//    int* devInput, * devOutput;
//    //�ϴ� ũ��� �ƴϱ�
//    unsigned int MemDataSize = DATASIZE * sizeof(int);
//
//    // device �ڸ� ����ݴϴ�.
//    cudaMalloc((void**)&devInput, MemDataSize);
//    cudaMalloc((void**)&devOutput, MemDataSize);
//    cudaMemset(devOutput, 0, MemDataSize);
//
//    // �ڸ� ������� ���縦 ���ݴϴ�.00000
//    cudaMemcpy(devInput, TestInput, MemDataSize, cudaMemcpyHostToDevice);
//
//    // block ũ�� �����մϴ�.
//    dim3    dimBlocksize(BLOCK_SIZE);
//    dim3    dimGridsize(ceil((DATASIZE - 1) / (float)BLOCK_SIZE) + 1);
//    // �ϴ� Max���� min���� �˾ƾ� �մϴ�.
//    // ���� �����ϴ� cpu���� �ð��ݴϴ�.
//    
//    start = clock();
//    for (int i = 0; i < DATASIZE; i++) {
//        oddevensort << < dimGridsize, dimBlocksize >> > (devInput, DATASIZE, i);
//    }
//    stop = clock();
//
//    // ����� testoutput�� �����մϴ�.
//    cudaMemcpy(TestOutput, devInput, MemDataSize, cudaMemcpyDeviceToHost);
//
// /*   for (int i = 0; i < DATASIZE; i++) {
//        cout << TestOutput[i] << ", ";  //��� Ȯ�ο�
//        if ((i + 1) % 16 == 0)  {
//            cout << endl;
//        }
//    }*/
//    cout << endl << "�迭 ũ�� : " << sizeof(TestOutput) << endl << endl;
//   print_elapsed(start, stop); //�ɸ��ð� ������ݴϴ�.
//
//   //���� GPU�� ������ �ڸ� free.
//   //malloc - free�� �׻� ¦������. 
//   //�׻������ �մϴ�. 
//    cudaFree(devInput);
//    cudaFree(devOutput);
//
//    return 0;
//}
//
////https://github.com/ptjoker95/OddEvenSort-with-CUDA/blob/master/oddevensort.cu
////��ó�� ���� �����ϴ�.
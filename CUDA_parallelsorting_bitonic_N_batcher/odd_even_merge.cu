////12163291 강현지 알고리즘설계 HW1
//#pragma warning(disable: 4819) //경고 끄기
//
//#include<stdio.h>
//#include<iostream>
//#include <cuda_runtime.h>
//#include <cuda.h>
//#include <time.h> //for난수
//#include <math.h>
//
//using namespace std;
//
//#define DATASIZE 1048576 //2048 131072 262144 1048576원래 안됐는데 스택 오버플로우 설정 따로 해주니 됐음
//#define BLOCK_SIZE 2048  //1024 2048 2048 2048
////524288 1024 오래걸려서 그렇지 되긴함 2097152 개 //80초,,
////1048576 1024 아무리기다려도..
////1048576 2048 4194304개 0.21초 0.204초 등듣등
////1048576 4089 0.211초등등 우선 2048이랑 별차이는 없음
//
//void print_elapsed(clock_t start, clock_t stop) //시간출력용
//{
//    double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC;
//    printf("CUDA ODD EVEN MERGE\n소요시간 : %.3fs\n", elapsed);
//}
//
//__global__ void oddevensort(int* input, unsigned int len, int i)
//{
//    //개별 블럭의 좌표
//    unsigned int tx = threadIdx.x;
//
//    //전체 이미지의 좌표
//    unsigned int x = tx + blockDim.x * blockIdx.x;
//    //이동에 쓸 임시 변수
//    int temp;
//
//    //자료의 길이만큼 돌리는데, 인덱스(i)가 짝수이면 데이터의 짝수자리와 그 다음 숫자를 비교.
//    //인덱스가 홀수이면 데이터의 홀수자리와 그 다음 숫자를 비교해서 정렬한다.
//    if (i % 2 == 0)
//    {
//        // 길이를 측정안해주면 블럭에 남아있던 자리에 있는 자료가 튀어나올 수 있으니 조심.
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
//    cout << "12163291\n강현지\n";
//
//    srand(time(NULL));
//
//    for (int i = 0; i < DATASIZE; i++) {
//        TestInput[i] = rand() % 100; //난수생성해줍니다.
//    }
//
//    //device 설정
//    int* devInput, * devOutput;
//    //일단 크기는 아니까
//    unsigned int MemDataSize = DATASIZE * sizeof(int);
//
//    // device 자리 잡아줍니다.
//    cudaMalloc((void**)&devInput, MemDataSize);
//    cudaMalloc((void**)&devOutput, MemDataSize);
//    cudaMemset(devOutput, 0, MemDataSize);
//
//    // 자리 잡았으면 복사를 해줍니다.00000
//    cudaMemcpy(devInput, TestInput, MemDataSize, cudaMemcpyHostToDevice);
//
//    // block 크기 설정합니다.
//    dim3    dimBlocksize(BLOCK_SIZE);
//    dim3    dimGridsize(ceil((DATASIZE - 1) / (float)BLOCK_SIZE) + 1);
//    // 일단 Max값과 min값을 알아야 합니다.
//    // 비교적 간단하니 cpu에게 맡겨줍니다.
//    
//    start = clock();
//    for (int i = 0; i < DATASIZE; i++) {
//        oddevensort << < dimGridsize, dimBlocksize >> > (devInput, DATASIZE, i);
//    }
//    stop = clock();
//
//    // 결과물 testoutput에 복사합니다.
//    cudaMemcpy(TestOutput, devInput, MemDataSize, cudaMemcpyDeviceToHost);
//
// /*   for (int i = 0; i < DATASIZE; i++) {
//        cout << TestOutput[i] << ", ";  //결과 확인용
//        if ((i + 1) % 16 == 0)  {
//            cout << endl;
//        }
//    }*/
//    cout << endl << "배열 크기 : " << sizeof(TestOutput) << endl << endl;
//   print_elapsed(start, stop); //걸린시간 출력해줍니다.
//
//   //위에 GPU에 마련한 자리 free.
//   //malloc - free는 항상 짝이지요. 
//   //항상해줘야 합니다. 
//    cudaFree(devInput);
//    cudaFree(devOutput);
//
//    return 0;
//}
//
////https://github.com/ptjoker95/OddEvenSort-with-CUDA/blob/master/oddevensort.cu
////출처는 위와 같습니다.
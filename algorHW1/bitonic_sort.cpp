
#include <iostream>
#include <time.h> //for 난수생성
using namespace std;

#define SWAP(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
#define ASIZE 16 //100이면0초걸림 10000이면 0.04 인가 정도 걸림 
//2의n제곱의 수를 입력으로 넣어야 결과가 출력됨, 왜냐하면 병렬 과정이기 때문에 .

#define UP true //true
#define DOWN false //false

clock_t start, finish, used_time = 0;//실행 시간 측정을 위한 변수

//실행 시간을 측정 및 출력하는 함수
void calculate_time(void)
{
	used_time = finish - start;
	cout << ".... 완료!" << endl << "소요시간 : " << (float)used_time / CLOCKS_PER_SEC << " 초" << endl;
}

//direcion은 sorting 방향을 나타냅니다. 오름차, 내림차. 만약 random_data[i] > random_data[j] (왼쪽이 오른쪽보다 큼)가 방향(1이면 오름차 0이면 내림차)과 같으면, 둘의 자리는 swap 됩니다. 
void compAndSwap(int random_data[], int i, int j, int direction)
{
	int temp;
	if (direction == (random_data[i] > random_data[j])) //true면 1이 나올거고 아니면0
		SWAP(random_data[i], random_data[j],temp);
}

//direction 값이 1이면, 오름차순일거고 0이면 내림차순 일것임. sorting시작점은 index 위치 low에서 시작된다. 보통0이지만 다를 수도있지. array_size는 sorting되는 요소들의 개수입니다.
 void bitonicMerge(int random_data[], int low, int array_size, int direction)
{
	if (array_size > 1)
	{
		int k = array_size / 2 ;

		for (int i = low; i < low + k ; i++) {
			compAndSwap(random_data, i, i + k, direction);
		}
		
		// Merge the results.
		bitonicMerge(random_data, low, k, direction);
		
		bitonicMerge(random_data, low + k, k, direction);
	
		for (int i = 0; i < ASIZE; i++) {
			cout << random_data[i] << (i % 16 == 15 ? "\n\n" : ","); //10개 출력마다 endl
		}
	}
}

/* This function first produces a bitonic sequence by recursivel sorting its two halves in opposite sorting orders, and then calls bitonicMerge to make them in the same order */
void bitonic_sort(int random_data[], int low, int array_size, int direction) //random_data, 0, ASIZE, upORdown
{
	if (array_size > 1)
	{
		int k = array_size / 2 ;

		// sort in ascending order since direction here is 1 (up)
		bitonic_sort(random_data, low, k, UP);

		// sort in descending order since direction here is 0 (down) 
		bitonic_sort(random_data, low + k, k, DOWN);
	
		// 첫 예시 upORdown 값이 1이므로, Merge the results in ascending order 
		bitonicMerge(random_data, low, array_size, direction);
		
	}
}

int random_data[ASIZE]; // 배열의 크기 = 정렬할 데이터의 개수

// Driver code 
int main()
{
	int upORdown = 1;   // 1이면 오름차순 // 0 이면 내림차순  

	srand((int)time(NULL));

	for (int i = 0; i < ASIZE; i++) { // for문 반복횟수 = 정렬할 데이터의 개수
		random_data[i] = rand() % 1000; // %1000이므로, 백의 자리수로 랜덤변수 
	}

	cout << "처음" << endl;
	for (int i = 0; i < ASIZE; i++) {
		cout << random_data[i] << (i % 16 == 15 ? "\n\n" : ","); //10개 출력마다 endl
	}

	start = clock(); //시작시간 재기

	bitonic_sort(random_data, 0, ASIZE , upORdown);

	finish = clock(); //끝난시간 재기

	//확인용
	cout << "확인용" << endl;
	for (int i = 0; i < ASIZE ; i++) {
		cout << random_data[i] << (i % 16 == 15 ? "\n\n" : ","); //10개 출력마다 endl
	}

	calculate_time(); //sorting 하는데 걸린시간
                                               
	return 0;
}

//int N = array_sizeof(random_data) / array_sizeof(random_data[0]); //어레이 전체크기  / 어레이 한칸 크기
//배열에 숫자가 몇개 들어갔는지 알기 위해 크기를 구할 때는 = 위와같이 전체 공간을 요소의 크기로 나눠줌
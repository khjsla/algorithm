//12163291 강현지 알고리즘 설계 HW1
#include <stdio.h>
#include <iostream>
#include <time.h> //for 난수생성
using namespace std;

#define SWAP(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
#define ASIZE 4194304 //100이면0초걸림 10000이면 0.04 인가 정도 걸림 
//2의n제곱의 수를 입력으로 넣어야 결과가 출력됨, 왜냐하면 병렬 과정이기 때문에 .

#define ASIZE_sel 200000 //100이면0초걸림 10000이면 0.04 인가 정도 걸림 
//select는 성능이 제일 별로라서 입력 숫자 값을 따로 설정해 주었습니다.

#define UP true //true
#define DOWN false //false

clock_t start, finish, used_time = 0;//실행 시간 측정을 위한 변수

//실행 시간을 측정 및 출력하는 함수
void calculate_time(void)
{
	used_time = finish - start;
	cout << "소요시간 : " << (float)used_time / CLOCKS_PER_SEC << "s" << endl << endl;
}

///////////////////////////////// SELECTION //////////////////////////////////

void selection_sort(int random_data[], int n) { //n= 데이터 개수, []=데이터 값 들어있는 배열
	int min, temp;

	//마지막 숫자는 자동적으로 정렬되므로 sort를 안해줘도 된다. 따라서 n-1만큼 반복한다.
	for (int i = 0; i < n - 1; i++) {
		min = i; //우선 처음에는 최솟값이 처음자리 [0]임. 
		//i 숫자 자리에 맞는 값을 찾아주게 되는것임
		//이후에 최솟값을 탐색해서 이와 비교해줌,

		//최솟값을 탐색한다
		for (int j = i + 1; j < n; j++) { //i값의 자리를 찾아줘야 하므로, i+1부터 비교해줌
			if (random_data[j] < random_data[min]) { //가장 작은 수가 나올때까지 반복 비교해서 
				min = j; //min에 가장작은 수가 들어있는 index값을 넣어줌.
			}
		}

		//자기자신이 최솟값이면 이동을 하지않고,
		//자기자신이 최솟값이 아니면 swap으로 자기자신의 자리와 최솟값의 자리를 바꿔줍니다.
		if (i != min) {
			SWAP(random_data[i], random_data[min], temp);
		}
	}
}

///////////////////////////////// Median 3 QUICK //////////////////////////////////

//퀵정렬의 속도향상 방법 -3 ; 중간값 분할
void three_sort(int random_data[], int left, int mid, int right) { //3개의 후보 pivot을 순서대로 정리하는 함수

	int temp;

	if (random_data[left] > random_data[mid]) SWAP(random_data[left], random_data[mid], temp);
	if (random_data[mid] > random_data[right]) SWAP(random_data[mid], random_data[right], temp);
	if (random_data[left] > random_data[mid]) SWAP(random_data[left], random_data[mid], temp);

	//이걸로 맨왼쪽이 가장큰 순서대로 3개 pivot후보가 정렬됨
}

//quicksort는 inplace (별도의 저장공간 필요하지않음)
void quick_sort(int random_data[], int left, int right) { //n= 데이터 개수, []=데이터 값 들어있는 배열
	int pivot, temp;
	int mid = left + (right - left) / 2; //중간 길이(mid) 값 인덱스 찾기

	three_sort(random_data, left, mid, right); //세개의 예비pivot 순차적으로 정렬

	if (right - left + 1 > 3) { //정렬할 대상이 3개 이상인 경우에만 quick_sort 수행.

		pivot = random_data[mid]; //pivot설정해줌 (위에서 구한 mid 인덱스 자리에 있는 값이 기준이됨)

		SWAP(random_data[mid], random_data[right - 1], temp); //가운데있는 pivot 기준값을 맨오른쪽에서 1개 왼쪽에 있는 거랑 자리 바꿔줌

		int i = left; //맨앞은 그냥 맨앞
		int j = right - 1; //맨뒤는 이미정렬되어있으므로, right이 아닌 right-1부터 시작 //맨 오른쪽에서 하나 -1 부터

		while (true) { //break 일때까지 while문 반복

			while (random_data[++i] < pivot && i < right); //왼쪽에서하나 오른쪽으로 오게됐고(점점 중앙으로), 맨 오른쪽 보다 작으면
			while (random_data[--j] > pivot && left < j);  //오른쪽에서하나 왼쪽으로 오게됐고(점점 중앙으로), 맨 왼쪽 보다 크면

			if (i >= j) break; //만나게 되면 그 곳이 pivot의 자리입니다.

			SWAP(random_data[i], random_data[j], temp); //자리 바꿔줍니다.
		}

		SWAP(random_data[i], random_data[right - 1], temp); //자리를 찾았으므로 값 넣어줌
		quick_sort(random_data, left, i - 1); //왼쪽부분 sort
		quick_sort(random_data, i + 1, right); //오른쪽 부분 sort
	}
}

// i++는 i에 1을 증가시킨 후, 증가시키기 전 값을 return합니다.
// ++i는 i에 1을 증가시킨 후, 그 증가된 값을 return합니다.

///////////////////////////////// SHELL //////////////////////////////////

//shell sort = insertion 을 보완한 알고리즘
void shell_sort(int random_data[], int size) { //n= 데이터 개수, []=데이터 값 들어있는 배열 //gap은 size/2
	for (int gap = size / 2; gap > 0; gap /= 2) { //gap 이 0보다 크면 계속 진행합니다. 갭은 회차마다 /2 가 됩니다.
		if (gap % 2 == 0) { //갭이 만약 짝수이면
			gap++; //+1로 홀수로 만들어 줍니다. 홀수인 것이 더 좋기 때문입니다.
		}
		for (int i = gap; i < size; i++) { //gap의 숫자에 +1하면서 (갭끼리 비교하면서) 하나씩 오른쪽으로 끝이나올때까지 이동합니다.
			int temp = random_data[i]; //현재 삽입될 숫자인 i번째 값을 temp에 저장해둡니다.
			int j = 0;
			//i-gap까지는 정렬되어있으므로,i ~ i-gap 까지확인
			//j가 gap값 보다 크고 temp값보다 j - gap 배열(gap의 왼쪽)의 값이 크면 
			for (j = i; (j > gap && random_data[j - gap] > temp); j = j - gap) {
				random_data[j] = random_data[j - gap]; //갭의 차이만큼 있는 것 끼리 자리 바꿔줍니다.
			}
			random_data[j] = temp; //삽입될 숫자를 j에  
		}
	}
}

///////////////////////////////// BITONIC //////////////////////////////////

//direcion은 sorting 방향을 나타냅니다. 오름차, 내림차. 만약 random_data[i] > random_data[j] (왼쪽이 오른쪽보다 큼)가 방향(1이면 오름차 0이면 내림차)과 같으면, 둘의 자리는 swap 됩니다. 
void compAndSwap(int random_data[], int i, int j, int direction)
{
	int temp;
	if (direction == (random_data[i] > random_data[j])) //true면 1이 나올거고 아니면0
		SWAP(random_data[i], random_data[j], temp);
}

//direction 값이 1이면, 오름차순일거고 0이면 내림차순 일것임. sorting시작점은 index 위치 low에서 시작된다. 보통0이지만 다를 수도있지. array_size는 sorting되는 요소들의 개수입니다.
void bitonicMerge(int random_data[], int low, int array_size, int direction)
{
	if (array_size > 1)
	{
		int k = array_size / 2;

		for (int i = low; i < low + k; i++) {
			compAndSwap(random_data, i, i + k, direction);
		}

		// Merge the results.
		bitonicMerge(random_data, low, k, direction);
		bitonicMerge(random_data, low + k, k, direction);
	}
}

/* This function first produces a bitonic sequence by recursivel sorting its two halves in opposite sorting orders, and then calls bitonicMerge to make them in the same order */
void bitonic_sort(int random_data[], int low, int array_size, int direction) //random_data, 0, ASIZE, upORdown
{
	if (array_size > 1)
	{
		int k = array_size / 2;

		// sort in ascending order since direction here is 1 (up)
		bitonic_sort(random_data, low, k, UP); //오름차순으로 정렬하는 부분

		// sort in descending order since direction here is 0 (down) 
		bitonic_sort(random_data, low + k, k, DOWN); //내림차순으로 정렬하는 부분

		// 첫 예시 upORdown 값이 1이므로, Merge the results in ascending order 
		bitonicMerge(random_data, low, array_size, direction); //merge 하는 함수
	}
}

///////////////////////////////// oddeven MERGE //////////////////////////////////

class batcher //바처 알고리즘 클래스를 선언해줍니다.
{
public:
	void oddevenmergesort(int random_data[], int left, int n);
	void oddevenmerge(int random_data[], int left, int n, int r);
};

void batcher::oddevenmergesort(int random_data[], int left, int n)
{
	if (n > 1) //맨오른 이 1보다크먄
	{
		int m = n / 2; //m이라는 수는 맨오른수의 /2 즉, 배열을 반으로가름, 4로
		oddevenmergesort(random_data, left, m); //재귀. 처음에는 0,4 임 / 다음은 0,2임 / 다음은 0,1이므로 끝남
		oddevenmergesort(random_data, left + m, m);
		oddevenmerge(random_data, left, n, 1);
	}
	/* left is the starting position and
	 n is the length of the piece to be merged,
	 r is the distance of the elements to be compared //r은 비교할 숫자간의 간격. 1의 간격을 가지게됨
	*/
}

void batcher::oddevenmerge(int random_data[], int left, int n, int r)
{
	int m = r * 2;
	int temp; //for swap

	if (m < n)
	{
		oddevenmerge(random_data, left, n, m); // even subsequence 
		oddevenmerge(random_data, left + r, n, m); // odd subsequence
		for (int i = left + r; i + r < left + n; i += m) {
			if (random_data[i] > random_data[i + r]) //비교해서 스왑해줍니다.
				SWAP(random_data[i], random_data[i + r], temp);
		}
	}
	else { //m이 n보다 크면
		if (random_data[left] > random_data[left + r])
			SWAP(random_data[left], random_data[left + r], temp);
	}

}

int random_data[ASIZE]; // 배열의 크기 = 정렬할 데이터의 개수
int random_data_sel[ASIZE_sel]; // 배열의 크기 = 정렬할 데이터의 개수
int cparray[ASIZE];

void cparr(int random_data[ASIZE]) { //비교용 어레이 카피 함수입니다.
	for (int i = 0; i < ASIZE; i++) {
		cparray[i] = random_data[i];
	}
}

void printarr(int random_array[ASIZE],int size) { //확인용 어레이 프린트 함수입니다.
	for (int i = 0; i < size; i++) {
		cout << random_array[i] << (i % 16 == 15 ? "\n\n" : ","); //16개 출력마다 endl
	}
}

///////////////////////////////// Driver code 
int main(){
	cout << "12163291  \n강현지\n" << endl;

	int upORdown = 1;   // 1이면 오름차순 // 0 이면 내림차순  

	srand((int)time(NULL));
	for (int i = 0; i < ASIZE; i++) { // for문 반복횟수 = 정렬할 데이터의 개수
		random_data[i] = rand() % 100; // %1000이므로, 백의 자리수로 랜덤변수 
	}

	for (int i = 0; i < ASIZE_sel; i++) {
		random_data_sel[i] = random_data[i];
	}

	start = clock(); //시작시간 재기
	selection_sort(random_data_sel, ASIZE_sel); //오름차순 정렬
	finish = clock(); //끝난시간 재기
	cout << "SELECTION" << endl;
	calculate_time(); //sorting 하는데 걸린시간

	cparr(random_data);

	start = clock(); //시작시간 재기
	quick_sort(cparray, 0, ASIZE - 1); //배열은 0부터 시작이므로 SIZE-1 이 left값
	finish = clock(); //끝난시간 재기
	//printarr(cparray, ASIZE);
	cout << "MED 3 QUICK" << endl;
	calculate_time(); //sorting 하는데 걸린시간

	cparr(random_data);

	start = clock(); //시작시간 재기
	shell_sort(cparray, ASIZE);
	finish = clock(); //끝난시간 재기
	//printarr(cparray, ASIZE);
	cout << "SHELL" << endl;
	calculate_time(); //sorting 하는데 걸린시간

	cparr(random_data);

	start = clock(); //시작시간 재기
	bitonic_sort(cparray, 0, ASIZE, upORdown);
	finish = clock(); //끝난시간 재기
	//printarr(cparray, ASIZE);
	cout << "BITONIC" << endl;
	calculate_time(); //sorting 하는데 걸린시간

	cparr(random_data);

	batcher ba;
	start = clock(); //시작시간 재기
	ba.oddevenmergesort(cparray, 0, ASIZE);
	finish = clock(); //끝난시간 재기
	//printarr(cparray, ASIZE);
	cout << "ODD EVEN MERGE" << endl;
	calculate_time(); //sorting 하는데 걸린시간

	return 0;
}

//int N = array_sizeof(random_data) / array_sizeof(random_data[0]); //어레이 전체크기  / 어레이 한칸 크기
//배열에 숫자가 몇개 들어갔는지 알기 위해 크기를 구할 때는 = 위와같이 전체 공간을 요소의 크기로 나눠줌
#include <iostream>
#include <time.h> //for 난수생성
using namespace std;

#define SWAP(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
#define ASIZE 16

clock_t start, finish, used_time = 0;    //실행 시간 측정을 위한 변수

//실행 시간을 측정 및 출력하는 함수
void calculate_time(void){
	used_time = finish - start;
	cout << ".... 완료!" << endl << "소요시간 : " << (float)used_time / CLOCKS_PER_SEC << " 초" << endl;
}

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
		int j = right - 1; //맨뒤는 이미정렬되어있으므로, right이 아닌 right-1부터 시작 //맨왼쪽에서 하나 왼쪽부터

		while(true) { //break 일때까지 while문 반복
			
			while (random_data[++i] > pivot && i < right);
			while (random_data[--j] < pivot && left < j);
			
			if (i >= j) break; 

			SWAP(random_data[i], random_data[j], temp);
		}
		
		SWAP(random_data[i], random_data[right - 1], temp);
		quick_sort(random_data, left, i - 1);
		quick_sort(random_data, i + 1, right);
	}
}

// i++는 i에 1을 증가시킨 후, 증가시키기 전 값을 return합니다.
// ++i는 i에 1을 증가시킨 후, 그 증가된 값을 return합니다.

int random_data[ASIZE]; // 배열의 크기 = 정렬할 데이터의 개수
//stack overflow 방지 위해 전역으로 우선 정의

int main() {

	srand((int)time(NULL));

	for (int i = 0; i < ASIZE; i++) { // for문 반복횟수 = 정렬할 데이터의 개수
		random_data[i] = rand() % 100; // %1000이므로, 백의 자리수로 랜덤변수 
	}

	start = clock(); //시작시간 재기

	quick_sort(random_data,0,ASIZE-1); //배열은 0부터 시작이므로 SIZE-1 이 left값

	finish = clock(); //끝난시간 재기

	//확인용
	for (int i = 0; i < ASIZE; i++) {
		cout << random_data[i] << (i % 16 == 15 ? "\n\n" : ","); //10개 출력마다 endl
	}

	calculate_time(); //sorting 하는데 걸린시간

}
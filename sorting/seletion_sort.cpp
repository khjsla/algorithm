#include <iostream>
#include <time.h> //for 난수생성
using namespace std;

#define swap(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
#define ASIZE 100000 //이게 겨우임 //10초

clock_t start, finish, used_time = 0;    //실행 시간 측정을 위한 변수

//실행 시간을 측정 및 출력하는 함수
void calculate_time(void)
{
	used_time = finish - start;
	cout << ".... 완료!" << endl << "소요시간 : " << (float)used_time / CLOCKS_PER_SEC << " 초" << endl;
}


void selection_sort(int random_data[], int n) { //n= 데이터 개수, []=데이터 값 들어있는 배열
	int min,temp;

	//마지막 숫자는 자동적으로 정렬되므로 sort를 안해줘도 된다. 따라서 n-1만큼 반복한다.
	for (int i = 0; i < n - 1; i++) { 
		min = i; //우선 처음에는 최솟값이 처음자리 [0]임. 
		//i 숫자 자리에 맞는 값을 찾아주게 되는것임
		//이후에 최솟값을 탐색해서 이와 비교해줌,

		//최솟값을 탐색한다
		for (int j = i + 1; j < n; j++) { //i값의 자리를 찾아줘야 하므로, i+1부터 비교해줌
			if (random_data[j] > random_data[min]) { //가장 작은 수가 나올때까지 반복 비교해서 
				min = j; //min에 가장작은 수가 들어있는 index값을 넣어줌.
			}
		}

		//자기자신이 최솟값이면 이동을 하지않고,
		//자기자신이 최솟값이 아니면 swap으로 자기자신의 자리와 최솟값의 자리를 바꿔줍니다.
		if (i != min) {
			swap(random_data[i], random_data[min], temp);
		}
	}
}
int random_data[ASIZE]; // 배열의 크기 = 정렬할 데이터의 개수

int main() {

	//main내에서 배열크기가 500000이 되니 stack overflow발생
	//전역변수로 설정해주니 stack overflow에러는 발생하지 않았지만 
	//컴퓨터에 무리가 가는듯한 느낌이 들어서 100000정도로 우선설정
	//이건 10초정도에 마무리가되더라

	srand((int)time(NULL)); 
	
	for (int i = 0; i < ASIZE; i++) { // for문 반복횟수 = 정렬할 데이터의 개수
		random_data[i] = rand() % 1000; // %1000이므로, 백의 자리수로 랜덤변수 
	} 

	start = clock(); //시작시간 재기

	selection_sort(random_data, ASIZE); //지금은 오름차순 정렬
	
	finish = clock(); //끝난시간 재기

	/*for (int i = 0; i < ASIZE; i++) {
		cout << random_data[i] << (i % 10 == 9 ? "\n\n" : ","); //10개 출력마다 endl
	}*/

	calculate_time(); //sorting 하는데 걸린시간

}
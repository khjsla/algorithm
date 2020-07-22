#pragma warning(disable:4996)

#include <map> //for map
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define SWAP(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )

bool nowaycheck(int a[], int b[], int n);
void selection_sort(int a[], int b[], int lr[], int diff[], int n);
void result(int lr[], int diff[], int n);
int nextlrchange(int lr[], int n, int x);

int main() {
	int *a; //a의 빵 밀가루 배열
	int *b; //b의 빵 밀가루 배열
	int *lr;
	int *diff;
	int n;
	scanf("%d", &n); //빵 종류

	a = (int *)malloc(sizeof(int)* n);
	b = (int *)malloc(sizeof(int)* n);
	lr = (int *)malloc(sizeof(int)* n);
	diff = (int *)malloc(sizeof(int)* n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	} //이러면 a[], b[]에 값 제대로 채워지게 죔

	if (nowaycheck(a, b, n)) { //한쪽이 크거나 작으면
		free(a); //동적할당 해제
		free(b);
		printf("-1");
		return -1;
	}
	else {

		for (int i = 0; i < n; i++) { //pair 만들기
			if (a[i] > b[i]) { //왼-1
				diff[i] = a[i] - b[i];
				lr[i] = 1;
			}
			else { //오-2
				diff[i] = b[i] - a[i];
				lr[i] = 2;
			}
		} //차이, 왼오 정리

		selection_sort(a, b, lr, diff, n); //오름차 정렬됨


		free(a); //동적할당 해제
		free(b);
		return 0;
	}
}

bool nowaycheck(int a[], int b[], int n) {
	int acnt = 0;
	int bcnt = 0;
	for (int i = 0; i < n; i++) { //n번반복
		if (a[i] > b[i]) acnt++;
		else bcnt++;
	}
	if (acnt == n || bcnt == n) {
		return true;
	}
}

void selection_sort(int a[],int b[],int lr[], int diff[], int n) { //n= 데이터 개수, []=데이터 값 들어있는 배열
	int min, temp;

	//마지막 숫자는 자동적으로 정렬되므로 sort를 안해줘도 된다. 따라서 n-1만큼 반복한다.
	for (int i = 0; i < n - 1; i++) {
		min = i; //우선 처음에는 최솟값이 처음자리 [0]임. 
		//i 숫자 자리에 맞는 값을 찾아주게 되는것임
		//이후에 최솟값을 탐색해서 이와 비교해줌,

		//최솟값을 탐색한다
		for (int j = i + 1; j < n; j++) { //i값의 자리를 찾아줘야 하므로, i+1부터 비교해줌
			if (a[j] < a[min]) { //가장 작은 수가 나올때까지 반복 비교해서 
				min = j; //min에 가장작은 수가 들어있는 index값을 넣어줌.
			}
		}

		//자기자신이 최솟값이면 이동을 하지않고,
		//자기자신이 최솟값이 아니면 swap으로 자기자신의 자리와 최솟값의 자리를 바꿔줍니다.
		if (i != min) {
			SWAP(a[i], a[min], temp);
			SWAP(b[i], b[min], temp);
			SWAP(lr[i], lr[min], temp);
			SWAP(diff[i], diff[min], temp);
		}
	}
}

void result(int lr[], int diff[], int n) {
	int i = 0;
	int next = 0;
	int result_l; //왼쪽 합 
	int result_r; //오른쪽 합
	do {
		if (lr[0] == 1) { //왼쪽이 더 크면
			result_l = diff[i]; //왼쪽 결과 값이 차이 값 넣음
		}
		else {//오른쪽이 더 크면
			result_r = diff[i];
		}

		if (diff[0] == 0) {
		}

		next = nextlrchange(lr, n, i); //바로 가장 가까운반대푠 차이 값 찾음
		if (diff[i] < diff[next]) {
			
		}
	} while (result_l == result_r);
}

int nextlrchange(int lr[],int n,int x) {
	int i = 0;
	int chk = lr[x]; //x번째값이 무슨 방향인지 - 왼이면 1 오른이면 2
	while (true){
		i++;
		if (lr[i] != chk) break; //다음에 달라지는 곳
	}
	return i;
}
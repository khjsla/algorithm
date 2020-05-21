

#include <iostream>
#include <stack> //for 스택사용
#include <time.h>
using namespace std;

#define ASIZE 100
#define swap(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )

int Partition(int a[], int left, int right)
{
	int pivot = a[right];
	// j가 r+1부터 시작하는 이유는 가장 처음에 v와 비교할 때 j를 감소시키고 시작하기 때문이다.
	// i도 마찬가지라서, a[l+1]부터 비교하게 된다.

	int index = left;
	int temp;

	// i와 j가 교차될 때까지 진행한다.
	for (int i = left; i < right; i++) {
		if (a[i] <= pivot) {
			swap(a[i], a[index], temp);
			index++;
		}
	}

	swap(a[index], a[right], temp);
	return index;
}

void QuickSort(int a[], int left, int right){
	int index;
	
	if (left<right) {
		index = Partition(a, left, right);
		QuickSort(a, left, index - 1); //왼쪽줄세우기 끝
		QuickSort(a, index + 1, right); //오른쪽 줄세우기 끝
	}
	else {
		return;
	}
}

int a[ASIZE] = { 0, };

int main() {
	srand((int)time(NULL));

	for (int i = 0; i < ASIZE; i++) { // for문 반복횟수 = 정렬할 데이터의 개수
		a[i] = rand() % 1000; // %1000이므로, 백의 자리수로 랜덤변수 
	}

	QuickSort(a, 0, ASIZE - 1);

	for (int i = 0; i < ASIZE; i++) {
		cout << a[i] << (i % 10 == 9 ? "\n\n" : ","); //10개 출력마다 endl
	}

}
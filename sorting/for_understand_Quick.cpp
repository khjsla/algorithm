

#include <iostream>
#include <stack> //for ���û��
#include <time.h>
using namespace std;

#define ASIZE 100
#define swap(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )

int Partition(int a[], int left, int right)
{
	int pivot = a[right];
	// j�� r+1���� �����ϴ� ������ ���� ó���� v�� ���� �� j�� ���ҽ�Ű�� �����ϱ� �����̴�.
	// i�� ����������, a[l+1]���� ���ϰ� �ȴ�.

	int index = left;
	int temp;

	// i�� j�� ������ ������ �����Ѵ�.
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
		QuickSort(a, left, index - 1); //�����ټ���� ��
		QuickSort(a, index + 1, right); //������ �ټ���� ��
	}
	else {
		return;
	}
}

int a[ASIZE] = { 0, };

int main() {
	srand((int)time(NULL));

	for (int i = 0; i < ASIZE; i++) { // for�� �ݺ�Ƚ�� = ������ �������� ����
		a[i] = rand() % 1000; // %1000�̹Ƿ�, ���� �ڸ����� �������� 
	}

	QuickSort(a, 0, ASIZE - 1);

	for (int i = 0; i < ASIZE; i++) {
		cout << a[i] << (i % 10 == 9 ? "\n\n" : ","); //10�� ��¸��� endl
	}

}
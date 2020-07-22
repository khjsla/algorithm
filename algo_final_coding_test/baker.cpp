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
	int *a; //a�� �� �а��� �迭
	int *b; //b�� �� �а��� �迭
	int *lr;
	int *diff;
	int n;
	scanf("%d", &n); //�� ����

	a = (int *)malloc(sizeof(int)* n);
	b = (int *)malloc(sizeof(int)* n);
	lr = (int *)malloc(sizeof(int)* n);
	diff = (int *)malloc(sizeof(int)* n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	} //�̷��� a[], b[]�� �� ����� ä������ ��

	if (nowaycheck(a, b, n)) { //������ ũ�ų� ������
		free(a); //�����Ҵ� ����
		free(b);
		printf("-1");
		return -1;
	}
	else {

		for (int i = 0; i < n; i++) { //pair �����
			if (a[i] > b[i]) { //��-1
				diff[i] = a[i] - b[i];
				lr[i] = 1;
			}
			else { //��-2
				diff[i] = b[i] - a[i];
				lr[i] = 2;
			}
		} //����, �޿� ����

		selection_sort(a, b, lr, diff, n); //������ ���ĵ�


		free(a); //�����Ҵ� ����
		free(b);
		return 0;
	}
}

bool nowaycheck(int a[], int b[], int n) {
	int acnt = 0;
	int bcnt = 0;
	for (int i = 0; i < n; i++) { //n���ݺ�
		if (a[i] > b[i]) acnt++;
		else bcnt++;
	}
	if (acnt == n || bcnt == n) {
		return true;
	}
}

void selection_sort(int a[],int b[],int lr[], int diff[], int n) { //n= ������ ����, []=������ �� ����ִ� �迭
	int min, temp;

	//������ ���ڴ� �ڵ������� ���ĵǹǷ� sort�� �����൵ �ȴ�. ���� n-1��ŭ �ݺ��Ѵ�.
	for (int i = 0; i < n - 1; i++) {
		min = i; //�켱 ó������ �ּڰ��� ó���ڸ� [0]��. 
		//i ���� �ڸ��� �´� ���� ã���ְ� �Ǵ°���
		//���Ŀ� �ּڰ��� Ž���ؼ� �̿� ������,

		//�ּڰ��� Ž���Ѵ�
		for (int j = i + 1; j < n; j++) { //i���� �ڸ��� ã����� �ϹǷ�, i+1���� ������
			if (a[j] < a[min]) { //���� ���� ���� ���ö����� �ݺ� ���ؼ� 
				min = j; //min�� �������� ���� ����ִ� index���� �־���.
			}
		}

		//�ڱ��ڽ��� �ּڰ��̸� �̵��� �����ʰ�,
		//�ڱ��ڽ��� �ּڰ��� �ƴϸ� swap���� �ڱ��ڽ��� �ڸ��� �ּڰ��� �ڸ��� �ٲ��ݴϴ�.
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
	int result_l; //���� �� 
	int result_r; //������ ��
	do {
		if (lr[0] == 1) { //������ �� ũ��
			result_l = diff[i]; //���� ��� ���� ���� �� ����
		}
		else {//�������� �� ũ��
			result_r = diff[i];
		}

		if (diff[0] == 0) {
		}

		next = nextlrchange(lr, n, i); //�ٷ� ���� �����ݴ�Ǧ ���� �� ã��
		if (diff[i] < diff[next]) {
			
		}
	} while (result_l == result_r);
}

int nextlrchange(int lr[],int n,int x) {
	int i = 0;
	int chk = lr[x]; //x��°���� ���� �������� - ���̸� 1 �����̸� 2
	while (true){
		i++;
		if (lr[i] != chk) break; //������ �޶����� ��
	}
	return i;
}
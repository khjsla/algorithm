#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

typedef int index; 

float sum(index begin, index end, float p[]) { //���� ���ϴ� �κ�
	float sum_total = 0;
	for (int i = begin; i <= end; i++) {
		sum_total += p[i];
	}
	return sum_total;
}

void OptimalST(index n, index **R, float p[]) {
	index i, j, k, diagonal;

	float **A = new float*[n + 2];
	float min;

	for (int s = 0; s < n + 2; s++) {
		A[s] = new float[n + 1];
	}

	//��꿡 ������ �ʴ� �κ�
	for (int i = 1; i <= n; i++) {
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		A[0][i - 1] = NULL;

		R[i][i] = i; //���⼭ ���� �ԷµǴ±���
		R[i][i - 1] = 0;
		R[0][i - 1] = NULL;
	}

	A[0][n] = NULL;
	A[n + 1][n] = 0;

	R[0][n] = NULL;
	R[n + 1][n] = 0;

	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			min = A[i][i - 1] + A[i + 1][j] + sum(i, j, p);
			for (k = i; k <= j; k++) {
				if (min >= A[i][k - 1] + A[k + 1][j] + sum(i, j, p)) {
					min = A[i][k - 1] + A[k + 1][j] + sum(i, j, p);
					R[i][j] = k; //1,2,3,4 ���ķδ� ���⼭ �ԷµǴ±���
				}
			}
			A[i][j] = min;
		}
	}

	//for A(�ּ� Ȯ�� ��)Ȯ�� 
	for (index i = 1; i <= n; i++) {
		for (index j = i; j <= n; j++) {
			printf("A[%d][%d]-%f ", i, j, A[i][j]);
			if (j % 4 == 0) printf("\n"); //�ٹٲ�
		}
	}

	printf("\n���� �� A: %f\n", A[1][n]);

	for (int s = 0; s < n + 2; s++) {
		delete[] A[s]; //�޸� Ǯ���ֱ�
	}

}

int main() {
	//�� �ϳ� �Է¹ް�, �� ũ�⸸ŭ�� �迭�ϳ�, �� ���� +1 ��ŭ�� �迭�ϳ� ����
	//�� ũ���� �迭���� �Էµ� ��尪,
	//+1 �迭���� Ȯ���� �־���

	int *key; //��尪
	float *p; //Ȯ����
	int n; //�������� ����
	scanf("%d", &n);
	
	key = (int*)malloc(sizeof(int)*n); //�Է°���ŭ key�迭 ����
	p = (float*)malloc(sizeof(float)*(n+1)); //�Է°�+1��ŭ p�迭 ����
	//p[0] = NULL;

	for (int i = 0; i < n; i++) { //������ ������ŭ
		scanf("%d %f", &key[i], &p[i + 1]);
	}

	index **R = new index *[n + 2];

	for (int i = 0; i < n + 2; i++) {
		R[i] = new index[n + 1];
	}

	OptimalST(n, R, p);

	//for R(��尪)Ȯ��
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			printf("R[%d][%d]-%d ", i, j, R[i][j]);
			if (j % 4 == 0)printf("\n");
		}
	}

	int x = R[1][n];
	printf("\n���װ� key: %d\n", key[x-1]);

	for (int i = 0; i < n + 2; i++) {
		delete[] R[i];
	}

	return 0;
}
#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

typedef int index; 

float sum(index begin, index end, float p[]) { //총합 구하는 부분
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

	//계산에 사용되지 않는 부분
	for (int i = 1; i <= n; i++) {
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		A[0][i - 1] = NULL;

		R[i][i] = i; //여기서 값이 입력되는구나
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
					R[i][j] = k; //1,2,3,4 이후로는 여기서 입력되는구나
				}
			}
			A[i][j] = min;
		}
	}

	//for A(최소 확률 값)확인 
	for (index i = 1; i <= n; i++) {
		for (index j = i; j <= n; j++) {
			printf("A[%d][%d]-%f ", i, j, A[i][j]);
			if (j % 4 == 0) printf("\n"); //줄바꿈
		}
	}

	printf("\n코테 값 A: %f\n", A[1][n]);

	for (int s = 0; s < n + 2; s++) {
		delete[] A[s]; //메모리 풀어주기
	}

}

int main() {
	//값 하나 입력받고, 그 크기만큼의 배열하나, 그 수의 +1 만큼의 배열하나 생성
	//그 크기의 배열에는 입력된 노드값,
	//+1 배열에는 확률값 넣어줌

	int *key; //노드값
	float *p; //확률값
	int n; //데이터의 개수
	scanf("%d", &n);
	
	key = (int*)malloc(sizeof(int)*n); //입력값만큼 key배열 생성
	p = (float*)malloc(sizeof(float)*(n+1)); //입력값+1만큼 p배열 생성
	//p[0] = NULL;

	for (int i = 0; i < n; i++) { //데이터 개수만큼
		scanf("%d %f", &key[i], &p[i + 1]);
	}

	index **R = new index *[n + 2];

	for (int i = 0; i < n + 2; i++) {
		R[i] = new index[n + 1];
	}

	OptimalST(n, R, p);

	//for R(노드값)확인
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			printf("R[%d][%d]-%d ", i, j, R[i][j]);
			if (j % 4 == 0)printf("\n");
		}
	}

	int x = R[1][n];
	printf("\n코테값 key: %d\n", key[x-1]);

	for (int i = 0; i < n + 2; i++) {
		delete[] R[i];
	}

	return 0;
}
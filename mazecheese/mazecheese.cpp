#define _CRT_SECURE_NO_WARNINGS
#define NO -1
#define TRAP 2

#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
//#include <iostream>
//using namespace std;

void in(int **p, int n, int m);
void out(int **p, int n, int m);
int find(int **p, int **x, int n, int m);

int main() {
	int **p;
	int **x;
	int n, m; //n = 행:세로몇줄? // m = 열:가로몇개?

	scanf("%d %d", &n, &m); //이중 배열 크기 입력

	//p 이중배열 생성
	p = (int**)malloc(sizeof(int *) *n);   // 이중 포인터에 (int 포인터 크기 * 세로 크기)만
	for (int i = 0; i < n; i++)            // 세로 크기만큼 반복
	{
		p[i] = (int *)malloc(sizeof(int) * m);    // (int 크기 * 가로 크기)만큼 동적 메모리 할당.
										   // 배열의 가로
	}

	//x 이중배열 생성
	x = (int**)malloc(sizeof(int *) *n);   // 이중 포인터에 (int 포인터 크기 * 세로 크기)만
	for (int i = 0; i < n; i++)            // 세로 크기만큼 반복
	{
		x[i] = (int *)malloc(sizeof(int) * m);    // (int 크기 * 가로 크기)만큼 동적 메모리 할당.
										   // 배열의 가로
	}

	in(p, n, m); //입력
	//out(p, n, m); //확인용

	//치즈 찾기
	printf("%d", find(p, x, n, m));

	//메모리 free
	for (int i = 0; i < n; i++) {   // 세로 크기만큼 반복
		free(p[i]);                // 2차원 배열의 가로 공간 메모리 해제
		free(x[i]);
	}
	free(p);    // 2차원 배열의 세로 공간 메모리 해제
	free(x);
}

void in(int **p, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &p[i][j]);
		}
	}
}
void out(int **p, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");//1n당 한줄 띄기
	}
}

int find(int **p, int **x, int n, int m){	
	int max = 0; //쥐가 가진 치즈 개수
	int mouse = p[n - 1][0]; //쥐 첫위치
	int i, j = 0;

	//경로기억 위한
	for (i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			x[i][j] = 0;
		}
	}

	//현 위치서 오른
	for (j = 1; j < m; j++) {
		if (x[n - 1][j - 1] == NO || p[n - 1][j] == TRAP) { //
			x[n - 1][j] = NO;
		}
		else {
			x[n - 1][j] = p[n - 1][j] + x[n - 1][j - 1];
		}
	}

	//현 위치서 위
	for (i = n - 2; i >= 0; i--) { 
		if (x[i + 1][0] == NO || p[i][0] == TRAP) {
			x[i][0] = NO;
		}
		else {
			x[i][0] = p[i][0] + x[i + 1][0];
		}
	}

	for (i = n - 2; i >= 0; i--) {
		for (j = 1; j < m; j++) {
			if (p[i][j] == TRAP) {
				x[i][j] = NO;
			}
			else { 
				if (x[i + 1][j] > x[i][j - 1]) {
					max = x[i + 1][j];
				}
				else {
					max = x[i][j - 1];
				}
				x[i][j] = p[i][j] + max; 
			}
		}
	}

	return x[0][m - 1];
}
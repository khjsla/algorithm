#define _CRT_SECURE_NO_WARNINGS
#define NO -1
#define TRAP 2

#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
//#include <iostream>
//using namespace std;

void in(int **p, int n, int m);
void out(int **p, int n, int m);
int find(int **p, int **x, int n, int m);

int main() {
	int **p;
	int **x;
	int n, m; //n = ��:���θ���? // m = ��:���θ?

	scanf("%d %d", &n, &m); //���� �迭 ũ�� �Է�

	//p ���߹迭 ����
	p = (int**)malloc(sizeof(int *) *n);   // ���� �����Ϳ� (int ������ ũ�� * ���� ũ��)��
	for (int i = 0; i < n; i++)            // ���� ũ�⸸ŭ �ݺ�
	{
		p[i] = (int *)malloc(sizeof(int) * m);    // (int ũ�� * ���� ũ��)��ŭ ���� �޸� �Ҵ�.
										   // �迭�� ����
	}

	//x ���߹迭 ����
	x = (int**)malloc(sizeof(int *) *n);   // ���� �����Ϳ� (int ������ ũ�� * ���� ũ��)��
	for (int i = 0; i < n; i++)            // ���� ũ�⸸ŭ �ݺ�
	{
		x[i] = (int *)malloc(sizeof(int) * m);    // (int ũ�� * ���� ũ��)��ŭ ���� �޸� �Ҵ�.
										   // �迭�� ����
	}

	in(p, n, m); //�Է�
	//out(p, n, m); //Ȯ�ο�

	//ġ�� ã��
	printf("%d", find(p, x, n, m));

	//�޸� free
	for (int i = 0; i < n; i++) {   // ���� ũ�⸸ŭ �ݺ�
		free(p[i]);                // 2���� �迭�� ���� ���� �޸� ����
		free(x[i]);
	}
	free(p);    // 2���� �迭�� ���� ���� �޸� ����
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
		printf("\n");//1n�� ���� ���
	}
}

int find(int **p, int **x, int n, int m){	
	int max = 0; //�㰡 ���� ġ�� ����
	int mouse = p[n - 1][0]; //�� ù��ġ
	int i, j = 0;

	//��α�� ����
	for (i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			x[i][j] = 0;
		}
	}

	//�� ��ġ�� ����
	for (j = 1; j < m; j++) {
		if (x[n - 1][j - 1] == NO || p[n - 1][j] == TRAP) { //
			x[n - 1][j] = NO;
		}
		else {
			x[n - 1][j] = p[n - 1][j] + x[n - 1][j - 1];
		}
	}

	//�� ��ġ�� ��
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
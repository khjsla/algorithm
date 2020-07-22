//12163291 ������ bellman
#include <iostream>
#include <stdlib.h>
using namespace std;

#define NODE 6

void BellmanFord();
void printBM();
void printMAP(int node_matrix[NODE][NODE]);

int node_matrix[NODE][NODE];
int D[NODE][NODE]; //distance;
int P[NODE][NODE]; //path

void main() {
	int node, i, j, temp;
	node = NODE;
	cout << "12163291 ������ Bellman-Ford" << endl;
	cout << "���� ����� ����:  " << NODE << endl;
	cout << "������ �ִ� ��尣�� �������� 9999�Է�." << endl;
	
	for (i = 0; i <= NODE - 1; i++) {
		for (j = 0; j <= NODE - 1; j++) {
			if (i != j) { //�밢�� �κ��� �ƴϸ�
				cout << i << "���� " << j << "�� ����ġ�� �Է��ϼ���.: ";
				cin >> temp;
				node_matrix[i][j] = temp;
				/*if (i == 0 && j == 1) {
					node_matrix[i][j] = 5;
				}
				else if (i == 0 && j == 2) {
					node_matrix[i][j] = 9;
				}
				else if (i == 0 && j == 3) {
					node_matrix[i][j] = 11;
				}
				else if (i == 1 && j == 4) {
					node_matrix[i][j] = 10;
				}
				else if (i == 2 && j == 1) {
					node_matrix[i][j] = -15;
				}
				else if (i == 2 && j == 3) {
					node_matrix[i][j] = 3;
				}
				else if (i == 2 && j == 4) {
					node_matrix[i][j] = 1;
				}
				else if (i == 3 && j == 5) {
					node_matrix[i][j] = 8;
				}
				else if (i == 3 && j == 6) {
					node_matrix[i][j] = 8;
				}
				else if (i == 4 && j == 7) {
					node_matrix[i][j] = 2;
				}
				else if (i == 5 && j == 2) {
					node_matrix[i][j] = 12;
				}
				else if (i == 6 && j == 5) {
					node_matrix[i][j] = -7;
				}
				else if (i == 7 && j == 6) {
					node_matrix[i][j] = 4;
				}
				else {
					node_matrix[i][j] = 9999;
				}*/
			}
			else { //�밢�� �κ�
				node_matrix[i][j] = 0;
			}
		}
	}

	printMAP(node_matrix); //�Էµ� node �� ��� �����ֱ�
	
	BellmanFord();
	cout << "\nBellman-Ford:" << endl;
	printBM();
}
void BellmanFord() {
	int i, j, k, x;

	for (i = 0; i <= NODE - 1; i++) {
		for (j = 0; j <= NODE - 1; j++) {
			P[i][j] = 0; //�ʱ�ȭ
			D[i][j] = node_matrix[i][j];
		}
	}

	bool cycle = false; //for ���� cycle ���� Ȯ�ο�

	for (x = 0; x <= NODE - 1; x++) {// N - 2 = n - 1 �� �ݺ� �ֳ��ϸ� ��ü ����� ���� N �� �̴ϱ� 
									 // +1�� �� �������� ������ ���� cycle Ȯ�� 
		for (k = 0; k <= NODE - 1; k++) { // �ҽ� 
			for (i = 0; i <= NODE - 1; i++) {// ��������
				for (j = 0; j <= NODE - 1; j++) { // ���.
					if (k != i) {
						if (D[k][j] + node_matrix[j][i] < D[k][i]) { //���� ���� ������ �� ���� ��θ� ã�Ե�
							//�ִܰ�� ���ŵ�
							D[k][i] = D[k][j] + node_matrix[j][i]; //ª�� ����ġ�� �����Ѵ�.
							P[k][i] = j + 1; //ª�� ���� ���� �� ����� ���� �����Ѵ�.
							//n (n-1 (+1) )���� ������ ��, �� ���� ���ŵǸ� 
							//���� cycle�� �ִ°��̹Ƿ�
							//�Ʒ��� �ڵ�� Ȯ�� �����ϴ�
							if (x == NODE - 1) cycle = true; //���� ����Ŭ�� ������, loop���� ���� �۾���.
							//��� ���� �۾����� cycle�� ����ٴ� ���� �� �� ����
						}
					}
				}
			}
		}
	}

}
void printBM(){
	int i = 0, j;
		cout << "�ҽ� ��尡 " << i << "�� ��" << endl;
		//cout << "Node \t Length \t Path" << endl;
		for (j = 0; j <= NODE - 1; j++)
			if (i != j){
				if (D[i][j] < 999) {
					cout << " " << D[i][j] << " ";
				}
				else {
					cout << " " << "INF" << " ";
				}
			}
		cout << endl;
	
}


void printMAP(int node_matrix[NODE][NODE]) {
	cout << endl << "Bellman - Ford �� �����ų MAP" << endl;
	for (int i = 0; i <= NODE - 1; i++) {
		for (int j = 0; j <= NODE - 1; j++) {
			if (node_matrix[i][j] < 999) {
				cout << " " << node_matrix[i][j] << " ";
			}
			else {
				cout << " " << "X" << " ";
			}
		}
		cout << endl;
	}
}

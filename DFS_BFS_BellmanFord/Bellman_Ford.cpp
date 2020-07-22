//12163291 강현지 bellman
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
	cout << "12163291 강현지 Bellman-Ford" << endl;
	cout << "현재 노드의 개수:  " << NODE << endl;
	cout << "끊어져 있는 노드간의 간선에는 9999입력." << endl;
	
	for (i = 0; i <= NODE - 1; i++) {
		for (j = 0; j <= NODE - 1; j++) {
			if (i != j) { //대각선 부분이 아니면
				cout << i << "에서 " << j << "의 가중치를 입력하세요.: ";
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
			else { //대각선 부분
				node_matrix[i][j] = 0;
			}
		}
	}

	printMAP(node_matrix); //입력된 node 맵 행렬 보여주기
	
	BellmanFord();
	cout << "\nBellman-Ford:" << endl;
	printBM();
}
void BellmanFord() {
	int i, j, k, x;

	for (i = 0; i <= NODE - 1; i++) {
		for (j = 0; j <= NODE - 1; j++) {
			P[i][j] = 0; //초기화
			D[i][j] = node_matrix[i][j];
		}
	}

	bool cycle = false; //for 음의 cycle 생김 확인용

	for (x = 0; x <= NODE - 1; x++) {// N - 2 = n - 1 번 반복 왜냐하면 전체 노드의 수가 N 개 이니까 
									 // +1번 더 돌려보는 것으로 음의 cycle 확인 
		for (k = 0; k <= NODE - 1; k++) { // 소스 
			for (i = 0; i <= NODE - 1; i++) {// 도착지점
				for (j = 0; j <= NODE - 1; j++) { // 노드.
					if (k != i) {
						if (D[k][j] + node_matrix[j][i] < D[k][i]) { //여태 구한 값보다 더 작은 경로를 찾게됨
							//최단경로 갱신됨
							D[k][i] = D[k][j] + node_matrix[j][i]; //짧은 가중치를 적용한다.
							P[k][i] = j + 1; //짧게 가기 위해 전 노드의 값을 저장한다.
							//n (n-1 (+1) )번쨰 돌렸을 때, 또 값이 갱신되면 
							//음의 cycle이 있는것이므로
							//아래의 코드로 확인 가능하다
							if (x == NODE - 1) cycle = true; //음의 사이클이 있으면, loop값이 점점 작아짐.
							//계속 값이 작아지는 cycle이 생겼다는 것을 알 수 있음
						}
					}
				}
			}
		}
	}

}
void printBM(){
	int i = 0, j;
		cout << "소스 노드가 " << i << "일 때" << endl;
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
	cout << endl << "Bellman - Ford 에 적용시킬 MAP" << endl;
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

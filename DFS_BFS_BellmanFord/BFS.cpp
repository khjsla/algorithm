//12163291 ������ BFS
#include <queue>
#include <iostream>
using namespace std;

#define NODE 20 //��尳��

int node_matrix[NODE][NODE];
bool visited[NODE]; //��� �湮 ���� Ȯ��

int result[NODE];  //����� ����ϱ����� �迭
int path[NODE]; //���� ��¿�

void BFS(int start);

int main(){
	cout << "12163291 ������ �˰��� ���� HW3\n";

	int start;

	for(int i=0; i<NODE; i++)
		for(int j=0; j<NODE; j++)
			cin >> node_matrix[i][j]; //node_matrix�迭 �Է¹���

	cin >> start; //����node
	
	BFS(start); //BFS

	cout << "BFS ���: " ;

	for (int i = 0; i < NODE; i++)
		cout << result[i] << " ";  //��� �� ���
	cout << "\n";

	cout << "BFS ���� ���: ";
		cout << result[0] << " ";  //��� �� ���
	for (int i = 1; i < NODE; i++) //���� ���
		cout << path[i - 1] << "-" << result[i] << " ";  //�� ������� ���!
	cout << "\n";

	return 0;
}

void BFS(int start) { //BFS�Լ�
	int n = 0, j;
	int x = 0;

	queue<int> Q; //�湮�� ������ ����
	Q.push(start);
	visited[start] = true;  //ó�� �湮 ��� üũ

	while (!Q.empty()) {
		result[n] = j = Q.front(); //������ �E ��� ��Ƶα�
		path[x] = result[n];
		n++;
		Q.pop(); //pop //���� �տ� �ִ��� �M - �̴� result�ȿ� �̹� �־����

		for (int k = 0; k < NODE; k++) {
			if (node_matrix[j][k] == 1 && visited[k] == false) { //���� ��尡 �湮 ��������
				Q.push(k); //�ְ�
				visited[k] = true; //�湮�ߴٰ� üũ
				x++; //�̰� ���� �־���� for ����
				path[x] = result[n];
			}

		}
	}
}
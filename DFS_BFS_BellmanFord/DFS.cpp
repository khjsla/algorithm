//12163291 ������ DFS
#include <stack>
#include <iostream>
using namespace std;

#define NODE 20 //��Ʈ ����

int node_matrix[NODE][NODE];
bool visited[NODE]; //��� �湮���� Ȯ��
int result[NODE];  //����� ����ϱ����� �迭

void DFS(int start); //DFS�Լ�

int main(){
	cout << "12163291 ������ �˰��� ���� HW3\n";
	int start; //������

	for(int i=0; i<NODE; i++)
		for(int j=0; j<NODE; j++)
			cin >> node_matrix[i][j]; //node map �迭 �Է¹���

	cin >> start; //����node
	DFS(start); //DFS

	cout << "DFS ���: " ;

	for (int i = 0; i < NODE; i++)
		cout << result[i] << " ";  //��� �� ���
	cout << "\n";

	cout << "BFS ���� ���: ";
	cout << result[0] << " ";  //��� �� ���
	for (int i = 1; i < NODE; i++) //���� ���
		cout << result[i - 1] << "-" << result[i] << " ";  //�� ������� ���!
	cout << "\n";

	return 0;
}

void DFS(int start) { //DFS�Լ�
	int n = 0, j;
	stack<int> S; //�湮�� ������ �����ϴ� ����
	S.push(start); //�������� ���ÿ� �ִ´�.

	while (!S.empty()) { //������ �� �� ����
		result[n] = j = S.top(); //�� ��带 j�� ��Ƶ�, �������� ���� result���� ����
		n++;
		S.pop(); //pop(���� ���� �ִ� ��尡 ���ÿ��� ����)

		if (visited[j] == false) { //pop�� ��尡 �湮���� ���� ����
			visited[j] = true;   //�湮�ߴٰ� üũ
			for (int k = 0; k < NODE; k++) { //������ ������ �湮 �� �� ����
				if (node_matrix[j][k] == 1 && visited[k] == false)
					S.push(k); //���ÿ� �ִ´�.
			}
		}
	}
}

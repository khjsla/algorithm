//12163291 강현지 DFS
#include <stack>
#include <iostream>
using namespace std;

#define NODE 20 //노트 개수

int node_matrix[NODE][NODE];
bool visited[NODE]; //노드 방문여부 확인
int result[NODE];  //결과를 출력하기위한 배열

void DFS(int start); //DFS함수

int main(){
	cout << "12163291 강현지 알고리즘 설계 HW3\n";
	int start; //시작점

	for(int i=0; i<NODE; i++)
		for(int j=0; j<NODE; j++)
			cin >> node_matrix[i][j]; //node map 배열 입력받음

	cin >> start; //시작node
	DFS(start); //DFS

	cout << "DFS 결과: " ;

	for (int i = 0; i < NODE; i++)
		cout << result[i] << " ";  //결과 값 출력
	cout << "\n";

	cout << "BFS 간선 출력: ";
	cout << result[0] << " ";  //결과 값 출력
	for (int i = 1; i < NODE; i++) //간선 출력
		cout << result[i - 1] << "-" << result[i] << " ";  //뺀 순서대로 출력!
	cout << "\n";

	return 0;
}

void DFS(int start) { //DFS함수
	int n = 0, j;
	stack<int> S; //방문할 정점을 저장하는 스택
	S.push(start); //시작점을 스택에 넣는다.

	while (!S.empty()) { //스택이 빌 때 까지
		result[n] = j = S.top(); //뺄 노드를 j에 담아둠, 결과출력을 위해 result에도 저장
		n++;
		S.pop(); //pop(가장 위에 있는 노드가 스택에서 나옴)

		if (visited[j] == false) { //pop된 노드가 방문하지 않은 노드면
			visited[j] = true;   //방문했다고 체크
			for (int k = 0; k < NODE; k++) { //인접한 노드들이 방문 안 한 노드면
				if (node_matrix[j][k] == 1 && visited[k] == false)
					S.push(k); //스택에 넣는다.
			}
		}
	}
}

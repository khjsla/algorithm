//12163291 강현지 BFS
#include <queue>
#include <iostream>
using namespace std;

#define NODE 20 //노드개수

int node_matrix[NODE][NODE];
bool visited[NODE]; //노드 방문 여부 확인

int result[NODE];  //결과를 출력하기위한 배열
int path[NODE]; //간선 출력용

void BFS(int start);

int main(){
	cout << "12163291 강현지 알고리즘 설계 HW3\n";

	int start;

	for(int i=0; i<NODE; i++)
		for(int j=0; j<NODE; j++)
			cin >> node_matrix[i][j]; //node_matrix배열 입력받음

	cin >> start; //시작node
	
	BFS(start); //BFS

	cout << "BFS 결과: " ;

	for (int i = 0; i < NODE; i++)
		cout << result[i] << " ";  //결과 값 출력
	cout << "\n";

	cout << "BFS 간선 출력: ";
		cout << result[0] << " ";  //결과 값 출력
	for (int i = 1; i < NODE; i++) //간선 출력
		cout << path[i - 1] << "-" << result[i] << " ";  //뺀 순서대로 출력!
	cout << "\n";

	return 0;
}

void BFS(int start) { //BFS함수
	int n = 0, j;
	int x = 0;

	queue<int> Q; //방문할 정점을 저장
	Q.push(start);
	visited[start] = true;  //처음 방문 노드 체크

	while (!Q.empty()) {
		result[n] = j = Q.front(); //밖으로 뺼 노드 담아두기
		path[x] = result[n];
		n++;
		Q.pop(); //pop //지금 앞에 있던거 뻄 - 이는 result안에 이미 넣어뒀음

		for (int k = 0; k < NODE; k++) {
			if (node_matrix[j][k] == 1 && visited[k] == false) { //인접 노드가 방문 안했으면
				Q.push(k); //넣고
				visited[k] = true; //방문했다고 체크
				x++; //이건 여기 있어야함 for 간선
				path[x] = result[n];
			}

		}
	}
}
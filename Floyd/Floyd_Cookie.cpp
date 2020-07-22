#pragma warning(disable:4996)
#include <stdio.h>

#define MAX_NODE 1001 // 노드의 갯수
#define INIT_VALUE 7777777 // 무한대

//adjacency matrix 생성
int graph[MAX_NODE][MAX_NODE];
// 경로 추적을 위한 matrix 생성
int path[MAX_NODE][MAX_NODE];

int V, E;//for n,m 입력

/* function prototype*/
void AppendNode(int(*graph)[MAX_NODE], int start, int end, int cost);
void floyd(int(*graph)[MAX_NODE], int(*path)[MAX_NODE]);
void PrintPath(int(*path)[MAX_NODE], int start, int end);
void init();

void AppendNode(int(*graph)[MAX_NODE], int start, int end, int cost)
{
	graph[start - 1][end - 1] = cost;
}

void floyd(int(*graph)[MAX_NODE], int(*path)[MAX_NODE])
{
	int i, j, k;

	for (k = 0; k < V; k++)
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
			{    // 기존의 값보다 k를 경유한 값이 더 작다면 if문 실행
				if (graph[i][j] > graph[i][k] + graph[k][j])
				{
					// i에서 j로 갈 때, k를 거쳐서 갔다는 것을 기록
					path[i][j] = k + 1;
					// cost 업데이트
					graph[i][j] = graph[i][k] + graph[k][j];
				}//end if
			}//end for
}//end function

void PrintPath(int(*path)[MAX_NODE], int start, int end)
{
	// 다른 노드를 경유 한다면 if문 실행
	if (path[start - 1][end - 1] != -1)
	{
		// start 노드에서 경유하는 노드까지의 경로 검사
		PrintPath(path, start, path[start - 1][end - 1]);
		printf("%2d ", path[start - 1][end - 1]);
		// 경유하는 노드에서 end 노드까지 경로 검사
		PrintPath(path, path[start - 1][end - 1], end);
	}
}

void init() {
	int i, j;
	/* initialize */
	/* graph = INIT_VALUE로, path = -1로 배열을 초기화 한다 */
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
		{
			if (i == j)
			{
				graph[i][j] = 0;
			}
			else
			{
				graph[i][j] = INIT_VALUE;
			}
			path[i][j] = -1;
		}
}

int main(){
	int start, end;
	
	scanf("%d %d", &V, &E);
	if (E > 1000000) {
		return 0;
	}

	init();

	//printf("정점 연결( 정점1 정점2 비용) \n");
	for (int i = 0; i < E; i++) { //18 번 반복
		int v1, v2, cost;
		scanf("%d %d %d", &v1, &v2, &cost);
		AppendNode(graph, v1, v2, cost);
	}

	/* 그래프 연결 확인 */
	//DisplayGraph(graph);

	/* floyd 알고리즘 */
	floyd(graph, path);

	// floyd 알고리즘 수행 후 변화
	//DisplayGraph(graph);


	/* 경로 추적 */
	
	while (true){
		scanf("%d", &start);		
		if (start == 0)break;
		scanf("%d", &end);
		if (graph[start - 1][end - 1] > 77777) {
			printf("0\n");
		}
		else {
			printf("%d ", graph[start - 1][end - 1]);
			printf("%2d ", start);
			PrintPath(path, start, end);
			printf("%2d\n", end);
		}
	}
	
	return(0);
}
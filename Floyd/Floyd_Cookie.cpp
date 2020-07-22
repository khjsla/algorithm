#pragma warning(disable:4996)
#include <stdio.h>

#define MAX_NODE 1001 // ����� ����
#define INIT_VALUE 7777777 // ���Ѵ�

//adjacency matrix ����
int graph[MAX_NODE][MAX_NODE];
// ��� ������ ���� matrix ����
int path[MAX_NODE][MAX_NODE];

int V, E;//for n,m �Է�

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
			{    // ������ ������ k�� ������ ���� �� �۴ٸ� if�� ����
				if (graph[i][j] > graph[i][k] + graph[k][j])
				{
					// i���� j�� �� ��, k�� ���ļ� ���ٴ� ���� ���
					path[i][j] = k + 1;
					// cost ������Ʈ
					graph[i][j] = graph[i][k] + graph[k][j];
				}//end if
			}//end for
}//end function

void PrintPath(int(*path)[MAX_NODE], int start, int end)
{
	// �ٸ� ��带 ���� �Ѵٸ� if�� ����
	if (path[start - 1][end - 1] != -1)
	{
		// start ��忡�� �����ϴ� �������� ��� �˻�
		PrintPath(path, start, path[start - 1][end - 1]);
		printf("%2d ", path[start - 1][end - 1]);
		// �����ϴ� ��忡�� end ������ ��� �˻�
		PrintPath(path, path[start - 1][end - 1], end);
	}
}

void init() {
	int i, j;
	/* initialize */
	/* graph = INIT_VALUE��, path = -1�� �迭�� �ʱ�ȭ �Ѵ� */
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

	//printf("���� ����( ����1 ����2 ���) \n");
	for (int i = 0; i < E; i++) { //18 �� �ݺ�
		int v1, v2, cost;
		scanf("%d %d %d", &v1, &v2, &cost);
		AppendNode(graph, v1, v2, cost);
	}

	/* �׷��� ���� Ȯ�� */
	//DisplayGraph(graph);

	/* floyd �˰��� */
	floyd(graph, path);

	// floyd �˰��� ���� �� ��ȭ
	//DisplayGraph(graph);


	/* ��� ���� */
	
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
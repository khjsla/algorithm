#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue>
using namespace std;

int N, R, cnt = 0;

int stellar[101][101][101] = { 0, };
bool group[101][101][101] = { false, };

void BFS(int y, int x, int z) {
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(z, make_pair(y, x)));
	group[y][x][z] = true;
	cnt++;

	while (!q.empty()) {
		int dx = q.front().second.second; //c
		int dy = q.front().second.first; //r
		int dz = q.front().first; //h
		q.pop();

		for (int z = -R; z <= R; z++) {
			for (int y = -R; y <= R; y++) {
				for (int x = -R; x <= R; x++) {
					int next_x = x + dx;
					int next_y = y + dy;
					int next_z = z + dz;

					if ((next_x >= 0 && next_x < N) && (next_y >= 0 && next_y < N) && (next_z >= 0 && next_z < N)) {
						if (group[next_y][next_x][next_z] == false && stellar[next_y][next_x][next_z] == 1) {
							q.push(make_pair(next_z, make_pair(next_y, next_x)));
							group[next_y][next_x][next_z] = true;
						}
					}
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &R, &N);

	for (int z = 0; z < N; z++) {
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++) {
				scanf("%d", &stellar[x][y][z]);
			}
	}

	for (int z = 0; z < N; z++) {
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++) {
				if (stellar[y][x][z] == 1 && group[y][x][z] == false) {
					BFS(y, x, z);
				}
			}
	}

	printf("%d\n", cnt);

	return 0;
}
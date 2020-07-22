//#include <iostream>
//#include <queue>
//using namespace std;
//
//int n; //배열크기
//int cnt;
//int dx[24] = {-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1,0,0,0,0}; //x이동 //1,3,4,여야하나?
//int dy[24] = {0,0,-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1,0,0}; //y이동
//int dz[24] = {0,0,0,0,-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1}; //z이동
//
//int map[101][101][101];      //지도 3차원 
//int group[101][101][101] = { 0, };     //그룹묶기 3차원
//
//void bfs(int x, int y, int z, int r) {
//	queue< pair< pair<int, int>, int> > q;
//	cnt++;
//	q.push(make_pair(make_pair(x, y), z));
//	group[x][y][z] = 1;
//
//	while (!q.empty()) {
//		int x = q.front().first.first;
//		int y = q.front().first.second;
//		int z = q.front().second;
//		
//		q.pop();
//
//		for (int i = 0; i < 6 * r ; i++) {
//			int nx = x + dx[i]; //각 배열값 더해짐
//			int ny = y + dy[i];
//			int nz = z + dz[i];
//
//			if (nx >= 0 && nx < n && ny >= 0 && ny < n && nz >= 0 && nz < n) {
//				if (map[nx][ny][nz] == 1 && group[nx][ny][nz] == 0) {
//					q.push(make_pair(make_pair(nx, ny), nz));
//					group[nx][ny][nz] = 1;
//				}
//			}
//		}
//	}
//}
//
//
//int main() {
//	int r;
//	cin >> r; //그룹 범위
//	if (r > 4) {
//		return 0;
//	}
//	cin >> n; //3차원 배열크기
//
//	for (int z = 0; z < n; z++) {
//		for (int y = 0; y < n; y++) {
//			for (int x = 0; x < n; x++) {
//				cin >> map[x][y][z]; //지도 입력
//			}
//		}
//	}
//
//	int cnt = 0;
//	for (int z = 0; z < n; z++) {
//		for (int y = 0; y < n; y++) {
//			for (int x = 0; x < n; x++) {
//				if(map[x][y][z] == 1 && group[x][y][z] == 0)
//				bfs(x, y, z, r);
//			}
//		}
//	}
//	cout << cnt << '\n';
//
//	return 0;
//}

//#include <iostream>
//#include <queue>
//using namespace std;
//
//int n; //�迭ũ��
//int cnt;
//int dx[24] = {-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1,0,0,0,0}; //x�̵� //1,3,4,�����ϳ�?
//int dy[24] = {0,0,-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1,0,0}; //y�̵�
//int dz[24] = {0,0,0,0,-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1,0,0,0,0,-1,1}; //z�̵�
//
//int map[101][101][101];      //���� 3���� 
//int group[101][101][101] = { 0, };     //�׷칭�� 3����
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
//			int nx = x + dx[i]; //�� �迭�� ������
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
//	cin >> r; //�׷� ����
//	if (r > 4) {
//		return 0;
//	}
//	cin >> n; //3���� �迭ũ��
//
//	for (int z = 0; z < n; z++) {
//		for (int y = 0; y < n; y++) {
//			for (int x = 0; x < n; x++) {
//				cin >> map[x][y][z]; //���� �Է�
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

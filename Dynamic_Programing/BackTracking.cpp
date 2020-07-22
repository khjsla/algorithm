//#include <iostream>
//#include <time.h> //for �ð�üũ
//using namespace std;
//
//clock_t start, finish, used_time = 0;    //���� �ð� ������ ���� ����
//
//int N; //ü���� ũ��
//int cnt; //��� ����� ���� �ִ��� Ȯ��
//int board[15] = { 0, };
////�� ���� �ٲ� �� �ִ�
//
////���� �ð��� ���� �� ����ϴ� �Լ�
//void calculate_time(void)
//{
//	used_time = finish - start;
//	cout << ".... �Ϸ�!" << endl << "�ҿ�ð� : " << (float)used_time / CLOCKS_PER_SEC << " ��" << endl;
//}
//
//bool possible(int row); //�� ���� �� �ִ��� ������Ȯ��
//void backtracking_NQ(int row); //��Ʈ��ŷ���� �䱸�ϱ�
//
///* N queens ���� �� ��,
//   1. �� ó�� ������ ��ġ�� 1,1 �� ���� ���¿��� ������ �� ������ 
//   2. 1������ �����ϴ� ������ ������ �� �������� 1�� 2���� ������ ������ġ�� ���Ͽ� ������ �� ������
//   3. ���� ������ N�� ���� ��� �ݺ��մϴ�.
//*/
//
//int main() {
//	cout << "12163291 ������ �˰��򼳰� N-Q\nü���� ũ�� �Է�\n";
//	cin >> N;
//	//ü���� ũ�� �Է�
//
//	start = clock(); //���۽ð� ���
//
//	//ù° �ٿ� �� N���� ���� ������ �� ���� ���� ����� ���� ����մϴ�.
//	backtracking_NQ(0);
//
//	finish = clock(); //�����ð� ���
//
//	cout << cnt << endl;
//	calculate_time(); //sorting �ϴµ� �ɸ��ð�
//}
//
//bool possible(int row) { //ü���ǿ� ���� ���� �� �ִ��� ������ �Ǵ����ִ� �Լ� �Դϴ�.
//	for (int i = 0; i < row; i++) { //i�� 0����� ������ ���� ��ġ�� �� �ٷ� �� ������� �ǹ��մϴ�.
//		if (board[row] == board[i] || abs(row - i) == abs(board[row] - board[i])) { //���� ���� �ְų�, �밢���� �ִٸ�.
//			return false; //���� �� �����ϴ�.
//		}
//		//�װ��� �ƴ϶�� ���� ���� �� �ִ� �ڸ� �� ���Դϴ�.
//	}
//	return true;
//}
//
//void backtracking_NQ(int row) {
//	if (row == N) {
//		cnt++; //������ ���� cnt �ϴ� ����
//		return;
//	}
//	//ù �࿡ ���̴� ���� ��ġ�� i �� ���մϴ�.
//	for (int i = 0; i < N; i++) { // i = ���� ��ġ 
//		board[row] = i;
//		if (possible(row)) { //���� ���� �� �ִ� �ڸ��̸�
//			backtracking_NQ(row + 1);
//		}
//		//��� �� ������
//		board[row] = 0;
//	}
//}
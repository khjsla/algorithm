//#include <iostream>
//#include <time.h> //for 시간체크
//using namespace std;
//
//clock_t start, finish, used_time = 0;    //실행 시간 측정을 위한 변수
//
//int N; //체스판 크기
//int cnt; //몇개의 경우의 수가 있는지 확인
//int board[15] = { 0, };
////이 수는 바뀔 수 있다
//
////실행 시간을 측정 및 출력하는 함수
//void calculate_time(void)
//{
//	used_time = finish - start;
//	cout << ".... 완료!" << endl << "소요시간 : " << (float)used_time / CLOCKS_PER_SEC << " 초" << endl;
//}
//
//bool possible(int row); //퀸 놓을 수 있는지 없는지확인
//void backtracking_NQ(int row); //백트래킹으로 답구하기
//
///* N queens 문제 일 때,
//   1. 맨 처음 여왕의 위치를 1,1 에 놓은 상태에서 정답을 다 구한후 
//   2. 1열에서 시작하는 여왕은 정답을 다 구했으니 1행 2열에 여왕의 시작위치를 구하여 정답을 다 구한후
//   3. 위의 과정을 N열 까지 계속 반복합니다.
//*/
//
//int main() {
//	cout << "12163291 강현지 알고리즘설계 N-Q\n체스판 크기 입력\n";
//	cin >> N;
//	//체스판 크기 입력
//
//	start = clock(); //시작시간 재기
//
//	//첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력합니다.
//	backtracking_NQ(0);
//
//	finish = clock(); //끝난시간 재기
//
//	cout << cnt << endl;
//	calculate_time(); //sorting 하는데 걸린시간
//}
//
//bool possible(int row) { //체스판에 퀸을 놓을 수 있는지 없는지 판단해주는 함수 입니다.
//	for (int i = 0; i < row; i++) { //i는 0행부터 마지막 퀸이 위치한 곳 바로 윗 행까지를 의미합니다.
//		if (board[row] == board[i] || abs(row - i) == abs(board[row] - board[i])) { //같은 열에 있거나, 대각선에 있다면.
//			return false; //놓을 수 없습니다.
//		}
//		//그것이 아니라면 퀸을 놓을 수 있는 자리 인 것입니다.
//	}
//	return true;
//}
//
//void backtracking_NQ(int row) {
//	if (row == N) {
//		cnt++; //가능한 개수 cnt 하는 변수
//		return;
//	}
//	//첫 행에 놓이는 돌의 위치는 i 가 정합니다.
//	for (int i = 0; i < N; i++) { // i = 열의 위치 
//		board[row] = i;
//		if (possible(row)) { //퀸을 놓을 수 있는 자리이면
//			backtracking_NQ(row + 1);
//		}
//		//통과 다 끝나면
//		board[row] = 0;
//	}
//}
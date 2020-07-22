#include <iostream> //절댓값 함수인 abs사용
#include <time.h> //for 시간체크
#include <cstdlib>  
#include<iomanip>
using namespace std;

#define p_size 80 //population size 80

clock_t start, finish, used_time = 0;    //실행 시간 측정을 위한 변수

//실행 시간을 측정 및 출력하는 함수
void calculate_time(void)
{
	used_time = finish - start;
	cout << ".... 완료!" << endl << "소요시간 : " << (float)used_time / CLOCKS_PER_SEC << " 초" << endl;
}

struct gene { //하나의 유전자 struct
	int chro[255]; //유전자
	int fit;    //적응도
};

struct gene ge[p_size + 1];

void swap(int* s, int a, int b);
void swap(int a, int b);
bool test(int j, int** vec, const int& number);
void downsort(int N);
void fitness(int N);
int roulletWheelSelection();
void cross(int a, int b, int** c_after);
void mutation(int N, int** m_after);

int N;  //체스판 크기
int p_num = 0;

int main() {
	cout << "12163291 강현지 알고리즘설계 N-Q\n";

	srand((unsigned)time(NULL));

	//필요한 변수들 선언
	int generation = 1;
	int loop = 0;
	double elit = 0.05;

	cout << "체스판 크기입력\n";
	cin >> N;  //크기 입력

	int p_num = 0;

	int** genetic = new int*[p_size]; //유전자
	int** after = new int*[p_size]; //자식

	for (int i = 0; i < p_size; i++) {
		genetic[i] = new int[N + 1];
		after[i] = new int[N + 1];
	}

	for (int i = 0; i < p_size; i++) {
		for (int j = 0; j < N; j++) {
			genetic[i][j] = 0; //유전자는 0
			after[i][j] = 1; //자식은 1
		}
	}

	start = clock();

	for (int i = 0; i < p_size; i++) {
		for (int j = 0; j < N; j++) {
			p_num = rand() % N + 1;  //한 세대를 랜덤 생성
			while (test(i, genetic, p_num)) { //test값이 false가 될때까지
				p_num = rand() % N + 1; //랜덤생성
			}
			genetic[i][j] = p_num;
		}
	}
	for (int i = 0; i < p_size; i++) {
		for (int j = 0; j < N; j++) {
			ge[i].chro[j] = genetic[i][j];  //유전자 정보 저장
		}
	}
	while (generation != 1000000) {
		fitness(N);  //적응도 체크
		for (int row = 0; row < p_size; row++) {
			if (ge[row].fit == N * (N - 1)) { //한 세트 찾으면 
				finish = clock();
				calculate_time();
				exit(0);
			}
		}
		while (loop != p_size / 2) {
			int a = roulletWheelSelection();  //roullete을 통해 랜덤하게 값 선택
			int b = roulletWheelSelection();
			loop++;
			cross(a, b, after); 
		}
		mutation(N, after); //변이

		int elite = p_size * elit;
		for (int i = 0; i < elite; i++) {
			for (int j = 0; j < N; j++) {
				after[i][j] = ge[i].chro[j];
			}
		}
		for (int i = 0; i < p_size; i++) {
			for (int j = 0; j < N; j++) {
				ge[i].chro[j] = after[i][j];
			}
		}
		generation++;
	}
	if (generation == 1000000) {
		cout << "실 패" << endl;
	}
	return 0;
}

void swap(int* s, int a, int b) {
	int temp = s[a];
	s[a] = s[b];
	s[b] = temp;
}

void swap(int a, int b) {
	gene temp = ge[a];
	ge[a] = ge[b];
	ge[b] = temp;
}

bool test(int j, int** vec, const int& number) {
	for (int i = 0; i < N; i++) {
		if (vec[j][i] == number) {
			return true;
		}
	}
	return false;
}

void downsort(int N) { //내림차순으로 정렬
	int max;
	for (int i = 0; i < N - 1; i++) {
		max = i;
		for (int j = i + 1; j < N; j++) {
			if (ge[j].fit > ge[max].fit) {
				max = j;
			}
		}
		swap(i, max);
	}
}

void fitness(int N) { //적응도를 부여하는 함수
	for (int i = 0; i < p_size; i++) { //먼저, population size만큼 돌면서 
		ge[i].fit = 0;  //적응도를 0으로 초기화한다.
	}

	for (int row = 0; row < p_size; row++) { //populatinsize만큼 반복
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (ge[row].chro[i] != ge[row].chro[j] //같은 열에 있지 않고
					&& abs(ge[row].chro[i] - ge[row].chro[j]) != abs(i - j)) { //대각선 상에 있지 않으면
					ge[row].fit++; //적응도 증가
				}
			}
		}
	}
	downsort(p_size); //적응도를 내림차순으로 정렬(적응도 높은 것이 앞에 오도록)
}

int roulletWheelSelection() { 
	int total_fit = 1;
	int* roullet = new int[p_size + 1]; 
	for (int i = 0; i < p_size; i++) {
		roullet[i] = ge[i].fit;
		if (i > 0) {
			roullet[i] = roullet[i] + roullet[i - 1];
		}
	}
	total_fit = roullet[p_size - 1];
	int r = rand() % total_fit + 1;
	int num = 0;
	for (int i = 0; i < p_size; i++) {
		if (r < roullet[i]) {
			num = i;
			break;
		}
	}
	return num;
}

void cross(int a, int b, int** c_after) { 
	for (int i = 0; i < N*(9 / 10); i++) {  // 90퍼의 확률
		c_after[a][i] = ge[a].chro[i];
		c_after[b][i] = ge[b].chro[i];
	}

	for (int j = N * (7 / 10); j < N; j++) {
		c_after[(p_size - 1) - b][j] = ge[a].chro[j];
		c_after[(p_size - 1) - a][j] = ge[b].chro[j];
	}

	for (int k = 0; k < p_size; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (c_after[k][i] == c_after[k][j]) {
					p_num = rand() % N + 1; //0에서 N까지 랜덤하게 저장
					while (test(k, c_after, p_num)) {
						p_num = rand() % N + 1; //0에서 N까지 랜덤하게 저장 
					}
					c_after[k][j] = p_num;
				}
			}
		}
	}
}

void mutation(int N, int** m_after) {  //돌연변이 생성, 1%의 확률
	int random_number;
	int a = rand() % N; //0에서 N-1까지 랜덤하게 입력
	int b = rand() % N; //0에서 N-1까지 랜덤하게 입력
	for (int i = 0; i < p_size; i++) {
		random_number = rand() % 100; //0에서 99까지 랜덤하게 random_number에 입력
		if (random_number < 1) {  //1%의 확률로 변이가 일어난다.
			swap(m_after[i], a, b);
		}
	}
}
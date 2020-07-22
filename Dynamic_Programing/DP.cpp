#include <iostream> //���� �Լ��� abs���
#include <time.h> //for �ð�üũ
#include <cstdlib>  
#include<iomanip>
using namespace std;

#define p_size 80 //population size 80

clock_t start, finish, used_time = 0;    //���� �ð� ������ ���� ����

//���� �ð��� ���� �� ����ϴ� �Լ�
void calculate_time(void)
{
	used_time = finish - start;
	cout << ".... �Ϸ�!" << endl << "�ҿ�ð� : " << (float)used_time / CLOCKS_PER_SEC << " ��" << endl;
}

struct gene { //�ϳ��� ������ struct
	int chro[255]; //������
	int fit;    //������
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

int N;  //ü���� ũ��
int p_num = 0;

int main() {
	cout << "12163291 ������ �˰��򼳰� N-Q\n";

	srand((unsigned)time(NULL));

	//�ʿ��� ������ ����
	int generation = 1;
	int loop = 0;
	double elit = 0.05;

	cout << "ü���� ũ���Է�\n";
	cin >> N;  //ũ�� �Է�

	int p_num = 0;

	int** genetic = new int*[p_size]; //������
	int** after = new int*[p_size]; //�ڽ�

	for (int i = 0; i < p_size; i++) {
		genetic[i] = new int[N + 1];
		after[i] = new int[N + 1];
	}

	for (int i = 0; i < p_size; i++) {
		for (int j = 0; j < N; j++) {
			genetic[i][j] = 0; //�����ڴ� 0
			after[i][j] = 1; //�ڽ��� 1
		}
	}

	start = clock();

	for (int i = 0; i < p_size; i++) {
		for (int j = 0; j < N; j++) {
			p_num = rand() % N + 1;  //�� ���븦 ���� ����
			while (test(i, genetic, p_num)) { //test���� false�� �ɶ�����
				p_num = rand() % N + 1; //��������
			}
			genetic[i][j] = p_num;
		}
	}
	for (int i = 0; i < p_size; i++) {
		for (int j = 0; j < N; j++) {
			ge[i].chro[j] = genetic[i][j];  //������ ���� ����
		}
	}
	while (generation != 1000000) {
		fitness(N);  //������ üũ
		for (int row = 0; row < p_size; row++) {
			if (ge[row].fit == N * (N - 1)) { //�� ��Ʈ ã���� 
				finish = clock();
				calculate_time();
				exit(0);
			}
		}
		while (loop != p_size / 2) {
			int a = roulletWheelSelection();  //roullete�� ���� �����ϰ� �� ����
			int b = roulletWheelSelection();
			loop++;
			cross(a, b, after); 
		}
		mutation(N, after); //����

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
		cout << "�� ��" << endl;
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

void downsort(int N) { //������������ ����
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

void fitness(int N) { //�������� �ο��ϴ� �Լ�
	for (int i = 0; i < p_size; i++) { //����, population size��ŭ ���鼭 
		ge[i].fit = 0;  //�������� 0���� �ʱ�ȭ�Ѵ�.
	}

	for (int row = 0; row < p_size; row++) { //populatinsize��ŭ �ݺ�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (ge[row].chro[i] != ge[row].chro[j] //���� ���� ���� �ʰ�
					&& abs(ge[row].chro[i] - ge[row].chro[j]) != abs(i - j)) { //�밢�� �� ���� ������
					ge[row].fit++; //������ ����
				}
			}
		}
	}
	downsort(p_size); //�������� ������������ ����(������ ���� ���� �տ� ������)
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
	for (int i = 0; i < N*(9 / 10); i++) {  // 90���� Ȯ��
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
					p_num = rand() % N + 1; //0���� N���� �����ϰ� ����
					while (test(k, c_after, p_num)) {
						p_num = rand() % N + 1; //0���� N���� �����ϰ� ���� 
					}
					c_after[k][j] = p_num;
				}
			}
		}
	}
}

void mutation(int N, int** m_after) {  //�������� ����, 1%�� Ȯ��
	int random_number;
	int a = rand() % N; //0���� N-1���� �����ϰ� �Է�
	int b = rand() % N; //0���� N-1���� �����ϰ� �Է�
	for (int i = 0; i < p_size; i++) {
		random_number = rand() % 100; //0���� 99���� �����ϰ� random_number�� �Է�
		if (random_number < 1) {  //1%�� Ȯ���� ���̰� �Ͼ��.
			swap(m_after[i], a, b);
		}
	}
}
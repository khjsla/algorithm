//#include <iostream>
//#include <time.h> //for ��������
//using namespace std;
//
//#define ASIZE 512
//
//clock_t start, finish, used_time = 0;    //���� �ð� ������ ���� ����
//
////���� �ð��� ���� �� ����ϴ� �Լ�
//void calculate_time(void)
//{
//	used_time = finish - start;
//	cout << ".... �Ϸ�!" << endl << "�ҿ�ð� : " << (float)used_time / CLOCKS_PER_SEC << " ��" << endl;
//}
//
////shell sort = insertion �� ������ �˰���
//void shell_sort(int random_data[], int size) { //n= ������ ����, []=������ �� ����ִ� �迭 //gap�� size/2
//	for (int gap = size / 2; gap > 0; gap /= 2) {
//		if (gap % 2 == 0) {
//			gap++;
//		}
//		for (int i = gap; i < size; i++) {
//			int temp = random_data[i];
//			int j = 0;
//			for (j = i; (j > gap&&random_data[j - gap] > temp); j = j - gap) {
//				random_data[j] = random_data[j - gap];
//			}
//			random_data[j] = temp;
//		}
//	}
//}
//
//int random_data[ASIZE]; // �迭�� ũ�� = ������ �������� ����
//
//int main() {
//	srand((int)time(NULL));
//
//	for (int i = 0; i < ASIZE; i++) { // for�� �ݺ�Ƚ�� = ������ �������� ����
//		random_data[i] = rand() % 1000; // %1000�̹Ƿ�, ���� �ڸ����� �������� 
//	}
//
//	start = clock(); //���۽ð� ���
//
//	shell_sort(random_data, ASIZE);
//
//	finish = clock(); //�����ð� ���
//
//	for (int i = 0; i < ASIZE; i++) {
//		cout << random_data[i] << (i % 10 == 9 ? "\n\n" : ","); //10�� ��¸��� endl
//	}
//
//	calculate_time(); //sorting �ϴµ� �ɸ��ð�
//
//}
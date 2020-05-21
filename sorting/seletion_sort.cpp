#include <iostream>
#include <time.h> //for ��������
using namespace std;

#define swap(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
#define ASIZE 100000 //�̰� �ܿ��� //10��

clock_t start, finish, used_time = 0;    //���� �ð� ������ ���� ����

//���� �ð��� ���� �� ����ϴ� �Լ�
void calculate_time(void)
{
	used_time = finish - start;
	cout << ".... �Ϸ�!" << endl << "�ҿ�ð� : " << (float)used_time / CLOCKS_PER_SEC << " ��" << endl;
}


void selection_sort(int random_data[], int n) { //n= ������ ����, []=������ �� ����ִ� �迭
	int min,temp;

	//������ ���ڴ� �ڵ������� ���ĵǹǷ� sort�� �����൵ �ȴ�. ���� n-1��ŭ �ݺ��Ѵ�.
	for (int i = 0; i < n - 1; i++) { 
		min = i; //�켱 ó������ �ּڰ��� ó���ڸ� [0]��. 
		//i ���� �ڸ��� �´� ���� ã���ְ� �Ǵ°���
		//���Ŀ� �ּڰ��� Ž���ؼ� �̿� ������,

		//�ּڰ��� Ž���Ѵ�
		for (int j = i + 1; j < n; j++) { //i���� �ڸ��� ã����� �ϹǷ�, i+1���� ������
			if (random_data[j] > random_data[min]) { //���� ���� ���� ���ö����� �ݺ� ���ؼ� 
				min = j; //min�� �������� ���� ����ִ� index���� �־���.
			}
		}

		//�ڱ��ڽ��� �ּڰ��̸� �̵��� �����ʰ�,
		//�ڱ��ڽ��� �ּڰ��� �ƴϸ� swap���� �ڱ��ڽ��� �ڸ��� �ּڰ��� �ڸ��� �ٲ��ݴϴ�.
		if (i != min) {
			swap(random_data[i], random_data[min], temp);
		}
	}
}
int random_data[ASIZE]; // �迭�� ũ�� = ������ �������� ����

int main() {

	//main������ �迭ũ�Ⱑ 500000�� �Ǵ� stack overflow�߻�
	//���������� �������ִ� stack overflow������ �߻����� �ʾ����� 
	//��ǻ�Ϳ� ������ ���µ��� ������ �� 100000������ �켱����
	//�̰� 10�������� ���������Ǵ���

	srand((int)time(NULL)); 
	
	for (int i = 0; i < ASIZE; i++) { // for�� �ݺ�Ƚ�� = ������ �������� ����
		random_data[i] = rand() % 1000; // %1000�̹Ƿ�, ���� �ڸ����� �������� 
	} 

	start = clock(); //���۽ð� ���

	selection_sort(random_data, ASIZE); //������ �������� ����
	
	finish = clock(); //�����ð� ���

	/*for (int i = 0; i < ASIZE; i++) {
		cout << random_data[i] << (i % 10 == 9 ? "\n\n" : ","); //10�� ��¸��� endl
	}*/

	calculate_time(); //sorting �ϴµ� �ɸ��ð�

}
#include <iostream>
#include <time.h> //for ��������
using namespace std;

#define SWAP(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
#define ASIZE 16

clock_t start, finish, used_time = 0;    //���� �ð� ������ ���� ����

//���� �ð��� ���� �� ����ϴ� �Լ�
void calculate_time(void){
	used_time = finish - start;
	cout << ".... �Ϸ�!" << endl << "�ҿ�ð� : " << (float)used_time / CLOCKS_PER_SEC << " ��" << endl;
}

//�������� �ӵ���� ��� -3 ; �߰��� ����
void three_sort(int random_data[], int left, int mid, int right) { //3���� �ĺ� pivot�� ������� �����ϴ� �Լ�
	int temp;
	 
	if (random_data[left] > random_data[mid]) SWAP(random_data[left], random_data[mid], temp);
	if (random_data[mid] > random_data[right]) SWAP(random_data[mid], random_data[right], temp);
	if (random_data[left] > random_data[mid]) SWAP(random_data[left], random_data[mid], temp);

	//�̰ɷ� �ǿ����� ����ū ������� 3�� pivot�ĺ��� ���ĵ�
}

//quicksort�� inplace (������ ������� �ʿ���������)
void quick_sort(int random_data[], int left, int right) { //n= ������ ����, []=������ �� ����ִ� �迭
	int pivot, temp;
	int mid = left + (right - left) / 2; //�߰� ����(mid) �� �ε��� ã��

	three_sort(random_data, left, mid, right); //������ ����pivot ���������� ����

	if (right - left + 1 > 3) { //������ ����� 3�� �̻��� ��쿡�� quick_sort ����.
		
		pivot = random_data[mid]; //pivot�������� (������ ���� mid �ε��� �ڸ��� �ִ� ���� �����̵�)

		SWAP(random_data[mid], random_data[right - 1], temp); //����ִ� pivot ���ذ��� �ǿ����ʿ��� 1�� ���ʿ� �ִ� �Ŷ� �ڸ� �ٲ���
		
		int i = left; //�Ǿ��� �׳� �Ǿ�
		int j = right - 1; //�ǵڴ� �̹����ĵǾ������Ƿ�, right�� �ƴ� right-1���� ���� //�ǿ��ʿ��� �ϳ� ���ʺ���

		while(true) { //break �϶����� while�� �ݺ�
			
			while (random_data[++i] > pivot && i < right);
			while (random_data[--j] < pivot && left < j);
			
			if (i >= j) break; 

			SWAP(random_data[i], random_data[j], temp);
		}
		
		SWAP(random_data[i], random_data[right - 1], temp);
		quick_sort(random_data, left, i - 1);
		quick_sort(random_data, i + 1, right);
	}
}

// i++�� i�� 1�� ������Ų ��, ������Ű�� �� ���� return�մϴ�.
// ++i�� i�� 1�� ������Ų ��, �� ������ ���� return�մϴ�.

int random_data[ASIZE]; // �迭�� ũ�� = ������ �������� ����
//stack overflow ���� ���� �������� �켱 ����

int main() {

	srand((int)time(NULL));

	for (int i = 0; i < ASIZE; i++) { // for�� �ݺ�Ƚ�� = ������ �������� ����
		random_data[i] = rand() % 100; // %1000�̹Ƿ�, ���� �ڸ����� �������� 
	}

	start = clock(); //���۽ð� ���

	quick_sort(random_data,0,ASIZE-1); //�迭�� 0���� �����̹Ƿ� SIZE-1 �� left��

	finish = clock(); //�����ð� ���

	//Ȯ�ο�
	for (int i = 0; i < ASIZE; i++) {
		cout << random_data[i] << (i % 16 == 15 ? "\n\n" : ","); //10�� ��¸��� endl
	}

	calculate_time(); //sorting �ϴµ� �ɸ��ð�

}
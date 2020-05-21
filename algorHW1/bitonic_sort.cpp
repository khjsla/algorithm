
#include <iostream>
#include <time.h> //for ��������
using namespace std;

#define SWAP(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
#define ASIZE 16 //100�̸�0�ʰɸ� 10000�̸� 0.04 �ΰ� ���� �ɸ� 
//2��n������ ���� �Է����� �־�� ����� ��µ�, �ֳ��ϸ� ���� �����̱� ������ .

#define UP true //true
#define DOWN false //false

clock_t start, finish, used_time = 0;//���� �ð� ������ ���� ����

//���� �ð��� ���� �� ����ϴ� �Լ�
void calculate_time(void)
{
	used_time = finish - start;
	cout << ".... �Ϸ�!" << endl << "�ҿ�ð� : " << (float)used_time / CLOCKS_PER_SEC << " ��" << endl;
}

//direcion�� sorting ������ ��Ÿ���ϴ�. ������, ������. ���� random_data[i] > random_data[j] (������ �����ʺ��� ŭ)�� ����(1�̸� ������ 0�̸� ������)�� ������, ���� �ڸ��� swap �˴ϴ�. 
void compAndSwap(int random_data[], int i, int j, int direction)
{
	int temp;
	if (direction == (random_data[i] > random_data[j])) //true�� 1�� ���ðŰ� �ƴϸ�0
		SWAP(random_data[i], random_data[j],temp);
}

//direction ���� 1�̸�, ���������ϰŰ� 0�̸� �������� �ϰ���. sorting�������� index ��ġ low���� ���۵ȴ�. ����0������ �ٸ� ��������. array_size�� sorting�Ǵ� ��ҵ��� �����Դϴ�.
 void bitonicMerge(int random_data[], int low, int array_size, int direction)
{
	if (array_size > 1)
	{
		int k = array_size / 2 ;

		for (int i = low; i < low + k ; i++) {
			compAndSwap(random_data, i, i + k, direction);
		}
		
		// Merge the results.
		bitonicMerge(random_data, low, k, direction);
		
		bitonicMerge(random_data, low + k, k, direction);
	
		for (int i = 0; i < ASIZE; i++) {
			cout << random_data[i] << (i % 16 == 15 ? "\n\n" : ","); //10�� ��¸��� endl
		}
	}
}

/* This function first produces a bitonic sequence by recursivel sorting its two halves in opposite sorting orders, and then calls bitonicMerge to make them in the same order */
void bitonic_sort(int random_data[], int low, int array_size, int direction) //random_data, 0, ASIZE, upORdown
{
	if (array_size > 1)
	{
		int k = array_size / 2 ;

		// sort in ascending order since direction here is 1 (up)
		bitonic_sort(random_data, low, k, UP);

		// sort in descending order since direction here is 0 (down) 
		bitonic_sort(random_data, low + k, k, DOWN);
	
		// ù ���� upORdown ���� 1�̹Ƿ�, Merge the results in ascending order 
		bitonicMerge(random_data, low, array_size, direction);
		
	}
}

int random_data[ASIZE]; // �迭�� ũ�� = ������ �������� ����

// Driver code 
int main()
{
	int upORdown = 1;   // 1�̸� �������� // 0 �̸� ��������  

	srand((int)time(NULL));

	for (int i = 0; i < ASIZE; i++) { // for�� �ݺ�Ƚ�� = ������ �������� ����
		random_data[i] = rand() % 1000; // %1000�̹Ƿ�, ���� �ڸ����� �������� 
	}

	cout << "ó��" << endl;
	for (int i = 0; i < ASIZE; i++) {
		cout << random_data[i] << (i % 16 == 15 ? "\n\n" : ","); //10�� ��¸��� endl
	}

	start = clock(); //���۽ð� ���

	bitonic_sort(random_data, 0, ASIZE , upORdown);

	finish = clock(); //�����ð� ���

	//Ȯ�ο�
	cout << "Ȯ�ο�" << endl;
	for (int i = 0; i < ASIZE ; i++) {
		cout << random_data[i] << (i % 16 == 15 ? "\n\n" : ","); //10�� ��¸��� endl
	}

	calculate_time(); //sorting �ϴµ� �ɸ��ð�
                                               
	return 0;
}

//int N = array_sizeof(random_data) / array_sizeof(random_data[0]); //��� ��üũ��  / ��� ��ĭ ũ��
//�迭�� ���ڰ� � ������ �˱� ���� ũ�⸦ ���� ���� = ���Ͱ��� ��ü ������ ����� ũ��� ������
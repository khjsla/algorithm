//12163291 ������ �˰��� ���� HW1
#include <stdio.h>
#include <iostream>
#include <time.h> //for ��������
using namespace std;

#define SWAP(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
#define ASIZE 4194304 //100�̸�0�ʰɸ� 10000�̸� 0.04 �ΰ� ���� �ɸ� 
//2��n������ ���� �Է����� �־�� ����� ��µ�, �ֳ��ϸ� ���� �����̱� ������ .

#define ASIZE_sel 200000 //100�̸�0�ʰɸ� 10000�̸� 0.04 �ΰ� ���� �ɸ� 
//select�� ������ ���� ���ζ� �Է� ���� ���� ���� ������ �־����ϴ�.

#define UP true //true
#define DOWN false //false

clock_t start, finish, used_time = 0;//���� �ð� ������ ���� ����

//���� �ð��� ���� �� ����ϴ� �Լ�
void calculate_time(void)
{
	used_time = finish - start;
	cout << "�ҿ�ð� : " << (float)used_time / CLOCKS_PER_SEC << "s" << endl << endl;
}

///////////////////////////////// SELECTION //////////////////////////////////

void selection_sort(int random_data[], int n) { //n= ������ ����, []=������ �� ����ִ� �迭
	int min, temp;

	//������ ���ڴ� �ڵ������� ���ĵǹǷ� sort�� �����൵ �ȴ�. ���� n-1��ŭ �ݺ��Ѵ�.
	for (int i = 0; i < n - 1; i++) {
		min = i; //�켱 ó������ �ּڰ��� ó���ڸ� [0]��. 
		//i ���� �ڸ��� �´� ���� ã���ְ� �Ǵ°���
		//���Ŀ� �ּڰ��� Ž���ؼ� �̿� ������,

		//�ּڰ��� Ž���Ѵ�
		for (int j = i + 1; j < n; j++) { //i���� �ڸ��� ã����� �ϹǷ�, i+1���� ������
			if (random_data[j] < random_data[min]) { //���� ���� ���� ���ö����� �ݺ� ���ؼ� 
				min = j; //min�� �������� ���� ����ִ� index���� �־���.
			}
		}

		//�ڱ��ڽ��� �ּڰ��̸� �̵��� �����ʰ�,
		//�ڱ��ڽ��� �ּڰ��� �ƴϸ� swap���� �ڱ��ڽ��� �ڸ��� �ּڰ��� �ڸ��� �ٲ��ݴϴ�.
		if (i != min) {
			SWAP(random_data[i], random_data[min], temp);
		}
	}
}

///////////////////////////////// Median 3 QUICK //////////////////////////////////

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
		int j = right - 1; //�ǵڴ� �̹����ĵǾ������Ƿ�, right�� �ƴ� right-1���� ���� //�� �����ʿ��� �ϳ� -1 ����

		while (true) { //break �϶����� while�� �ݺ�

			while (random_data[++i] < pivot && i < right); //���ʿ����ϳ� ���������� ���Եư�(���� �߾�����), �� ������ ���� ������
			while (random_data[--j] > pivot && left < j);  //�����ʿ����ϳ� �������� ���Եư�(���� �߾�����), �� ���� ���� ũ��

			if (i >= j) break; //������ �Ǹ� �� ���� pivot�� �ڸ��Դϴ�.

			SWAP(random_data[i], random_data[j], temp); //�ڸ� �ٲ��ݴϴ�.
		}

		SWAP(random_data[i], random_data[right - 1], temp); //�ڸ��� ã�����Ƿ� �� �־���
		quick_sort(random_data, left, i - 1); //���ʺκ� sort
		quick_sort(random_data, i + 1, right); //������ �κ� sort
	}
}

// i++�� i�� 1�� ������Ų ��, ������Ű�� �� ���� return�մϴ�.
// ++i�� i�� 1�� ������Ų ��, �� ������ ���� return�մϴ�.

///////////////////////////////// SHELL //////////////////////////////////

//shell sort = insertion �� ������ �˰���
void shell_sort(int random_data[], int size) { //n= ������ ����, []=������ �� ����ִ� �迭 //gap�� size/2
	for (int gap = size / 2; gap > 0; gap /= 2) { //gap �� 0���� ũ�� ��� �����մϴ�. ���� ȸ������ /2 �� �˴ϴ�.
		if (gap % 2 == 0) { //���� ���� ¦���̸�
			gap++; //+1�� Ȧ���� ����� �ݴϴ�. Ȧ���� ���� �� ���� �����Դϴ�.
		}
		for (int i = gap; i < size; i++) { //gap�� ���ڿ� +1�ϸ鼭 (������ ���ϸ鼭) �ϳ��� ���������� ���̳��ö����� �̵��մϴ�.
			int temp = random_data[i]; //���� ���Ե� ������ i��° ���� temp�� �����صӴϴ�.
			int j = 0;
			//i-gap������ ���ĵǾ������Ƿ�,i ~ i-gap ����Ȯ��
			//j�� gap�� ���� ũ�� temp������ j - gap �迭(gap�� ����)�� ���� ũ�� 
			for (j = i; (j > gap && random_data[j - gap] > temp); j = j - gap) {
				random_data[j] = random_data[j - gap]; //���� ���̸�ŭ �ִ� �� ���� �ڸ� �ٲ��ݴϴ�.
			}
			random_data[j] = temp; //���Ե� ���ڸ� j��  
		}
	}
}

///////////////////////////////// BITONIC //////////////////////////////////

//direcion�� sorting ������ ��Ÿ���ϴ�. ������, ������. ���� random_data[i] > random_data[j] (������ �����ʺ��� ŭ)�� ����(1�̸� ������ 0�̸� ������)�� ������, ���� �ڸ��� swap �˴ϴ�. 
void compAndSwap(int random_data[], int i, int j, int direction)
{
	int temp;
	if (direction == (random_data[i] > random_data[j])) //true�� 1�� ���ðŰ� �ƴϸ�0
		SWAP(random_data[i], random_data[j], temp);
}

//direction ���� 1�̸�, ���������ϰŰ� 0�̸� �������� �ϰ���. sorting�������� index ��ġ low���� ���۵ȴ�. ����0������ �ٸ� ��������. array_size�� sorting�Ǵ� ��ҵ��� �����Դϴ�.
void bitonicMerge(int random_data[], int low, int array_size, int direction)
{
	if (array_size > 1)
	{
		int k = array_size / 2;

		for (int i = low; i < low + k; i++) {
			compAndSwap(random_data, i, i + k, direction);
		}

		// Merge the results.
		bitonicMerge(random_data, low, k, direction);
		bitonicMerge(random_data, low + k, k, direction);
	}
}

/* This function first produces a bitonic sequence by recursivel sorting its two halves in opposite sorting orders, and then calls bitonicMerge to make them in the same order */
void bitonic_sort(int random_data[], int low, int array_size, int direction) //random_data, 0, ASIZE, upORdown
{
	if (array_size > 1)
	{
		int k = array_size / 2;

		// sort in ascending order since direction here is 1 (up)
		bitonic_sort(random_data, low, k, UP); //������������ �����ϴ� �κ�

		// sort in descending order since direction here is 0 (down) 
		bitonic_sort(random_data, low + k, k, DOWN); //������������ �����ϴ� �κ�

		// ù ���� upORdown ���� 1�̹Ƿ�, Merge the results in ascending order 
		bitonicMerge(random_data, low, array_size, direction); //merge �ϴ� �Լ�
	}
}

///////////////////////////////// oddeven MERGE //////////////////////////////////

class batcher //��ó �˰��� Ŭ������ �������ݴϴ�.
{
public:
	void oddevenmergesort(int random_data[], int left, int n);
	void oddevenmerge(int random_data[], int left, int n, int r);
};

void batcher::oddevenmergesort(int random_data[], int left, int n)
{
	if (n > 1) //�ǿ��� �� 1����ũ��
	{
		int m = n / 2; //m�̶�� ���� �ǿ������� /2 ��, �迭�� �����ΰ���, 4��
		oddevenmergesort(random_data, left, m); //���. ó������ 0,4 �� / ������ 0,2�� / ������ 0,1�̹Ƿ� ����
		oddevenmergesort(random_data, left + m, m);
		oddevenmerge(random_data, left, n, 1);
	}
	/* left is the starting position and
	 n is the length of the piece to be merged,
	 r is the distance of the elements to be compared //r�� ���� ���ڰ��� ����. 1�� ������ �����Ե�
	*/
}

void batcher::oddevenmerge(int random_data[], int left, int n, int r)
{
	int m = r * 2;
	int temp; //for swap

	if (m < n)
	{
		oddevenmerge(random_data, left, n, m); // even subsequence 
		oddevenmerge(random_data, left + r, n, m); // odd subsequence
		for (int i = left + r; i + r < left + n; i += m) {
			if (random_data[i] > random_data[i + r]) //���ؼ� �������ݴϴ�.
				SWAP(random_data[i], random_data[i + r], temp);
		}
	}
	else { //m�� n���� ũ��
		if (random_data[left] > random_data[left + r])
			SWAP(random_data[left], random_data[left + r], temp);
	}

}

int random_data[ASIZE]; // �迭�� ũ�� = ������ �������� ����
int random_data_sel[ASIZE_sel]; // �迭�� ũ�� = ������ �������� ����
int cparray[ASIZE];

void cparr(int random_data[ASIZE]) { //�񱳿� ��� ī�� �Լ��Դϴ�.
	for (int i = 0; i < ASIZE; i++) {
		cparray[i] = random_data[i];
	}
}

void printarr(int random_array[ASIZE],int size) { //Ȯ�ο� ��� ����Ʈ �Լ��Դϴ�.
	for (int i = 0; i < size; i++) {
		cout << random_array[i] << (i % 16 == 15 ? "\n\n" : ","); //16�� ��¸��� endl
	}
}

///////////////////////////////// Driver code 
int main(){
	cout << "12163291  \n������\n" << endl;

	int upORdown = 1;   // 1�̸� �������� // 0 �̸� ��������  

	srand((int)time(NULL));
	for (int i = 0; i < ASIZE; i++) { // for�� �ݺ�Ƚ�� = ������ �������� ����
		random_data[i] = rand() % 100; // %1000�̹Ƿ�, ���� �ڸ����� �������� 
	}

	for (int i = 0; i < ASIZE_sel; i++) {
		random_data_sel[i] = random_data[i];
	}

	start = clock(); //���۽ð� ���
	selection_sort(random_data_sel, ASIZE_sel); //�������� ����
	finish = clock(); //�����ð� ���
	cout << "SELECTION" << endl;
	calculate_time(); //sorting �ϴµ� �ɸ��ð�

	cparr(random_data);

	start = clock(); //���۽ð� ���
	quick_sort(cparray, 0, ASIZE - 1); //�迭�� 0���� �����̹Ƿ� SIZE-1 �� left��
	finish = clock(); //�����ð� ���
	//printarr(cparray, ASIZE);
	cout << "MED 3 QUICK" << endl;
	calculate_time(); //sorting �ϴµ� �ɸ��ð�

	cparr(random_data);

	start = clock(); //���۽ð� ���
	shell_sort(cparray, ASIZE);
	finish = clock(); //�����ð� ���
	//printarr(cparray, ASIZE);
	cout << "SHELL" << endl;
	calculate_time(); //sorting �ϴµ� �ɸ��ð�

	cparr(random_data);

	start = clock(); //���۽ð� ���
	bitonic_sort(cparray, 0, ASIZE, upORdown);
	finish = clock(); //�����ð� ���
	//printarr(cparray, ASIZE);
	cout << "BITONIC" << endl;
	calculate_time(); //sorting �ϴµ� �ɸ��ð�

	cparr(random_data);

	batcher ba;
	start = clock(); //���۽ð� ���
	ba.oddevenmergesort(cparray, 0, ASIZE);
	finish = clock(); //�����ð� ���
	//printarr(cparray, ASIZE);
	cout << "ODD EVEN MERGE" << endl;
	calculate_time(); //sorting �ϴµ� �ɸ��ð�

	return 0;
}

//int N = array_sizeof(random_data) / array_sizeof(random_data[0]); //��� ��üũ��  / ��� ��ĭ ũ��
//�迭�� ���ڰ� � ������ �˱� ���� ũ�⸦ ���� ���� = ���Ͱ��� ��ü ������ ����� ũ��� ������
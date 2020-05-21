//#include <iostream>
//#include <time.h> //for ��������
//using namespace std;
//
//#define swap(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
//#define array_size 4194304 
////100�̸�0�ʰɸ� 10000�̸� 0.04 �ΰ� ���� �ɸ� 
////2��n������ ���� �Է����� �־�� ����� ��µ�, �ֳ��ϸ� ���� �����̱� ������ .
//
//clock_t start, finish, used_time = 0;//���� �ð� ������ ���� ����
//
////���� �ð��� ���� �� ����ϴ� �Լ�
//void calculate_time(void)
//{
//	used_time = finish - start;
//	cout << ".... �Ϸ�!" << endl << "�ҿ�ð� : " << (clock_t)used_time / CLOCKS_PER_SEC << " ��" << endl;
//}
//
//class batcher
//{
//public:
//	void oddevenmergesort(int random_data[], int left, int n);
//	void oddevenmerge(int random_data[], int left, int n, int r);
//};
//
//void batcher::oddevenmergesort(int random_data[], int left, int n)
//{
//	if (n > 1) //�ǿ��� �� 1����ũ��
//	{
//	int m = n / 2; //m�̶�� ���� �ǿ������� /2 ��, �迭�� �����ΰ���, 4��
//	oddevenmergesort(random_data, left, m); //���. ó������ 0,4 �� / ������ 0,2�� / ������ 0,1�̹Ƿ� ����
//	oddevenmergesort(random_data, left + m, m);
//	oddevenmerge(random_data, left, n, 1);
//	}
//	/* left is the starting position and
//	 n is the length of the piece to be merged,
//	 r is the distance of the elements to be compared //r�� ���� ���ڰ��� ����. 1�� ������ �����Ե� 
//	*/
//}
//
//void batcher::oddevenmerge(int random_data[], int left, int n, int r)
//{
//	int m = r * 2;
//	int temp; //for swap
//
//	if (m < n)
//	{
//		oddevenmerge(random_data, left, n, m); // even subsequence
//		oddevenmerge(random_data, left + r, n, m); // odd subsequence
//		for (int i = left + r; i + r < left + n; i += m) {
//			if (random_data[i] > random_data[i+r])
//			swap(random_data[i], random_data[i + r], temp);
//		}
//	}
//	else {
//		if (random_data[left] > random_data[left + r])
//		swap(random_data[left], random_data[left + r], temp);
//	}
//
//}
//int random_data[array_size]; // �迭�� ũ�� = ������ �������� ����
//
//int main() {
//	batcher ba;
//
//	srand((int)time(NULL));
//
//	for (int i = 0; i < array_size; i++) { // for�� �ݺ�Ƚ�� = ������ �������� ����
//		random_data[i] = rand() % 1000; // %1000�̹Ƿ�, ���� �ڸ����� �������� 
//	}
//	
//	start = clock(); //���۽ð� ���
//	
//	ba.oddevenmergesort(random_data, 0, array_size);
//
//	finish = clock(); //�����ð� ���
//	
//	for (int i = 0; i < array_size; i++) {
//		cout << random_data[i] << (i % 10 == 9 ? "\n\n" : ","); //10�� ��¸��� endl
//	}
//	
//	calculate_time(); //sorting �ϴµ� �ɸ��ð�
//	                                               
//	return 0;
//}

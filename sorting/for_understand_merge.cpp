#include <stdio.h>
#include <iostream>
#include <time.h> //for ��������
using namespace std;

# define ASIZE 100

//�ְ� ���� - �������� ���� - ���Ľ�����
void merge(int list[], int left, int mid, int right) { //�迭, ù - �߰� - �� ���� ����
	
	int sorted[ASIZE]; // �迭�� merge�� �����Ͽ��� ������, �ٸ� ��������� ������ �ʿ��մϴ� = not in-place

	int i, j, k, l;
	i = left; //���� ���� ����
	j = mid + 1; //������ ���� ����
	k = 0; //ó���� �迭�� ù���� �ڸ�

	//printf("\n[in merge] left = %d mid = %d right = %d\n", left, mid+1, right);
	/* ���� ���ĵ� list�� �պ� */
	//�� ���������� ���������� �ο� ���̴�
	while (i <= mid && j <= right) { //i �� mid���� ����, j�� ������ ���ԵǸ�
		if (list[i] <= list[j]) { //������ ó���� �������� ó������ ������
			sorted[k] = list[i];
			k++; //k �ϳ� ���������� �Ű���
			i++; //j �ϳ� ����������
		}
		else { //������ ó���� �������� ó������ ũ��
			sorted[k] = list[j];
			j++; //j �ϳ� ���������� �Ű���
			k++; //k �ϳ� ����������
		}
	}

//	������ �����ߴ��� �������� �����ߴ��� 
//	������ ��������� //������ i �� �߰� ������ �� �Űܰ��� �ʾҴٸ�
	while (i<=mid){
		sorted[k] = list[i];
		k++;
		i++;
	}
//	�������� ��������� //�������� (�� �߰� �ε��� �κ�) j �� ������ �� �Űܰ��� �ʾҴٸ�
	while (j <= right) {
		sorted[k] = list[j];
		j++;
		k++;
	}

	k--; // �̰ž����� k �� [] 9�� ������
	
	while (k >= 0) { //k�� -1�� �ɶ� ���� ���Ƿ� �����ص״� (sort�� ���� ����ִ� ��̰���) ������ list[]�迭�� �ٿ��ֱ� ����
		list[left + k] = sorted[k];
		k--;
	}
	 //���� �ִ� ������ �ϰ� ����

}


//�갡 ������ .���� �� ������ - ����ǥ�� ¥��
void merge_sort(int list[], int left, int right) { //ù���� left�� ������ ���� right 
	//exit condition �̳� �ƴϳķ� ����
//	exit condition = �ο�ְ� ������ exit condition��

	//���⼭ left�� index 0�̰� right�� 7��
	if (left < right) { //exit condition = left�� right���� ũ�� exit condition ��

		int mid = (left + right) / 2; // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(divide)
		
		//printf("\n  [left] low = %d mid=%d", left, mid);
		merge_sort(list, left, mid); // ���� �κ� ����Ʈ ���� -����(conquer)
		
		//printf("\n  [right] mid+1= %d right= %d", mid+1, right);
		merge_sort(list, mid + 1, right); // ���� �κ� ����Ʈ ���� -����(conquer)

		//printf("\n  [do merge.] low= %d, mid= %d right= %d", left, mid, right);
		merge(list, left, mid, right); // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(combine)
		//for (int i = 0; i < ASIZE; i++) {
		//	printf("%d ", list[i]);
		//}
		printf("\n");

	}
	else {
		return;
	}
}

int list[ASIZE];

void main() {

	srand((int)time(NULL));
	
	for (int i = 0; i < ASIZE; i++) { // for�� �ݺ�Ƚ�� = ������ �������� ����
		list[i] = rand() % 1000; // %1000�̹Ƿ�, ���� �ڸ����� �������� 
	}

	printf("---��---\n");

	for (int i = 0; i < ASIZE; i++) {
		printf("%d ", list[i]);
	}

	 //�պ� ���� ����(left: �迭�� ���� = 0, right: �迭�� �� = 7)
	merge_sort(list, 0, ASIZE - 1);

	printf("\n---��---\n");

	// ���� ��� ���
	for (int i = 0; i < ASIZE; i++) {
		printf("%d ", list[i]);
	}

	printf("\n");
}

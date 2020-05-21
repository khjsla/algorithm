//#define _CRT_SECURE_NO_WARNINGS
//#define SWAP(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
//
//#include <string>
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//int nextJump[50]; //init nextJump���� ������ �δ� �迭
//
//void InitnextJump(char *p){
//	int i, j = 0, M = strlen(p);
//
//	nextJump[0] = -1;
//
//	for (i = 0, j = -1; i < M; i++, j++) {
//		nextJump[i] = (p[i] == p[j]) ? nextJump[j] : j; //�����ȹ���
//		while ((j >= 0) && (p[i] != p[j]))
//			j = nextJump[j];
//	}
//}
//
//void selection_sort(int random_data[], int n, string string_[]) { //n= ������ ����, []=������ �� ����ִ� �迭
//	int min;
//	int temp;
//	string x;
//
//	//������ ���ڴ� �ڵ������� ���ĵǹǷ� sort�� �����൵ �ȴ�. ���� n-1��ŭ �ݺ��Ѵ�.
//	for (int i = 0; i < n - 1; i++) {
//		min = i; //�켱 ó������ �ּڰ��� ó���ڸ� [0]��. 
//		//i ���� �ڸ��� �´� ���� ã���ְ� �Ǵ°���
//		//���Ŀ� �ּڰ��� Ž���ؼ� �̿� ������,
//
//		//�ּڰ��� Ž���Ѵ�
//		for (int j = i + 1; j < n; j++) { //i���� �ڸ��� ã����� �ϹǷ�, i+1���� ������
//			if (random_data[j] > random_data[min]) { //���� ���� ���� ���ö����� �ݺ� ���ؼ� 
//				min = j; //min�� �������� ���� ����ִ� index���� �־���.
//			}
//		}
//
//		//�ڱ��ڽ��� �ּڰ��̸� �̵��� �����ʰ�,
//		//�ڱ��ڽ��� �ּڰ��� �ƴϸ� swap���� �ڱ��ڽ��� �ڸ��� �ּڰ��� �ڸ��� �ٲ��ݴϴ�.
//		if (i != min) {
//			SWAP(random_data[i], random_data[min], temp);
//			SWAP(string_[i], string_[min], x);
//		}
//	}
//}
//
//
//int KMP(char *p, char *t){  //pos = KMP(*ã�� pattern, *�������� text + i) 
//	int i, j, M = strlen(p), N = strlen(t);
//	//M�� pattern�� ����
//	//N�� text�� ����
//
//	InitnextJump(p);
//	//pattern�� �־ ���̻�, ���λ縦 ���ؼ� nextJump[]�ȿ� 
//	//ȿ�������� �ٽ� ��ġ�� ������ �� �ִ� ��ġ ������ �־��ش�
//
//	for (i = 0, j = 0; j < M && i < N; i++, j++) {
//		while ((j >= 0) && (t[i] != p[j])) {
//			j = nextJump[j];
//		}
//	}
//
//	if (j == M) { //���� j�� ++�Ǵٰ� pattern�� ���̰� �Ǹ�
//		return i - M; //i���� pattern�� ���̸� �A ���� ��ġ�� pos�ν�, pattern�� �߻��� ��
//	}
//	else {
//		return false; //����ġ �ϰ� �Ǿ����ϴ�.
//	}
//}
//
//int main(){
//	char text[250];
//	char pattern[8];
//
//	string strin[1000]; //string�������
//	int whereis[50]; //�� string�� ���� ����ִ��� ������� ����
//	int M, N, pos;
//	int i = 0; 
//
//	cin >> pattern;
//	//scanf("%s", pattern); //pio�Է�
//
//	M = strlen(pattern); //M�� pattern�� ����
//	
//	string save;
//	while (1) { //��� �ݺ�
//
//		//scanf("%s", text); //pio�Է�
//		cin >> text;
//		save = text; //�ؽ�Ʈ �켱 ��Ʈ������ ����
//		//printf("save�� : %s\n", save); //pos�� ã�� ������ �߻��� ��ġ�Դϴ�.
//		cout << "save��: " << save << endl;
//		if (strcmp(text, "0") == 0) break; //�Է°� 0�̸� ����
//
//		N = strlen(text); //N�� text�� ����
//		pos = KMP(pattern, text); //pos = KMP(ã�� pattern, �������� text + i) 
//
//		if (pos!=false) { //���� i �� text�� ���̺��� ������ 
//			printf("������ �߻��� ��ġ : %d\n", pos); //pos�� ã�� ������ �߻��� ��ġ�Դϴ�.
//			whereis[i] = pos;
//			strin[i] = save;
//			i++;
//		}
//		else { //���� i�� ���� text�� ���̺��� ũ��
//			break; //��������
//		}
//
//		//save.clear(); //������ ������ save�� �����
//		//printf("clear�� save�� : %s\n", save); //pos�� ã�� ������ �߻��� ��ġ�Դϴ�.
//		//cout << "clear: " << save << endl;
//	}
//
//	selection_sort(whereis, i, strin);
//
//	for (int j = 0; j < i; j++) {
//		printf("%s", strin[j]);
//	}
//
//}
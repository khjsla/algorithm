//12163291 ������ �˰��� ���� ����2 KMP
#pragma warning(disable:4996) //_s ���� ���ֱ�

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream> //for FTTPfile �б�
using namespace std;

#define TOTAL_LEN 40835 //for HTTPfile
char TextFile[TOTAL_LEN]; //HTTPfile �����
int nextPlace[TOTAL_LEN];

int cnt; //for -1���� ���¿�
int MinPlace[50] = { 0 }; //-1�� ��Ÿ���� ��ġ ����ϴ� �迭, 
//������ �˰��򿡼�, nextPlace[0] �� �ƴԿ��� �ұ��ϰ�, ���� -1�� ��쿡 , �װ��� �������� pattern ��ġ �˻縦 �ѹ� �� ���ݴϴ�.

void InitnextPlace(char *pattern) { //pattern - �������ġ ã�Ƴ��� �Լ�
	cnt = 0; //cnt �ʱ�ȭ
	int i, j = 0;
	int k = 0; //-1 �� ��Ÿ�� ���� �ڸ��� �����ϱ� ����
	int M = strlen(pattern); //������ ���� M

	nextPlace[0] = -1; //0��°���� -1�� ����

	for (i = 0, j = -1; i < M; i++, j++) { //i=0, j-1����, i�� j�� �Ͽ�ư ��� �ϳ����þ��, i < ���ϱ��� �� ��.
		//nextPlace[i] = j; //��������
		nextPlace[i] = (pattern[i] == pattern[j]) ? nextPlace[j] : j; //�����ȹ���
		while ((j >= 0) && (pattern[i] != pattern[j])) {
			j = nextPlace[j];
		}
		if(nextPlace[i]==-1){
			cnt++; //-1������ +1 //-1�� ��Ÿ���� ���� ��
			if (i != 0) {
				MinPlace[k] = i; //[0]����.. -1�� ������ ��ġ ���� ���Ե�
				k++;
			}
		}
	}
	cnt--; //nextPlace[0]���� -1�� ��츦 cnt���� �����ϴ� �뵵�� -1
}

int KMP(char *pattern, char *text){ //�ѹ��� �ѹ� ã�� �ȴ�.
	int i, j;
	int M = strlen(pattern);
	int N = strlen(text);
	
	InitnextPlace(pattern); //���⼭ nextPlace[] �迭�� ���� ä������, �����ǰԵȴ�.
	
	for (i = 0, j = 0; j < M && i < N; i++, j++) { //���ϱ��ڱ��� �� ��ŭ for�� �ݺ�
		while ((j >= 0) && (text[i] != pattern[j])) {
			j = nextPlace[j];
		}
	}

	if (j == M) { //j�� 1���þ�ٰ� pattern�� ũ��� ���ԵǸ�, 
		return i - M; //�� ��Ÿ�� ��ġindex�� return 
	}
	else {
		return i;
	}
}

int main(){
	printf("12163291 ������ �˰��򼳰� KMP #HW2\n");

	char text[100] = "ababab"; //pattern�� ã�Ƴ� text �κ�

	ifstream RFC2616("RFC2616_modified.txt");  //pattern�� ã�Ƴ� textfile
	if (RFC2616.is_open()) { //txt ���� ������ 
		int i = 0;
		while(!RFC2616.eof()){ //text������ ��� ������ 
			RFC2616 >> TextFile[i]; //TextFIle[]�� HTTP ���� ��� ���Ե�.
			//cout << TextFile[i]; //�� ������ Ȯ�ο�
			i++;
		}
		//cout << "HTTPfile ����: " << i << endl << endl; //40835���� ������
	}

	char pattern[50] = "connections"; //KMP�� ã�� pattern .

	int pos; //pattern�� ã�� �κ�
	int previous = 0;
	int i = 0; //�켱 0�ε� �̰� previous �Ǹ鼭 +M���� ���Եǰ�, ��ħ�˻��� �Ұ����ϰԵ� 

	int M = strlen(pattern); 
	//int N = strlen(text); //not HTTP file ã�� ��
    int N = strlen(TextFile);

	/*printf("Text: "); //text ���
	for (int i = 0; i < N; i++) {
		printf("%c", text[i]); 
	}
	cout << endl;*/

	printf("Pattern: "); //pattern ���
	for (int i = 0; i < M; i++) {
		printf("%c", pattern[i]);
	}
	cout << endl << endl;

	while (1) { 
		pos = KMP(pattern, TextFile + i); //�迭�̸� +i �̹Ƿ�, �迭���� +i�� �κк��� ù �˻�
		pos += previous; //���� pattern ������ �� + pattern ���� // �̰� ������ ������ �κ��� �˻��� ����� ���Ե�
		
		if (cnt > 0) { //���� pattern���� �ߺ��Ǵ� �κ��� �����
			i = pos + MinPlace[0]; //MinPlace[0]�� ���� [0]�ƴ� ������ 
			//ó������ -1�� �����ϴ� �κ��� ��ġ index���� ������
		}
		else { //���� pattern���� �ߺ��Ǵ� �κ��� ������ ������ ���� ������ �Ѵ�.
			i = pos + M; //�� M(������ ����)�� ���ϴ°� �ƴ϶� nextPlace[0]�̾ƴѵ� 
			//nextPlace[]���� -1�� ���� ������ �κп��� �� �˻��ϵ��� �Ѵ�.
		}
		
		if (i <= N) {
			printf("������ �߻��� ��ġ : %d\n", pos);
		}
		else break;
		
		previous = i; //������ search�� �κ��� ���ؼ�
	}

	printf("\nnext[]:"); //nextinit���� ���� next[] ���̺� �� print
	for (int i = 0; i < M; i++) {
		printf(" %d /", nextPlace[i]); 
	}

	printf("\nnext[]���� -1 �� ����([0]����): %d\n\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("next[]���� -1 �� ��ġ: %d\n", MinPlace[i]); //nextinit ���� ���� next[] �迭�ȿ� -1�� ����
	}

	printf("KMP ����");
}

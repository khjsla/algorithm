#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>

int next[50];

void InitNext(char *p)
{
	int i, j = 0, M = strlen(p);

	next[0] = -1;
	for (i = 0, j = -1; i < M; i++, j++) {
		//next[i] = j; //��������
		next[i] = (p[i] == p[j]) ? next[j] : j; //�����ȹ���
		while ((j >= 0) && (p[i] != p[j]))
			j = next[j];
	}

}

int KMP(char *p, char *t)
{
	int i, j, M = strlen(p), N = strlen(t);
	InitNext(p);
	for (i = 0, j = 0; j < M && i < N; i++, j++)
		while ((j >= 0) && (t[i] != p[j])) j = next[j];
	if (j == M) return i - M;
	else return i;
}

int main(){
	char text[100];// = "AABAAbabcababAABAAaabbabAABAAaab"; 
	char pattern[50];// = "AABAA";
	int M, N, pos, previous = 0, i = 0;
	int cnt = 0;

	scanf("%s", text); //text�� �Է�
	N = strlen(text);

	while (1) {
		scanf("%s", pattern); //ã�� �ܾ��Է�
		if (strcmp(pattern, "0") == 0) break; //0������ ��
		M = strlen(pattern);

		while (1) { //i�� ������ ���������� �׳� �ֱ⸸ �ϸ� ������ kmp����Ǹ鼭,
			pos = KMP(pattern, text + i);
			pos += previous;
			i = pos + M;
			if (i <= N) { //pateern ������ ����� �´�
				printf("������ �߻��� ��ġ : %d\n", pos);
				cnt++;
			}
			else break;
			previous = i;
		}

		printf("%d �� �߻�. ��Ʈ�� Ž�� ����.\n", cnt);
		cnt = 0; i = 0; previous = 0;
	}

	return 0;
}

#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>

int next[50];

void InitNext(char *p)
{
	int i, j = 0, M = strlen(p);

	next[0] = -1;
	for (i = 0, j = -1; i < M; i++, j++) {
		//next[i] = j; //원래버전
		next[i] = (p[i] == p[j]) ? next[j] : j; //개선된버전
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

	scanf("%s", text); //text값 입력
	N = strlen(text);

	while (1) {
		scanf("%s", pattern); //찾을 단어입력
		if (strcmp(pattern, "0") == 0) break; //0들어오면 끝
		M = strlen(pattern);

		while (1) { //i가 끝까지 가기전까지 그냥 있기만 하면 무조건 kmp실행되면서,
			pos = KMP(pattern, text + i);
			pos += previous;
			i = pos + M;
			if (i <= N) { //pateern 있으면 여기로 온다
				printf("패턴이 발생한 위치 : %d\n", pos);
				cnt++;
			}
			else break;
			previous = i;
		}

		printf("%d 개 발생. 스트링 탐색 종료.\n", cnt);
		cnt = 0; i = 0; previous = 0;
	}

	return 0;
}

//12163291 강현지 알고리즘 설계 과제2 KMP
#pragma warning(disable:4996) //_s 에러 없애기

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream> //for FTTPfile 읽기
using namespace std;

#define TOTAL_LEN 40835 //for HTTPfile
char TextFile[TOTAL_LEN]; //HTTPfile 저장용
int nextPlace[TOTAL_LEN];

int cnt; //for -1개수 세는용
int MinPlace[50] = { 0 }; //-1이 나타나는 위치 기억하는 배열, 
//개선된 알고리즘에서, nextPlace[0] 이 아님에도 불구하고, 값이 -1인 경우에 , 그곳을 기점으로 pattern 일치 검사를 한번 더 해줍니다.

void InitnextPlace(char *pattern) { //pattern - 재시작위치 찾아내는 함수
	cnt = 0; //cnt 초기화
	int i, j = 0;
	int k = 0; //-1 이 나타난 곳의 자리를 저장하기 위한
	int M = strlen(pattern); //패턴의 길이 M

	nextPlace[0] = -1; //0번째에는 -1로 설정

	for (i = 0, j = -1; i < M; i++, j++) { //i=0, j-1부터, i와 j는 하여튼 계속 하나씩늘어난다, i < 패턴길이 인 한.
		//nextPlace[i] = j; //원래버전
		nextPlace[i] = (pattern[i] == pattern[j]) ? nextPlace[j] : j; //개선된버전
		while ((j >= 0) && (pattern[i] != pattern[j])) {
			j = nextPlace[j];
		}
		if(nextPlace[i]==-1){
			cnt++; //-1있으면 +1 //-1이 나타나는 개수 셈
			if (i != 0) {
				MinPlace[k] = i; //[0]부터.. -1이 나오는 위치 정보 들어가게됨
				k++;
			}
		}
	}
	cnt--; //nextPlace[0]에서 -1인 경우를 cnt에서 제외하는 용도의 -1
}

int KMP(char *pattern, char *text){ //한번에 한번 찾게 된다.
	int i, j;
	int M = strlen(pattern);
	int N = strlen(text);
	
	InitnextPlace(pattern); //여기서 nextPlace[] 배열의 값이 채워지고, 형성되게된다.
	
	for (i = 0, j = 0; j < M && i < N; i++, j++) { //패턴글자길이 수 만큼 for문 반복
		while ((j >= 0) && (text[i] != pattern[j])) {
			j = nextPlace[j];
		}
	}

	if (j == M) { //j가 1씩늘어나다가 pattern의 크기랑 같게되면, 
		return i - M; //그 나타난 위치index값 return 
	}
	else {
		return i;
	}
}

int main(){
	printf("12163291 강현지 알고리즘설계 KMP #HW2\n");

	char text[100] = "ababab"; //pattern을 찾아낼 text 부분

	ifstream RFC2616("RFC2616_modified.txt");  //pattern을 찾아낼 textfile
	if (RFC2616.is_open()) { //txt 파일 있으면 
		int i = 0;
		while(!RFC2616.eof()){ //text파일이 비기 전까지 
			RFC2616 >> TextFile[i]; //TextFIle[]에 HTTP 내용 모두 들어가게됨.
			//cout << TextFile[i]; //잘 들어갔는지 확인용
			i++;
		}
		//cout << "HTTPfile 길이: " << i << endl << endl; //40835개의 글자임
	}

	char pattern[50] = "connections"; //KMP로 찾을 pattern .

	int pos; //pattern을 찾은 부분
	int previous = 0;
	int i = 0; //우선 0인데 이게 previous 되면서 +M으로 가게되고, 겹침검색이 불가능하게됨 

	int M = strlen(pattern); 
	//int N = strlen(text); //not HTTP file 찾는 용
    int N = strlen(TextFile);

	/*printf("Text: "); //text 출력
	for (int i = 0; i < N; i++) {
		printf("%c", text[i]); 
	}
	cout << endl;*/

	printf("Pattern: "); //pattern 출력
	for (int i = 0; i < M; i++) {
		printf("%c", pattern[i]);
	}
	cout << endl << endl;

	while (1) { 
		pos = KMP(pattern, TextFile + i); //배열이름 +i 이므로, 배열에서 +i한 부분부터 첫 검색
		pos += previous; //전에 pattern 구해진 곳 + pattern 길이 // 이것 때문에 겹쳐진 부분의 검색이 힘들어 지게됨
		
		if (cnt > 0) { //만약 pattern에서 중복되는 부분이 생기면
			i = pos + MinPlace[0]; //MinPlace[0]의 값은 [0]아닌 곳에서 
			//처음으로 -1이 등장하는 부분의 위치 index값이 들어가있음
		}
		else { //만약 pattern에서 중복되는 부분이 생기지 않으면 원래 방법대로 한다.
			i = pos + M; //이 M(패턴의 길이)을 더하는게 아니라 nextPlace[0]이아닌데 
			//nextPlace[]에서 -1의 값을 가지는 부분에서 또 검색하도록 한다.
		}
		
		if (i <= N) {
			printf("패턴이 발생한 위치 : %d\n", pos);
		}
		else break;
		
		previous = i; //다음에 search할 부분을 위해서
	}

	printf("\nnext[]:"); //nextinit으로 구한 next[] 테이블 값 print
	for (int i = 0; i < M; i++) {
		printf(" %d /", nextPlace[i]); 
	}

	printf("\nnext[]에서 -1 의 개수([0]제외): %d\n\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("next[]에서 -1 의 위치: %d\n", MinPlace[i]); //nextinit 으로 구한 next[] 배열안에 -1의 개수
	}

	printf("KMP 종료");
}

//#define _CRT_SECURE_NO_WARNINGS
//#define SWAP(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
//
//#include <string>
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//int nextJump[50]; //init nextJump정보 저장해 두는 배열
//
//void InitnextJump(char *p){
//	int i, j = 0, M = strlen(p);
//
//	nextJump[0] = -1;
//
//	for (i = 0, j = -1; i < M; i++, j++) {
//		nextJump[i] = (p[i] == p[j]) ? nextJump[j] : j; //개선된버전
//		while ((j >= 0) && (p[i] != p[j]))
//			j = nextJump[j];
//	}
//}
//
//void selection_sort(int random_data[], int n, string string_[]) { //n= 데이터 개수, []=데이터 값 들어있는 배열
//	int min;
//	int temp;
//	string x;
//
//	//마지막 숫자는 자동적으로 정렬되므로 sort를 안해줘도 된다. 따라서 n-1만큼 반복한다.
//	for (int i = 0; i < n - 1; i++) {
//		min = i; //우선 처음에는 최솟값이 처음자리 [0]임. 
//		//i 숫자 자리에 맞는 값을 찾아주게 되는것임
//		//이후에 최솟값을 탐색해서 이와 비교해줌,
//
//		//최솟값을 탐색한다
//		for (int j = i + 1; j < n; j++) { //i값의 자리를 찾아줘야 하므로, i+1부터 비교해줌
//			if (random_data[j] > random_data[min]) { //가장 작은 수가 나올때까지 반복 비교해서 
//				min = j; //min에 가장작은 수가 들어있는 index값을 넣어줌.
//			}
//		}
//
//		//자기자신이 최솟값이면 이동을 하지않고,
//		//자기자신이 최솟값이 아니면 swap으로 자기자신의 자리와 최솟값의 자리를 바꿔줍니다.
//		if (i != min) {
//			SWAP(random_data[i], random_data[min], temp);
//			SWAP(string_[i], string_[min], x);
//		}
//	}
//}
//
//
//int KMP(char *p, char *t){  //pos = KMP(*찾는 pattern, *뒤져야할 text + i) 
//	int i, j, M = strlen(p), N = strlen(t);
//	//M은 pattern의 길이
//	//N은 text의 길이
//
//	InitnextJump(p);
//	//pattern을 넣어서 접미사, 접두사를 비교해서 nextJump[]안에 
//	//효율적으로 다시 서치를 시작할 수 있는 위치 정보를 넣어준다
//
//	for (i = 0, j = 0; j < M && i < N; i++, j++) {
//		while ((j >= 0) && (t[i] != p[j])) {
//			j = nextJump[j];
//		}
//	}
//
//	if (j == M) { //만약 j가 ++되다가 pattern의 길이가 되면
//		return i - M; //i에서 pattern의 길이를 뺸 곳의 위치가 pos로써, pattern이 발생한 곳
//	}
//	else {
//		return false; //불일치 하게 되었습니다.
//	}
//}
//
//int main(){
//	char text[250];
//	char pattern[8];
//
//	string strin[1000]; //string순서대로
//	int whereis[50]; //그 string에 패턴 어디있는지 순서대로 삽입
//	int M, N, pos;
//	int i = 0; 
//
//	cin >> pattern;
//	//scanf("%s", pattern); //pio입력
//
//	M = strlen(pattern); //M은 pattern의 길이
//	
//	string save;
//	while (1) { //계속 반복
//
//		//scanf("%s", text); //pio입력
//		cin >> text;
//		save = text; //텍스트 우선 스트링으로 저장
//		//printf("save값 : %s\n", save); //pos는 찾는 패턴이 발생한 위치입니다.
//		cout << "save값: " << save << endl;
//		if (strcmp(text, "0") == 0) break; //입력값 0이면 나옴
//
//		N = strlen(text); //N은 text의 길이
//		pos = KMP(pattern, text); //pos = KMP(찾는 pattern, 뒤져야할 text + i) 
//
//		if (pos!=false) { //만약 i 가 text의 길이보다 작으면 
//			printf("패턴이 발생한 위치 : %d\n", pos); //pos는 찾는 패턴이 발생한 위치입니다.
//			whereis[i] = pos;
//			strin[i] = save;
//			i++;
//		}
//		else { //만약 i가 이제 text의 길이보다 크면
//			break; //끝내버림
//		}
//
//		//save.clear(); //패턴이 없으면 save는 비워줌
//		//printf("clear후 save값 : %s\n", save); //pos는 찾는 패턴이 발생한 위치입니다.
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
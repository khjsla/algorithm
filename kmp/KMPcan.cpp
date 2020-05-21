//#include <stdio.h>
//#include <string.h>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//#define s_len 250
//#define key_len 8
//
//int* InitNext(char*);
//char* getKey();
//int KMP(char*, char*, int*);
//void copy(char* s1, char* s2);
//void printResult();
//
//struct a {
//	int idx;
//	char* str;
//};
//
//a result[1000];
//
//int main(){
//	char* key = getKey();  // get key string
//	int* nxt = InitNext(key);
//
//	int match;
//	for (int i = 0; i < 1000; i++) {
//		// get random strings
//		char* randomstr = new char[250];
//		cin >> randomstr;
//		if (strcmp(randomstr, "0") == 0) break;
//
//		/* KMP */
//		match = KMP(key, randomstr, nxt);
//
//		/* save and sort */
//		int j = i;  // idx  for sorting
//		// allocate memory and save temp data
//		result[j].idx = match;
//		result[j].str = new char[250];
//		// sort in ascending order
//		while (j > 0 && result[j - 1].idx > match) {
//			result[j].idx = result[j - 1].idx;
//			copy(result[j].str, result[j - 1].str);
//			j--;
//		}
//		result[j].idx = match;
//		copy(result[j].str, randomstr);
//	}
//
//	printResult();
//	return 0;
//}
//
//void printResult() {
//	for (int i = 0; i < 1000; i++) {
//		if (result[i].str == NULL) break;
//		printf("%d, %s\n", result[i].idx, result[i].str);
//	}
//}
//
//int* InitNext(char *p)
//{
//	int i, j = 0, M = strlen(p);
//	int* nxt = new int[key_len + 1];  // length of next array = length of key string+1
//	nxt[0] = -1;
//	for (i = 0, j = -1; i < M; i++, j++) {
//		nxt[i] = (p[i] == p[j]) ? nxt[j] : j; //개선된버전
//		while ((j >= 0) && (p[i] != p[j]))
//			j = nxt[j];
//	}
//	return nxt;
//}
//
//char * getKey() {
//	char* key = new char[key_len];
//
//	cin >> key;  // get key string
//	return key;
//}
//
//int KMP(char *p, char *t, int *next) {
//	int i, j, M = strlen(p), N = strlen(t);
//	for (i = 0, j = 0; j < M && i < N; i++, j++)
//		while ((j >= 0) && (t[i] != p[j])) {
//			j = next[j];
//		}
//	if (j == M) return i - M;  // 일치. key string 내용이 시작하는 부분
//	else return -1;  // 불일치
//}
//
//// my strcpy function
//void copy(char* s1, char* s2) {
//	int i;
//	for (i = 0; i < strlen(s2); i++) {
//		s1[i] = s2[i];
//	}
//	s1[i] = NULL;
//}
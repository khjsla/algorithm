//#include <iostream>
//#include <time.h> //for 난수생성
//using namespace std;
//
//#define ASIZE 512
//
//clock_t start, finish, used_time = 0;    //실행 시간 측정을 위한 변수
//
////실행 시간을 측정 및 출력하는 함수
//void calculate_time(void)
//{
//	used_time = finish - start;
//	cout << ".... 완료!" << endl << "소요시간 : " << (float)used_time / CLOCKS_PER_SEC << " 초" << endl;
//}
//
////shell sort = insertion 을 보완한 알고리즘
//void shell_sort(int random_data[], int size) { //n= 데이터 개수, []=데이터 값 들어있는 배열 //gap은 size/2
//	for (int gap = size / 2; gap > 0; gap /= 2) {
//		if (gap % 2 == 0) {
//			gap++;
//		}
//		for (int i = gap; i < size; i++) {
//			int temp = random_data[i];
//			int j = 0;
//			for (j = i; (j > gap&&random_data[j - gap] > temp); j = j - gap) {
//				random_data[j] = random_data[j - gap];
//			}
//			random_data[j] = temp;
//		}
//	}
//}
//
//int random_data[ASIZE]; // 배열의 크기 = 정렬할 데이터의 개수
//
//int main() {
//	srand((int)time(NULL));
//
//	for (int i = 0; i < ASIZE; i++) { // for문 반복횟수 = 정렬할 데이터의 개수
//		random_data[i] = rand() % 1000; // %1000이므로, 백의 자리수로 랜덤변수 
//	}
//
//	start = clock(); //시작시간 재기
//
//	shell_sort(random_data, ASIZE);
//
//	finish = clock(); //끝난시간 재기
//
//	for (int i = 0; i < ASIZE; i++) {
//		cout << random_data[i] << (i % 10 == 9 ? "\n\n" : ","); //10개 출력마다 endl
//	}
//
//	calculate_time(); //sorting 하는데 걸린시간
//
//}
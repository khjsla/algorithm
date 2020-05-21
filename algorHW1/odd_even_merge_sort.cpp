//#include <iostream>
//#include <time.h> //for 난수생성
//using namespace std;
//
//#define swap(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )
//#define array_size 4194304 
////100이면0초걸림 10000이면 0.04 인가 정도 걸림 
////2의n제곱의 수를 입력으로 넣어야 결과가 출력됨, 왜냐하면 병렬 과정이기 때문에 .
//
//clock_t start, finish, used_time = 0;//실행 시간 측정을 위한 변수
//
////실행 시간을 측정 및 출력하는 함수
//void calculate_time(void)
//{
//	used_time = finish - start;
//	cout << ".... 완료!" << endl << "소요시간 : " << (clock_t)used_time / CLOCKS_PER_SEC << " 초" << endl;
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
//	if (n > 1) //맨오른 이 1보다크먄
//	{
//	int m = n / 2; //m이라는 수는 맨오른수의 /2 즉, 배열을 반으로가름, 4로
//	oddevenmergesort(random_data, left, m); //재귀. 처음에는 0,4 임 / 다음은 0,2임 / 다음은 0,1이므로 끝남
//	oddevenmergesort(random_data, left + m, m);
//	oddevenmerge(random_data, left, n, 1);
//	}
//	/* left is the starting position and
//	 n is the length of the piece to be merged,
//	 r is the distance of the elements to be compared //r은 비교할 숫자간의 간격. 1의 간격을 가지게됨 
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
//int random_data[array_size]; // 배열의 크기 = 정렬할 데이터의 개수
//
//int main() {
//	batcher ba;
//
//	srand((int)time(NULL));
//
//	for (int i = 0; i < array_size; i++) { // for문 반복횟수 = 정렬할 데이터의 개수
//		random_data[i] = rand() % 1000; // %1000이므로, 백의 자리수로 랜덤변수 
//	}
//	
//	start = clock(); //시작시간 재기
//	
//	ba.oddevenmergesort(random_data, 0, array_size);
//
//	finish = clock(); //끝난시간 재기
//	
//	for (int i = 0; i < array_size; i++) {
//		cout << random_data[i] << (i % 10 == 9 ? "\n\n" : ","); //10개 출력마다 endl
//	}
//	
//	calculate_time(); //sorting 하는데 걸린시간
//	                                               
//	return 0;
//}

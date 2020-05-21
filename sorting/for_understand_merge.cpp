#include <stdio.h>
#include <iostream>
#include <time.h> //for 난수생성
using namespace std;

# define ASIZE 100

//애가 정복 - 서열정리 해줌 - 정렬시켜줌
void merge(int list[], int left, int mid, int right) { //배열, 첫 - 중간 - 끝 선수 받음
	
	int sorted[ASIZE]; // 배열로 merge를 구현하였기 떄문에, 다른 저장공간이 별도로 필요합니다 = not in-place

	int i, j, k, l;
	i = left; //왼쪽 팀의 시작
	j = mid + 1; //오른쪽 팀의 시작
	k = 0; //처음은 배열의 첫번쨰 자리

	//printf("\n[in merge] left = %d mid = %d right = %d\n", left, mid+1, right);
	/* 분할 정렬된 list의 합병 */
	//다 끝날때까지 본격적으로 싸움 붙이는
	while (i <= mid && j <= right) { //i 가 mid까지 가고, j가 끝까지 가게되면
		if (list[i] <= list[j]) { //왼쪽팀 처음이 오른쪽팀 처음보다 작으면
			sorted[k] = list[i];
			k++; //k 하나 오른쪽으로 옮겨줌
			i++; //j 하나 오른쪽으로
		}
		else { //왼쪽팀 처음이 오른쪽팀 처음보다 크면
			sorted[k] = list[j];
			j++; //j 하나 오른쪽으로 옮겨줌
			k++; //k 하나 오른쪽으로
		}
	}

//	왼쪽이 전멸했는지 오른쪽이 전멸했는지 
//	왼쪽이 살아잇으면 //왼쪽팀 i 가 중간 끝까지 다 옮겨가지 않았다면
	while (i<=mid){
		sorted[k] = list[i];
		k++;
		i++;
	}
//	오른쪽이 살아있으면 //오른쪽팀 (약 중간 인덱스 부분) j 가 끝까지 다 옮겨가지 않았다면
	while (j <= right) {
		sorted[k] = list[j];
		j++;
		k++;
	}

	k--; // 이거없으면 k 는 [] 9에 가있음
	
	while (k >= 0) { //k가 -1이 될때 까지 임의로 설정해뒀던 (sort된 값이 들어있는 어레이값을) 원래의 list[]배열에 붙여넣기 해줌
		list[left + k] = sorted[k];
		k--;
	}
	 //남아 있는 값들을 일괄 복사

}


//얘가 나눠줌 .수를 다 나눠줌 - 대진표를 짜줌
void merge_sort(int list[], int left, int right) { //첫선수 left와 마지막 선수 right 
	//exit condition 이냐 아니냐로 나뉨
//	exit condition = 싸울애가 없으면 exit condition임

	//여기서 left는 index 0이고 right는 7임
	if (left < right) { //exit condition = left가 right보다 크면 exit condition 임

		int mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(divide)
		
		//printf("\n  [left] low = %d mid=%d", left, mid);
		merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(conquer)
		
		//printf("\n  [right] mid+1= %d right= %d", mid+1, right);
		merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(conquer)

		//printf("\n  [do merge.] low= %d, mid= %d right= %d", left, mid, right);
		merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(combine)
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
	
	for (int i = 0; i < ASIZE; i++) { // for문 반복횟수 = 정렬할 데이터의 개수
		list[i] = rand() % 1000; // %1000이므로, 백의 자리수로 랜덤변수 
	}

	printf("---전---\n");

	for (int i = 0; i < ASIZE; i++) {
		printf("%d ", list[i]);
	}

	 //합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
	merge_sort(list, 0, ASIZE - 1);

	printf("\n---후---\n");

	// 정렬 결과 출력
	for (int i = 0; i < ASIZE; i++) {
		printf("%d ", list[i]);
	}

	printf("\n");
}

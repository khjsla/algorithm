//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//#define SIZE 100
//
//class T
//{
//private:
//	int binarty_tree[SIZE + 1] = { 0 };
//	int tsize = 0;
//public:
//	void insertion(int val);
//	void deletion(int idx);
//	int search(int val);
//	void print();
//};
//
//int main() {
//	T Tree;
//
//	while (1) {
//		int num;
//		cin >> num;
//		
//		if (num > 0) { 
//			Tree.insertion(num); }
//		else if (num < 0) {
//			num = (-1)*num;
//			int idx = Tree.search(num);
//			if (idx == 0) { 
//				printf("0\n"); }
//			else {
//				printf("%d\n", num);
//				Tree.deletion(idx);
//			}
//		}
//		else if(num ==0) {
//			Tree.print();
//			break;
//		}
//	}
//
//	return 0;
//}
//
//void T::insertion(int val) {
//	int cur = 1; // a¸Ç
//	for (int i = 0; i < 8; i++) {
//		if (binarty_tree[cur] == 0) {
//			binarty_tree[cur] = val;
//			tsize++;
//		}
//		else if (val < binarty_tree[cur]) {  //¿Þ
//			cur = 2 * (cur);
//		}
//		else if (val > binarty_tree[cur]) {  //¿À¸¥
//			cur = 2 * (cur)+1;
//		}
//
//	}
//}
//
//int T::search(int val) {
//	int idx_ = 0;
//
//	for (int i = 1; i < SIZE; i++) {
//		if (binarty_tree[i] == val) {
//			idx_ = i;
//		}
//		else {
//
//		}
//	}
//
//	if (idx_ != 0) {
//		return idx_;
//	}
//	else {
//		return 0;
//	}
//}
//
//void T::deletion(int idx) {
//	binarty_tree[idx] = 0;
//	int left = 2 * (idx), right = 2 * (idx)+1;
//
//	if (binarty_tree[left] == 0 && binarty_tree[right] == 0) return;
//	else if (binarty_tree[right] == 0) {
//		binarty_tree[idx] = binarty_tree[left];
//		deletion(left);
//	}
//	else if (binarty_tree[left] == 0) {
//		binarty_tree[idx] = binarty_tree[right];
//		deletion(right);
//	}
//	else {
//		int rofl, lofr;
//		rofl = 2 * (left)+1;
//		lofr = 2 * (right);
//		if (rofl != 0) {
//			binarty_tree[idx] = binarty_tree[rofl];
//			deletion(rofl);
//		}
//		else if (lofr != 0) {
//			binarty_tree[idx] = binarty_tree[lofr];
//			deletion(lofr);
//		}
//		else {
//			binarty_tree[idx] = binarty_tree[left];
//			deletion(left);
//		}
//	}
//}
//
//void T::print() {
//	for (int i = 1; i < SIZE; i++) {
//		if (binarty_tree[i] != 0) {
//			printf("%d ", binarty_tree[i]);
//		}
//	}
//}
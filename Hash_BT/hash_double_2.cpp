// CPP program to implement double hashing 
#include <iostream> 
#include <stdlib.h>
#include <string>
#include <cstring>
using namespace std;

// Hash table size 
#define TABLE_SIZE 5000 

// Used in second hash function. 
#define PRIME 500

class DoubleHash {
	// Pointer to an array containing buckets 
	int* hashTable;
	int curr_size;

public:
	// function to check if hash table is full 
	bool isFull()
	{

		// if hash size reaches maximum size 
		return (curr_size == TABLE_SIZE);
	}

	// function to calculate first hash 
	int hash1(int key)
	{
		return (key % TABLE_SIZE);
	}

	// function to calculate second hash 
	int hash2(int key)
	{
		return (PRIME - (key % PRIME));
	}

	DoubleHash()
	{
		hashTable = new int[TABLE_SIZE];
		curr_size = 0;
		for (int i = 0; i < TABLE_SIZE; i++)
			hashTable[i] = -1;
	}

	// function to insert key into hash table 
	void insertHash(int key)
	{
		// if hash table is full 
		if (isFull())
			return;

		// get index from first hash 
		int index = hash1(key);

		// if collision occurs 
		if (hashTable[index] != -1) {
			// get index2 from second hash 
			int index2 = hash2(key);
			int i = 1;
			while (1) {
				// get newIndex 
				int newIndex = (index + i * index2) % TABLE_SIZE;

				// if no collision occurs, store 
				// the key 
				if (hashTable[newIndex] == -1) {
					hashTable[newIndex] = key;
					break;
				}
				i++;
			}
		}

		// if no collision occurs 
		else
		hashTable[index] = key;
		curr_size++;
	}

	// function to search key in hash table 
	int search(int key)
	{
		int index1 = hash1(key);
		int index2 = hash2(key);
		int i = 0;
		while (hashTable[(index1 + i * index2) % TABLE_SIZE] != key) {
			if (hashTable[(index1 + i * index2) % TABLE_SIZE] == -1) {
				//cout << "no" << endl;
				return 0;
			}
			i++;
		}
		//cout << "yes" << endl;
		return 1;
	}

	// function to display the hash table 
	void displayHash()
	{
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (hashTable[i] != -1)
				cout << i << " --> "
				<< hashTable[i] << endl;
			else
				cout << i << endl;
		}
	}
};

int getascii(string x) {
	string str = x;
	char cstr[15] = { 0, };
	strcpy(cstr, str.c_str()); //이제 cstr에 각각 알파벳이 삽입되게 됨
	int x_ = 0;
	for (int i = 0; i < 15; i++) {
		x_ = x_ + cstr[i];
	}
	return x_;
}

// Driver's code 
int main()
{
	DoubleHash h; //해시 클래스

	int sizes = 0;
	int finds = 0;
	scanf("%d", &sizes); //테이블 크기
	scanf("%d", &finds); //테이블 크기

	int *numPtr = (int*)malloc(sizeof(int) * sizes);    // (int 크기 * 입력받은 크기)만큼 동적 메모리 할당
	int *numPtr_ = (int*)malloc(sizeof(int) * finds);    // (int 크기 * 입력받은 크기)만큼 동적 메모리 할당

	for (int i = 0; i < sizes; i++)    // 입력받은 크기만큼 반복 //사이즈 크기의 어레이 생성
	{
		string x_;
		cin >> x_;
		int n_ = getascii(x_);
		numPtr[i] = n_;                 // 인덱스로 접근하여 값 할당
	}

    for (int i = 0; i < sizes; i++) { //테이블 크기만큼
		h.insertHash(numPtr[i]); //어레이 크기만큼 해쉬에 저 데이터 넣어주기 //반복되는 만큼 해쉬테이블 크기 생성되는거임
	}
	// searching some keys 

	int cnt = 0;

	for (int i = 0; i < finds; i++)    // 입력받은 크기만큼 반복 //사이즈 크기의 어레이 생성
	{
		string x__;
		cin >> x__; //글자 받음
		int n = getascii(x__);
		numPtr_[i] = n;                 // 인덱스로 접근하여 값 할당
	}
	
	for (int i = 0; i < finds; i++) { //테이블 크기만큼
		cnt = cnt + h.search(numPtr_[i]); //어레이 크기만큼 해쉬에 저 데이터 넣어주기 //반복되는 만큼 해쉬테이블 크기 생성되는거임
	}

	if (cnt == finds) {
		cout << "1";
	}
	else {
		cout << "0";
	}

	free(numPtr);    // 동적으로 할당한 메모리 해제
	free(numPtr_);    // 동적으로 할당한 메모리 해제

	return 0;
}
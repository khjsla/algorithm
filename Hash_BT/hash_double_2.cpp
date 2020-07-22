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
	strcpy(cstr, str.c_str()); //���� cstr�� ���� ���ĺ��� ���Եǰ� ��
	int x_ = 0;
	for (int i = 0; i < 15; i++) {
		x_ = x_ + cstr[i];
	}
	return x_;
}

// Driver's code 
int main()
{
	DoubleHash h; //�ؽ� Ŭ����

	int sizes = 0;
	int finds = 0;
	scanf("%d", &sizes); //���̺� ũ��
	scanf("%d", &finds); //���̺� ũ��

	int *numPtr = (int*)malloc(sizeof(int) * sizes);    // (int ũ�� * �Է¹��� ũ��)��ŭ ���� �޸� �Ҵ�
	int *numPtr_ = (int*)malloc(sizeof(int) * finds);    // (int ũ�� * �Է¹��� ũ��)��ŭ ���� �޸� �Ҵ�

	for (int i = 0; i < sizes; i++)    // �Է¹��� ũ�⸸ŭ �ݺ� //������ ũ���� ��� ����
	{
		string x_;
		cin >> x_;
		int n_ = getascii(x_);
		numPtr[i] = n_;                 // �ε����� �����Ͽ� �� �Ҵ�
	}

    for (int i = 0; i < sizes; i++) { //���̺� ũ�⸸ŭ
		h.insertHash(numPtr[i]); //��� ũ�⸸ŭ �ؽ��� �� ������ �־��ֱ� //�ݺ��Ǵ� ��ŭ �ؽ����̺� ũ�� �����Ǵ°���
	}
	// searching some keys 

	int cnt = 0;

	for (int i = 0; i < finds; i++)    // �Է¹��� ũ�⸸ŭ �ݺ� //������ ũ���� ��� ����
	{
		string x__;
		cin >> x__; //���� ����
		int n = getascii(x__);
		numPtr_[i] = n;                 // �ε����� �����Ͽ� �� �Ҵ�
	}
	
	for (int i = 0; i < finds; i++) { //���̺� ũ�⸸ŭ
		cnt = cnt + h.search(numPtr_[i]); //��� ũ�⸸ŭ �ؽ��� �� ������ �־��ֱ� //�ݺ��Ǵ� ��ŭ �ؽ����̺� ũ�� �����Ǵ°���
	}

	if (cnt == finds) {
		cout << "1";
	}
	else {
		cout << "0";
	}

	free(numPtr);    // �������� �Ҵ��� �޸� ����
	free(numPtr_);    // �������� �Ҵ��� �޸� ����

	return 0;
}
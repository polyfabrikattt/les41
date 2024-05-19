#include <iostream>
#include <string>

using namespace std;

string ToStr(int** matrix, int size);
void SpMatix(int** matrix, int num);

int main() {
	int num;
	do {
		system("cls");
		cout << "Input size of matrix:";
		cin >> num;
	} while (num <= 0);

	int** matrix = new int* [num];
	for (int i = 0; i < num; i++)
		matrix[i] = new int[num];

	SpMatix(matrix, num);

	cout << ToStr(matrix, num);
}

string ToStr(int** matrix, int size) {
	string adj = "";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			adj = adj + to_string(matrix[i][j]) + "\t";
		}
		adj += "\n";
	}
	return adj;
}
void SpMatix(int** matrix, int n) {
	int val= 1;
	for (int layer = 0; layer < (n + 1) / 2; ++layer) {
		int end = n - layer - 1;
		for (int i = layer; i <= end; ++i) matrix[layer][i] = val++;
		for (int i = layer + 1; i <= end; ++i) matrix[i][end] = val++;
		for (int i = end - 1; i >= layer; --i) matrix[end][i] = val++;
		for (int i = end - 1; i > layer; --i) matrix[i][layer] = val++;
	}
}
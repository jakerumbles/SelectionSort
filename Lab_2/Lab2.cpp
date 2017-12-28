// Jake Edwards
// CSC 331-001
// Dr. Ivancic
// Lab 2

#include <iostream>
#include <fstream>

using namespace std;

// args are the memory addresses of a and b, not the values themselves
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int* A, int n) {

	for(int j = 0; j < n - 1; j++) {
		int smallest = j;

		// tests all values after index j against the value at index j.
		// If value at index i is less that value at index j/smallest, swap the
		// two with each other
		for(int i = j + 1; i < n; i++) {
			if (A[i] < A[smallest]) {
				smallest = i;
			}
		}

		swap(A[j], A[smallest]);
	}
}

int main(int argc, char **argv){

	string fileName;
	string path = "/home/courses/cs3311/ProgramFiles/";
	string filePath;

	fileName = argv[1];
	filePath = path + fileName;

	ifstream inputFile(filePath);

	// get first number in file which tells how many lines there are
	int numLines;
	inputFile >> numLines;

	// just to move the file pointer up for "start"
	string trash;
	inputFile >> trash;

	// create a dynamic array.  Array size(numLines) will be determined at runtime
	int *ptr = new int(numLines);
	int A[*ptr];

	// to store each line
	int num;

	// loads each line to num, stores num in A[i], and then prints out A[i]
	for(int i = 0; i < numLines; i++) {
		inputFile >> num;
		A[i] = num;
		cout << A[i] << ", ";
	}

	// close the input file stream, inputFile
	inputFile.close();
	cout << "\n\n";

	// sort the array in ascending order using Selection Sort algorithm
	selectionSort(A, numLines);

	// print out sorted array
	for (int i = 0; i < numLines; i++) {
		cout << A[i] << ", ";
	}

	return 0;
}

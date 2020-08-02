#include <iostream>
#include <cmath>

//È÷Áö

using namespace std;


int Calculator(int* nArray, char* tArray, int* pindex);
void fPlus(int* p1, int* p2);
void fMinus(int* p1, int* p2);
void fTimes(int* p1, int* p2);
void fDivide(int* p1, int* p2);

int main()
{
	int narr[200] = { 0 }, result = 0, max_index = 0;
	char input[200];

	cout << "This program is calculator. Follow the instructions." << endl;
	cout << endl;



	for (int i = 0; ; i++) {
		cout << "Enter a number : ";
		cin >> narr[i];
		cout << "Enter calculate type : ";
		cin >> input[i];
		max_index = i;
		if (input[i] == '=') {
			break;
		}
	}



	result = Calculator(narr, input, &max_index);


	cout << endl;
	cout << "result = " << result << endl;





	return 0;
}

int Calculator(int* nArray, char* tArray, int* pindex) {


	int value = nArray[0];

	for (int i = 0; i < *pindex; ++i) {

		switch (tArray[i]) {
		case '+':
			fPlus(&value, nArray + i + 1);
			break;
		case '-':
			fMinus(&value, nArray + i + 1);
			break;
		case '*':
			fTimes(&value, nArray + i + 1);
			break;
		case '/':
			fDivide(&value, nArray + i + 1);
			break;
		}

	}


	return value;
}
void fPlus(int* p1, int* p2)
{
	(*p1) += (*p2);
}
void fMinus(int* p1, int* p2)
{
	(*p1) -= (*p2);
}
void fTimes(int* p1, int* p2)
{
	(*p1) *= (*p2);
}
void fDivide(int* p1, int* p2)
{
	(*p1) /= (*p2);
}

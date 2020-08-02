#include <iostream>
#include <cmath>
#include <ctime>

//����

using namespace std;

void save_Bignum(int* parr, int size);
void input_8digits(int x, int* parr, int index, int digit);
int Form_Backward(int* parr, int max_index, int size);
void get_CalcType(char* ptype);
int calc_arr(int* parr1, char calc, int* parr2, int* parr3, int size);
int fPlus(int* parr1, int* parr2, int* parr3, int size);
int fMinus(int* parr1, int* parr2, int* parr3, int size);
int fTimes(int* parr1, int* parr2, int* parr3, int size);
int fDivide(int* parr1, int* parr2, int* parr3, int size);
int fPlus_forTimes(int* parr1, int* parr3, int size);

int main()
{
	int nArray1[1000] = { 0 };
	int nArray2[1000] = { 0 };
	int nArray3[1000] = { 0 };
	char calctype;

	cout << "This program calculates about BIG number" << endl;
	cout << size(nArray1) << "�ڸ� ���� ���� ������ ������ �����մϴ�." << endl;
	cout << "(����1) (����) (����2)�� ����� �����մϴ�." << endl;
	cout << "��, �տ������� �ִ� 8�ڸ��� �Է��ϰ�, ��� ���� �Է��� �������� -1�� �Է����ּ���." << endl;

	save_Bignum(nArray1, sizeof(nArray1) / 4);
	get_CalcType(&calctype);
	save_Bignum(nArray2, sizeof(nArray2) / 4);
	clock_t t1 = clock();

	calc_arr(nArray1, calctype, nArray2, nArray3, sizeof(nArray1) / 4);

	cout << "number[3] = ";
	int count = 0;
	for (int i = 0; i < 1000; i++) {
		if (nArray3[i] != 0) {
			count++;
		}
		if (count > 0) {
			cout << nArray3[i];
		}
	}
	cout << endl;

	cout << "nArray3[997]=" << nArray3[997] << "nArray3[998]=" << nArray3[998] << "nArray3[999]=" << nArray3[999] << endl;
	clock_t t2 = clock();
	clock_t t = t2 - t1;
	cout << "Time : " << t << "ms" << endl;
	return 0;
}

void save_Bignum(int* parr, int size) // �迭�� ���������ϰ� ū �ڸ��� ���� �� ���ھ� ����ִ´�. ó���� 123450'00�÷� �ְ�, Form_Backward���� 00123450 �÷� �ٲ���. �ִ� 8�ڸ����� �Է°���.
{
	int x = 0, digit = 0, max_index = 0;

	for (int i = 0; ; i += 8) {
		cout << "Enter maximum 8 digits : ";
		cin >> x;
		if (x == -1) {
			break;
		}
		cout << "How many digit it is?" << endl;
		cin >> digit;
		input_8digits(x, parr, i, digit);
		max_index = i + digit - 1;
	}
	//cout << "max_index=" << max_index << endl;
	Form_Backward(parr, max_index, size);
}

void input_8digits(int x, int* parr, int index, int digit)
{
	for (int i = index + digit - 1; i >= index; i--) {
		parr[i] = x % 10;
		x = (x - parr[i]) / 10;
	}
}

int Form_Backward(int* parr, int max_index, int size) // 123450'00�� 00123450�� �������.
{
	int distance = (size - 1) - max_index; // distance�� �迭�� �Ǹ����� �ε����� max �ε����� ������.
	//cout << "distance=" << distance << endl;
	for (int i = (size - 1); i - distance >= 0; i--) {
		parr[i] = parr[i - distance];
	}
	for (int i = 0; i < distance; i++) {
		parr[i] = 0;
	}

	return 0;
}

void get_CalcType(char* ptype)
{
	cout << "Enter Caculation Type : ";
	cin >> *ptype;
}

int calc_arr(int* parr1, char calc, int* parr2, int* parr3, int size)
{
	switch (calc)
	{
	case '+':
		fPlus(parr1, parr2, parr3, size);
		break;
	case '-':
		fMinus(parr1, parr2, parr3, size);
		break;
	case '*':
		fTimes(parr1, parr2, parr3, size);
		break;
	case '/':
		fDivide(parr1, parr2, parr3, size);
		break;
	}

	return 0;
}

int fPlus(int* parr1, int* parr2, int* parr3, int size)
{
	for (int i = 0; i < size; i++) {
		parr3[i] = parr1[i];
	}

	for (int i = 0; i < size; i++) {
		parr3[i] += parr2[i];
	}

	for (int i = size - 1; i > 0; i--) {
		parr3[i - 1] += parr3[i] / 10;
		parr3[i] = parr3[i] % 10;
	}

	return 0;
}

int fMinus(int* parr1, int* parr2, int* parr3, int size)
{
	for (int i = 0; i < size; i++) {
		parr3[i] = (parr1[i] - parr2[i]);
	}
	for (int i = size - 1; i >= 0; i--) {
		if (parr3[i] < 0) {
			parr3[i] += 10;
			parr3[i - 1] -= 1;
		}
	}

	return 0;
}

int fTimes(int* parr1, int* parr2, int* parr3, int size)
{
	int N = 0;
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (parr2[i] != 0) {
			count++;
		}
		if (count > 0) {
			N += parr2[i] * pow(10, size - 1 - i);
		}
	}

	cout << "N : " << N << endl;

	for (int i = 1; i <= N; i++) {
		fPlus_forTimes(parr1, parr3, size);
	}

	return 0;
}

int fDivide(int* parr1, int* parr2, int* parr3, int size)
{

	return 0;
}

int fPlus_forTimes(int* parr1, int* parr3, int size)
{
	for (int i = 0; i < size; i++) {
		parr3[i] += parr1[i];
	}

	for (int i = size - 1; i > 0; i--) {
		parr3[i - 1] += parr3[i] / 10;
		parr3[i] = parr3[i] % 10;
	}

	return 0;
}
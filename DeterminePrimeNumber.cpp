#include <iostream>

using namespace std;

bool IsEven(int x)
{
	if (x % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool IsTri(int x)
{
	if (x % 3 == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool IsPent(int x)
{
	if (x % 5 == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool IsPrime(int x)
{
	int count = 0;

	for (int i = 7; i <= (x / 7); i += 2) {
		if (x % i == 0) {
			count++;
		}
	}

	if (count == 0) {
		//�Ҽ���� ��..!
		return true;
	}
	else {
		//��Ҽ���� ��
		return false;
	}
}



int main()
{
	int x;
	cout << "This is Prime Number Determinator. Enter Any Integer. : ";
	cin >> x;

	if(IsEven(x) == true) {
		//¦����
		cout << "Not Prime Number. (It's 2N)" << endl;
		goto END;
	}
	else {
		//Ȧ����
		goto A; //A�� �� ���� �Ǻ���.
	}
	
A:

	if (IsTri(x) == true) {
		//3�� �����
		cout << "Not Prime Number. (It's 3N)" << endl;
		goto END;
	}
	else {
		//3�� ��� �ƴ�
		goto B; //B�� �� ���� �Ǻ���.
	}

B:

	if (IsPent(x) == true) {
		//5�� �����
		cout << "Not Prime Number. (It's 5N)" << endl;
		goto END;
	}
	else {
		//5�� ����� �ƴ�
		goto C; //���� ��¥ �Ǻ��� ���ߵ�
	}

C:
	if (IsPrime(x) == true) {
		//�Ҽ���
		cout << "It's a Prime Number." << endl;
	}
	else {
		cout << "Not Prime Number." << endl;
	}



END:

	return 0;
}
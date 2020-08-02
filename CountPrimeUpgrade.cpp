#include <iostream>
#include <cmath>

//����

using namespace std;

int sum_1toN(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

bool IsPrime(int n)
{
	//2���� n-1���� 1ĭ���� mod�� ���ؼ�
	// 0 �� �ϳ��� ������ false,
	// 0 �� �ѹ��� �� ������ true.

	//��������
	//case1. n<=1
	//return false.
	//case2. n=2
	//return true.
	//case3. �� ��
	//3���� n-1���� 2ĭ���� mod�� ���ؼ�
	// 0 �� �ϳ��� ������ false,
	// 0 �� �ѹ��� �� ������ true.

	if (n == 1) {
		return false;
	}
	else if (n == 2) {
		return true;
	}

	for (int i = 3; i < n; i += 2) {
		if (fmod(n, i) == 0) {
			return false;
		}
	}
	return true;
}

int CountPrime(int n)
{

	// 2���� n���� 1ĭ���� IsPrime�� ���� ���ؼ�
	// IsPrime�� true�� ������ �� ���� ����ϰ�,
	// count�� 1 �÷���.
	// ���� IsPrime�� false�� ������ �ƹ��͵� ����.
	// �׸��� �������� count�� ��ȯ����.
	// �װ� (N������ �Ҽ��� �����ϱ�)

	//��������
	//case1. n=1
	// return 0;
	//case2. n=2
	// 2����ϰ�, return 1;
	//case3. �� ��
	// 3���� n���� 2ĭ���� IsPrime�� ���� ���ؼ�
	// IsPrime�� true�� ������ �� ���� ����ϰ�,
	// count�� 1 �÷���.
	// ���� IsPrime�� false�� ������ �ƹ��͵� ����.
	// �׸��� �������� count�� ��ȯ����.
	// �װ� (N������ �Ҽ��� �����ϱ�)

	if (n == 1) {
		return 0;
	}
	else if (n == 2) {
		cout << "Prime Number : " << 2 << endl;
		return 1;
	}

	int count = 1;

	cout << "Prime Number : " << 2 << endl;

	for (int i = 3; i <= n; i += 2) {
		if (IsPrime(i) == true) {
			cout << "Prime Number : " << i << endl;
			count++;
		}
	}

	return count;
}

int main()
{
	int N;
	cout << "Enter N : " << endl;
	cin >> N;
	int a = 0;
	a = sum_1toN(N);

	//cout << a << endl;

	a = CountPrime(N);

	cout << a << endl;

	//N=100000 �־��� �� �� 35��. (������ ���� 17�� ����)

	return 0;
}
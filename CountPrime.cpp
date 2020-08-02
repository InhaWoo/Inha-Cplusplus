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

	

	for (int i = 2; i < n; i++) {
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


	int count = 0;


	for (int i = 2; i <= n; i++) {
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
	
	// N=100000�� ���������� �� 52��.

	return 0;
}
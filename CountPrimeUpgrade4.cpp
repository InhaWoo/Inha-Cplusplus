#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

//����

using namespace std;

int p[10000000] = { 2 };

int a = 0;

bool IsPrime(int n)
{
	if (n == 1) { //1�� �Ҽ��ƴ�
		return false;
	}
	else if (n == 2 || n==3 || n==5) { //2,3,5�� �Ҽ���
		return true;
	}
	else if (fmod(n,2)==0 || fmod(n, 3) == 0 || fmod(n, 5) == 0) { //2,3,5�������
		return false;
	}
	//�� ��������� �� ���忡 ���� �ɷ��������� �Ѱ���



	/////******���� ����******/////

	// for���� ���� n�� ��� �ϳ��� ������ �ִµ�,
	// �� n�� �Ҽ����� true/false �Ǵ��ؾߵ�

	// ���� ���� �ֵ��� 6k-1, 6k+1 ����
	//( ��, n+1 % 6 = 0�̰ų� n-1 % 6 =0�� �ֵ��� ���ٴ� ��)
	
	for (int j = 0; j <= a && p[j] <= sqrt(n); j++) { //��Ե� ���̷��� ������ �׽�Ʈ
		if (fmod(n, p[j]) == 0) return false;
	}
	//�� �׽�Ʈ�� ����ϸ� prime number��� ����Ʈ�� �����޾Ƽ� prime�̶�� �迭 p�� �̸��� �÷���
	a++;
	p[a] = n;
	return true;

}

int CountPrime(int n)
{

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

	//cout << "Prime Number : " << 2 << endl;

	for (int i = 3; i <= n; i += 2) {//100000���Ͽ� �Ҽ��� ��ΰ�?
		if (IsPrime(i) == true) {
			//cout << "Prime Number : " << i << endl;
			count++;
			//cout << "Program is counting Number of Prime Numbers below : " << n;
			//cout << ", count : " << count << endl;
		}
	}

	return count;
}

int main()
{
	int N=100000;
	//cout << "Enter N : " << endl;
	//cin >> N;
	clock_t StartTime = clock();
	int a;
	cout << "Program is counting Number of Prime Numbers below : " << N;
	
	a = CountPrime(N);

	cout << "Number of Prime Numbers : " << a << endl;

	//N=100000 �־��� �� �� ��. (��½� �� ��.)
	clock_t EndTime = clock();
	clock_t elapsed = EndTime - StartTime;
	cout << "Executed Time : " << elapsed << "ms" << endl;
	return 0;
}
#include <iostream>
#include <cmath>

//히지

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
	//2부터 n-1까지 1칸마다 mod를 구해서
	// 0 이 하나라도 나오면 false,
	// 0 이 한번도 안 나오면 true.

	//수정방향
	//case1. n<=1
	//return false.
	//case2. n=2
	//return true.
	//case3. 그 외
	//3부터 n-1까지 2칸마다 mod를 구해서
	// 0 이 하나라도 나오면 false,
	// 0 이 한번도 안 나오면 true.

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

	// 2부터 n까지 1칸마다 IsPrime의 값을 구해서
	// IsPrime이 true가 나오면 그 수를 출력하고,
	// count도 1 늘려줌.
	// 만약 IsPrime이 false가 나오면 아무것도 안함.
	// 그리고 마지막에 count를 반환해줌.
	// 그게 (N까지의 소수의 개수니깐)

	//수정방향
	//case1. n=1
	// return 0;
	//case2. n=2
	// 2출력하고, return 1;
	//case3. 그 외
	// 3부터 n까지 2칸마다 IsPrime의 값을 구해서
	// IsPrime이 true가 나오면 그 수를 출력하고,
	// count도 1 늘려줌.
	// 만약 IsPrime이 false가 나오면 아무것도 안함.
	// 그리고 마지막에 count를 반환해줌.
	// 그게 (N까지의 소수의 개수니깐)

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

	//N=100000 넣었을 때 약 35초. (이전에 비해 17초 단축)

	return 0;
}
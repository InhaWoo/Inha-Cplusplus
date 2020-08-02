#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

//히지

using namespace std;

int p[10000000] = { 2 };

int a = 0;

bool IsPrime(int n)
{
	if (n == 1) { //1은 소수아님
		return false;
	}
	else if (n == 2 || n==3 || n==5) { //2,3,5는 소수임
		return true;
	}
	else if (fmod(n,2)==0 || fmod(n, 3) == 0 || fmod(n, 5) == 0) { //2,3,5배수죽임
		return false;
	}
	//자 여기까지는 좀 초장에 많이 걸러놓을려고 한거임



	/////******이제 본론******/////

	// for문에 의해 n이 계속 하나씩 들어오고 있는데,
	// 그 n이 소수인지 true/false 판단해야됨

	// 현재 남은 애들은 6k-1, 6k+1 꼴임
	//( 즉, n+1 % 6 = 0이거나 n-1 % 6 =0인 애들은 갔다는 뜻)
	
	for (int j = 0; j <= a && p[j] <= sqrt(n); j++) { //어떻게든 죽이려는 일종의 테스트
		if (fmod(n, p[j]) == 0) return false;
	}
	//그 테스트를 통과하면 prime number라는 엘리트로 인정받아서 prime이라는 배열 p에 이름을 올려줌
	a++;
	p[a] = n;
	return true;

}

int CountPrime(int n)
{

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

	//cout << "Prime Number : " << 2 << endl;

	for (int i = 3; i <= n; i += 2) {//100000이하에 소수가 몇개인가?
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

	//N=100000 넣었을 때 약 초. (출력시 약 초.)
	clock_t EndTime = clock();
	clock_t elapsed = EndTime - StartTime;
	cout << "Executed Time : " << elapsed << "ms" << endl;
	return 0;
}
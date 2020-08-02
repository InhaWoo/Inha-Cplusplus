#include <iostream>
#include <cmath>
#include <ctime>

//히지

using namespace std;

int p[10000000] = { 2 };

int a = 0;

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
	//7부터 n-1까지 2칸마다 mod를 구해서
	// 0 이 하나라도 나오면 false,
	// 0 이 한번도 안 나오면 true.

	/*수정방향2

	소수를 저장하는 배열을 만든다.
	배열의 이름은 p.
	크기는..음... p[10000]크기로 만든다
	일단 소수 2는 좀 빡치니까 p[0]=2 저장해줌
	for문에서 단한번도 false를 만들어내지않은 수를
	p[1], p[2], p[3], ... 에 저장해준다.
	p[1]부터 p[X]까지 비교하는 식으로 한다.
	긍까 예를 들어서 13이 소수인지 체크하고싶다 그러면
	그동안 소수로 나왔던 애들 3, 5, 7, 11로만 체크하는거임
	3,5,7,9,11로 체크하는게 아니고 ㅇㅇ

	지금까지 배열을 채운 칸의 수를 a라 하자.
	즉, 맨처음엔 a=0인거임
	자 이제 3이 소수인지 판별할거임
	배열의 제일 첫째칸부터 제일 마지막까지 3 mod p[a]를 구하자.
	(지금은 3%2만 보는거임)
	제일 처음~제일 마지막까지 했는데 mod==0 한번도 안나옴.
	그러면 a를 1 늘려서 a=1로 만들어주고,
	p[a]에다가 3을 넣는거임. (즉, p[1]=3)
	자 이제 5가 소수인지 판별할거임
	배열의 제일 첫째칸부터 제일 마지막까지 5 mod p[a]를 구하자.
	(지금은 5%2, 5%3 보는거임)
	제일 처음~제일 마지막까지 했는데 mod==0 한번도 안나옴.
	그러면 a를 1 늘려서 a=2로 만들어주고,
	p[a]에다가 5을 넣는거임. (즉, p[2]=5)
	자 이제 7이 소수인지 판별할거임
	배열의 제일 첫째칸부터 제일 마지막까지 7 mod p[a]를 구하자.
	(지금은 7%2, 7%3, 7%5 보는거임)
	제일 처음~제일 마지막까지 했는데 mod==0 한번도 안나옴.
	그러면 a를 1 늘려서 a=3으로 만들어주고,
	p[a]에다가 7을 넣는거임. (즉, p[3]=7)
	자 이제 9가 소수인지 판별할거임
	배열의 제일 첫째칸부터 제일 마지막까지 9 mod p[a]를 구하자.
	(지금은 9%2, 9%3, 9%5, 9%7 보는거임)
	제일 처음~제일 마지막까지 했는데 mod==0이 9%3에서 뜸.
	그럼 아무일도 안 일어남. 그리고 continue함.

	자 이제 11이 소수인지 판별할거임
	.....

	이런식으로!

	*/


	if (n == 1) {
		return false;
	}
	// 루트N까지만 비교함. 그렇게 해도 됨.
	for (int j = 0; j <= a && p[j] <= sqrt(n); j++) { //어떻게든 죽이려는 일종의 테스트
		if (fmod(n, p[j]) == 0) return false;
	}
	//그 테스트를 통과하면 prime number라는 elite로 인정받아서 prime 배열에 이름을 올려줌
	a++;
	p[a] = n;
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
		//cout << "Prime Number : " << 2 << endl;
		return 1;
	}

	int count = 1;

	//cout << "Prime Number : " << 2 << endl;

	for (int i = 3; i <= n; i += 2) {
		if (IsPrime(i) == true) {
			//cout << "Prime Number : " << i << endl;
			count++;
			//cout << "Count : " << count << endl;
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
	cout << "Program is counting Number of Prime Numbers below : " << N << endl;
	int a;

	a = CountPrime(N);

	cout << "Number of Prime Numbers : " << a << endl;

	//N=100000 넣었을 때 약 0.1초. (출력시 약 19초.)
	clock_t EndTime = clock();
	clock_t elapsed = EndTime - StartTime;
	cout << "Executed Time : " << elapsed << "ms" << endl;
	return 0;
}
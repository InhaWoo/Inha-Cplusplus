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
		//소수라는 뜻..!
		return true;
	}
	else {
		//비소수라는 뜻
		return false;
	}
}



int main()
{
	int x;
	cout << "This is Prime Number Determinator. Enter Any Integer. : ";
	cin >> x;

	if(IsEven(x) == true) {
		//짝수임
		cout << "Not Prime Number. (It's 2N)" << endl;
		goto END;
	}
	else {
		//홀수임
		goto A; //A는 그 다음 판별기.
	}
	
A:

	if (IsTri(x) == true) {
		//3의 배수임
		cout << "Not Prime Number. (It's 3N)" << endl;
		goto END;
	}
	else {
		//3의 배수 아님
		goto B; //B는 그 다음 판별기.
	}

B:

	if (IsPent(x) == true) {
		//5의 배수임
		cout << "Not Prime Number. (It's 5N)" << endl;
		goto END;
	}
	else {
		//5의 배수가 아님
		goto C; //이제 진짜 판별기 가야됨
	}

C:
	if (IsPrime(x) == true) {
		//소수임
		cout << "It's a Prime Number." << endl;
	}
	else {
		cout << "Not Prime Number." << endl;
	}



END:

	return 0;
}
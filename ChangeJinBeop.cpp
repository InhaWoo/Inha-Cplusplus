#include <iostream>
#include <cmath>
#include <ctime>

//히지

using namespace std;

void JinBeopChange(int* num, int before_num, int after_num);

int main()
{
	int N, n1, n2;
	cout << "This program changes 'JinBeop'" << endl;
	cout << "Enter a number : ";
	cin >> N;
	cout << "Which 'JinBeop' is this number?" << endl;
	cin >> n1;
	cout << "To which 'JinBeop' do you want to change?" << endl;
	cin >> n2;

	clock_t StartTime = clock();

	cout << "Before : " << N << "_(" << n1 << ")" << endl;

	JinBeopChange(&N, n1, n2);

	cout << "After : " << N << "_(" << n2 << ")" << endl;

	clock_t EndTime = clock();
	clock_t elapsed = EndTime - StartTime;
	cout << "Executed Time : " << elapsed << "ms" << endl;


	return 0;
}

void JinBeopChange(int* num, int before_jinbeop, int after_jinbeop) {

	int n = 0;		//*num(a진법)을 n(10진법)으로 만들고, n(10진법)을 *num(b진법)으로 만들것임
	int Save_Before_digits[100] = { 0 };
	int x = *num;	//x는 진법을 변환할 때, 어떤 숫자들을 임시로 저장할 떄 사용될 것임.
	int max_index1 = 0;

	for (int i = 0; x != 0; i++) {
		Save_Before_digits[i] = x % 10;
		x = ((x - Save_Before_digits[i]) / 10);
		max_index1 = i;
	}		// 만약 처음 수가 11101010_(2)였으면 Save_Before_digits배열 안에 저장될때는 01010111 이렇게 들어감, max_index1 = 3.
			// x=0이 됐음

	for (int i = 0; i <= max_index1; i++) {
		n += Save_Before_digits[i] * (pow(before_jinbeop, i));
	}		//이제 *num(a진법)을 n(10진법)으로 바꿔냈음



	//이제 n(10진법)을 *num(b진법)으로 바꿔야함


	int max_index2 = 0;
	int Save_After_digits[100] = { 0 }; //이거 오류메세지 하도 뜨길래 그냥 ={0}해놨는데 문제생기면 바로 지우셈


	/*for (int i = 0; n != 0; i++) {
		Save_After_digits[i] = n % after_jinbeop; // n=234였다치면 Save_after_digits에는 3 5 4 이렇게 저장됨 (참고로 453_(7) = 234)
		n /= after_jinbeop;
		max_index2 = i;
	} // 453_(7)이면 max_index2 = 2가 됨

	for (int i = 0; i <= max_index2; i++) {
		x += Save_After_digits[i] * (pow(10, i)); //x는 453_(10)이 됐음.
	}*/

	//11101010_(2)를 7진법으로 변환하니 453_(7)로 변환 잘 됨. 실제로 두 수는 234임(10진법으로 변환 시).

	*num = x;

}
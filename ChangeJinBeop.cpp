#include <iostream>
#include <cmath>
#include <ctime>

//����

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

	int n = 0;		//*num(a����)�� n(10����)���� �����, n(10����)�� *num(b����)���� �������
	int Save_Before_digits[100] = { 0 };
	int x = *num;	//x�� ������ ��ȯ�� ��, � ���ڵ��� �ӽ÷� ������ �� ���� ����.
	int max_index1 = 0;

	for (int i = 0; x != 0; i++) {
		Save_Before_digits[i] = x % 10;
		x = ((x - Save_Before_digits[i]) / 10);
		max_index1 = i;
	}		// ���� ó�� ���� 11101010_(2)������ Save_Before_digits�迭 �ȿ� ����ɶ��� 01010111 �̷��� ��, max_index1 = 3.
			// x=0�� ����

	for (int i = 0; i <= max_index1; i++) {
		n += Save_Before_digits[i] * (pow(before_jinbeop, i));
	}		//���� *num(a����)�� n(10����)���� �ٲ����



	//���� n(10����)�� *num(b����)���� �ٲ����


	int max_index2 = 0;
	int Save_After_digits[100] = { 0 }; //�̰� �����޼��� �ϵ� �߱淡 �׳� ={0}�س��µ� ��������� �ٷ� �����


	/*for (int i = 0; n != 0; i++) {
		Save_After_digits[i] = n % after_jinbeop; // n=234����ġ�� Save_after_digits���� 3 5 4 �̷��� ����� (����� 453_(7) = 234)
		n /= after_jinbeop;
		max_index2 = i;
	} // 453_(7)�̸� max_index2 = 2�� ��

	for (int i = 0; i <= max_index2; i++) {
		x += Save_After_digits[i] * (pow(10, i)); //x�� 453_(10)�� ����.
	}*/

	//11101010_(2)�� 7�������� ��ȯ�ϴ� 453_(7)�� ��ȯ �� ��. ������ �� ���� 234��(10�������� ��ȯ ��).

	*num = x;

}
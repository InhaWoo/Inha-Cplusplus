#include <iostream>
#include <cmath>

//10���� ���� �Է¹ް�, �װ� �������� ������

using namespace std;

int main()
{
	int s[10];


	for (int i = 0; i < 10; i++) {
		cout << "Enter score : ";
		cin >> s[i];
	}

	int count = 0;
	//s[0~9]�� �ִ� �ֵ��߿��� max���� ����ϰ�,
	//���� �� s[5]�� max������ s[5]�� ����ϰ�,
	//s[5]=0�̶�� �ٲٰ� �ٽ� s[0~9]�߿��� max�� ���
	//�׷� max�� ���� ��� �ƴ���?
	//�ϴ� max=s[1]�̶� �ϰ�,
	//if (s[j]>=max) max=s[j]; �� ����
	for (; count != 10;) {

		int max = s[0];

		for (int j = 0; j < 10; j++) {
			if (s[j] >= max) {
				max = s[j];
			}
		}

		cout << max << endl;

		for (int k = 0; k < 10; k++) {
			if (s[k] == max) {
				s[k] = 0;
				count++;
				break;
			}
		}
	}




	return 0;
}
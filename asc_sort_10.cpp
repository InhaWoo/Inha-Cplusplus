#include <iostream>
#include <cmath>

//10개의 수를 입력받고, 그걸 오름차순 정렬함

using namespace std;

int main()
{
	int s[10];


	for (int i = 0; i < 10; i++) {
		cout << "Enter score : ";
		cin >> s[i];
	}

	int count = 0;
	//s[0~9]에 있는 애들중에서 max값을 출력하고,
	//예를 들어서 s[5]가 max였으면 s[5]를 출력하고,
	//s[5]=0이라고 바꾸고 다시 s[0~9]중에서 max값 출력
	//그럼 max가 뭔지 어떻게 아느냐?
	//일단 max=s[1]이라 하고,
	//if (s[j]>=max) max=s[j]; 라 하자
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
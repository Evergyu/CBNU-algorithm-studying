#include <iostream>
#include <string>

using namespace std;


void hanoi(int n,int from, int by, int to) {
	if (n == 1) {
		cout << from << " " << to << "\n";//movedisk
	}
	else {
		hanoi(n - 1, from, to, by);	//���� n-1���� 1���� 3������ 2�� �ű��
		cout << from << " " << to << "\n";//1���� ������ 1���� 3���� �ű�
		hanoi(n - 1, by, from, to);	//2�� �ִ� ���� n-1�� 3���� �Ű���
	}
}

int main() {

	int k;
	cin >> k;
	string answer;
	answer = to_string(pow(2, k));
	int idx = answer.find('.');
	answer = answer.substr(0, idx);
	answer[answer.length() - 1] -= 1;
	cout << answer;

	cout << answer<<"\n";
	if (k <= 20) {
		hanoi(k, 1, 2, 3);
	}


	return 0;
}



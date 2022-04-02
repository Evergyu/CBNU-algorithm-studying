/*
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200002
using namespace std;

bool visited[MAX];

bool cmp(pair<int, int> a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}

	return a.second < b.second;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int j = 0;
	int visitcount = 0;
	int count = 0;
	int n;
	cin >> n;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end(), cmp);




	while (true) {
		if (visitcount == n)
			break;

		int start = v[j].first;
		int end = v[j].second;
		visited[j] = true;
		visitcount++;
		count++;

		for (int i = 1; i < n; i++) {
			if (end == v[i].first && !visited[i]) {
				start = v[i].first;
				end = v[i].second;
				visited[i] = true;
				visitcount++;
			}
		}

		j++;
	}

	cout << count;

	return 0;
}
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;	//�������� �켱������ �ȴ�

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}

	sort(v.begin(), v.end());
	pq.push(v[0].second);	//ù��° ���� ����ð� pq�� ����
	for (int i = 1; i < n; i++) {	//�ʿ��� ���ǽ� Ž��
		pq.push(v[i].second);	//i��° ���� ����ð� pq�� ����

		if (pq.top() <= v[i].first) {
			pq.pop();
		}

	}
	cout << pq.size();
	return 0;
}
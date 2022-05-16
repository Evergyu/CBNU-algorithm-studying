// ȸ�ǽ� ���� �˰��� (�׸���, �켱���� ť)
// ����, ���ð� pair �̿��ؼ� �Է¹��� 
// sort(���۽ð� ��������) ���� ����  
// ���� �ð��ϋ� ������ �ð� �������� ����

#include <iostream>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

typedef pair <int, int> intpair;

int main()

{
	int cnt = 0;
	int n;
	cin >> n;
	intpair* v = new intpair[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i].first, v[i].second; // ȸ�� ���۽ð� ���ð����� n�� �Է¹���
	}
	sort(v, v + n + 1);
	priority_queue<int, vector<int>, greater<int>>pq; // �켱���� ť�� ����ؼ� ����
	pq.push(v[0].second); //������ �����ϱ�, �� ó�������� �ð��� �ִ´�.

	int start, end;
	for (int i = 1; i <= n; i++)
	{
		start = v[i].first;
		end = v[i].second;
		if (pq.top() > start)
		{
			pq.push(end);
		}	//�������� ���ǽ��� ������ �ð� > ���� ���� ���۽ð� => ���ǽ� �߰�
		else
		{
			pq.pop();	// �ƴϸ� ��
			pq.push(end);
		}
	}
	cout << pq.size() << endl;
	return 0;
}
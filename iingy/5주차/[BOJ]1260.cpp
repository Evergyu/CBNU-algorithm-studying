//Baekjoon 1260 DFS and BFS
//Not solved, copied

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int v, e, startNum;
vector<int> vec[1001];   // ��������Ʈ
bool check[1001];        // check�迭
void dfs(int x);
void bfs(int x);

int main()
{
    /*������ ����, ������ ����, Ž������ ������ ��ȣ �Է¹ޱ�*/
    cin >> v >> e >> startNum;

    /*�Է��� �޾� ��������Ʈ �����*/
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        // �־��� ������ ������̶�� �Ͽ����Ƿ�
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    /*���� ��ȣ�� ������ �湮�� �� �ֵ��� ��������Ʈ�� �����������*/
    for (int i = 1; i <= v; i++)
        sort(vec[i].begin(), vec[i].end());

    /*��������Ʈ�� �̿��ؼ� DFS, BFSŽ���ϱ�*/
    dfs(startNum);
    cout << "\n";

    memset(check, false, sizeof(check));

    bfs(startNum);
    cout << "\n";
}

void dfs(int x) {
    cout << x << " ";
    check[x] = true;

    for (int i = 0; i < vec[x].size(); i++) {
        int y = vec[x][i];
        if (check[y] == false)
            dfs(y);
    }
}

void bfs(int x) {
    queue<int> q;

    q.push(x);
    check[x] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for (int i = 0; i < vec[currentNode].size(); i++) {
            int y = vec[currentNode][i];
            if (check[y] == false) {
                q.push(y);
                check[y] = true;
            }
        }
    }
}
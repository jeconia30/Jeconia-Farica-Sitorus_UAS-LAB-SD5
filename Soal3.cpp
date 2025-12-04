#include <iostream>
#include <vector>
using namespace std;

vector<int> adjList[2000];
int depth[2000];
bool visited[2000];

void dfs(int node, int d) {
    visited[node] = true;
    depth[node] = d;

    for (int child : adjList[node]) {
        if (!visited[child]) {
            dfs(child, d + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> manager(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> manager[i];
        if (manager[i] != -1) {
            adjList[manager[i]].push_back(i);
        }
    }

    int answer = 1;

    for (int i = 1; i <= n; i++) {
        if (manager[i] == -1) {
            dfs(i, 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        answer = max(answer, depth[i]);
    }

    cout << answer << endl;

    return 0;
}
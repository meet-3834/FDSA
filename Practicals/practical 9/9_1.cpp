#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;
    cout << node << " ";

    for (int x : adj[node]) {
        if (!vis[x])
            DFS(x, adj, vis);
    }
}

void BFS(int start, vector<int> adj[], int n) {
    vector<int> vis(n, 0);
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int x : adj[node]) {
            if (!vis[x]) {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    vector<int> vis(n, 0);

    cout << "DFS: ";
    DFS(start, adj, vis);

    cout << "\nBFS: ";
    BFS(start, adj, n);

    return 0;
}

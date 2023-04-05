#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100000;

vector<int> adj[MAXN];  // adjacency list
bool vis[MAXN];         // visited array

void dfs(int u) {
    vis[u] = true;      // mark current node as visited
    cout << u << " ";   // print current node
    for (int v : adj[u]) {
        if (!vis[v]) {  // if adjacent node is not visited
            dfs(v);     // recursive call dfs for the adjacent node
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;      // read number of nodes and edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;  // read edge u -> v
        adj[u].push_back(v);
        adj[v].push_back(u);  // add undirected edge
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {  // if node is not visited
            dfs(i);     // call dfs for the node
        }
    }
    return 0;
}

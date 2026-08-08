#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> state;
vector<int> in_degree;   
vector<int> ans;
bool has_cycle = false;
void dfs(int u) {
    state[u] = 1;
    for (int v : adj[u]) {
        if (state[v] == 1) {
            cout << "NO\n";
            exit(0);
        }
        if (state[v] == 0) {
            dfs(v);
        }
    }

    state[u] = 2;      
    ans.push_back(u);
  }

int main() {
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    state.assign(n + 1, 0);
    in_degree.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }
    vector<int> zero_in;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            zero_in.push_back(i);
        }
    }
    if (zero_in.size() != 1) {
        cout << "NO\n";
        return 0;
    }
    dfs(zero_in[0]);
    if (ans.size() != n) {
        cout << "NO\n";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    for (int x : ans) {
        cout << x << "\n";
    }

    return 0;
}

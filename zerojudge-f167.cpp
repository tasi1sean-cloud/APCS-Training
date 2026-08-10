#include <bits/stdc++.h> 
using namespace std; 
int n, m; 
vector<vector<int>> adj; 
vector<int> in_degree; 
vector<int> ans; 
void bfs() {
queue<int> q;
for (int i = 1; i <= n; i++) {
if (in_degree[i] == 0) q.push(i);
}
while (!q.empty()) {
if (q.size() > 1) {
cout << "NO\n";
exit(0);
}
int u = q.front();
q.pop();
ans.push_back(u);
for (int v : adj[u]) {
in_degree[v]--;
if (in_degree[v] == 0) q.push(v);
}
}
}
int main() {
cin >> n >> m; 
adj.assign(n + 1, vector<int>()); 
in_degree.assign(n + 1, 0); 
for (int i = 0; i < m; i++) { 
int a, b; 
cin >> a >> b; 
adj[a].push_back(b); 
in_degree[b]++; 
} 
bfs(); 
if (ans.size() != n) { 
cout << "NO\n"; 
return 0; 
} 
cout << "YES\n"; 
for (int x : ans) { 
cout << x << "\n"; 
} 
return 0; 
}

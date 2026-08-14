#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int counter = 0;

void dfs(int node){
  visited[node] = true;
  ++counter;
  for(int i = 0; i < adj[node].size(); ++i){
    int neighbor = adj[node][i];
    if(!visited[neighbor]){
      dfs(neighbor);
    }
  }
}

int main(){
  int N, M;
  cin >> N >> M;
  adj.assign(N+1, {});
  while(M--){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  long long ans = 0;
  for(int i = 1; i <= N; ++i){
    visited.assign(N+1, false);
    counter = 0;
    dfs(i);
    ans += counter;
  }
  cout << ans << "\n";
  return 0;
}
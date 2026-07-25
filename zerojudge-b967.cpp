#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
long long ans = 0;

long long dfs(int root){
  int s = adj[root].size();
  if(s == 0) return 1;
  long long depth = 0, max1 = 0, max2 = 0;
  for(int i = 0; i < s; ++i){
    int neighbor = adj[root][i];
    depth = dfs(neighbor);
    if(depth > max1){
      max2 = max1;
      max1 = depth;
    }else if(depth > max2){
      max2 = depth;
    }
  }
  ans = max(ans, max1 + max2);
  return max1 + 1;
}

int main(){
int n, root = -1;
  cin >> n;
  adj.assign(n, {});
  vector<int> parent(n, -1);
  for(int i = 0; i < n-1; ++i){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    parent[b] = a;
  }
  for(int i = 1; i <= n; ++i){
    if(parent[i] == -1){
      root = i;
      break;
    }
  }
  dfs(root);
  cout << ans << "\n";
}
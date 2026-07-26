#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
long long ans = 0;

long long dfs(int root){
  int s = adj[root].size();
  if(s == 0) return 1;
  long long height=0;
  for(int i = 0; i < s; ++i){
    int neighbor = adj[root][i];
    height = max(height,dfs(neighbor));
  }
  ans+=height;
  return height + 1;
}

int main(){
int n, root = -1;
  cin >> n;
  adj.assign(n+1, {});
  vector<int> parent(n, -1);
  for(int i = 1; i < n; ++i){
    int a,b;
    cin >> a >> b;
    
  }
  for(int i = 1; i <= n; ++i){
    if(parent[i] == -1){
      root = i;
      break;
    }
  }
  dfs(root);
  cout << root << "\n" << ans << "\n";
}
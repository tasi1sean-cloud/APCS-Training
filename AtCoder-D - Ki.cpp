#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,q;
vector<vector<ll>> adj;
vector<ll> ans;
vector<bool> visited;
void dfs(ll root){
  visited[root]=true;
  for (int i=0;i<adj[root].size();i++){
    if (!visited[adj[root][i]]) {
      ans[adj[root][i]]+=ans[root];
      dfs(adj[root][i]);
    }
  }
}

int main(){
  cin >> n >> q;
  adj.assign(n+1,{});
  ans.assign(n+1,0);
  visited.assign(n+1,false);
  for (int i=1;i<=n-1;i++){
    ll a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  while(q--){
    ll root,add;
    cin >> root >> add;
    ans[root]+=add;
  }
  dfs(1);
  for (int i=1;i<=n;i++){
    cout << ans[i] << " "; 
  }
  return 0;
}
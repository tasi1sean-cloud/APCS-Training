#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<ll>> adj;
ll n;
vector<bool> visited;
ll dfs(ll root){
    ll s=adj[root].size();
    visited[root]=true;
    if (s==0) return 1;
    ll hight = 0;
    for (ll i=0;i<s;i++){
        if (!visited[adj[root][i]]) {
            hight=max(dfs(adj[root][i]),hight);
            }
    }
    return hight+1;
}

int main()
{
    cin >> n;
    adj.assign(n,{});
    visited.assign(n,true);
    for (int i=0;i<n-1;i++){
        int  a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        visited[b]=false;
    }
    for (ll i=0;i<n;i++){
        if (visited[i]){
            visited[i]=false;
            cout << dfs(i);
            break;
        }
    }
    return 0;
}
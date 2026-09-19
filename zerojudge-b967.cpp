#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<ll>> adj;
ll n;
vector<bool> visited;
ll ans=0;
ll dfs(ll root){
    ll s=adj[root].size();
    visited[root]=true;
    if (s==0) return 1;
    ll max_=0,max1=0;
    for (ll i=0;i<s;i++){
        if (!visited[adj[root][i]]) {
            int x=dfs(adj[root][i]);
            if (x>max_){
                max1=max_;
                max_=x;
                continue;
            }
            if (x>max1){
                max1=x;
            }
            }
    }
    if (s>=2&&max_+max1>ans){
        ans=max_+max1;
    }
    return max_+1;
}

int main()
{
    cin >> n;
    adj.assign(n,{});
    visited.assign(n,true);
    for (ll i=0;i<n-1;i++){
        ll  a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        visited[b]=false;
    }
    for (ll i=0;i<n;i++){
        if (visited[i]){
            visited[i]=false;
            dfs(i);
            cout << ans;
            break;
        }
    }
    return 0;
}
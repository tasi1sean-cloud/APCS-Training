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
    if (s==0) return 0;
    ll hight = 0;
    for (ll i=0;i<s;i++){
        if (!visited[adj[root][i]]) {
            ll x;
            x=dfs(adj[root][i]);
            hight=max(x,hight);
            ans+=x;
            }
    }
    return hight+1;
}

int main()
{
    cin >> n;
    adj.assign(n+1,{});
    visited.assign(n+1,true);
    for (ll i=1;i<=n;i++){
        ll k;
        cin >> k;
        for (ll j=0;j<k;j++){
            ll x;
            cin >> x;
            adj[i].push_back(x);
            visited[x]=false;
        }
    }
    for (ll i=1;i<=n;i++){
        if (visited[i]){
            visited[i]=false;
            cout << i << "\n" << ans+dfs(i);
            break;
        }
    }
    return 0;
}
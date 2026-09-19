#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<ll>> adj;
ll n;
vector<bool> visited;
vector<int> color;
ll ans=0;

ll dfs(ll root){
    ll s=adj[root].size();
    visited[root]=true;
    if (s==0) return color[root];
    ll total=color[root];
    for (ll i=0;i<s;i++){
        if (!visited[adj[root][i]]) {
            int x=dfs(adj[root][i]);
            total+=x;
        }
        
     }
     if (total==0) ans++;
    return total;
}

int main()
{
    int t;
    cin >> t;
    while (t--){
    ans=0;
    cin >> n;
    adj.assign(n+1,{});
    visited.assign(n+1,false);
    color.assign(n+1,0);
    for (ll i=2;i<n+1;i++){
        ll x;
        cin >> x;
        adj[x].push_back(i);
    }
    string s;
    cin >> s;
    for (ll i=0;i<s.size();i++){
        if (s[i]=='W') color[i+1]=1;
        else color[i+1]=-1;
        }
    dfs(1);
    cout << ans << endl;
    }
    return 0;
}
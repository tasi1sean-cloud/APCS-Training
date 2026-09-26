#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<ll>> adj;
ll n;
vector<bool> visited;
vector<char> cat;
ll ans=0;

void dfs(ll root){
    ll s=adj[root].size();
    visited[root]=true;
    if (s==1) {
        ans++;
        return string(cat[root]);
    }
    string s;
    for (ll i=0;i<s;i++){
        if (!visited[adj[root][i]]) {
            string x=dfs(adj[root][i]);
            s.push_back(x);
        }  
     }
     
        for (int i=0;i<s.size();i++){
            if(int(s[i]-'0')>m){
                ans--;
            }
            if (cat[root]=='1'){
                s[i]=s[i]+1;
            }
        }
     
    return s;
}

int main()
{
    cin >> n;
    adj.assign(n+1,{});
    visited.assign(n+1,false);
    cat.assign(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> cat[i];//1有貓0沒有
    }
    for (ll i=0;i<n-1;i++){
        ll a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
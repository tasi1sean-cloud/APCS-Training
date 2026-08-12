#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
set <ll> key;
vector <vector<ll>> adj;
vector <ll> vt;
vector <vector<ll>> canget;
ll ans=0;
void dfs(ll a){
    ans++;
    vt[a]=LLONG_MAX;
    ll s=canget[a].size();
    for (int i=0;i<s;i++){
        ll cur_key = canget[a][i];
        if (key.count(cur_key)==0){ key.insert(canget[a][i]);
        for (int j=0;j<adj[cur_key].size();j++){ 
                vt[adj[cur_key][j]]--;
                if (vt[adj[cur_key][j]]==0){
                    dfs(adj[cur_key][j]);
                }
        }
        }
    }
}
int main(){
    cin >> n >> m >> k;
    int t;
    cin >> t;
    vt.assign(n,0);
    for (int i=0;i<t;i++){
        ll x;
        cin >> x;
        key.insert(x);
    }
    adj.assign(m,{});
    for (int j=0;j<n;j++){
        for (int i=0;i<k;i++){
            ll a;
            cin >> a;
            adj[a].push_back(j);
            if (key.count(a)==0) vt[j]++;
        }
    }
    canget.assign(n,{});
    for (int j=0;j<n;j++){
        for (int i=0;i<k;i++){
            ll a;
            cin >> a;
            canget[j].push_back(a);
        }
    }
    for (int i=0;i<n;i++){
        if (vt[i]==0){
            dfs(i);
        }
    }
    cout << ans;
    return 0;
}
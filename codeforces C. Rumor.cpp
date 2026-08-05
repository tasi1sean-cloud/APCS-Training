#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;
ll ans=0;
vector<int> vt;
vector<vector<ll>> v1;
vector<bool> visited;
int min_=INT_MAX;
void dfs(int a){
    int s=v1[a].size();
    min_=min(min_,vt[a]);
    visited[a]=true;
        for (int i=0;i<s;i++){
            if (!visited[v1[a][i]]){
                dfs(v1[a][i]);
            }
        }
 
}

int main(){
    cin >> n >> m;
    visited.assign(n,false);
    v1.assign(n,{});
    vt.assign(n,0);
    for (int i=0;i<n;i++){
        cin >> vt[i];
    }
    while (m--){
        int x,y;
        cin >> x >> y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    for (int i=0;i<n;i++){
        if (!visited[i]){
            min_=INT_MAX;
            dfs(i);
            ans+=min_;
        }
    }
    cout << ans;
    return 0;
}
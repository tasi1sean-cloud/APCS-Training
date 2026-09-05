#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> adj;
ll pos=0;
ll ans=0;
int po;
void dfs(int now){
    pos++;
    if(now!=0) {
        ans+=abs(po-now);
        po=now;
        if (now%2==0){
            dfs(adj[pos]);//6.0
            po=now;
            dfs(adj[pos]);//8
        }else{
            dfs(adj[pos]);
            po=now;
            dfs(adj[pos]);
            po=now;
            dfs(adj[pos]);
        }
    }else return;
}

int main()
{   
   int n;
   while(cin >> n){
        adj.push_back(n);
   }
   po=adj[0];
   dfs(adj[0]);
   cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
char m1;
int n;
int ans=0;
vector<vector<pair<int,int>>> vt;
void dfs(int x,int y){
  int s=vt[x].size();
  if(s==0) {
    ans=max(ans,y);
    return;
  }
  for(int i = 0; i < s; ++i){
    int neighbor = vt[x][i].first;
    int w = vt[x][i].second;
    dfs(neighbor, y+w);
  }
}
int main(){
  cin >> m1 >> n;
  int m = m1 - 'A';
  vt.assign(26,{});
  while (n--){
    char p1,c1;
    int w;
    cin >> p1 >> c1 >> w;
    int p=p1-'A',c=c1-'A';
    vt[p].push_back({c,w});
  }
  dfs(m,0);
  return 0;
}
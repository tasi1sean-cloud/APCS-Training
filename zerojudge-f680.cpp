#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
vector<vector<bool>> visited;
vector<vector<int>> vt;
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y){
  visited[x][y]=true;
  for(int i = 0;i < 4; i++){
    int nx=x+d[i][0],ny=y+d[i][1];
    if(nx>=0&&nx<n&&ny>=0&&ny<n){
      if(!visited[nx][ny]&&vt[nx][ny]==vt[x][y]){
        dfs(nx,ny);
      }
    }
  }
}
int main(){
  cin >> n;
  vt.assign(n,vector<int>(n,0));
  visited.assign(n,vector<bool>(n,false));
  int ans=0;
  for(int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin >> vt[i][j];
    }
  }for(int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if(!visited[i][j] && vt[i][j]!=0){
        dfs(i,j);
        ++ans;
      }
    }
  }
  cout << ans;
  return 0;
}
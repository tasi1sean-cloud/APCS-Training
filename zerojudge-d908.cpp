#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int h,w;
vector<vector<int>> vt;
vector<int> ans;
int num;
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main(){
  cin >> h >> w;
  queue<pair<int,int>> q;
  vt.assign(h,vector<int>(w,-1));
  for (int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      char ch;
      cin >> ch;
      if (ch=='-'){
        vt[i][j]=0;
        q.push({i,j});
      }
    }
  }
   
  cin >> num;
  ans.assign(num+1,0);
  while(!q.empty()){
    int x=q.front().first,y=q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int nx=x+d[i][0],ny=y+d[i][1];
      
      if(nx>=0&&nx<h&&ny>=0&&ny<w&&vt[nx][ny]==-1){
        q.push({nx,ny});
        vt[nx][ny]=vt[x][y]+1;
        if (vt[nx][ny]>num) vt[nx][ny]=1; 
      }
    }
  }
  for (int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      ans[vt[i][j]]++;
    }
  }
  for (int i=1;i<num+1;i++) cout << ans[i] << " ";
  return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int n;
  cin >> n;
  int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<int>> dist(n, vector<int>(n, -1));
  int cx, cy;
  cin >> cx >> cy;
  queue<pair<int, int>> q;
  dist[cx][cy] = 0;
  q.push({cx, cy});
  while(!q.empty()){
    int cx = q.front().first, cy = q.front().second;
    q.pop();
    for(int i = 0; i < 4; ++i){
      int nx = cx + dir[i][0], ny = cy + dir[i][1];
      if(nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1){
        dist[nx][ny] = dist[cx][cy] + 1;
        q.push({nx, ny});
      }
    }
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cout << dist[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
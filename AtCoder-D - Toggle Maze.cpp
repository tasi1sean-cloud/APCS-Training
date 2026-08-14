#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W, 0));
  vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(W, vector<bool>(2, false)));
  int sx = -1, sy = 1, ex = -1, ey = -1;
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      cin >> grid[i][j];
      if(grid[i][j] == 'S'){
        sx = i;
        sy = j;
      }
      if(grid[i][j] == 'G'){
        ex = i;
        ey = j;
      }
    }
  }
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push({{sx, sy}, {0, 0}});
  visited[sx][sy][0] = 1;
  int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    int r = cur.first.first; // x 座標
    int c = cur.first.second; // y 座標
    int state = cur.second.first; // 狀態, state = 0 -> switch 沒有被按下, state = 1 -> 有按下
    int dist = cur.second.second;
    if(r == ex && c == ey){
      cout << dist << "\n";
      return 0;
    }
    for(int i = 0; i < 4; ++i){
      int nx = r + dir[i][0], ny = c + dir[i][1];
      int newState = state;
      if(nx >= 0 && nx < H && ny >= 0 && ny < W){
        char cell = grid[nx][ny];
        if(cell == '#') continue;
        if(cell == 'x' && state == 0) continue;
        if(cell == 'o' && state == 1) continue;
        if(cell == '?') newState = 1-state;
        if(!visited[nx][ny][newState]){
          visited[nx][ny][newState] = 1;
          q.push({{nx, ny}, {newState, dist + 1}});
        }
      }
    }
  }
  cout << -1 << "\n";
  return 0;
}
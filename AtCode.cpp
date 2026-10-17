#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y;
    int state;
    int step;
};
int h, w;
vector<vector<char>> grid;
int d[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int sx, sy, ex, ey;
vector<vector<vector<bool>>> visited;

int main() {
    cin >> h >> w;
    grid.assign(h, vector<char>(w));
    visited.assign(h,vector<vector<bool>>(w,vector<bool>(2,false)));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') { sx = i; sy = j; }
            if (grid[i][j] == 'G') { ex = i; ey = j; }
        }
    }
    queue<Node> q;
    q.push({sx, sy, 0, 0});
    visited[sx][sy][0] = true;
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();
        if (curr.x == ex && curr.y == ey) {
            cout << curr.step << "\n";
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + d[i][0];
            int ny = curr.y + d[i][1];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                char cell = grid[nx][ny];
                if (cell == '#') continue;
                if (curr.state == 0 && cell == 'x') continue;
                if (curr.state == 1 && cell == 'o') continue;
                int next_state = curr.state;
                if (cell == '?') {
                    next_state = 1 - curr.state;
                }
                if (!visited[nx][ny][next_state]) {
                    visited[nx][ny][next_state] = true;
                    q.push({nx, ny, next_state, curr.step + 1});
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> vt;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int bfs(int height){
    vector<vector<int>> visited(n, vector<int>(n, 0)), dist(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while(!q.empty()){
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        for(int d = 0; d < 4; ++d){
            int nx = cx + dir[d][0], ny = cy + dir[d][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]){
                if(abs(vt[nx][ny] - vt[cx][cy]) <= height){
                    if(nx == n-1 && ny == n-1){
                        return dist[cx][cy] + 1;
                    }
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[cx][cy] + 1;
                }
            }
        }
    }
    return -1;
}


int main()
{
    cin >> n;
    vt.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> vt[i][j];
        }
    }
    int l = 0, r = 1000000, ans = 0, path = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        int temp = bfs(mid);
        if(temp != -1){
            ans = mid;
            r = mid - 1;
            path = temp;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << "\n" << path << "\n";
    return 0;
}
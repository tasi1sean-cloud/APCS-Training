#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<vector<int>> vt;
int ans,ans2;
int d[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
ll bfs(int x,int y,int height){
    queue<pair<pair<int,int>,int>> q;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    q.push({{x,y},0});
    visited[x][y]=true;
    ll sum=0;
    while(!q.empty()){
        int x=q.front().first.first,y=q.front().first.second,step=q.front().second;
        q.pop();
        if (x==n-1&&y==n-1){
            return step;
        }
        for (int i=0;i<4;i++){
            int next_x=x+d[i][0],next_y=y+d[i][1];
            if (next_x>=0&&next_x<n&&next_y>=0&&next_y<n&&abs(vt[next_x][next_y]-vt[x][y])<=height&&!visited[next_x][next_y]){
                q.push({{next_x,next_y},step+1});
                visited[next_x][next_y]=true;
            }
        }
    }
    return 0;
}
int main()
{
    int max_=INT_MIN;
    cin >> n;
    vt.assign(n,vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> vt[i][j];
            max_=max(max_,vt[i][j]);
        }   
    }
    int l=0,r=max_,mid;
    while (r>=l){
        mid = (l+r)/2;
        ll total=bfs(0,0,mid);
        if (total>0){
            ans=mid;
            ans2=total;
            r=mid-1;
        }else if(total==0){
            l=mid+1;
        }
    }
    cout << ans << "\n" << ans2;
    return 0;
}

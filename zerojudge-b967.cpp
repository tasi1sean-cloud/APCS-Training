#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<vector<int>> vt;
int ans;
vector<vector<int>> visited;
int key=0;
ll dfs(int k,int x,int y){
    ll sum=0;
    if (x+1<n&&abs(vt[x+1][y]-vt[x][y])<=k) {
        visited[x+1][y]=abs(key-1);
        sum+=dfs(k,x+1,y);
    }
    if (y+1<n&&abs(vt[x][y+1]-vt[x][y])<=k) {
        visited[x][y+1]=abs(key-1);
        sum+=dfs(k,x,y+1);
    }
    if (x-1>=0&&abs(vt[x-1][y]-vt[x][y])<=k) {
        visited[x-1][y]=abs(key-1);
        sum+=dfs(k,x-1,y);
    }
    if (y-1>0&&abs(vt[x][y-1]-vt[x][y])<=k) {
        visited[x][y-1]=abs(key-1);
        sum+=dfs(k,x,y-1);
    }
    return sum+1;
}

int main()
{
    int max_=0;
    cin >> n;
    vt.assign(n,{});
    visited.assign(n,vector<int>(n,0));
    ll check=n*n;
    if (check%2==0) check=check/2;
    else if (check%2==1) check=check/2+1;
    for (int i=0;i<n;i++){
        while(n--){
            int x;
            cin >> x;
            vt[i].push_back(x);
            max_=max(max_,x);
        }
    }
    int l=0,r=max_,mid;
    while(r>=l){
        mid=(r+l)/2;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                ll now;
                if (visited[i][j]==key) {
                    now=dfs(mid,i,j);
                    if(now>=check){
                        ans=mid;
                        r=mid-1;
                    }else{
                        l=mid+1;
                    }
                }
            }

        }
        key=abs(key-1);
    }
    cout << ans;
    return 0;
}

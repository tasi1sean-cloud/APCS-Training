#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    int h,w,k; 
    cin >> h >> w >> k; 
    vector <vector<int>> vt(h,vector<int>(w,0)); 
    vector<pair<int,int>> d{{1,0},{0,1},{-1,0},{0,-1}}; 
    vector<pair<int,int>> d2{{1,1},{1,-1},{-1,1},{-1,-1}}; 
    
    for (int i=0;i<h;i++){ 
        for (int j=0;j<w;j++){ 
            cin >> vt[i][j]; 
        } 
    } 
    
    while (k--){ 
        vector<pair<int,int>> v1, v2;
        for (int i=0;i<h;i++){ 
            for (int j=0;j<w;j++){ 
                if (vt[i][j]==1) v1.push_back({i,j});
                if (vt[i][j]==-1) v2.push_back({i,j});
            }
        }
        
        for (auto p : v1){ 
            for (int i=0;i<4;i++){ 
                int nh = p.first + d[i].first; 
                int nw = p.second + d[i].second; 
                if(nh >= 0 && nh < h && nw >= 0 && nw < w){ 
                    vt[nh][nw] = 1; 
                } 
            } 
        } 
        
        for (auto p : v2){ 
            if (vt[p.first][p.second] == 1) continue;
            for (int i=0;i<4;i++){ 
                int nh = p.first + d2[i].first; 
                int nw = p.second + d2[i].second; 
                if(nh >= 0 && nh < h && nw >= 0 && nw < w){ 
                    if(vt[nh][nw] == 0) vt[nh][nw] = -1; 
                } 
            } 
        } 
    } 
    
    for (int i=0;i<h;i++){ 
        for (int j=0;j<w;j++){ 
            cout << vt[i][j] << " "; 
        } 
        cout << endl; 
    } 
    return 0; 
}

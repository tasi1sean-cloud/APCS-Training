#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    int h, w, k; 
    cin >> h >> w >> k; 
    
    vector<vector<int>> vt(h, vector<int>(w, 0)); 
    vector<vector<int>> v2(h, vector<int>(w, 0)); 
    
    vector<pair<int, int>> d{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
    long long sum = 0, nsum = 0;
    
    for (int i = 0; i < h; i++) { 
        for (int j = 0; j < w; j++) { 
            cin >> vt[i][j]; 
            sum += vt[i][j]; 
        } 
    } 
    
    while (k--) { 
        for (int j = 0; j < h; j++) { 
            for (int g = 0; g < w; g++) { 
                int up = 0, low = 0; 
                int all=0;
                
                for (int i = 0; i < 4; i++) { 
                    int nh = j + d[i].first; 
                    int nw = g + d[i].second; 
                    
                    
                    if (nh >= 0 && nh < h && nw >= 0 && nw < w) { 
                        all++;
                        if (vt[nh][nw] > vt[j][g]) up++; 
                        else if (vt[nh][nw] < vt[j][g]) low++; 
                    } 
                } 
                
               
                if (up > all/2) v2[j][g] = vt[j][g] + 1; 
                else if (low > all/2) v2[j][g] = vt[j][g] - 1; 
                else v2[j][g] = vt[j][g]; 
            } 
        } 
        vt = v2; 
    } 
    
    for (int i = 0; i < h; i++) { 
        for (int j = 0; j < w; j++) { 
            nsum += vt[i][j]; 
        } 
    } 
    
    cout << nsum - sum << "\n"; 
    return 0; 
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    //substr(開頭,長度)
    int n,m;
    cin >> n >> m;
    vector<vector<int>> vt(n,vector<int>(m,0));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> vt[i][j];
        }
    }
    int ans=0;
    int oldans=1;
    while(ans!=oldans){
        oldans=ans;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (vt[i][j]>0){
                    for (int k=0;k<n;k++){
                        if (vt[k][j]==vt[i][j]&&k!=i){
                            int g=0;
                            if(k<i){
                                for (int o=k;o<=i;o++){
                                    g=vt[o][j]+g;
                                }
                                if(g/2==vt[i][j]){
                                    ans=ans+vt[i][j];
                                    vt[i][j]=0;
                                    vt[k][j]=0;
                                }
                            }
                            if(k>i){
                                for (int o=i;o<=k;o++){
                                    g=vt[o][j]+g;
                                }
                                if(g/2==vt[i][j]){
                                    ans=ans+vt[i][j];
                                    vt[i][j]=0;
                                    vt[k][j]=0;
                                }
                            }
                            
                        }
                    }
                    for (int k=0;k<m;k++){
                        if (vt[i][k]==vt[i][j]&&k!=j){
                            int g=0;
                            if(k<j){
                                for (int o=k;o<=j;o++){
                                    g=vt[i][o]+g;
                                }
                                if(g/2==vt[i][j]){
                                    ans=ans+vt[i][j];
                                    vt[i][j]=0;
                                    vt[i][k]=0;
                                }
                            }
                            if(k>j){
                                for (int o=j;o<=k;o++){
                                    g=vt[i][o]+g;
                                }
                                if(g/2==vt[i][j]){
                                    ans=ans+vt[i][j];
                                    vt[i][j]=0;
                                    vt[i][k]=0;
                                }
                            }
                            
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
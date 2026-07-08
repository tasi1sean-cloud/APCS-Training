#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x=int(sqrt(2147483647))+1;
    vector <bool> vt(x,true);
    vector <int> v1;
    vt[0]=false;
    vt[1]=false;
    for (int i=0;i<x;i++){
        if (vt[i]!=false){
            for (long long j=1LL*i*i;j<x;j=j+i){
                vt[j]=false;
            }            
        }
    }
    for (int i=0;i<x;i++){
        if (vt[i]){
            v1.push_back(i);
        }
    }
    long long a;
    while(cin >> a){
        for (int i=0;i<v1.size();i++){
            if (a==0||a==1) {
                cout << "非質數" << "\n";
                break;
            }
            if (a==v1[i]){
                cout << "質數" << "\n";
                break;
            }
            if (a%v1[i]==0){
                cout << "非質數" << "\n";
                break;
            }
            if (1LL*(v1[i]) * v1[i] > a&&a%v1[i]!=0){
                cout << "質數" << "\n";
                break; 
            }
            if (1LL*(v1[i]) * v1[i] > a) break;
        }
    }
    return 0;
}
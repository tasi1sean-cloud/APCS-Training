#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll c;
vector <ll> vt;
bool check(ll level){
    ll now=0;
    for (int i=1;i<=n;i++){
        if (level>vt[i])now += (level-vt[i])*(level-vt[i]);
        if(now>c) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    cin >> c;
    vt.assign(n+1,0);
    for (int i=1;i<=n;i++) cin >> vt[i];
    ll l=0,r=100000000,mid;
    ll ans;
    while(r>=l){
        mid=(r+l)/2;
        if (check(mid)){
            l=mid+1;
            ans=mid;
        }else {
            r=mid-1;
        }
    }
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;
vector<ll> vt;

int main()
{
    cin >> n >> m;
    vt.assign(n+1,0);
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        vt[i]=vt[i-1]+x;
    }
    int now=0;
    while(m--){
        ll q;
        cin >> q;
        if (now!=0) q+=vt[now];
        while(q>vt[n]) q-=vt[n];
        now=((lower_bound(vt.begin(),vt.end(),q)-vt.begin()))%n;
    }
    cout << now;
    return 0;
}
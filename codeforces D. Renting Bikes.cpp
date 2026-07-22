#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;
ll a;
vector<ll> b,p;
bool check(int r){
    if(r==0) return true;
    ll total=0;
    for (int i=0;i<r;i++){
        int boy=b[n-1-i];
        int bike=p[r-1-i];
        if (bike>boy)total+=(bike-boy);
        if(total>a) return false;
    }
    return true;
}
int main(){
    cin >> n >> m;
    cin >> a;
    b.assign(n,0);
    p.assign(m,0);
    for (int i=0;i<n;i++) cin >> b[i];
    for (int i=0;i<m;i++) cin >> p[i];

    sort(b.begin(),b.end());
    sort(p.begin(),p.end());
    int r=min(n,m) l=0;
    int ans = 0;
    while(l<=r){
        int mid=l+r/2
        if (check(mid)){
            ans = mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    ll cost=0;
    for (int i=0;i<ans;i+=)cost += p[i];
    ll endans=max(0LL,cost-a);
    cout << ans << " " << endans << endl;


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;
vector<ll> vt;
ll ans=0;

int main(){
  cin >> n >> m;
  vt.assign(n,0);
  for (int i=0;i<n;i++)cin >> vt[i];
  sort(vt.begin(),vt.end());
  while(m--){
    ll s,e;
    cin >> s >> e;
    ans+=upper_bound(vt.begin(),vt.end(),e)-lower_bound(vt.begin(),vt.end(),s);
  }
  cout << ans << "\n";
  return 0;
}
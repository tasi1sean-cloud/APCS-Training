#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,k;
vector <ll> h;
vector <int> w;
bool check(ll hi){
  int now=0;
  int noww=0;
    for (int i=0;i<n;i++){
    if (h[i]>=hi) noww++;
    else noww=0;
    if (noww == w[now]) {
      now++;
      if (now==k) return true;
      noww=0;
    }
  }
  return false;
}
int main(){
  ll max_ = LLONG_MIN;
  cin >> n >> k;
  h.assign (n,0);
  w.assign (k,0);
  
  for(int i = 0; i < n; ++i) {
    cin >> h[i];
    if (h[i]>max_) max_=h[i];
  }
  for(int i = 0; i < k; ++i) cin >> w[i];
  ll l = 0, r = max_;
  ll ans = r;
  while(l <= r){
    ll mid = (l + r) / 2;
    if(check(mid)){
      ans = mid;
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll c;
vector<ll> a;

bool check(ll level){
  ll sum_ = 0;
  for(int i = 0; i < n; ++i){
    if(a[i] < level){
      sum_ += (level-a[i]) * (level-a[i]);
      if(sum_ > c) return false;
    }
  }
  return true; 
}

int main(){
  cin >> n >> c;
  a.assign(n, 0);
  for(int i = 0; i < n; ++i) cin >> a[i];
  ll l = 1, r = 20000000, ans = 0;
  // 對等級做 2 分搜，因為等級具有單調性
  while(l <= r){
    ll mid = (l+r) / 2;
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
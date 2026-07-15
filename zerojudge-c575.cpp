#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, k;
vector<ll> pos;

// 檢查能否在 dia 下用 k 座基地台覆蓋所有服務點
// 在這個 dia 下，覆蓋所有點使用幾個 k
bool check(ll dia){
  int used = 0; // 已經使用幾個基地台
  int i = 0;
  while(i < n){
    ll rightmost = pos[i] + dia;
    ++used;
    if(used > k) return false;
    while(i < n && pos[i] <= rightmost) ++i;
  }
  return true;
}

int main(){
  cin >> n >> k;
  pos.assign(n, 0);
  for(int i = 0; i < n; ++i) cin >> pos[i];
  sort(pos.begin(), pos.end()); // O(nlogn)
  ll l = 0, r = pos.back() - pos.front();
  ll ans = r;
  // 對直徑做二分搜
  while(l <= r){
    ll mid = (l + r) / 2;
    if(check(mid)){
      // 直徑越大，所使用的基地台越少
      ans = mid;
      r = mid - 1;
    }else{
      // 直徑越小，所使用的基地台越多
      l = mid + 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
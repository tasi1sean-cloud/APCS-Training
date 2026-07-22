#include <bitds/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector <int> a(n),b(n),c(n);
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n;i++) cin >> b[i];
  for (int i=0;i<n;i++) cin >> c[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  ll total=0;
  for (int i=0;i<b.size();i++){
    int bi=b[i];
    ll l=lower bound(a.begin(),a.end,bi)-a.begin;
    ll r=n - (upper bound(c.begin(),c.end(),bi)-c.begin);
    total+=r*l;
  }
  cout << total << endl;
  return 0;
}
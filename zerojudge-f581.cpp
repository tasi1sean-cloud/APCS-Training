#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n,m;
  cin >> n >> m;
  vector <ll> p(n);
  vector <ll> primex(n);
  for (int i=0;i<n;i++){
    cin >> p[i];
    if (i!=0) primex[i]=primex[i-1]+p[i];
    else primex[i]=p[i];
  }
  int now=0;
  while (m--){
    ll q;
    cin >> q;
    ll target;
    if (now!=0)  target = q+primex[now-1];
    else  target = q;
    while(target>primex[n-1]){
      now=0;
      target = target - primex[n-1];
    }
    now = ((lower_bound(primex.begin(),primex.end(),target) - primex.begin()) + 1)%n;
  }
  cout << now << endl;
  return 0;
}

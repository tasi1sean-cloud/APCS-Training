//這題要看
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N+1), prefix(N+1);
  for(int i = 1; i <= N; ++i){
    cin >> A[i];
    prefix[i] = prefix[i-1] + A[i];
  }
  ll ans = 0;
  for(int left = 1; left <= N; ++left){
    // 要找到最小的 right, 使得 prefix[right] >= K + prefix[left - 1]
    ll target = K + prefix[left - 1];
    int right = lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
    if(right <= N) ans += (N-right+1);
  }
  cout << ans << "\n";
  return 0;
}
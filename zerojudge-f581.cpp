#include <iostream>
#include <vector>
#include <algorithm>   // lower_bound
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> room(n), prefix(n);
  for(int i = 0; i < n; ++i){
    cin >> room[i];
    if(i != 0) prefix[i] = prefix[i-1] + room[i];
    else prefix[i] = room[i];
  }
  int idx = 0;
  while(m--){
    int target;
    cin >> target;
    if(idx > 0) target = prefix[idx-1] + target;
    if(target > prefix[n-1]){
      idx = 0;
      target = target - prefix[n-1];
    }
    int left = lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
    idx = (left + 1) % n;
  }
  cout << idx << "\n";
  return 0;
}

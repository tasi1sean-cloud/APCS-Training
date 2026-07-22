#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
      vector<long long> arr(n + 1, 0);
      vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
          sum[i] = sum[i - 1] + arr[i];
  }
        // 處理每一次的詢問
        for (int i = 0; i < m; i++) {
            long long l, r, a, b;
            cin >> l >> r >> a >> b;

          long long _sum = sum[r] - sum[l - 1];
            long long t_val = _sum * a;
          long long ba = a + b;
            long long le = l;
          long long ri = r;
            long long ans = r; // 預設答案

          while (le<=ri) {
                long long mid = (le + ri) / 2;
                long long ent_sum = sum[mid] - sum[l-1];
                if (ent_sum * ba >= t_val) {
                    ans = mid;         
                    ri = mid - 1;  
                } else {
                    le = mid + 1; 
                }
            }

            cout << ans << "\n";
        }
    }
    return 0;
}

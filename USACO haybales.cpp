#include <iostream>
#include <vector>
#include <algorithm>

/*
==================== 解題思維 ====================

【題意】
N 個乾草堆在一維道路上，給 Q 筆詢問，每筆問「位置在 [A,B] 內有幾個乾草堆」。

【核心想法】
暴力每筆詢問掃全部 N 個 → O(N*Q)，N,Q 到 10^5 會 TLE。
先把位置「排序」，排好後就能用「二分搜」快速數區間內的點數：

  [A,B] 內的數量 = (位置 <= B 的數量) - (位置 < A 的數量)

用 upper_bound / lower_bound 各一次二分搜：
  - upper_bound(B)：第一個 > B 的位置 → 其 index = 「<= B 的數量」
  - lower_bound(A)：第一個 >= A 的位置 → 其 index = 「< A 的數量」
兩者相減即為答案。

【複雜度】
排序 O(N log N) + 每筆詢問 O(log N)，總共 O((N+Q) log N)，輕鬆過。

=================================================
*/


using namespace std;

int main(){
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  vector<int> pos(n);
  for(int i = 0; i < n; ++i) cin >> pos[i];

  sort(pos.begin(), pos.end());

  while(q--){
    int A, B;
    cin >> A >> B;

    // 位置 <= B 的數量: 第一個 > B 的位置 index
    int posB = upper_bound(pos.begin(), pos.end(), B) - pos.begin();
    
    // 位置 < A 的數量: 第一個 >= A 的位置 index
    int posA = lower_bound(pos.begin(), pos.end(), A) - pos.begin();

    cout << posB - posA << "\n";
  }
  return 0;
}
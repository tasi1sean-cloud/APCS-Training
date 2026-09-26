#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max_=LLONG_MIN;
int n,m,q;
vector<vector<int>> vt;
vector<int> a;
vector<int> ans;
void backtracking(int start){
    if (a.size()==n){
      ll sum=0;
      for (int i=0;i<q;i++){
        if(a[vt[i][1]-1]-a[vt[i][0]-1]==vt[i][2]) sum+=vt[i][3];
      }
      max_=max(max_,sum);
      return;
    }
    for (int i=start;i<=m;i++){
      a.push_back(i);
      backtracking(i);
      a.pop_back();
    }
}

int main(){
  cin >> n >> m >> q;
  vt.assign(q,{});
  for(int i=0;i<q;i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vt[i].push_back(a);
    vt[i].push_back(b);
    vt[i].push_back(c);
    vt[i].push_back(d);
  }
  backtracking(1);
  cout << max_;
  return 0;
}
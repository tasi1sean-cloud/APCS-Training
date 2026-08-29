#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string svt;
string target;
int l;
string s;
unordered_set<string> st;
void dfs(string target,int l){
        if (svt.size()==l){
            if (!st.count(svt)){
                cout << svt;
                exit(0);
            }
            return;
        }
        for(int i = 0; i < target.size(); ++i){
            svt.push_back(target[i]);
            dfs (target,l);
            svt.pop_back();
        }
}

int main()
{   
   cin >> target;
   cin >> l;
   cin >> s;
   int n = s.size();
   for (int i=0;i<n-l+1;i++){
        st.insert(s.substr(i,l));
   }
   dfs(target,l);
}
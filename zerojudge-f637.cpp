#include <bits/stdc++.h>
using namespace std;

string S;
int idx = 0;

int dfs(int n){
    char c = S[idx];
    ++idx;
    if(c == '0') return 0;
    else if(c == '1') return n*n;
    int half = n/2;
    int res = 0;
    res += dfs(half);
    res += dfs(half);
    res += dfs(half);
    res += dfs(half);
    return res;
}


int main()
{
    cin >> S;
    int n;
    cin >> n;
    cout << dfs(n) << "\n";
    return 0;
}
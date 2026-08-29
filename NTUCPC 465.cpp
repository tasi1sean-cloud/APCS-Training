#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    unordered_map<int, int> ump; // ump[x] = y 第x顆球是 y 號
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int a, b;
            cin >> a >> b;
            if(!ump.count(a) && !ump.count(b)){
                ump[a] = a;
                ump[b] = b;
            }else if(ump.count(a) && !ump.count(b)){
                ump[b] = b;
            }else if(!ump.count(a) && ump.count(b)){
                ump[a] = a;
            }
            swap(ump[a], ump[b]);
        }else if(op == 2){
            int c;
            cin >> c;
            if(!ump.count(c)) ans += c;
            else ans += ump[c];
        }
    }
    cout << ans << "\n";
    return 0;
}
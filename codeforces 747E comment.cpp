#include <bits/stdc++.h>
using namespace std;

string s;
int pos; // 目前讀到字串的哪一個位置

vector<vector<string>> ans;

void dfs(int depth){
    int n = s.size();
    int start = pos;
    while(pos < n && s[pos] != ',') pos++;
    string text = s.substr(start, pos - start); // 擷取留言
    ++pos; // 跳過逗號
    int count = 0;
    while(pos < n && s[pos] != ','){
        count = count * 10 + s[pos] - '0';
        pos++;
    }
    ++pos; // 跳過逗號
    
    while(ans.size() < depth){
        vector<string> empty;
        ans.push_back(empty);
    }
    ans[depth-1].push_back(text);
    
    for(int i = 0; i < count; ++i){
        dfs(depth+1);
    }
}

int main()
{
    cin >> s;
    pos = 0;
    int n = s.size();
    while(pos < n){
        dfs(1);
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
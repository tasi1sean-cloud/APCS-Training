#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
map<int,vector<string>> vt;
int index=0;
void dfs(int target,int height){
    int now=0;
    vector<string> v1;
    for (int i=index;i<s.size();i++){
        if (now==target) {
            vt[height].push_back(s.substr(index, i - index));
            return;
        }
        if(s[i]==','){
            now++;
            v1.push_back(s.substr(index,i-index));
            int size;
            for (int j=i+1;j<s.size();j++) {
                if(s[j]==',') {
                    index=j+1;
                    string s1=s.substr(i+1,j-1-i);
                    size = stoi(s1);
                    break;
                }
            }
            dfs(size,height+1);
            i=index-1;
        }
    }
}

int main(){
    cin >> s;
    while(index<s.size()-1){
        dfs(1,1);
    }
    for (auto x:vt){
        cout << x <<" "
    }
    return 0;
}
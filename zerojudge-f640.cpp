#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<string> adj;
int pos=0;
ll dfs(string now){
    pos++;
    if (now == "f") {
        ll x;
        x=dfs(adj[pos]);
        return 2*x-3;
    }
    if (now=="g"){
        ll x,y;
        x=dfs(adj[pos]);
        y=dfs(adj[pos]);
        return 2*x+y-7;
    }
    if (now=="h"){
        ll x,y,z;
        x=dfs(adj[pos]);
        y=dfs(adj[pos]);
        z=dfs(adj[pos]);
        return 3*x-2*y+z;
    }
    
    return stoi(now);
}

int main()
{   
    string input;
    getline(cin,input);
    stringstream ss(input);
    string token;
    while(ss >> token){
        adj.push_back(token);
    }
    cout << dfs(adj[pos]);
    return 0;
}
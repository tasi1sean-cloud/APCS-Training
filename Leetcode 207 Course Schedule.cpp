class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visited;

    bool dfs(int node){
        if(visited[node] == 2) return true;
        if(visited[node] == 1) return false;
        visited[node] = 1;
        for(int i = 0; i < adj[node].size(); ++i){
            int neighbor = adj[node][i];
            if(dfs(neighbor) == false) return false;
        }
        visited[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses, {});
        for(int i = 0; i < prerequisites.size(); ++i){
            int c = prerequisites[i][0], p = prerequisites[i][1];
            adj[p].push_back(c);
        }
        visited.assign(numCourses, 0);
        for(int i = 0; i < numCourses; ++i){
            if(visited[i] == 0){
                if(dfs(i) == false) return false;
            }
        }
        return true;
    }
};
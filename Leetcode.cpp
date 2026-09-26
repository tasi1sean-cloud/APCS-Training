class Solution {
public:
    vector<vector<int>> adj;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses, {});
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); ++i){
            int c = prerequisites[i][0], p = prerequisites[i][1];
            adj[p].push_back(c);
            indegree[c]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] == 0) q.push(i);
        }
        int visited = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ++visited;
            for(int i = 0; i < adj[node].size(); ++i){
                int neighbor = adj[node][i];
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }
        return visited == numCourses;
    }
};
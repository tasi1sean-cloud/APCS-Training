class Solution {
public:
    vector<vector<int>> ans;
    vector<int> now;
    int sum=0;
    void backtracking(int start,vector<int> vt,int num) {
        if (sum == num) {
            ans.push_back(now);
            return;
        }
        if (sum>num) return;
        for (int i = start; i < vt.size(); i++) {
            now.push_back(vt[i]);
            sum+=vt[i];
            backtracking(i,vt,num);
            sum-=vt[i];
            now.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(0,candidates,target);
        return ans;
    }
};
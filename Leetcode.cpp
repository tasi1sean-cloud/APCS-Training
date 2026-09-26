class Solution {
public:
    vector<vector<int>> ans;
    vector<int> now;
    vector<bool> visited;
    void backtracking(int start_, vector<int> nums) {
        if (now.size() == nums.size()) {
            ans.push_back(now);
            return;
        }
        for (int i = start_; i < nums.size(); i++) {
            if(!visited[i]){now.push_back(nums[i]);
            visited[i]=true;
            backtracking(0,nums);
                now.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        visited.assign(nums.size(),false);
        backtracking(0,nums);
        return ans;
    }
};
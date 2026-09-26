class Solution {
public:
    vector<vector<int>> ans;
    vector<int> now;
    void backtracking(int start_, int end_, int size) {
        if (now.size() == size) {
            ans.push_back(now);
            return;
        }
        for (int i = start_; i <= end_; i++) {
            now.push_back(i);
            backtracking(i+1, end_, size);
            now.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {

        backtracking(1, n, k);
        return ans;
    }
};
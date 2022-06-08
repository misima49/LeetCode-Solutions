class Solution {
    void findSubsets(int ind, vector<int>& cur, vector<vector<int>>& answer, vector<int>& nums) {
        answer.push_back(cur);
        
        int n = nums.size();
        for(int i = ind; i < n; i++) {
            if(i != ind && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            findSubsets(i+1, cur, answer, nums);
            cur.pop_back();
        }
        
        // findSubset
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        findSubsets(0, cur, answer, nums);
        
        return answer;
    }
};
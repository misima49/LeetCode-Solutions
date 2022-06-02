class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1, k = 1;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        while(i < j) {
            if(nums[i] > 0) break;
            while(k < j) {
                if(nums[i]+nums[j]+nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(k < n-1 && nums[k+1] == nums[k]) k++;
                    k++;
                    while(j > 0 && nums[j-1] == nums[j]) j--;
                    j--;
                } else if(nums[i]+nums[j]+nums[k] < 0) {
                    while(k < n-1 && nums[k+1] == nums[k]) k++;
                    k++;
                } else {
                    while(j > 0 && nums[j-1] == nums[j]) j--;
                    j--;
                }
            }

            while(i < n-1 && nums[i+1] == nums[i]) i++;
            i++;
            k = i+1;
            j = n-1;
        }
        
        return ans;
    }
};
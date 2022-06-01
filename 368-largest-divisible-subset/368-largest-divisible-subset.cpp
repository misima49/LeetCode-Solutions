class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0), hash(n, -1);
        sort(nums.begin(), nums.end());
        int largestInd = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j] == 0) {
                    
                    // cout << i << " " << j << " " << dp[i] << " " << dp[j] << "\n";
                    if(dp[i] < 1+dp[j]) {
                        dp[i] = 1+dp[j];
                        hash[i] = j;
                        if(dp[largestInd] < dp[i]) largestInd = i;
                    }
                }
            }
        }
        
        vector<int> ans;
        while(hash[largestInd] != -1) {
            ans.push_back(nums[largestInd]);
            largestInd = hash[largestInd];
        }
        
        ans.push_back(nums[largestInd]);
        return ans;
    }
};
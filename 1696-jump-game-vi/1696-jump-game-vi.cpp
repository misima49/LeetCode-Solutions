class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -1e8);
        dp[n-1] = nums[n-1];
        
        deque<int> dq;
        dq.push_back(n-1);
        
        for(int i = n-2; i >= 0; i--) {
//             int maxScore = -1e8;
            
//             for(int j = 1; j <= k && j+i < n; j++) {
//                 maxScore = dp[i+j], maxScore);
//             }
            
            if(dq.front() > i+k) dq.pop_front();
            dp[i] = dp[dq.front()] + nums[i];
            
            while(!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        
        return dp[0];
    }
};
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            int maxEle = -1e8;
            int maxSum = -1e8;
            int len = 0;
            int limit = min(n, i+k);
            for(int j = i; j < limit; j++) {
                maxEle = max(maxEle, arr[j]);
                len++;
                int sum = len*maxEle + dp[j+1];
                maxSum = max(maxSum, sum);
            }
            
            dp[i] = maxSum;
        }
        
        return dp[0];
    }
};
class Solution {
    int findPartitions(int ind, int n, int k, vector<int>& arr, vector<int>& dp) {
        if(ind == n) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int maxEle = -1e8;
        int limit = min(ind+k, n);
        int maxSum = -1e8;
        int len = 0;
        for(int i = ind; i < limit; i++) {
            maxEle = max(maxEle, arr[i]);
            len++;
            int sum = len*maxEle + findPartitions(i+1, n, k, arr, dp);
            maxSum = max(maxSum, sum);
        }
        
        return dp[ind] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return findPartitions(0, n, k, arr, dp);
    }
};
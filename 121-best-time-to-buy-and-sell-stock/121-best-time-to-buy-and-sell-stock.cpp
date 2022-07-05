class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int rightMax = prices[n-1];
        int maxProfit = 0;
        
        for(int i = n-2; i >= 0; i--) {
            if(rightMax < prices[i]) rightMax = prices[i];
            else if(maxProfit < rightMax - prices[i]) maxProfit = rightMax - prices[i];
        }
        
        return maxProfit;
    }
};
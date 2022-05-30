class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2, 0), cur(2, 0);
        
        for(int i = n-1; i >= 0; i--) {
            cur[0] = max(prices[i]+next[1], next[0]);
            cur[1] = max(-prices[i]+next[0], next[1]);
            
            next = cur;
        }
        
        return next[1];
    }
};
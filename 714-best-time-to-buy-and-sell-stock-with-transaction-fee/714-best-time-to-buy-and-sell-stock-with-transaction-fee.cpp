class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        // vector<int> next(2, 0), cur(2, 0);
        int next0 = 0, next1 = 0;
        int cur0 = 0, cur1 = 0;
        
        for(int i = n-1; i >= 0; i--) {
            cur0 = max(prices[i] - fee + next1,
                          next0);
            
            cur1 = max(-prices[i] + next0,
                          next1);
            
            next0 = cur0;
            next1 = cur1;
        }
        
        return next1;
    }
};
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<int> next(2*k+1, 0), cur(2*k+1, 0);;
        
        for(int i = n-1; i >= 0; i--) {
            for(int transNo = 1; transNo <= 2*k; transNo++) {
                if(transNo % 2 == 0) {
                    cur[transNo] = 
                        max(-prices[i]+next[transNo-1], 
                            next[transNo]);
                } else {
                    cur[transNo] = 
                        max(prices[i]+next[transNo-1],
                           next[transNo]);
                }
            }
            
            swap(cur, next);
        }
        
        return next[2*k];
    }
};
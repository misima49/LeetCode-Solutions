class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        vector<int> price(n, 1e8);
        price[src] = 0;
        while(k--) {
            vector<int> temp(price);
            
            for(vector<int> itr : flights) {
                if(temp[itr[1]] > price[itr[0]] + itr[2]) {
                    temp[itr[1]] = price[itr[0]] + itr[2];
                }
            }
            
            price = temp;
        }
        
        if(price[dst] == 1e8) return -1;
        return price[dst];
    }
};
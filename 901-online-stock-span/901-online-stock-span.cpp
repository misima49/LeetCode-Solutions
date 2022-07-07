class StockSpanner {
    stack<pair<int, int>> minSt;
    int itr; // itr keeps the day we currently are at.
public:
    StockSpanner() {
        while(!minSt.empty()) minSt.pop();
        minSt.emplace(-1, 1e8);
        itr = -1;
    }
    
    int next(int price) {
        itr++;
        while(!minSt.empty() && minSt.top().second <= price) minSt.pop();
        
        if(minSt.empty()) {
            minSt.emplace(itr, price);
            return 1;
        }
        
        int span = itr - minSt.top().first;
        minSt.emplace(itr, price);
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
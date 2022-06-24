class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long> maxH(target.begin(), target.end());
        long sum = 0;
        
        for(int i : target) sum += i;
        
        while(maxH.top() > 1) {
            long lSum = sum - maxH.top();
            if(lSum == 1) return true;
            if(lSum == 0 || maxH.top()%lSum <= 0 || maxH.top()%lSum >= maxH.top()) return false;
            int prevVal = maxH.top()%lSum;
            sum = lSum + prevVal;
            maxH.pop();
            maxH.push(prevVal);
        }
        
        return true;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exist;
        int answer = 0, curCount = 0;
        
        for(int itr : nums) {
            exist.insert(itr);
        }
        
        for(int itr : nums) {
            curCount = 0;
            if(exist.find(itr-1) == exist.end()) {
                int curEle = itr;
                while(exist.find(curEle++) != exist.end()) {
                    curCount++;
                }
            }
            
            answer = max(answer, curCount);
        }
        
        return answer;
    }
};
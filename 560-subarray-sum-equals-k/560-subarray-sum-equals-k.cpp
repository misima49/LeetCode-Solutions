class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int answer = 0;
        int curSum = 0;
        unordered_map<int, int> exist;
        
        exist[0] = 1;
        
        for(int i = 0; i < n; i++) {
            curSum += nums[i];
            
            if(exist.count(curSum-k) > 0) {
                answer += exist[curSum-k];
            }
            
            exist[curSum]++;
        }
        
        return answer;
    }
};
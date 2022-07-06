class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxDq;
        deque<int> minDq;
        int maxLen = 0;
        int l = 0;
        
        for(int r = 0; r < n; r++) {
            while(!maxDq.empty() && maxDq.back() < nums[r]) {
                maxDq.pop_back();
            }
            maxDq.push_back(nums[r]);
            
            while(!minDq.empty() && minDq.back() > nums[r]) {
                minDq.pop_back();
            }
            minDq.push_back(nums[r]);
            
            while(maxDq.front() - minDq.front() > limit) {
                if(maxDq.front() == nums[l]) maxDq.pop_front();
                if(minDq.front() == nums[l]) minDq.pop_front();
                l++;
            }
            
            maxLen = max(maxLen, r-l+1);
        }
        
        return maxLen;
    }
};
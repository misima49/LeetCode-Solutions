class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        
        int ans = 0;
        for(int& itr : nums) {
            if(hash.count(itr-1)) continue;
            int curLen = 1;
            while(hash.count(itr+1)) {
                itr++;
                curLen++;
            }
            
            ans = ans < curLen ? curLen : ans;
        }
        
        return ans;
    }
};
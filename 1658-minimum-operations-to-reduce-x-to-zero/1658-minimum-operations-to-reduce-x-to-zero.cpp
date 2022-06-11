class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        
        if(totSum == x) return n;
        
        int target = totSum - x;
        unordered_map<int, int> hash;
        int sum = 0;
        int maxLen = 0;
        hash[0] = -1;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            hash[sum] = i;
            if(hash.find(sum-target) != hash.end()) {
                // cout << target-sum << " " << hash[target-sum] << " " << i << "\n";
                maxLen = max(maxLen, i-hash[sum-target]);
            }
        }
        
        if(maxLen == 0) return -1;
        return n-maxLen;
    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        int curSc = 0, maxSc = 0;
        int curSt = 0;
        
        for(int i = 0; i < n; i++) {
            if(hash.find(nums[i]) == hash.end()) {
                hash[nums[i]] = i;
                curSc += nums[i];
            } else {
                if(hash[nums[i]] >= curSt) {                    
                    // cout << nums[curSt] << " " << nums[i] << "\n";
                    maxSc = max(maxSc, curSc);
                    for(int j = curSt; j < hash[nums[i]]; j++) {
                        curSc -= nums[j];
                    }
                    curSt = hash[nums[i]]+1;
                } else {
                    curSc += nums[i];
                }
                // cout << curSt << " " << nums[curSt] << " " << i << " "<< nums[i] << "\n";
                hash[nums[i]] = i;
            }
        }

        maxSc = max(maxSc, curSc);
        
        return maxSc;
    }
};
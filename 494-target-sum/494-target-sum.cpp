struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

class Solution {
    int findSum(int ind, int target, vector<int>& nums, unordered_map<pair<int, int>, int, hash_pair>& dp) {
        if(ind < 0) {
            if(target == 0) return 1;
            return 0;
        }
        
        if(dp.find({ind, target}) != dp.end()) return dp[{ind, target}];
        
        int posi = findSum(ind-1, target-nums[ind], nums, dp);
        int neg = findSum(ind-1, target+nums[ind], nums, dp);
        
        // cout << posi << " " << neg << "\n";
        
        return dp[{ind, target}] = posi + neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<pair<int, int>, int, hash_pair> dp;
        return findSum(nums.size()-1, target, nums, dp);
    }
};
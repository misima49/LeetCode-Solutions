class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        
        for(int num : nums) {
            ++hash[num];
        }
        
        vector<vector<int>> buckets(nums.size()+1);
        for(auto& itr : hash) {
            buckets[itr.second].push_back(itr.first);
        }
        
        vector<int> ans;
        for(int i = buckets.size()-1; i >= 0 && ans.size() < k; i--) {
            for(int& itr : buckets[i]) {
                ans.push_back(itr);
                if(ans.size() == k) break;
            }
        }
        
        return ans;
    }
};
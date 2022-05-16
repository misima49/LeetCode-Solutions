class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        
        for(int itr : nums) {
            if(hash.find(itr) != hash.end())
                hash[itr]++;
            else
                hash.insert({itr, 1});
        }
        
        unordered_map<int, int>::iterator itr;
        for(itr = hash.begin(); itr != hash.end(); itr++) {
            if(itr->second > nums.size()/2) return itr->first;
        }
        
        return -1;
    }
};
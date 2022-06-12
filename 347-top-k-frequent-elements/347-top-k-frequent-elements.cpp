class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        
        for(int num : nums) {
            hash[num]++;
        }
        
        unordered_map<int, int>::iterator mapItr = hash.begin();
        
        while(mapItr != hash.end()) {
            minH.push({mapItr->second, mapItr->first});
            mapItr++;
            if(minH.size() > k)
                minH.pop();
            
        }
        
        
        vector<int> ans;
        while(!minH.empty()) {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        
        return ans;
    }
};
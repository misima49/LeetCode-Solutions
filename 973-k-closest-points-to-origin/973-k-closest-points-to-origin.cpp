class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxH;
        
        for(vector<int> point : points) {
            int dist = point[0]*point[0] + point[1]*point[1];
            maxH.push({dist, point});
            if(maxH.size() > k) 
                maxH.pop();
        }
        
        vector<vector<int>> ans;
        while(!maxH.empty()) {
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        
        return ans;
    }
};
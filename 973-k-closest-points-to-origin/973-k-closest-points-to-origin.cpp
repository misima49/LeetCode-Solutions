class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxH;
        
        for(int i = 0; i < points.size(); i++) {
            vector<int> point = points[i];
            int dist = point[0]*point[0] + point[1]*point[1];
            maxH.push({dist, i});
            if(maxH.size() > k) 
                maxH.pop();
        }
        
        vector<vector<int>> ans;
        while(!maxH.empty()) {
            ans.push_back(points[maxH.top().second]);
            maxH.pop();
        }
        
        return ans;
    }
};
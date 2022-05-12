class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        
        int curStart = intervals[0][0];
        int curLargestEnd = intervals[0][1];
        
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][0] <= curLargestEnd) {
                if(intervals[i][1] > curLargestEnd) {
                    curLargestEnd = intervals[i][1];
                }
            } else {
                result.push_back({curStart, curLargestEnd});
                curStart = intervals[i][0];
                curLargestEnd = intervals[i][1];
            }
        }
        
        result.push_back({curStart, curLargestEnd});
        return result;
    }
};
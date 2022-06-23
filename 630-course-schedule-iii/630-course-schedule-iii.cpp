class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<pair<int, int>> maxH;
        int currentTotalTime = 0;
        
        for(vector<int> itr : courses) {
            maxH.push({itr[0], itr[1]});
            currentTotalTime += itr[0];
            if(currentTotalTime > itr[1]) {
                currentTotalTime -= maxH.top().first;
                maxH.pop();
            }
        }
        
        return maxH.size();
    }
};
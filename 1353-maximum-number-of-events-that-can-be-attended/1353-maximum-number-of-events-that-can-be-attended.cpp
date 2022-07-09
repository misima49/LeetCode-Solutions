// struct heapComp {
//     bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
        
//     }
// }

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> minh;
        int n = events.size();
        sort(events.begin(), events.end());
        
        int ans = 0, day = 0, i = 0;
        
        for(day = 1; day <= 100000; day++) {
            while(minh.size() && minh.top() < day) minh.pop();

            while(i < n && events[i][0] <= day) {
                minh.push(events[i][1]);
                i++;
            }
            // cout << i << " ";
            if(minh.size() && minh.top() >= day){
                ans++;
                minh.pop();
            }
        }
        
        return ans;
    }
};
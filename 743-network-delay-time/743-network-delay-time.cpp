class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(vector<int> itr : times) {
            adj[itr[0]].push_back({itr[1], itr[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        vector<int> time(n+1, 1e8);
        time[0] = -1e8;
        time[k] = 0;
        minH.push({0, k});
        
        while(!minH.empty()) {
            int curDist = minH.top().first;
            int curNode = minH.top().second;
            minH.pop();
            
            for(pair<int, int> itr : adj[curNode]) {
                if(time[itr.first] > curDist + itr.second) {
                    time[itr.first] = curDist + itr.second;
                    minH.push({time[itr.first], itr.first});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            // cout << time[i] << " ";
            if(time[i] == 1e8) return -1;
            if(time[i] > ans) ans = time[i];
        }
        
        return ans;
    }
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) return 0;
        int finalState = (1 << n) - 1;
        
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        
        for(int i = 0; i < n; i++) {
            visited.insert({i, (1 << i)});
            q.emplace(i, 1 << i);
        }
        
        int shortestPath = 0;
        while(!q.empty()) {
            shortestPath++;
            int sz = q.size();
            while(sz--) {
                int curNode = q.front().first;
                int curBitStat = q.front().second;
                // cout << curNode << " " << curBitStat << "\n";
                q.pop();
                for(int itr : graph[curNode]) {
                    int newBitStat = (1 << itr) | curBitStat;
                    if(newBitStat == finalState) return shortestPath;
                    if(visited.find({itr, newBitStat}) == visited.end()) {
                        q.emplace(itr, newBitStat);
                        visited.insert({itr, newBitStat});
                    }
                }
            }
        }
        
        return -1;
    }
};
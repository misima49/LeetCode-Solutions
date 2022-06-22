#define red 0
#define blue 1
using vvp = vector<vector<pair<int, int>>>;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vvp graph(n);
        
        for(vector<int> itr : redEdges) {
            graph[itr[0]].push_back({itr[1], red});
        }
        
        for(vector<int> itr : blueEdges) {
            graph[itr[0]].push_back({itr[1], blue});
        }
        
        vector<vector<int>> distance(n, vector<int>({-1, -1}));
        
        queue<pair<int, int>> q;
        distance[0] = {0, 0};        
        q.emplace(0, red);
        q.emplace(0, blue);
        
        while(!q.empty()) {
            auto [curNode, curCol] = q.front();
            q.pop();

            for(pair<int, int> itr : graph[curNode]) {
                if(curCol != itr.second && 
                   (distance[itr.first][itr.second] == -1 ||
                        distance[itr.first][itr.second] > distance[curNode][curCol]+1)) {
                    distance[itr.first][itr.second] = distance[curNode][curCol]+1;
                    q.emplace(itr.first, itr.second);
                }
            }
        }
        
        vector<int> ans;
        for(vector<int> itr : distance) {
            if(itr[0] < itr[1]) {
                if(itr[0] != -1) ans.push_back(itr[0]);
                else ans.push_back(itr[1]);
            } else {
                if(itr[1] != -1) ans.push_back(itr[1]);
                else ans.push_back(itr[0]);
            }
        }
        
        return ans;
    }
};
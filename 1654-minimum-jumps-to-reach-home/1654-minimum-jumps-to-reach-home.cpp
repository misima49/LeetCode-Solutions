struct hashFunction
    {
        size_t operator()(const pair<int , bool> &x) const{
        return x.first ^ x.second;
    }

};

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if(x == 0) return 0;
        unordered_set<int> forb(forbidden.begin(), forbidden.end());
        unordered_set<pair<int, bool>, hashFunction> visited;
        int ans = 0;
        int lim = 6000;
        queue<pair<int, bool>> q;
        
        q.emplace(0, false);
        visited.insert({0, false});
        
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            
            while(sz--) {
                int cur = q.front().first;
                bool canMoveBack = q.front().second;
                q.pop();
                cout << cur << " ";
                if(cur+a < lim && forb.find(cur+a) == forb.end()
                   && visited.find({cur+a, true}) == visited.end()) {
                    if(cur+a == x) return ans;
                    
                    q.emplace(cur+a, true);
                    visited.insert({cur+a, true});
                }
                
                if(canMoveBack && cur-b >= 0 && forb.find(cur-b) == forb.end()
                   && visited.find({cur-b, false}) == visited.end()) {
                    if(cur-b == x) return ans;
                    
                    q.emplace(cur-b, false);
                    visited.insert({cur-b, false});
                }
            }
        }
        
        return -1;
    }
};
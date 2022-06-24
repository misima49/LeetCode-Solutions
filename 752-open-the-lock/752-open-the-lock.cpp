class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        unordered_set<string> locked(deadends.begin(), deadends.end());
        queue<string> q;
        int ans = 0;
        
        if(locked.count("0000")) return -1;
        
        locked.insert("0000");
        q.push("0000");
        
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            while(sz--) {
                string cur = q.front();
                // cout << cur << " ";
                q.pop();
                for(int i = 0; i < 4; i++) {
                    string nextCode = cur;
                    string prevCode = cur;
                        
                    if(nextCode[i] == '9') {
                        nextCode[i] = '0';
                    } else {
                        nextCode[i]++;
                    }
                    
                    if(prevCode[i] == '0') {
                        prevCode[i] = '9';
                    } else {
                        prevCode[i]--;
                    }
                    
                    if(nextCode == target || prevCode == target) return ans;
                    
                    if(!locked.count(nextCode)) {
                        q.push(nextCode);
                        locked.insert(nextCode);
                    }
                    
                    if(!locked.count(prevCode)) {
                        q.push(prevCode);
                        locked.insert(prevCode);
                    }
                }
            }
        }
        
        return -1;
    }
};
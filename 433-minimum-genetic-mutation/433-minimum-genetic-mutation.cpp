#define dir vector<char>({'A', 'C', 'G', 'T'})
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end) return 0;
        
        unordered_set<string> visited;
        unordered_set<string> validGene(bank.begin(), bank.end());
        if(validGene.find(end) == validGene.end()) return -1;
        
        queue<string> q;
        int ans = 0;
        validGene.insert(start);
        visited.insert(start);
        
        q.push(start);
        
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            while(sz--) {
                string cur = q.front();
                q.pop();
                
                for(int itr = 0; itr < 8; itr++) {
                    string newGene = cur;
                    for(int i = 0; i < 4; i++) {
                        newGene[itr] = dir[i];
                        if(visited.find(newGene) == visited.end() 
                           && validGene.find(newGene) != validGene.end()) {
                            if(newGene == end) return ans;
                            visited.insert(newGene);
                            q.push(newGene);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};
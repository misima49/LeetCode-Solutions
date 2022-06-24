class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end) return 0;
        
        unordered_set<string> validGene(bank.begin(), bank.end());
        if(validGene.find(end) == validGene.end()) return -1;
        
        queue<string> q;
        int ans = 0;
        validGene.erase(start);
        
        q.push(start);
        
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            while(sz--) {
                string cur = q.front();
                q.pop();
                
                for(int itr = 0; itr < 8; itr++) {
                    string newGene = cur;
                    for(char ch : string("ACGT")) {
                        newGene[itr] = ch;
                        if(validGene.find(newGene) != validGene.end()) {
                            if(newGene == end) return ans;
                            validGene.erase(newGene);
                            q.push(newGene);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};
class Solution {
    bitset<20> taken;
    bool findSeq(vector<int>& ans, int ind, int n) {
        if(ind == n*2-1) return true;
        if(ans[ind] != -1) return findSeq(ans, ind+1, n);
        for(int i = n; i > 1; i--) {
            if(!taken[i] && ind+i < n*2-1 && ans[ind+i] == -1) {
                ans[ind] = ans[ind+i] = i;
                taken[i] = 1;
                
                if(findSeq(ans, ind+1, n)) return true;
                
                taken[i] = 0;
                ans[ind] = ans[ind+i] = -1;
            }
        }
        if(!taken[1]) {
            ans[ind] = 1;
            taken[1] = 1;
            if(findSeq(ans, ind+1, n)) return true;
            taken[1] = 0;
            ans[ind] = -1;
        }
        
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(n*2-1, -1);
        findSeq(ans, 0, n);
        return ans;
    }
};
class Solution {
public:
    string getPermutation(int n, int k) {
        string answer = "";
        vector<int> nInts;
        int fact = 1;
        for(int i = 1; i <= n; i++) {
            nInts.push_back(i);
            fact *= i;
        }
        fact /= n;
        k--;
        
        while(true) {
            answer.append(to_string(nInts[k/fact]));
            nInts.erase(nInts.begin() + k/fact);
            
            if(nInts.size() == 0)
                break;
            
            k = k % fact;
            fact /= nInts.size();
        }
        
        return answer;
    }
};
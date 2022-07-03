#define mod 1000000007

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        unordered_map<int, long long> knows;
        long long ans = 1;
        knows.insert({1, 1});
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                if(j <= i-forget) {
                    if(knows.find(j) != knows.end()) {
                        ans -= knows[j];
                        knows.erase(j);
                    }
                } else if(j <= i-delay) {
                    if(knows.find(j) != knows.end()) {
                        ans += knows[j];
                        knows[i] += knows[j]%mod;
                    }
                }
                
                ans = ans%mod;
            }
            
            // cout << "Day " << i << " people " << knows[i] << "\n"; 
        }
        
        return ans%mod;
    }
};
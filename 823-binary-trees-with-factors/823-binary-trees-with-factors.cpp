#define mod 1000000007
class Solution {
    long long findTree(int ind, vector<int>& arr, unordered_map<int, long long>& a, unordered_map<int, long long>& dp) {
        int n = arr.size();
        
        // cout << ind << " ";
        if(dp.count(ind)) return dp[ind];
        
        long long ans = 1;
        
        for(int i = ind+1; i < n; i++) {
            if(arr[ind]%(long long)arr[i] == 0 && a.count(arr[ind]/arr[i])) {
                ans = (ans + findTree(i, arr, a, dp) * findTree(a[arr[ind]/arr[i]], arr, a, dp))%mod;
            }
        }
        
        return dp[ind] = ans;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        unordered_map<int, long long> a;
        for(int i = 0; i < arr.size(); i++) {
            a[arr[i]] = i;
        }
        unordered_map<int, long long> dp;
        
        for(int i = 0; i < arr.size(); i++) {
            if(!dp.count(i)) findTree(i, arr, a, dp);
        }
        
        long long ans = 0;
        for(auto& itr : dp) {
            ans = (ans + itr.second)%mod;
        }

        return ans;
    }
};
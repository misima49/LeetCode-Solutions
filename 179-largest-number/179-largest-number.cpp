class Solution {
    bool static sortComp(int a, int b) {
        if(a == 0) return false;
        if(b == 0) return true;
        int digitsA = (int)log10(a)+1;
        int digitsB = (int)log10(b)+1;
        
        long long aFirst = a*pow(10, digitsB) + b;
        long long bFirst = b*pow(10, digitsA) + a;
        
        return aFirst > bFirst;
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), sortComp);
        if(nums[0] == 0) return "0";
        string ans = "";
        for(int itr : nums) {
            ans.append(to_string(itr));
        }
        
        return ans;
    }
};
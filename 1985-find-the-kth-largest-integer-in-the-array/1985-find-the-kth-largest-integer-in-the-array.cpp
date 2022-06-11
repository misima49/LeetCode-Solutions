class compFunc {
    public:
        int operator() (string& a, string& b) {
            if(a.length() == b.length()) 
                return a > b;
            else 
                return a.length() > b.length();
        }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, compFunc> minH;
        
        cout << ("123" < "2");
        
        for(string num : nums) {
            minH.push(num);
            if(minH.size() > k)
                minH.pop();
        }
        
        return minH.top();
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        stack<int> st;
        
        for(int num : nums2) {
            if(st.empty()) {
                st.push(num);
            } else if(st.top() < num) {
                while(!st.empty() && st.top() < num) {
                    hash[st.top()] = num;
                    st.pop();
                }
                
                st.push(num);
            } else {
                st.push(num);
            }
        }
        
        vector<int> ans(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++) {
            if(hash.find(nums1[i]) != hash.end()) {
                ans[i] = hash[nums1[i]];
            }
        }
        
        return ans;
    }
};
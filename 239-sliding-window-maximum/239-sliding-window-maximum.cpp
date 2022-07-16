class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int>l;
        vector<int>v;
        int i =0 , j=0;
        while(j<nums.size()){
            while(l.size()>0 && l.back()<nums[j]){
                l.pop_back();
            }
            // cout << j << " ";
            l.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else {
                v.push_back(l.front());
                if(nums[i]==l.front()){
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
        return v;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        int el0 = -1, el1 = -1;
        int count0 = 0, count1 = 0;
        
        for(int i = 0; i < n; i++) {
            if(el0 == nums[i]) count0++;
            else if(el1 == nums[i]) count1++;
            else if(count0 == 0) {
                el0 = nums[i];
                count0++;
            } else if(count1 == 0) {
                el1 = nums[i];
                count1++;
            } else {
                count0--;
                count1--;
            }
        }
        count0 = count1 = 0;
        for(int itr : nums) {
            if(itr == el0) count0++;
            if(itr == el1) count1++;
        }
        
        if(count0 > nums.size()/3) answer.push_back(el0);
        if(count1 > nums.size()/3 && el1 != el0) answer.push_back(el1);
        return answer;
    }
};
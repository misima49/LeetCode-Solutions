class Solution {
    int merge(int start, int mid, int end, vector<int>& nums) {
        int j = mid+1;
        int count = 0;
        for(int i = start; i <= mid; i++) {
            while(j <= end && nums[i] > 2LL*nums[j]) {
                j++;
            }
            count += j-mid-1;
        }
        
        vector<int> temp;
        int left = start, right = mid+1;
        
        while(left <= mid && right <= end) {
            if(nums[left] < nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        
        while(left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= end) {
            temp.push_back(nums[right]);
            right++;
        }
        
        for(int itr = start, i = 0; itr <= end; itr++) {
            nums[itr] = temp[i++];
        }
        
        return count;
    }
    
    int mergeSort(int start, int end, vector<int>& nums) {
        if(start >= end) {
            return 0;
        }

        int mid = start + (end-start)/2;
        int count = mergeSort(start, mid, nums);
        count += mergeSort(mid+1, end, nums);
        count += merge(start, mid, end, nums);
        
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0, n-1, nums);
    }
};
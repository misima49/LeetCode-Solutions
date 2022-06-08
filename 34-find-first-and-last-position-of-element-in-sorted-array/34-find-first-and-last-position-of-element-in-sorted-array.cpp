class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int start = 0;
        int end = nums.size()-1;
        int mid = (end - start)/2;
        
        while(start < end && start <= mid && mid <= end) {
            // cout << start << " " << mid << " " << end << "\n";
            if(nums[mid] == target) break;
            else if(nums[mid] < target)
                start = mid+1;
            else 
                end = mid-1;
            
            mid = start + (end-start)/2;
        }
        
        // cout << "here";
        if(mid >= nums.size() || nums[mid] != target) return {-1, -1};
        
        start = end = mid;
        while((start > 0 && nums[start-1] == target) || (end < nums.size()-1 && nums[end+1] == target)) {
            if(start > 0 && nums[start-1] == target) start--;
            if(end < nums.size()-1 && nums[end+1] == target) end++;
            
        }
        
        return {start, end};
    }
};
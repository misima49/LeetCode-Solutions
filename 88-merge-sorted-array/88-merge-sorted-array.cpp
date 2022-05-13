class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n;
        m--, n--;
        while(i--) {
            if(m < 0) {
                nums1[i] = nums2[n];
                n--;
            } else if(n < 0) {
                nums1[i] = nums1[m];
                m--;
            } else if(nums1[m] > nums2[n]) {
                // cout << "added from nums1 "<< nums1[m] << i << "\n";
                nums1[i] = nums1[m];
                m--;
            } else {
                // cout << "added from nums2 " << nums2[n] << i << "\n";
                nums1[i] = nums2[n];
                n--;
            }
        }
    }
};
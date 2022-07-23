class Solution {
    vector<int> ans;
    unordered_map<int, int> origElementIndex;
    
    void merge(vector<int>& nums, vector<int>& indices, int st, int ed) {
        int md = st + (ed-st)/2;
        int len1 = md-st+1;
        int len2 = ed-md;
        vector<int> vec1(indices.begin()+st, indices.begin()+md+1);
        vector<int> vec2(indices.begin()+md+1, indices.begin()+ed+1);
        
        int itr1 = 0, itr2 = 0;
        int itrOrig = st;
        int count = 0;
        while(itr1 < len1 && itr2 < len2) {
            if(nums[vec1[itr1]] <= nums[vec2[itr2]]) {
                ans[vec1[itr1]] += count;
                indices[itrOrig++] = vec1[itr1++];
            } else {
                count++;
                indices[itrOrig++] = vec2[itr2++];
            }
        }
        // cout << "here";
        
        while(itr1 < len1) {
            ans[vec1[itr1]] += count;
            indices[itrOrig++] = vec1[itr1++];
        }
        
        while(itr2 < len2) {
            indices[itrOrig++] = vec2[itr2++];
        }
    }
    
    void mergeSort(vector<int>& nums, vector<int>& indices, int st, int ed) {
        if(st >= ed) return;
        
        // cout << st << " " << ed << "\n";
        
        int md = st + (ed-st)/2;
        mergeSort(nums, indices, st, md);
        mergeSort(nums, indices, md+1, ed);
        
        merge(nums, indices, st, ed);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n, 0);
        vector<int> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);
        mergeSort(nums, indices, 0, n-1);
        
        return ans;
    }
};
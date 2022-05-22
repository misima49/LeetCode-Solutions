struct hashFunction 
{
      size_t operator()(const vector<int> &myVector) const 
      {
        std::hash<int> hasher;
        size_t answer = 0;

        for (int i : myVector) 
        {
          answer ^= hasher(i) + 0x9e3779b9 + (answer << 6) + (answer >> 2);
        }
        return answer;
      }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        if(nums.size() < 4) return answer;
        int n = nums.size();
        long long int curSum = 0LL;
        unordered_set<vector<int>, hashFunction> exist; 
        sort(nums.begin(), nums.end());
        
        int i = 0, j = 1, s = 2, e = n-1;
        
        
        for(int i = 0; i <= n-4; i++) {
            for(int j = i+1; j <= n-3; j++) {
                s = j+1;
                e = n-1;
                while(s < e) {
                    curSum = (long long int)(nums[i]+nums[j])+nums[s]+nums[e];
                    if(curSum == target) {
                        if(exist.find({nums[i], nums[j], nums[s], nums[e]}) == exist.end()) {
                            exist.insert({nums[i], nums[j], nums[s], nums[e]});
                            answer.push_back({nums[i], nums[j], nums[s], nums[e]});
                        }
                        s++;
                    } else if(curSum < target) {
                        s++;
                    } else {
                        e--;
                    }
                }
            }
            
        }
        
        return answer;
    }
};
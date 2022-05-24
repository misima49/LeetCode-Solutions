// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        int answer = 0;

        unordered_map<int, int> exist;
        int curSum = 0;
        for(int i = 0; i < n; i++) {
            curSum += nums[i];
            if(curSum == 0) {
                answer = max(answer, i+1);
                exist.insert({curSum, i});
            }
            if(exist.find(curSum) == exist.end()) {
                exist.insert({curSum, i});
            } else {
                exist.insert({curSum, i});
                answer = max(answer, i-exist.find(curSum)->second);
            }
        }
        
        return answer;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
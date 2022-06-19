class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string cur = "";
        vector<vector<string>> ans;
        
        for(char ch : searchWord) {
            cur.push_back(ch);
            vector<string> suggestions;
            auto itr = lower_bound(products.begin(), products.end(), cur);
            for(int i = 0; i < 3 && itr != products.end(); i++) {
                if((*itr).find(cur)) break;
                suggestions.push_back(*itr);
                itr++;
            }
            ans.push_back(suggestions);
        }
        
        return ans;
    }
};
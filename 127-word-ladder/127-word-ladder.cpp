class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> validWord(wordList.begin(), wordList.end());
        if(!validWord.count(endWord)) return 0;
        
        int n = beginWord.length();
        int transCount = 1;
        queue<string> q;
        
        q.push(beginWord);
        validWord.erase(beginWord);
        
        while(!q.empty()) {
            int sz = q.size();
            transCount++;
            while(sz--) {
                string cur = q.front();
                q.pop();
                
                // cout << cur << " ";
                
                for(int i = 0; i < n; i++) {
                    string newWord = cur;
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        newWord[i] = ch;
                        if(validWord.count(newWord)) {
                            if(newWord == endWord) return transCount;
                            q.push(newWord);
                            validWord.erase(newWord);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};
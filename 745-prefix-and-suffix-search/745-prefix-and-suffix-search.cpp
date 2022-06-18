struct Node {
private:
    Node* links[27];
    int idx;
public:
    Node* getNext(char ch) {
        // if(ch == '#') {
        //     return links[26];
        // }
        return links[ch-'a'];
    }
    
    void insertLink(char ch, Node* nNode) {
        // if(ch == '#')
        //     links[26] = nNode;
        links[ch-'a'] = nNode;
    }
    
    void setIdx(int i) {
        idx = i;
    }
    
    bool containsChar(char ch) {
        // if(ch == '#')
        //     return links[26] != NULL;
        return links[ch-'a'] != NULL;
    }
    
    int getIdx() {
        return idx;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word, int i) {
        Node* itr = root;
        
        for(char ch : word) {
            if(!itr->containsChar(ch)) {
                itr->insertLink(ch, new Node());
            }
            
            itr = itr->getNext(ch);
            itr->setIdx(i);
        }
        
    }
    
    int searchPrefix(string prefix) {
        Node* itr = root;
        for(char ch : prefix) {
            if(!itr->containsChar(ch)) {
                return -1;
            } else {
                itr = itr->getNext(ch);
            }
        }
        
        return itr->getIdx();
    }
};

class WordFilter {
    Trie* trie;
public:
    WordFilter(vector<string>& words) {
        trie = new Trie();
        
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            int wordLen = word.length();
            
            for(int j = 0; j < wordLen; j++) {
                string temp = word.substr(j, wordLen - j);
                temp.push_back('{');
                temp.append(word);
                trie->insert(temp, i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string searchStr = suffix.append("{" + prefix);
        return trie->searchPrefix(searchStr);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
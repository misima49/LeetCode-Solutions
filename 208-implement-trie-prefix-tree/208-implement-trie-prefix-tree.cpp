struct Node {
    Node* links[26];
    bool wordEnd = false;
    
    bool containsChar(char ch) {
        return links[ch-'a'];
    }
    
    Node* getNext(char ch) {
        return links[ch-'a'];
    }
    
    void insertLink(char ch, Node* nNode) {
        links[ch-'a'] = nNode;
    }
    
    void setEnd() {
        wordEnd = true;
    }
    
    bool isEnd() {
        return wordEnd;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *itr = root;
        for(char ch : word) {
            if(!(itr->containsChar(ch))) {
                itr->insertLink(ch, new Node());
            }
            
            itr = itr->getNext(ch);
        }
        
        itr->setEnd();
    }
    
    bool search(string word) {
        Node* itr = root;
        for(char ch : word) {
            if(itr->containsChar(ch)) {
                itr = itr->getNext(ch);
            } else 
                return false;
        }
        
        return itr->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* itr = root;
        for(char ch : prefix) {
            if(itr->containsChar(ch)) {
                itr = itr->getNext(ch);
            } else 
                return false;
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
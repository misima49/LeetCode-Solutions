class TextEditor {
    stack<char> left;
    stack<char> right;
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(char c:text) {
            left.push(c);
        }
    }
    
    int deleteText(int k) {
        int count = 0;
        while(!left.empty() && k > 0) {
            left.pop();
            k--;
            count++;
        }
        
        return count;
    }
    
    string cursorLeft(int k) {
        char c;
        while(!left.empty() && k > 0) {
            c = left.top();
            left.pop();
            right.push(c);
            k--;
        }
        
        return stringTillCursor();
    }
    
    string cursorRight(int k) {
        char c;
        while(!right.empty() && k > 0) {
            c = right.top();
            right.pop();
            left.push(c);
            k--;
        }
        
        return stringTillCursor();
    }
    
    string stringTillCursor() {
        string cur = "";
        int len = 10;
        
        while(!left.empty() && len > 0) {
            cur.push_back(left.top());
            left.pop();
            len--;
        }
        
        reverse(cur.begin(), cur.end());
        
        for(char c:cur) {
            left.push(c);
        }
        
        return cur;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
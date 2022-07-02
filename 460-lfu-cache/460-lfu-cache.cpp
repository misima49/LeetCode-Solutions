struct Node {
    int key, value;
    int freq;
    Node *prev, *next;
    Node(int _key = -1, int _val = -1) {
        key = _key;
        value = _val;
        freq = 1;
    }
};

class dll {
    Node* head;
    Node* tail;
    int sz = 0;
    
public:
    dll() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        sz = 0;
    }
    
    void insertNode(Node* node) {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
        sz++;
    }
    
    void delNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        sz--;
    }
    
    void deleteLRU() {
        delNode(tail->prev);
    }
    
    Node* get_tail() {return tail;}
    
    int get_size() {return sz;}
    
};

class LFUCache {
    map<int, dll*> freq_list;
    map<int, Node*> key_node;
    int min_freq;
    int cache_cap;
    int total_cap;
    
    void updateNodeFreq(Node* node) {
        freq_list[node->freq]->delNode(node);
        
        if(freq_list[node->freq]->get_size() == 0 && node->freq == min_freq){
            min_freq++;
            freq_list.erase(node->freq);
        }
        
        node->freq++;
        
        dll* new_dll = new dll();
        if(freq_list.find(node->freq) != freq_list.end()) {
            new_dll = freq_list[node->freq];
        }
        
        freq_list[node->freq] = new_dll;
        new_dll->insertNode(node);
    }
public:
//     void printFreqList() {
//         cout << "Cur freq list:\n";
//         for(auto itr : freq_list) {
//             cout << itr.first << " " << itr.second->get_size() << "\n";
//         }
//     }
    
    LFUCache(int capacity) {
        min_freq = 0;
        total_cap = cache_cap = capacity;
    }
    
    int get(int key) {
        if(key_node.find(key) == key_node.end()) return -1;
        
        Node* node = key_node[key];
        updateNodeFreq(node);
        // printFreqList();
        return node->value;
    }
    
    void put(int key, int value) {
        if(total_cap == 0) return;
        
        
        if(key_node.find(key) != key_node.end()) {
            Node* node = key_node[key];
            node->value = value;
            updateNodeFreq(node);
            return;
        }
        
        if(!cache_cap) {
            key_node.erase(freq_list[min_freq]->get_tail()->prev->key);
            freq_list[min_freq]->deleteLRU();
            cache_cap++;
        }
        cache_cap--;
        min_freq = 1;
        dll* new_dll = new dll();
        
        if(freq_list.find(min_freq) != freq_list.end()) new_dll = freq_list[min_freq];
        
        Node* new_node = new Node(key, value);
        new_dll->insertNode(new_node);
        key_node[key] = new_node;
        freq_list[min_freq] = new_dll;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
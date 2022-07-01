class LRUCache {
    size_t lruCap;
    unordered_map<int, list<pair<int, int>>::iterator> lruMap;
    list<pair<int, int>> lruCache;
public:
    LRUCache(size_t capacity):lruCap(capacity) {}
    
    int get(int key) {
        // cout << "\nGet: " << key;
        auto found_itr = lruMap.find(key);
        if(found_itr == lruMap.end()) return -1;
        else {
            lruCache.splice(lruCache.begin(), lruCache, found_itr->second);
            return found_itr->second->second;
        }
    }
    
    void put(int key, int value) {
        // cout << "\nPut: " << key;
        auto found_itr = lruMap.find(key);
        if(found_itr != lruMap.end()) {
            found_itr->second->second = value;
            lruCache.splice(lruCache.begin(), lruCache, found_itr->second);
            return;
        }
        
        if(lruCache.size() == lruCap) {
            int lastEle = lruCache.back().first;
            lruMap.erase(lastEle);
            lruCache.pop_back();
        }
        
        lruCache.emplace_front(key,  value);
        lruMap[key] = lruCache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
public:
    int capacity;
    unordered_map<int,int>freq,lru;
    queue<int>lru_hist;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(lru.count(key)){
            lru_hist.push(key);
            freq[key]++;
            return lru[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        lru_hist.push(key);
        freq[key]++;
        lru[key] = value;

        if(lru.size() > this->capacity) {
            remove();
        }
    }

    void remove() {
        while(!lru_hist.empty()) {
            int curr = lru_hist.front();
            lru_hist.pop();
            freq[curr]--;
            if(freq[curr] == 0) {
                lru.erase(curr);
                break;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

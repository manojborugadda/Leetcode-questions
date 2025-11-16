
class LFUCache {
private: 
    // For obtaining value
    unordered_map<int, pair<int, int>> keyToVal; // Key to {value, frequency}

    // For dealing with LFU and LRU
    unordered_map<int, list<int>> freqToKeys; // Frequency to keys
    
    int size;
    int keys;
    int minFreq;

public:
    LFUCache(int capacity) {
        size = capacity;
        keys = 0;
        minFreq = 1;
    }
    
    int get(int key) {
        if (keyToVal.find(key) == keyToVal.end()){
            return -1;
        }
        // Remove from previous frequency
        int prevFreq = keyToVal[key].second++; // Set new frequency
        freqToKeys[prevFreq].remove(key);

        // If it was minimum frequency and only key in list
        if (prevFreq == minFreq && freqToKeys[prevFreq].empty()){ 
            minFreq++;
        }

        // Add to front for most recently used
        freqToKeys[prevFreq+1].push_front(key);
        return keyToVal[key].first;
    }
    
    void put(int key, int value) {
        // For edge case so we do not try to remove a 0 capacity cache
        if (size == 0){ 
            return;
        }

        // We can use 'get' to check if key already exists and to increment frequency
        if (get(key) != -1){ 
            keyToVal[key].first = value;
            return;
        }

        if (size == keys){
            // Must remove LFU + LRU key
            keyToVal.erase(freqToKeys[minFreq].back()); 
            freqToKeys[minFreq].pop_back(); 
            keys--;
        }

        keys++;
        minFreq = 1; // Min freq is always 1 after inserting new key
        keyToVal[key] = {value, 1};
        freqToKeys[minFreq].push_front(key);
    }
};

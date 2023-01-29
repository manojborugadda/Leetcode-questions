class LFUCache { //TC:O(1)  SC:O(N)
public:
    map<int,int>val,freq,rec;
    int c = 0 , curr_cap = 0;
    set<pair<int,pair<int,int>>>s;
    int cap;
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(val.find(key) != val.end()) {
            c++;
            int fr = freq[key];
            int curr_c = rec[key];
            auto it = s.find({fr,{curr_c, key}});
            s.erase(it);
            fr++;
            curr_c = c;
            freq[key] = fr;
            rec[key] = curr_c;
            s.insert({fr,{curr_c, key}});
            return val[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap == 0) {
            return;
        }
        if(val.find(key) == val.end()) {
            if(curr_cap >= cap) {
                auto it = s.begin();
                int k = it->second.second;
                s.erase(it);
                val.erase(k);
                freq.erase(k);
                rec.erase(k);
                curr_cap--;
                put(key,value);
            } else {
                c++;
                val[key] = value;
                int fr = 1;
                int curr_c = c;
                freq[key] = fr;
                rec[key] = curr_c;
                s.insert({fr, {curr_c, key}});
                curr_cap++;
            }
        } else {
            c++;
            val[key] = value;
            int fr = freq[key];
            int curr_c =rec[key];
            auto it = s.find({fr,{curr_c, key}});
            s.erase(it);
            fr++;
            curr_c = c;
            freq[key] = fr;
            rec[key] = curr_c;
            s.insert({fr,{curr_c, key}});
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

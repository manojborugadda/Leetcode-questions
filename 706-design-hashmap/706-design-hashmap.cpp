class MyHashMap { // SC: O(1000000) as it is given in the problem
public:
    vector<int>ans;
    MyHashMap() {
        ans.resize(1e6+1,-1);
    }
    
    void put(int key, int value) {
        ans[key] = value; // TC:O(1)
    }
    
    int get(int key) {
        return ans[key]; // TC:O(1)
    }
    
    void remove(int key) { // TC:O(1)
        put(key,-1);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
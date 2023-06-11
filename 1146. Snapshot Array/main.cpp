/**
 Time complexity: O(1) for set() and snap(). O(log snapshots) for get() since it performs a binary search using upper_bound to find the snapshot ID.
Space complexity: O(length * snapshots) since it uses a vector of maps to store snapshots.
 */


class SnapshotArray {
public:
    vector<map<int,int>>vec;
    int ID = 0; 
    SnapshotArray(int length) {
        vec.resize(length);
        for(int i = 0 ;i<length;i++) {
            vec[i][0] = 0;
        }
    }
    
    void set(int index, int val) {
        vec[index][ID] = val;
    }
    
    int snap() {
        return ID++;
    }
    
    int get(int index, int snap_id) {
        if(vec[index].find(snap_id) != vec[index].end()) {
            return vec[index][snap_id];
        }

        auto it = --(vec[index].upper_bound(snap_id));
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */


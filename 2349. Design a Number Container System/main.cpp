class NumberContainers {//solved this using SETS, HASHMAPS but we can do using HASHMAPS& HEAPS
public:
    unordered_map<int,set<int>>numToidx;
    unordered_map<int,int>idxTonum;

    NumberContainers() {
    }
    
    void change(int index, int number) {//O(log n)
        if(idxTonum.count(index)) {
            int num = idxTonum[index];
            numToidx[num].erase(index);
            if(numToidx[num].size() == 0)  numToidx.erase(num);
        }
        idxTonum[index] = number;
        numToidx[number].insert(index);
    }
    
    int find(int number) {//TC:O(1)
        if(numToidx.count(number) == 0) {
            return -1;
        }
        //numToidx[number].begin() --> gives the location of that particular idx not VALUE
        return *(numToidx[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

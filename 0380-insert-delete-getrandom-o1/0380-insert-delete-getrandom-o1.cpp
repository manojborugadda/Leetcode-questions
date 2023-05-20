class RandomizedSet { //TC:O(1) SC:O(N)
public:
     
    unordered_map<int,int>map; //storing the ELEMENT and and its INDEX in the Map
    vector<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.count(val) == true ) { //if the val is present before hand in the MAP
            return false;
        }
        //if it is not present in the map we insert into vector
        v.push_back(val);
        map[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(map.count(val) == false) {//if the element is not present in the MAP before 
            return false;
        }
        //for removing the element "val" in O(1) time complexity we have to use vector here otherwise it could leads to O(N) if we use MAP alone
        
        //take the last element of the vector
        int lastValue = v.back(); //we can write this also ------> v[v.size()-1]
        int index = map[val]; //index of the element in MAP which has to be removed
        v[index] = lastValue; //put the lastValue at "index" in the vector
        map[lastValue] = index; //updating the lastValue in the MAP
        v.pop_back();
        map.erase(val);
        return true;
        
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
//     //What is the rand in C++?
//" rand() function" is an inbuilt function in C++ STL, which is defined in header file <cstdlib>. rand() is used to generate a series of random numbers
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

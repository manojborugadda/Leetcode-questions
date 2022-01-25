class Solution {
public:
    string destCity(vector<vector<string>>& paths)
    {
       set<string>s;
        
        for(auto row:paths){    // inserting the destination cities into the HASH SET
            s.insert(row[1]);
        }
        
        for(auto row:paths)        //now checking if the originating cities are there in HASH SET and                                              erasing if its there
        {
            if(s.count(row[0]) > 0){
                s.erase(row[0]);
            }
        }
        
        for(auto x:s){         // returning the answer which is there in the HASH SET
            return x;
        }
        
        return "";
    }
};
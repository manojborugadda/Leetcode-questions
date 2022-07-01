class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){ //Comparator function for the logic of sort
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int total_units = 0;
        sort(boxTypes.begin(),boxTypes.end(),comp);
        //[[1,3],[2,2],[3,1]] sorting on the basis of second element in the vector
        //[[1,3],[2,2],[3,1]]   after sorting
        for(int i = 0;i<boxTypes.size();i++){
                int k = min(truckSize,boxTypes[i][0]);
                total_units = total_units + (k * boxTypes[i][1]);
                truckSize = truckSize-k;
            if(truckSize==0) break;// truckSize is used completely
        }
        
        return total_units;
    }
};
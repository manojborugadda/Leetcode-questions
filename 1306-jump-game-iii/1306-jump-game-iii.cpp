class Solution {//Time Complexity : O(n) because all indexes are being visited only once
                //Space Complexity : O(n) visited array
public:
    
    bool recur(vector<int>& arr, int index,vector<int>&visited){
//if the start is less than 0 OR greater than array size OR the cell is already visited we return FALSE
        if(index < 0 or index >= arr.size() or visited[index]){
            return false;
        }
        //if the given start index is pointing to 0 we return TRUE
        if(arr[index]==0){
            return true;
        }
        // mark that position as TRUE;
        visited[index]  = true;
        
        return recur(arr,index+arr[index],visited) or recur(arr,index-arr[index],visited);
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>visited(n,false);
        return recur(arr,start,visited);
    }
};



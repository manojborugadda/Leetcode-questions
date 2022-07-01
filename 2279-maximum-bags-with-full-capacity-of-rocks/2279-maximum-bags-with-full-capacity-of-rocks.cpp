class Solution { //TC:O(nlogn)+O(n)   SC:O(1)
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int count = 0;
        //for Example capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
        
        //transforming of capacity vector which has the differences values from rock vector
        for(int i  = 0;i<n;i++){
            capacity[i] = capacity[i]-rocks[i];
        }// after transforming Capacity vector looks like [1,1,0,1]
        
        sort(capacity.begin(),capacity.end()); // afer sorting [0,1,1,1]  //TC:O(nlogn)
        
        for(int i = 0;i<n;i++) //TC:O(n)
        {
            if(capacity[i]==0){//if it is already matched
                count++;
            }else if(additionalRocks >= capacity[i]){ 
                additionalRocks -= capacity[i];
                count++;
            }else{ //additionalRocks == 0
                break;
            }
        }
        return count;
    }
};
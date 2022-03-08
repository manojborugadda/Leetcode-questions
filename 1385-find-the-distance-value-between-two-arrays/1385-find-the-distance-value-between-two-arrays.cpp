class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 =   arr1.size();
        int count  = 0;
        while(n1--){
            bool check = true;
            for(int i = 0;i<arr2.size();i++){
                if(abs(arr1[n1]-arr2[i]) <= d){
                    check = false;
                    break;
                }
            }
            if(check) count++;
        }
        return count;
    }
};
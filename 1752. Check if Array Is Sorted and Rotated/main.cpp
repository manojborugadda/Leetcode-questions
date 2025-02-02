class Solution {//tc:o(n)  sc:o(1)
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if( n <= 1) return true;
        int count = 0;//inversion count // PIVOT POSITION kind of
        for(int i = 1;i<n;i++) {
            if(nums[i] < nums[i-1]) {
                count++;
            }
        }

        //check between the last and first element due to rotation
        if(nums[0] < nums[n-1]) count++;
        if( count <=1) return true; // it has to be one PIVOT position for any array which is rotated and sorted 
        else return false;
    }
};

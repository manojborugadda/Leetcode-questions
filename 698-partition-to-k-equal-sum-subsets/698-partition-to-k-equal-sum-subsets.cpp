class Solution {
private:
    
    vector<bool> used;
    int target;
    
    bool subsetSum(vector<int> &N, int i, int sum, int k){
        
		// Base cases
		if(k == 1) return true;
        if(sum == target) return subsetSum(N, 0, 0, k-1);
        if(i == N.size() || N[i] > target) return false;
        
		// Put element at i to bucket k
        if(used[i] ==0  and N[i]+sum <= target){
            used[i] = 1;
            if(subsetSum(N, i+1, sum+N[i], k))
				return true;
            used[i] = 0;
            
        }
		
		// Skip i
        return subsetSum(N, i+1, sum, k);
    }
	
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int N = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        //if sum of all elements of array is not equal to Zero it means it is not divisible by k and we cant divide the array int K non empty subsets
//         // if no.of elements in the array are less than K then we cant go forward 
        if(sum % k == 1 or N < k) return false;
        
        used.resize(N, 0);
        target = sum/k;
        
        return subsetSum(nums, 0, 0, k);
    }
};
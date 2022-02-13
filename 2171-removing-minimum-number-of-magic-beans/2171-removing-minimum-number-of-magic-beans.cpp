class Solution {
public:
    long long minimumRemoval(vector<int>& beans){
        
      long long n = beans.size();
        
        sort(beans.begin(), beans.end());
        
        long long remaining = INT_MIN;
        
        for(int i=0; i<n; i++){
            remaining = max(remaining, beans[i] * (n - i));  
        }
        
        //accumulate(): This function returns the sum of all the values lying in a range between [first, last] or [first,last,sum] where sum = initial value of the sum
        
        return accumulate(beans.begin(), beans.end(), (long long)0) - remaining; 
    }
};
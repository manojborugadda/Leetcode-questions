class Solution { //TC:O(max number) SC:O(1)
public:
    #define ll long long
    vector<long long> maximumEvenSplit(long long finalSum) {
// if the given finalSum is odd we return empty vector as it can't be formed by adding even numbers
        if(finalSum%2==1) return {}; 
        vector<ll>ans; // ans vector--------
        // as per the problem we can only take UNIQUE EVEN Positive Integers
        // we start taking numbers from 2,4,6,8,10......so on only even numbers
        ll sum = 0 , i = 2;
        while(i+sum <= finalSum){
            ans.push_back(i);
            sum = sum+i;
            i += 2;
        }
    // if current sum is EQUAL to finalSum we return the ans vector
// if current sum is NOT equal to finalSum we subtract the sum with last element in the answer vector.
        //we pop the last element in the ans vector
        // we push the "finalSum-sum"
        if(sum != finalSum){
          sum = sum-ans.back();   
          ans.pop_back();
          ans.push_back(finalSum-sum);  
        }
        return ans;
    }
};
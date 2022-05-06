// assume initially ans=k
// arr=[2,3,4,7,11] , k=5
// 2<=5 => k=6
// 3<=6 => k=7
// 4<=7 => k=8
// 7<=8 => k=9

class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		for(auto i : arr){
         if(i<=k){
             k++;   
        }
	}
        return k;
    }
};
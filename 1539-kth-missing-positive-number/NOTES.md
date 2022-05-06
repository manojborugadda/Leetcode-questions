class Solution {
public:
int findKthPositive(vector<int>& arr, int k
int L = 0 ;
int R = arr.size();
int count = 0;
while(L < R){
int mid = L + (R - L)/2;
if(arr[mid] - (mid + 1)  >= k)
R = mid;
else
L = mid + 1;
}
return L + k;
​
}
};
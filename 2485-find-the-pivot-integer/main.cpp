class Solution {//using BINARY SEARCH TC:O(nlogn) sc:O(1)
public:
    int pivotInteger(int n) {
        int left = 0 , right = n;
        int fullSum = (n*(n+1))/2;
        while(left <= right) {
            int midNum = (left + right) >> 1;//calculating the mid element
            int firsthalfSum = (midNum*(midNum+1))/2;
            int secondhalfSum = fullSum - firsthalfSum + midNum;
            if(firsthalfSum == secondhalfSum ) {
                return midNum;
            }else if(firsthalfSum < secondhalfSum) {
                left = midNum + 1;
            }else {
                right = midNum - 1;
            }
        }
        return -1;
    }
};

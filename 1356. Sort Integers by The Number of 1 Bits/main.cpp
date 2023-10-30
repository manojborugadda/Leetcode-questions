class Solution {
public:
    static int numberOf1s(int a) {
        int count = 0;
        while(a) {
            a = a&(a-1);
            count++;
        }
        return count;
    }
    static bool compare(int a,int b) {
        int p = numberOf1s(a);
        int q = numberOf1s(b);
        if(p == q) {
            return (a <= b);
        }else {
            return (p < q);
        }
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr),end(arr),compare);
        return arr;
    }
};

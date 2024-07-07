class Solution {///TC:O(no.of bottles/no.Exchange) SC:O(1)
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        int n = numBottles;
        while(n/numExchange > 0) {
            int a = n/numExchange;
            int b = n%numExchange;
            sum += a;
            n = a + b;
        }
        return sum;
    }
};

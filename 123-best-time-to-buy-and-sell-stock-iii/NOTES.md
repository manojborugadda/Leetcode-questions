https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/1846219/Easy-C%2B%2B-oror-Time-O(n)-and-Space-O(1)-oror-Explained
​
```
int maxProfit(vector<int>& prices) {
int firstBuy=INT_MAX,firstSell=0,secondBuy=INT_MAX,secondSell=0;
for(int currPrice : prices)
{
firstBuy=min(firstBuy,currPrice);                    // minimum price for 1st buy
firstSell=max(firstSell,currPrice-firstBuy);         // maximum profit after 1st sell
secondBuy=min(secondBuy,currPrice-firstSell);        // minimum price for 2nd buy after removing profit from 1st sell
secondSell=max(secondSell,currPrice-secondBuy);      // maximum profit after 2nd sell
```
return secondSell;
}
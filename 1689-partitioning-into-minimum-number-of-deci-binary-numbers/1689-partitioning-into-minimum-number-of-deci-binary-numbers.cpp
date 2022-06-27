class Solution { //by our observation here we have to find the largest element in the number
public:
    int minPartitions(string n) {
     return *max_element(n.begin(),n.end())-'0';   
    }
};

//                     //another approach
// //TC:O(N) SC:O(1)
// class Solution {
// public:
//     int minPartitions(string n) {
//         int ans=0;
//         for (char c: n) ans = max(c-'0',ans);
//         return ans;
//     }
// };


                                // EXPLANATION---------
// 3 2------given number
//-1 1 ---count = 1

// 2 0
//-1 0  ----count = 2

// 1 0
//-1 0-----count = 3

// 0 0-------STOP as we cant go further
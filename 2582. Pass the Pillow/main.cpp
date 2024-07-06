class Solution {//TC:O(TIME)  SC:O(1)
public:
    int passThePillow(int n, int time) {
        int i = 1;
        while(time > 0) {
            while(i < n and time > 0) {
            i++;
            time--;
        }
        while(i > 1 and time > 0) {
            i--;
            time--;
        }
    }
        return i;
    }
};

//Another approach for solving

// class Solution {
// public:
//     int passThePillow(int n, int time) 
//     {
//         int stand = 1, flag = 1;
//         while(time--)
//         {
//             if(flag)
//             {
//                 stand++;
//                 if(stand == n) flag = !flag;
//             }
//             else 
//             {
//                 stand--;
//                 if(stand == 1) flag = !flag;
//             }
//         }
//         return stand;
//     }
// };

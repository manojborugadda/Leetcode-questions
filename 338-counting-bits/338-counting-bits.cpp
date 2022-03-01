class Solution {
public:
    vector<int> countBits(int n){
       if(n==0) return {0};
          vector<int>ans(n+1);
        ans[0] = 0;// since bits of '0' is 0
        for(int i = 1;i<=n;i++){
            int count = 0;
            int num = i;
            while(num>0){
                count = count+num%2;
                num = num/2;
            }
            ans[i] = count;
        }
    return ans;
    }
    
//             another way of doing this problem
// //         1) itoa (i,buffer,2);
// //          2) std::bitset<8> b(42);
// //         3) std::bitset<8>(n).to_string()
    // above are the ways to convert Decimal to Binary
                //  vector<int>ans;
//         string temp;
//         int count = 0;
//         int i = 0;
//         while(i<=n){
//             temp  = bitset<8>(i).to_string();
//             for(int i=0;i<temp.length();i++){
//                 if(temp[i]=='1') count++;
//             }
//             ans.push_back(count);
//             count  = 0;
//             temp = "";
//             i++;
//         }
//     return ans;
    
};
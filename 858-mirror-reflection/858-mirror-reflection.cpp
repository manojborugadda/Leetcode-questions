//----------------------------APPROACH 1 ------------------------

/*
                    """""""Linear Diophantine Equation"""""""
 np - mq = 0     ------> m and n are Coefficients
 calculating the coefficients 'm' and 'n'
 n = q/gcd(p,q)
 m = p/gcd(p,q)
 //////////
 1.if n is EVEN and np becomes EVEN then it will strike by 0 no.of times
 2.if n is ODD we will check the 'q' IF it is ODD or EVEN 
 /// EQUATION ------>  m * q = n * p
 if 'm' is EVEN ray meets the receptor 2 and if 'm' is ODD the ray meets the receptor 1
*/

// class Solution {
// public:
//     int mirrorReflection(int p, int q) {
//         int hcf = gcd(p,q);
//         int n = q/hcf;
//         int m = p/hcf;
        
//         if(n%2 != 0){
//             if(m %2 == 0) return 2;
//             else{
//                 return 1;
//             }
//         }else{
//             return 0;   
//         }
//     }

//     int gcd(int a , int b){
//         if(a==0) return b;
//         return gcd(b%a,a);
//     }
// };

//----------------------------APPROACH 2------------------------
///////////////////////////////////////////////////////////////////////////
//           https://www.youtube.com/watch?v=b_Z3LBErlSs
class Solution {
public:
    int mirrorReflection(int p, int q) {
        //if p and q are EVEN we divide until any of them (or) Both becomes ODD
        while(p% 2 == 0 and q%2 ==0){
            p = p/2;
            q = q/2;
        }
        
        if(p%2 != 0 and q%2 == 0) return 0; // if P is ODD and Q is EVEN
        else if(p%2 == 0 and q%2 != 0) return 2; //if P is EVEN and Q is ODD
        else if(p%2 != 0 and q%2 != 0) return 1; //if both are ODD
        else return -1; // none of the above is happening
    }
};


/*So we can divide this question in three parts :

Division with its own multiple for eg. 8 / 4 = 2
Division without repeating numbers after decimal for eg. 41 / 2 = 20.5
Division with repeating numbers after decimal for eg. 14 / 3 = 4.(6) or 47 / 18 = 2.6(1)
*/


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
///The labs() function in C++ returns the absolute value of a long or long int data.
        
        //base cases
        if(denominator == 0) return "";
        if(numerator == 0) return "0";
        
        string ans; // answer string
        //if any of numerator or denominator is NEGATIVE we keep '-' before the ans
        if (numerator < 0 ^ denominator < 0) ans += '-';
        
        long num = labs(numerator) , den = labs(denominator) ;//taking the absolute values
        long quotient = num/den;
        long remainder = num%den;
        ans += to_string(quotient); //adding to our answer string
        if(remainder == 0) return ans; ///Division happened with its multiple
        else ans += '.' ; // if remainder is not ZERO
        
        unordered_map<long,int>map;
        
        while(remainder != 0){
//If the remainder is already in the map then we insert the “(” opening bracket at the position of that rem and lastly append a “)” closing bracket and break out of the loop and return the ans.
            if(map.find(remainder)!= map.end()){
                int position = map[remainder];
                ans.insert(position,"(");
                ans += ")";
                break;
            }else{//Division without repeating numbers after decimal for eg. 41 / 2 = 20.5
                
                map[remainder] = ans.length();
                remainder *= 10; //remainder = remainder*10
                quotient = remainder/den;
                remainder = remainder%den;
                ans += to_string(quotient);
            }
        }
        return ans;
    }
};


/*A bit wise XOR (exclusive or) operates on the bit level and uses the following Boolean truth table:

true OR true = false
true OR false = true
false OR false = false


*/
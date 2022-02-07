class Solution {
public:
    long long smallestNumber(long long num)
    {
        string s = to_string(num);
        if(num==0) return num;
        if(num<0){
            sort(s.begin(), s.end(), greater<char>());
            return -stoll(s);
        }
        //if(num>0)
        sort(s.begin(), s.end());
        if(s[0]=='0'){
            for(int i=0; i<s.length(); i++){
                if(s[i]!='0'){
                    swap(s[i], s[0]);
                    break;
                }
            }
        }
//std::stoll(): This function converts a string, provided as an argument in the function call, to long long int.
        return stoll(s);
            
    }
};
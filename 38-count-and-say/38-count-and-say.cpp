class Solution {
public:
    string countAndSay(int n) {
        string result = "1", current;
        while(--n){
            current = "";
            for(int i=0;i<result.size();i++){
                int count = 1;
                while(i < result.size()-1 && result[i] == result[i+1]){
                    count++;
                    i++;
                }
                current +=  to_string(count) + result[i] ;
            }
            result = current;
        }
        return result;
    }
};
class Solution {
public:
    
    bool check(char x){

    if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u') return true;
    else return false;
}
long long countVowels(string word) {
    
    long long ans=0;
    
    
    for(int i=0;i<word.size();i++)
    {
        
        if(check(word[i])){
            ans+=((i+1)*(word.size() -i));
        }
    }
    return ans;
    }
};
class Solution {
public:
    string capitalizeTitle(string title)
    {
          stringstream ss(title);        
        string m;
        string y = "";
        while(ss>>m){
            int n = m.size();
            if(n <= 2){
                for(int i = 0; i<n; i++){
                    m[i] = tolower(m[i]);
                } 
            }
            else{
                m[0] = toupper(m[0]);
                for(int i = 1; i<n; i++){
                    m[i] = tolower(m[i]);
                }
            }
            y += m + ' ';
        }
        y.pop_back();
        return y;
    }
};
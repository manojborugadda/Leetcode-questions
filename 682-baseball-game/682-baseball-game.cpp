class Solution {
public:
    int calPoints(vector<string>& ops) {
       
         stack<int>s;
        int a  = 0;
        int b = 0;
        int ans = 0;
        
        for(int i  = 0;i<ops.size();i++){  
                if(ops[i]=="C"){
                    s.pop();
                }
                else if(ops[i]=="D"){
                    s.push(s.top()*2);
                }
                else if(ops[i]== "+"){
                    a = s.top();
                    s.pop();
                    b = a + s.top();
                    s.push(a);
                    s.push(b);
                }
                else{
                    s.push(stoi(ops[i]));
            }
        }
            
            while(!s.empty()){
                ans = ans+s.top();
                s.pop();
            }
          return ans; 
        } 
};
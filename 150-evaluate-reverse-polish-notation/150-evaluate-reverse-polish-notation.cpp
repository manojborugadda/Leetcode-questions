class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // creating a stack which will contain integer values
        stack<int> s;             
        int n=tokens.size();
        // traversing the string
        for(int i=0;i<n;i++)
        {
            // if we encounter a character which is not (+,-,*,/) then we will first convert it into an integer and then push in stack
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/")
            {
                stringstream geek(tokens[i]);
                int x = 0;
                geek >> x;
                s.push(x);
                
            }
            // else if we encounter any character that is any operator, then we will pop two integers from stack and then perform the operation
            // and then push the resultant again into stack.
            else
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int res=0;
                if(tokens[i]=="+")
                {
                    res=a+b;
                }
                else if(tokens[i]=="-")
                {
                    res=b-a;
                }
                else if(tokens[i]=="*")
                {
                    res=a*b;
                }
                else if(tokens[i]=="/")
                {
                    res=b/a;
                }
                s.push(res);
            }
            
            
            
        }
        return s.top();
        
        
    }
};

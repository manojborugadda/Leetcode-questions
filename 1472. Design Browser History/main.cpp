class BrowserHistory {
    public:
    stack<string> b,f;

    //TC:O(m x l)  m-->is the largest length of the string and l--->no.of strings
    BrowserHistory(string homepage) {
        b.push(homepage);
    }
    
    //we have clear all the history of FORWARD before visiting
    void visit(string url) {//TC:O(1) 
        while(!f.empty()){
            f.pop();
        }
        b.push(url);
        //cout<<b.size()<<endl;
    }
    
    string back(int s) {//tc:o(steps) but technically it is no.of urls
        while(b.size()>1 and s){
            if(b.empty()) break;
            f.push(b.top());
            b.pop();
            s--;
        }
        return b.top();
    }
    
    string forward(int s) {//TC:O(STEPS) but  technically it is no.of urls
        while(s--){
            if(f.empty()) break;
            b.push(f.top());
            f.pop();
        }
        return b.top();
    }
};

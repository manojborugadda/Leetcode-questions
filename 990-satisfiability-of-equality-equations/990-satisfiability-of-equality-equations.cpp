class Solution {
public:
    
    int parent[26];
    int Size[26];
    
    int find(int v){
        if(v == parent[v]){
            return v;
        }
        return parent[v] = find(parent[v]);
    }
    
    void Union(int a, int b){
        
        a = find(a);
        b = find(b);
        
        if(a!=b){
            if(Size[a] < Size[b]){
                swap(a,b);
            }
            parent[b] = a;
            Size[a] += Size[b];
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++){
            parent[i] = i;
            Size[i] = 1;
        }
        
        for(auto x : equations){
            if(x[1] == '=')
                Union(x[0]-'a', x[3]-'a');
        }
                
        for(auto x : equations){

            if(x[1] == '!'){
                int a = find(x[0]-'a');
                int b = find(x[3]-'a');
                
                if(a == b){
                    return false;
                }
            }
        }
        
        return true;
    }
};
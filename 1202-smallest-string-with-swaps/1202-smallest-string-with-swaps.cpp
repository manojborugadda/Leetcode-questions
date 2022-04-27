class Solution {
public:
    vector<vector<int>>graph;  // for the matrix purpose
    vector<bool>visited;
    
    
     void dfs(int i,vector<int>&index,vector<char>&letters,string &s){
        
        visited[i] = true;
        letters.push_back(s[i]);
        index.push_back(i);
        
/// again we check if the element is visited or Not like 0-->1 and 1-->0.If NOT then we will go to another element
    
        for(auto j : graph[i]){  
            if(visited[j]==false){
                dfs(j,index,letters,s);
            }
        }
    }
    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.size();
        graph.resize(n);
        visited.resize(n,false);
        
        /// creating the matrix from the undirected graph we got 
        for(auto x: pairs){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        for(int i = 0;i<n;i++){
            
            vector<int>index;
            vector<char>letters;
            
            if(visited[i]== false){
                dfs(i,index,letters,s);
            }
            
            sort(index.begin(),index.end());
            sort(letters.begin(),letters.end());
        
        
       for(int i=0;i<index.size();i++){
            s[index[i]] = letters[i];
        }
   }
        
        return s;
    }
};
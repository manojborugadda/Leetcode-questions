class Solution {
public:
    double dfs(string a,string&b,unordered_map<string,unordered_map<string,double>>graph,unordered_set<string>&visited){
        
    if(graph[a].find(b)!=graph[a].end())  /// if we got the valid pair directly like ["a","b"] and  its reverse["b","a"]
    {
       return graph[a][b]; 
    }
        for(auto node :graph[a]){  // if we didnot get valid pair directly, we will check for every node
            
        if(visited.find(node.first)==visited.end()){   // if we didnot find in the visited set then we will add
            
            visited.insert(node.first);
            double val=dfs(node.first,b,graph,visited);  // again we see for the child nodes for valid pairs
            
            if(val)
            {
                graph[a][b]=node.second*val;
                return graph[a][b];
            }
        }
    }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        
       vector<double>ans;   // answer vector for storing the values
       unordered_map<string,unordered_map<string,double>>graph; // map containing String as KEY and map of(String,Double) as VALUE;
        
       for(int i=0;i<equations.size();i++)
       {
           graph[equations[i][0]][equations[i][1]]=values[i];
           graph[equations[i][1]][equations[i][0]]=(double) 1/(values[i]);  // reversal of above pair
       }
        
       for(int i=0;i<queries.size();i++){
           
           unordered_set<string>visited;
           double val=dfs(queries[i][0],queries[i][1],graph,visited);
           
           if(!val)
           {
               ans.push_back(-1.0);
           }
           
           else
           {
               ans.push_back(val);
           }
           
       }
        return ans;
    }
};
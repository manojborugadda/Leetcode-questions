class Solution {
public:
    void dfs(vector<char> adj[], char node, char minCharacter, vector<char>& visited)
    {
        // to this character, replace it with it's minimum character
        visited[node - 'a'] = minCharacter;
        
        // travel in neighbour of this character,
        // i.e travel in component of this character
        for(char& near: adj[node - 'a'])
        {
            // if this character is not visited, call dfs for it
            if(visited[near - 'a'] == '#')
            {
                dfs(adj, near, minCharacter, visited);
            }
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(); // extract size
        
        vector<char> adj[26]; // declaring adjacency matrix
        
        // travel through strings and establish connection
        for(int i = 0; i < n; i++)
        {
            adj[s1[i] - 'a'].push_back(s2[i]);
            adj[s2[i] - 'a'].push_back(s1[i]);
        }
        
        // make a visited vector of size 26
        // and symbol, '#' denotes that this particular character is not visited yet
        vector<char> visited(26, '#');
        
        // now, travel through each character
        for(char c = 'a'; c <= 'z'; c++)
        {
            // if this character is not visited yet, call dfs here 
            if(visited[c - 'a'] == '#')
            {
                // as we are calling dfs for each character, so
                // it will minimum value for that component.
                dfs(adj, c, c, visited);
            }
        }
        
        // Now lastly, replace each baseStr character with their 
        // minimum found out character in their component,
        for(int i = 0; i < baseStr.size(); i++)
        {
            baseStr[i] = visited[baseStr[i] - 'a'];
        }
        
        // return baseStr now, 
        return baseStr;
    } 
};

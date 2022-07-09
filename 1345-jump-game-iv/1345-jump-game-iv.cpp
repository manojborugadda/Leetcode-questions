class Solution { //TC:O(N)   SC:O(N)
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>indicesOfValues;
        //inserting the elements into the MAP
        for(int i = 0;i<n;i++){
            indicesOfValues[arr[i]].push_back(i);
        }
        
        vector<bool>visited(n,false); //visit array
        visited[0] = true; //initially we push first element index
        int steps = 0; // answer variable
        queue<int>q; // queue for BFS traversal
        q.push(0); 
        
        while(q.empty()==false){
            for(int size = q.size();size>0;size--){//If the level completed we increment Step
                int i = q.front();
                q.pop();
                if(i==n-1) return steps;// it means we reached the last index
                
                /*pushing elements into the next vector which has 
                    i + 1 where: i + 1 < arr.length.
                    i - 1 where: i - 1 >= 0.
                    j where: arr[i] == arr[j] and i != j*/
                vector<int>next = indicesOfValues[arr[i]];
                next.push_back(i+1);
                next.push_back(i-1);
                //pushing the elements in the NEXT Vector into the QUEUE as per conditions
                for(auto j : next){
                    if(j >= 0 and j < n and visited[j]==false){
                        visited[j] = true;
                        q.push(j);
                    }
                }
                //clearing the value of the key in the MAP for avoiding the later lookUp
                indicesOfValues[arr[i]].clear();//// avoid later lookup indicesOfValue arr[i]
            }
            steps++;
            
        }
        return steps;
    }
};
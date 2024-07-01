class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DSU(int n){
        parent.resize(n+1);
        for(int i = 1; i<=n; i++){  //Remember here parent 1 se start ho raha hai n taak hoga that why we use (n+1) as a parent and rank size:
            parent[i] = i;
        }
        rank.resize(n+1);
        components=n;
    }


     //STANDARD APPLICATIN OF DISJOINT SET FIND;
    int find (int x) {
        if (x == parent[x]) 
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    //STANDARD APPLICATION OF DISJOINT SET UNION;
    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        
        if (x_parent == y_parent) 
            return;
        
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
        }
        components--;
    }
  
    bool isSingleComponents(){
        return components==1;
    }
};

class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2){
        return v1[0]>v2[0];
    }    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);
       
        // auto cmp = [](vector<int> &vec1,vector<int> &vec2){ //lamda sorting:
        //     return vec1[0]>vec2[0];
        // };

        sort(edges.begin(),edges.end(),cmp);  //so that type 3 wale phale fix ho jaay:

        int edgeCount = 0;
        for(auto &vec : edges){
            int type = vec[0];
            int u = vec[1];
            int v = vec[2];

            if(type==3){
                //Alice
                bool addedge_or_not = false;

                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u,v);
                    addedge_or_not = true;
                }
  
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u,v);
                    addedge_or_not = true;
                }

                if(addedge_or_not==true){
                    edgeCount++;
                }

            }
            else if(type==2){
                     //BOb;
                    if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u,v);
                    edgeCount++;
                  }
            }
            else{
                //Alice:
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u,v);
                    edgeCount++;
                }
            }
        }
     
      if(Alice.isSingleComponents() == true && Bob.isSingleComponents()==true){
          return edges.size() - edgeCount;
      }
      return -1;
    
    }
};

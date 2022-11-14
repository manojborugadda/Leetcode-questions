class Solution {
public:
    vector<int>parent,size;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        size.resize(n);
        parent.resize(n);
        
        for(int i = 0;i<n;i++) {
            make(i);
        }
        
        int components = n;
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]) {
                    Union(i,j,components);
                }
            }
        }
        return n - components;
    }
    
    void make(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    
    void Union(int a,int b,int &components) {
    //we connect the small tree into the Large tree always
  //here 'a' is the LARGE tree and 'b' is the SMALL tree
  //we connect on the basis of SIZE and RANK usually
         a = find(a);
         b = find(b);
      if(a != b) {
        //UNION by SIZE
        if(size[a] < size[b]) {
          swap(a,b);
        }
          
        parent[b] = a;
        components--;
        size[a] += size[b];
          
        }
    }
    
    int find(int v) {
      if(v == parent[v]) return v;
      //Path Compression
      return parent[v] = find(parent[v]);
    }   
};
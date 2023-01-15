class Solution {
public:
    // function to find the parent of a given element in the union-find data structure
    int find(vector<int>& parent, int a) {
        // if the element is its own parent, return the element
        if(parent[a] == a)
            return a;
        // otherwise, set the parent of the element to be the parent of its parent and return that parent
        parent[a] = find(parent, parent[a]);
        return parent[a];
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        // create a vector to store the parents of each element
        vector<int> parent(n);
        // create maps to store the maximum element and count of elements in each connected component
        map<int,int> maxel;
        map<int, int> count;

        // initialize the parent vector and maps
        for(int i=0;i<n;i++){
            parent[i] = i;
            maxel[i] = vals[i];
            count[i] = 1;
        }

        // sort the edges based on the maximum value of the vertices in the edge
        sort(edges.begin(), edges.end(), [&](const vector<int>& a, vector<int>& b)
        {
            int m = max(vals[a[0]], vals[a[1]]);
            int n = max(vals[b[0]], vals[b[1]]);
            return m<n;
        });
        int ans=n;
        // for each edge, find the connected components of the vertices and union them
        for(auto edge : edges){
            int a = find(parent, edge[0]);
            int b = find(parent, edge[1]);
            if(maxel[a] != maxel[b]){
                // if the maximum element in the two connected components is different, set the parent of the connected component with smaller maximum value to be the parent of the connected component with the larger maximum value
                if(maxel[a] > maxel[b])
                    parent[b] = a;
                else
                    parent[a] = b;
            }
            else{
                // if the maximum element in the two connected components is the same, set the parent of the connected component with the smaller index to be the parent of the connected component with the larger index, and update the count of the new connected component
                parent[a] = b;
                ans += count[a] * count[b];
                count[b] += count[a];
            }
        }
        // return the total number of connected components plus the number of good paths
        return ans;
    }
};

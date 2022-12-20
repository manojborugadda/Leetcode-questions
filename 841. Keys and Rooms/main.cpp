class Solution { //TC:O(N)  SC:O(N)
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(0); //pushing the room number 0 as it is not LOCKED
        visited[0] = true;
        while(!q.empty()) {
            int curr_room = q.front();
            q.pop();
            for(int key : rooms[curr_room]) {
                if(!visited[key]) { //if the room is not visited before
                    visited[key] = true;
                    q.push(key);
                }
            }
        }
        //finding in the VISITED array if any room is not VISITED
        if( find( begin(visited),end(visited),false) != end(visited)) {
            return false;
        }
        return true;
    }
};

//https://www.geeksforgeeks.org/how-to-find-index-of-a-given-element-in-a-vector-in-cpp/

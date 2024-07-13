

class Solution {//TC:O(nlogn) SC:O(N)
public:
    struct Robot{
        int index;
        int position;
        int health;
        char direction;
    };

    void handleCollisions(stack<Robot>& st, Robot& robot) {
        // collide with robots going right with less healths -> current robot wins
        while (!st.empty() && st.top().direction == 'R' && st.top().health < robot.health) {
            st.pop();
            robot.health--;
        }

        // collide with robot going right with equal or greater health
        if (!st.empty() && st.top().direction == 'R') { 
            // equal health - both loses
            // greater health -> current robot loses
            if (st.top().health == robot.health)
                st.pop();
            else
                st.top().health--;
        } else {    // no more robot going right 
            st.push(robot);
        }
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        // attach index to robots
        vector<Robot> robots;
        for(int i=0; i<n; i++)
            robots.push_back({i, positions[i], healths[i], directions[i]});
        
        // sort robots based on position
        sort(robots.begin(), robots.end(), [](const auto &a, const auto &b){
            return a.position < b.position;
        });
    
        // Consider robots from left to right and handle collisions using stack
        stack<Robot> st;
        for(Robot& robot : robots){
            if(robot.direction == 'R')
                st.push(robot);
            else
                handleCollisions(st, robot);
        }

        // store remaining robots in stack in a vector
        robots.clear();         // reuse same robots vector
        while(!st.empty()){
            robots.push_back(st.top());
            st.pop();
        }

        // sort robot as per index as ans needs to be returned in same order as given
        sort(robots.begin(), robots.end(), [](const auto &a, const auto &b){
            return a.index < b.index;
        });

        // store health of robots in ans
        vector<int> ans;
        for(Robot robot : robots)
            ans.push_back(robot.health);

        return ans;
    }
};

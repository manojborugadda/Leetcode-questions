https://leetcode.com/problems/ipo/solutions/3220046/greedy-explained-video-java-c-python/

Time Complexity and Space Complexity:
Time complexity: O(N log N + K log N) = O(N log N), where N is the number of projects and K is the number of projects that we can select. Sorting the "projects" vector takes O(N log N) time, and adding and removing elements from the priority queue takes O(log N) time. The while loop that adds the available projects to the priority queue runs at most N times, and the for loop that selects the projects to complete runs K times.
Space complexity: O(N + N) = O(N), where N is the number of projects. The space is used to store the "projects" vector. The priority queue used in the solution has a maximum size of N,
https://www.youtube.com/watch?v=MC72LV0gxHc

https://leetcode.com/problems/ipo/solutions/3220067/simplest-solution-beginner-friendly-priority-queue-c-python3/

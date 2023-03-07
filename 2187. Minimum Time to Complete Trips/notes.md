```
Given time taken per trip = [1,2,3].
Let's say that at t = 0, trips = [0,0,0] since all three buses are on standby.
At t = 1, trips = [1,0,0], bus 1 has completed 1 trip, bus 2 has completed 1/2 a trip, and bus 3 has completed 1/3 of a trip.
At t = 2, trips = [2,1,0], bus 1 has completed 2 trips, bus 2 has completed 2/2 a trip or 1 trip, and bus 3 is still at 2/3 of a trip.
At t = 3, trips = [3,1,1], bus 1 has completed 3 trips, bus 2 has completed 1 + 1/2 trips, and bus 3 has completed 3/3 == 1 trip.


https://www.youtube.com/watch?v=2KwJ0zHBGI8

https://leetcode.com/problems/minimum-time-to-complete-trips/solutions/3267038/c-detailed-image-explanation-binary-search-easy-to-understand/
```

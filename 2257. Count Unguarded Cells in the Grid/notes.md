✅ Pros:

Easy to control the spread in four directions step-by-step.
Naturally prevents infinite loops if you track visited cells.
Good for shortest-path-like problems (though here it’s just spreading vision).
⚠️ Cons:

Slightly more overhead due to queue operations.
You’ll still need to stop early when hitting walls/guards, so BFS doesn’t give much extra benefit over a simple directional scan.
For large grids, BFS might be slower than just scanning in straight lines from each guard

So BFS is fine, but here directional scanning might be simpler and faster.

--------------------------------------------------------

✅ Pros:
Simple to implement recursively.
Easy to follow a single direction until you hit a wall or a guard.
No extra queue structure like BFS — just the call stack.
⚠️ Cons:
Recursive DFS can hit stack limits if the grid is very large (though constraints here are safe).
You’ll need to manage visited cells to avoid looping carefully.
Like BFS, it still requires stopping early when hitting obstacles, so directional scanning might be simpler.
So both BFS and DFS work, but directional scanning could be the cleanest here since guard vision is straight lines.

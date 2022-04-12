class Solution {
public:
// Helper function to check validility of neighbor
bool isValidNeighbor(int x, int y, vector<vector<int>>& board) {
return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
}
void gameOfLife(vector<vector<int>>& board) {
// All directions of neighbors
vector<int> ways_x = {0, 0, 1, 1, 1, -1, -1, -1};
vector<int> ways_y = {1, -1, 1, -1, 0, 0, 1, -1};
for (int row = 0; row < board.size(); row++) {
for (int col = 0; col < board[0].size(); col++) {
int count_live_neighbors = 0;
// Loop to count all live neighbors
for (int i = 0; i < 8; i++) {
int curr_x = row + ways_x[i], curr_y = col + ways_y[i];
if (isValidNeighbor(curr_x, curr_y, board) && abs(board[curr_x][curr_y]) == 1)
count_live_neighbors++;
}
// Rules 1 and 3: -1 indicates a cell that was live but now is dead.
if (board[row][col] == 1 && (count_live_neighbors < 2 || count_live_neighbors > 3))
board[row][col] = -1;
// Rule 4: 2 indicates a cell that was dead but now is live.
if (board[row][col] == 0 && count_live_neighbors == 3)
board[row][col] = 2;
}
}
// Get the final board
for (int row = 0; row < board.size(); row++) {
for (int col = 0; col < board[0].size(); col++) {
if (board[row][col] >= 1)
board[row][col] = 1;
else
board[row][col] = 0;
}
}
}
};
https://www.youtube.com/watch?v=-2DdS-SnBGg


// alternative solution
''
vector<vector<int>> generateMatrix(int n) {
vector < vector <int> > res(n, vector<int>(n, 0));
int total = n*n, start = 1;
int x = 0, y=-1;
while(start <= total)
{
for(int i=0; i<n; i++)
res[x][++y] = start++;
for(int i=0; i<n-1; i++)
res[++x][y] = start++;
for(int i=0; i<n-1; i++)
res[x][--y] = start++;
for(int i=0; i<n-2; i++)
res[--x][y] = start++;
n -= 2;
}
return res;
}
''

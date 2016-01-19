class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0)
            return 0;
        int col = grid[0].size();
        int number = 0;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(grid[i][j] == '0' || grid[i][j] == 'v')
                    continue;
                DFS(grid, i, j, row, col);
                number++;
            }
        }
        return number;
    }
    void DFS(vector<vector<char>>& grid, int r, int c, int row, int col){
        grid[r][c] = 'v';
        if(r+1<row && grid[r+1][c] =='1')
            DFS(grid, r+1, c, row, col);
        if(c+1<col && grid[r][c+1] =='1')
            DFS(grid, r, c+1, row, col);
        if(r-1>=0 && grid[r-1][c] =='1')
            DFS(grid, r-1, c, row, col);
        if(c-1>=0 && grid[r][c-1] =='1')
            DFS(grid, r, c-1, row, col);
    }
};

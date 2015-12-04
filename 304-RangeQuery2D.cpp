class NumMatrix {
public:
    vector<vector<int>> Mymatrix;
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size()==0)
            return;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int j=1;j<col;++j){
            matrix[0][j] += matrix[0][j-1];
        }
        for(int i=1;i<row;++i){
            matrix[i][0] += matrix[i-1][0];
        }
        for(int i=1;i<row;++i){
            for(int j=1;j<col;++j){
                matrix[i][j] += (matrix[i][j-1]+matrix[i-1][j]-matrix[i-1][j-1]);
            }
        }
        Mymatrix = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int t1 = (row1==0||col1==0)?0:Mymatrix[row1-1][col1-1];
        int t2 = (row1==0)?0:Mymatrix[row1-1][col2];
        int t3 = (col1==0)?0:Mymatrix[row2][col1-1];
        return Mymatrix[row2][col2] -(t2+t3-t1);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);


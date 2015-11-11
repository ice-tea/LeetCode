class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rn = matrix.size();
        int cn = matrix[0].size();
        int r = 0;
        int c = 0;
        while(r<rn){
            if(matrix[r][0] > target)
                break;
            r++;
        }
        if(r==0)
            return false;
        while(c < cn){
            if(matrix[r-1][c] == target)
                return true;
            c++;
        }
        return false;
    }
};

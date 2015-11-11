class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZeor = false;
        bool firstColZeor = false;
        int rn = matrix.size();
        int cn = matrix[0].size();
        int r=0,c=0;
        while(c<cn){
            if(matrix[0][c++]==0){
                firstRowZeor = true;
                break;
            }
        }
        while(r<rn){
            if(matrix[r++][0]==0){
                firstColZeor = true;
                break;
            }
        }
        
        for(int i=1;i<cn;++i){
            for(int j=1;j<rn;++j){
                if(matrix[j][i] == 0){
                    matrix[0][i] = 0;
                    matrix[j][0] = 0;
                }
            }
        }
        
        for(int i=1;i<cn;++i){
            for(int j=1;j<rn;++j){
                if(matrix[0][i] == 0 || matrix[j][0]==0){
                    matrix[j][i] = 0;
                }
            }
        }
        
        if(firstRowZeor)
            for(int i =0; i< cn; i++)
                matrix[0][i] =0;
        if(firstColZeor)
            for(int i =0; i< rn; i++)
                matrix[i][0] =0;
    }
};

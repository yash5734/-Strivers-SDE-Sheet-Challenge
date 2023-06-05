bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int i = 0;
        int m = mat[0].size();
        
        while(i<mat.size()){
            if(mat[i][0]<=target && mat[i][m-1]>=target){
                for(int j=0;j<m;j++){
                    if(mat[i][j] == target) return true;
                }
                return false;
            }
            i++;
        }
        return false;
}

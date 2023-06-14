class Solution {
private:

bool isCheck(int row,int col,int n, vector<string>board){
    int tempRow = row;
    int tempCol = col;

    while(row>=0 && col>=0){
        if(board[row][col]=='Q')return false;
        row--;
        col--;
    }

    row = tempRow;
    col = tempCol;

    while(row<n && col>=0){
        if(board[row][col]=='Q')return false;
        row++;
        col--;
    }

    row = tempRow;
    col = tempCol;

    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }

    return true;
}

void solve(int col, vector<string>board, int n, vector<vector<string>>&ans){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row =0;row<n;row++){
        if(isCheck(row,col,n,board)){
            board[row][col] = 'Q';
            solve(col+1,board,n,ans);
            board[row][col] = '.';
        }
    }
}

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0,board,n,ans);
        return ans;
    }
};

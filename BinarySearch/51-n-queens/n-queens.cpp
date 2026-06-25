class Solution {
public:
    vector<vector<string>> ans;;

    bool isSafe(int col, int row,vector<string>& board, int n){
        int Drow=row; int Dcol=col;
        while(row>=0 && col >=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=Drow; col=Dcol;
        while(col >=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        row=Drow; col=Dcol;
        while(row<n && col >=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }

    void Solve(int col, vector<string>& board, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(col,row,board,n)){
                board[row][col]='Q';
                Solve(col+1,board,n);
                board[row][col]='.';
            }
        }
    }
    

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        Solve(0, board, n);
        return ans;
    }
};
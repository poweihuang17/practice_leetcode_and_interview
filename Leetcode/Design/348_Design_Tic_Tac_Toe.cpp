class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n):sz(n) {
        rows.resize(n,0);
        cols.resize(n,0);
        diagonal=0;
        anti_diagonal=0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player==1)
        {
            rows[row]++;
            cols[col]++;
            if(row==col)
                diagonal++;
            if(row==sz-1-col)
                anti_diagonal++;
            if(rows[row]==sz || cols[col]==sz || diagonal==sz || anti_diagonal==sz)
                return 1;
        }
        else{
            rows[row]--;
            cols[col]--;
            if(row==col)
                diagonal--;
            if(row==sz-1-col)
                anti_diagonal--;
            if(rows[row]==-sz || cols[col]==-sz || diagonal==-sz || anti_diagonal==-sz)
                return 2;
        }
        return 0;
        
    }
    
private:
    vector<int> rows, cols;
    int diagonal, anti_diagonal;
    int sz;//What's this?
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
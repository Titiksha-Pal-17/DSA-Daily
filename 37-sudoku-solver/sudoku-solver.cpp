class Solution {
public:

    bool isSafe(vector<vector<char>>& board , int row , int col , char dig ){
        //horizontal
        for( int j=0; j<9 ;j++){
            if(board[row][j] ==dig){
                return false;
            }
        }
        //vertically
        for( int i=0; i<9 ;i++){
            if(board[i][col] ==dig){
                return false;
            }
        }
        //gitd

        int srow = (row/3)* 3 ;
        int scol = (col/3)* 3 ;
        for( int i=srow ;i<=srow +2 ; i++){
            for( int j =scol ;j<= scol+2 ; j++){
               if(board[i][j]==dig){
                   return false;
               }
            }
        }

        return true;

    }
    bool sudokuSolver(vector<vector<char>>& board , int row , int col  ){
        //base case
        if(row==9){
            return true;
        }
        //logic for next row and next column
        int nextR= row;
        int nextC=col+1;
        if(nextC==9){
            nextR++;
            nextC=0;
        }
        //if cell is not empty
        if(board[row][col] !='.'){
            return sudokuSolver(board, nextR, nextC);
        }
        
        //placing the correct digit in the cell
        for(char dig ='1';dig<='9';dig++){
            if( isSafe(board, row , col ,dig)){
                board[row][col] = dig;
                if( sudokuSolver(board, nextR, nextC)){
                    return true;
                }

              //if not true we will return the digit to '.'
              board[row][col] ='.';
            }
        }
    return false;

    }

    void solveSudoku(vector<vector<char>>& board) {

        sudokuSolver(board, 0, 0);
    }
};
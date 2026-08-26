class Solution {
public:

bool dfs(int i,int j,int startIndex,vector<vector<char>>&board,string word){

    //apply dfs from the current row and col

    if(startIndex==word.size())return true;

    // we can search in 4 Directoin

    if(i<0 || i>=board.size() || j<0 || j>=board[0].size()|| board[i][j]!=word[startIndex] ) return false;

    //UP
    //visited

    board[i][j]='0';

   bool up= dfs(i-1,j,startIndex+1,board,word);
    //DOW
   bool down=  dfs(i+1,j,startIndex+1,board,word);
    //LEFT
    bool left= dfs(i,j-1,startIndex+1,board,word);
    //RIGHT
   bool right=  dfs(i,j+1,startIndex+1,board,word);

   //backtract

   board[i][j]=word[startIndex];

   return up||down||left||right;

}
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        int startIndex = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // vector<vector<char>>visited(n,vector<char>(m,'0'));
                if (board[i][j] == word[0] && dfs(i, j, startIndex,board,word))
                    return true;
            }
        }
        return false;
    }
};
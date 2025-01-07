class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {    
        int m=board.size(); 
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(word[0]==board[i][j])
                {
                    bool found=dfs(board,i,j,word,0); 
                    if(found)
                    {
                        return true;
                    }
                }
            }
        } 
        return false;
    } 
     bool dfs(vector<vector<char>>& board,int r,int c, string word,int wordIndex) 
     {
        //base case 
        //valid case
        if(wordIndex==word.length())
        {
            return true;
        } 

        //outof bound case  
        int rows=board.size(); 
        int columns=board[0].size(); 

        if(r<0||c<0||r>=rows||c>=columns) 
        {
            return false;
        } 

        //invalid case 
        if(board[r][c]==' '||board[r][c]!=word[wordIndex])
        {
            return false;
        } 

        //mark as visited 
        char ch=board[r][c];
        board[r][c]=' '; 
        //dfs calls 
        if(dfs(board,r-1,c,word,wordIndex+1)||dfs(board,r,c+1,word,wordIndex+1)||
           dfs(board,r+1,c,word,wordIndex+1)||
           dfs(board,r,c-1,word,wordIndex+1))
        {
            return true;
        }  
        //backtracking
         board[r][c]=ch;
        return false;
     }
};
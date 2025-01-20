class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {  
        int n=board.size(); 
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));  
        vector<int>delrow={+1,-1,0,0}; 
       vector<int>delcol={0,0,1,-1};
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O' && visited[0][i]!=1)
            {
                dfs(0,i,visited,board,delrow,delcol);
            } 
             if(board[n-1][i]=='O'&&visited[n-1][i]!=1)
            {
                dfs(n-1,i,visited,board,delrow,delcol);
            }
        } 

        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && visited[i][0]!=1)
            {
                  dfs(i, 0, visited, board, delrow, delcol);
            } 
            if(board[i][m-1]=='O'&&visited[i][m-1]!=1)
            {
                 dfs(i, m-1, visited, board, delrow, delcol);
            }
        } 

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]!=1 && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    } 
    void dfs(int row,int col,vector<vector<int>>&visited,vector<vector<char>>&board,vector<int>&delrow,vector<int>&delcol)
    {
        visited[row][col]=1;  
        for(int w=0;w<4;w++)
        {
            int newrow=row+delrow[w]; 
            int newcol=col+delcol[w];  
            if(newrow>=0 && newrow<board.size() && newcol>=0 &&newcol<board[0].size() &&visited[newrow][newcol]!=1 && board[newrow][newcol]=='O')
            {
                dfs(newrow,newcol,visited,board,delrow,delcol);
            }

        }
    }
}; 


// vector<vector<char>>temp=board;  
//         int n=board.size(); 
//         int m=board[0].size(); 

//         vector<int>delrow={+1,-1,0,0}; 
//         vector<int>delcol={0,0,1,-1};
//         for(int i=0;i<board.size();i++)
//         {
//             for(int j=0;j<board[i].size();j++)
//             {
//                 if(board[i][j]=='O' && (i>0 && i<n-1) &&(j>0 && j<m-1))
//                 {
//                     for(int w=0;w<4;w++)
//                     {
//                         int newrow=delrow[w]+i; 
//                         int newcol=delcol[w]+j; 
//                         if(newrow>0 && newrow<n && newcol>0 && newcol<m && board[newrow][newcol]=='X')
//                         {
//                             board[i][j]='X';
//                         }
//                     }
//                 }
//             }
//         }  -->brute
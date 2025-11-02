class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board)  
    {
        //ok means we have to check whether at initial time , whether how many rook can hit  
        //check the postion of the rook and start going to vertical straight or horizontal  

        int x=0; 
        int y=0; 

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='R')
                {
                    x=i; 
                    y=j; 
                    break;
                }
            }
        } 


        int count=0;  
        bool flag=true;
        //left side :
        for(int i=y-1;i>=0;i--)
        {
            if(board[x][i]=='p' && flag)
            {
                count++; 
                break;
            } 
            else if(board[x][i]=='B')
            {
                flag=false; 
                break;
            }
        } 


        flag=true;
        //right side :
        for(int i=y+1;i<8;i++)
        {
            if(board[x][i]=='p' && flag)
            {
                count++; 
                break;
            } 
            else if(board[x][i]=='B')
            {
                flag=false;  
                break;
            }
        } 

        flag=true;  
        //up side: 
        for(int j=x-1;j>=0;j--)
        {
            if(board[j][y]=='p' && flag)
            {
                count++; 
                break;
            } 
            else if(board[j][y]=='B')
            {
                flag=false; 
                break;
            }

        } 


           flag=true;  
        //down side: 
        for(int j=x+1;j<8;j++)
        {
            if(board[j][y]=='p' && flag)
            {
                count++; 
                break;
            } 
            else if(board[j][y]=='B')
            {
                flag=false; 
                break;
            }

        } 


        return count;

    }
};
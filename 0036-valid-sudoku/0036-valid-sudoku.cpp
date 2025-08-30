class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)  
    {
        //1.firstly chcek the all rows and form the map from the rows and use that one for whether the duplkicate entry is present or not 

        int n=board.size(); 
        int m=board[0].size();
        

        for(int i=0;i<n;i++)
        {
            vector<char>vct=board[i]; 
            if(check(vct)==false)
            {
                return false;
            }  
            vct.clear();
          
        } 

         vector<char>vct2;
         for(int j=0;j<m;j++)
        {
           for(int i=0;i<n;i++)
           {
                if(board[i][j]!='.')
                {
                    vct2.push_back(board[i][j]);
                }
           } 

           if(check(vct2)==false)
           {
            return false;
           }  
        
            vct2.clear();
        } 
         


         //3rd: check for the puzzle box: 

         for(int i=0;i<9;i+=3)
         {
            for(int j=0;j<9;j+=3)
            {
                if(traverse_check(i,j,board)==false)
                {
                    return false;
                }
            }
         } 
         return true;
    } 

    bool traverse_check(int i, int j, vector<vector<char>>board) 
    {
        map<char,int>stdmap;
        for(int k=i;k<i+3;k++)
        {
            for(int w=j;w<j+3;w++)
            {
                if(board[k][w]!='.')
                {
                    if(stdmap.find( board[k][w])!=stdmap.end())
                    {
                        return false;
                    }  
                    stdmap[board[k][w]]++;
                }
            }
        } 
        return true;
    }
    bool check(vector<char>vct)
    {  
        map<char,int>stdmap; 
        for(int i=0;i<vct.size();i++)
        {
            if(vct[i]!='.')
            {   
                if(stdmap.find(vct[i])!=stdmap.end())
                {
                    return false;
                }
                stdmap[vct[i]]++;
            }
        } 

        return true; 


    }
};
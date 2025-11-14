class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries)  
    {
        //you are also given the 2D Query array : query[i]=[row1,col1,row2,col2] , add one to every element in teh submatrix with top left corner (row1,col1) and bottom right corner (row2,col2) this add 1 to mat[x][y] for all  
        // 1+mat[x][y] for all row1<=x<=row2 and col1<=y<=col2  

        vector<vector<int>>vct(n,vector<int>(n,0)); 
        
        for(int i=0;i<queries.size();i++)
        {
            int startx=queries[i][0];
            int starty= queries[i][1];
            int endx= queries[i][2];
            int endy=queries[i][3]; 

            increment_By_One(startx,endx,starty,endy,vct);
        }
        return vct;

    } 

    void increment_By_One(int x1,int x2,int y1,int y2, vector<vector<int>>&vct)
    {
        for(int i=x1;i<=x2;i++)
        {
            for(int j=y1;j<=y2;j++)
            {
                vct[i][j]+=1;
            }
        }
    }
};
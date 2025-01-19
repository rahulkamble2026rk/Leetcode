class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {  
        int n=mat.size(); 
        int m=mat[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0)); 
        queue<pair<pair<int,int>,int>>que; 
         
        vector<vector<int>>distance(n,vector<int>(m,0));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                {
                    distance[i][j]=0; 
                    que.push({{i, j}, 0});
                    visited[i][j] = 1;
                } 
            }
        }   
        vector<int>delrow={0,0,-1,+1}; 
        vector<int>delcol={1,-1,0,0}; 

        while(!que.empty())
        {
            int r=que.front().first.first; 
            int c=que.front().first.second; 
            int step=que.front().second; 
             
            que.pop();
             for(int i=0;i<4;i++)
             {
                int newrow=r+delrow[i];
                 int newcol=c+delcol[i]; 

                 if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && visited[newrow][newcol]!=1) 
                 {
                    que.push({{newrow,newcol},step+1}); 
                    distance[newrow][newcol]=step+1; 
                    visited[newrow][newcol]=1;
                 }
             }
            
        } 
        return distance;
    }
};
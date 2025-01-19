class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {    
        int n=image.size();
        int m=image[0].size(); 
        int intialcolour=image[sr][sc];
        vector<vector<int>>visited(n,vector<int>(m,0)); 
         for(int i=0;i<n;i++)
         {
            for(int j=0;j<m;j++)
            {
                visited[i][j]=image[i][j];
            }
         }
        queue<pair<pair<int,int>,int>>que;  
        que.push({{sr,sc},color}); 
          
        visited[sr][sc]=color;
        int delrow[]={0,1,0,-1}; 
        int delcol[]={1,0,-1,0};
        while(!que.empty())
        {
            int currow=que.front().first.first; 
            int curcol=que.front().first.second; 
            int curcolor=que.front().second; 

            que.pop(); 

            for(int i=0;i<4;i++)
            {
                int newrow=currow+delrow[i]; 
                int newcol=curcol+delcol[i]; 

                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && visited[newrow][newcol]!=curcolor && image[newrow][newcol]==intialcolour)
                {
                    que.push({{newrow,newcol},color}); 
                    visited[newrow][newcol]=color;
                }
            }
        }
        
        return visited;
    }
};
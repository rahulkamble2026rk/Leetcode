class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        //step1:visited 2D array & queue 
        int n=grid.size(); 
        int m=grid[0].size();  
        
        queue<pair< pair<int,int>, int> >que; 
        vector<vector<int>>visited(n,vector<int>(m, 0)); 

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                if(grid[i][j]==2)
                {    
                    que.push({{i,j},0});
                    visited[i][j]=2;
                } 
                else
                {
                    visited[i][j]=0;
                }
            }
        }

        //step2:iterat untill the queue will not become the empty 
        
        int time=0;  
        int delrow[]={-1,0,1,0}; 
        int delcol[]={0,1,0,-1};

        while(!que.empty())
        {
            int r=que.front().first.first; 
            int c=que.front().first.second;
            int t=que.front().second;  

            que.pop(); 
            time=max(t,time);
             for(int i=0;i<4;i++)   //for the 4 directions
            {
                 int currow=r+delrow[i]; 
                 int currcol=c+delcol[i];

                if(currow>=0&& currow<n && currcol>=0 && currcol<m && visited[currow][currcol]!=2 && grid[currow][currcol]==1)
                {
                    que.push({{currow, currcol},time+1}); 
                    visited[currow][currcol]=2;
                }
            } 
            
        } 

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && visited[i][j]!=2)
                {
                    return -1;
                }
            }
        } 
        return time;



    }
};
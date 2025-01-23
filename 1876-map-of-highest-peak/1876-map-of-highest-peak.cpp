class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)  
    {
        
        int n=isWater.size(); 
        int m=isWater[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0)); 
        vector<vector<int>>ans(n,vector<int>(m,-1));   

        queue<pair< pair<int,int>,int> >que; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1)
                {
                    ans[i][j]=0;  
                    visited[i][j]=1;
                    que.push({{i,j},0});
                }
            }
        } 

        vector<int>delrow={0,0,1,-1}; 
        vector<int>delcol={1,-1,0,0};
        while(!que.empty())
        {
            int currrow=que.front().first.first; 
            int currcol=que.front().first.second; 
            int val=que.front().second; 
            que.pop();
            for(int i=0;i<4;i++) 
            {
                int newrow=currrow+delrow[i]; 
                int newcol=currcol+delcol[i]; 

                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && visited[newrow][newcol]==0)

                {    ans[newrow][newcol]=val+1;
                    que.push({{newrow,newcol},val+1});
                    visited[newrow][newcol]=1;
                }
            }
        } 
        return ans;
    }
};
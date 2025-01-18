class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();  
        int count=0;
        //forming the adc.list 
        vector<vector<int>>adjlist(n+1);
        for(int i=0;i<n;i++)
        {    
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjlist[i+1].push_back(j+1); 
                    adjlist[j+1].push_back(i+1);
                }
            } 
        }  

        vector<int>visited(n+1,0); 
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==0) 
            {   
                count++;
                dfs(i,adjlist,visited);
            }
        }
      
      return count;
    } 
    void dfs(int node,vector<vector<int>>adjlist,vector<int>&visited)
    {
        visited[node]=1; 
        for(auto it:adjlist[node])
        {
            if(visited[it]!=1)
            {
                dfs(it,adjlist,visited);
            }
        }
    }
};
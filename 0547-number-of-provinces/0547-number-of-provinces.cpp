class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)  
    {
        //step1: formation of the adjaceny list: 
        int size=isConnected.size(); 
        vector<int>visited(size,0);  
        int count=0; 

        for(int i=0;i<size;i++)
        {
            if(!visited[i])
            { 
                dfs(i,isConnected,visited);
                count++;
            }
        } 
        return count;
    } 

    void dfs(int row,vector<vector<int>>&matrix,vector<int>&visited)
    {
        int m=matrix[row].size();  
        visited[row]=1; 
        for(int i=0;i<m;i++)
        {
            if(matrix[row][i]==1)
            {
                if(i==row || visited[i]==1)
                {
                    continue;
                } 
                else
                {
                    dfs(i,matrix,visited);
                }
            }
        }
    }
};
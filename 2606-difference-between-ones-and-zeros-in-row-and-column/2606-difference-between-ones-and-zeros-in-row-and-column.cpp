class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        vector<vector<int>>visited=grid; 
        int n=grid.size(); 
        int m=grid[0].size(); 

        vector<int>oneRow(n,0); 
        vector<int>zeroRow(n,0); 
        vector<int>oneCol(m,0); 
        vector<int>zeroCol(m,0); 

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==1)
                {
                    oneRow[i]++; 
                    oneCol[j]++;
                } 
                else if(visited[i][j]==0)
                {
                    zeroRow[i]++; 
                    zeroCol[j]++;
                }
            }
        } 
         
         vector<vector<int>>ans(n,vector<int>(m,0)); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) 
            {
                int sum=oneRow[i]+oneCol[j]-zeroRow[i]-zeroCol[j]; 
                ans[i][j]=sum;
            }
        } 
        return ans;
    }
};
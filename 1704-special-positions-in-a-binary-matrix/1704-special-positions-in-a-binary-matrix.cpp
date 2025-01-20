class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        vector<vector<int>>visited=mat; 
        int n=mat.size(); 
        int m=mat[0].size(); 

        vector<int>oneRow(n,0); 
        vector<int>oneCol(m,0); 

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==1)
                {
                    oneRow[i]++; 
                    oneCol[j]++;
                } 
            }
        } 
         
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) 
            {
                if(visited[i][j]==1)
                {
                    if(oneRow[i]==1 && oneCol[j]==1)
                    {
                        sum++;
                    }
                }
            }
        } 
        return sum;
    }
};
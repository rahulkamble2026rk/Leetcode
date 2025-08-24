class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)  
    {
        int n=matrix.size(); 
        int m=matrix[0].size(); 

        int maxi=min(m,n); 

        int i=1; 
        int result=0; 
        while(i<=maxi)
        {
            result+=count_size(i,n,m,matrix); 
            i++;
        }   
        return result;

    } 

    int count_size(int n,int rows,int cols,vector<vector<int>>& matrix)
    {
        int ans=0; 

        for(int i=0;i<=rows-n;i++)
        {
            for(int j=0;j<=cols-n;j++)
            {
                ans+=check_All(i,j,n,matrix);
            }
        } 

        return ans;
    } 


    int check_All(int i,int j,int n,vector<vector<int>>& matrix)
    {
        for(int k=i;k<i+n;k++)
        {
            for(int l=j;l<j+n;l++)
            {
                if(matrix[k][l]==0)
                {
                    return 0;
                }
            }
        } 

        return 1;
    }
};
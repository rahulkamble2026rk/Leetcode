class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        //traversing the side over the edge of the column : 

        int total_cols=mat[0].size();  
        int total_rows=mat.size(); 
        int flag=1;  
        vector<int>ans;

        for(int j=0;j<total_cols;j++)
        {
            traverse_add(mat,0,j,total_cols,total_rows,flag,ans);
        } 

        for(int i=1;i<total_rows;i++)
        {
            traverse_add(mat,i,(total_cols-1),total_cols,total_rows,flag,ans);
        } 
        return ans;
        
    }  

    void traverse_add(vector<vector<int>>&mat,int row,int col,int& total_cols,int& total_rows,int& flag,vector<int>&ans)
    {
        vector<int>temp; 
        int i=row; 
        int j=col;
        while(i<total_rows && j>=0)
        {
              temp.push_back(mat[i][j]); 
                j--;
                i++;
        } 

        if(flag)
        {
            reverse(temp.begin(),temp.end()); 
            flag=0;
        }   
        else
        {
            flag=1;
        }
        ans.insert(ans.end(),temp.begin(),temp.end());

    }


};
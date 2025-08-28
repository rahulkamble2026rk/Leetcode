class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid)  
    {
        //firstlty set the middle of teh diagonal :  

        int n=grid.size(); 
        int m=grid[0].size(); 

        int i=0; 
        int j=0; 
        vector<int>vct;
        while(i<n && j<m)
        {
            vct.push_back(grid[i][j]); 
            i++; 
            j++;
        } 
         
    
        sort(vct.rbegin(),vct.rend());  

        int ind=0; 
        i=0; 
        j=0;  

       while(i<n && j<m)
       {
           grid[i][j]=vct[ind]; 
           i++;
           j++; 
           ind++;
       }
            
        vct.clear(); 

        i=0;
        j=1;
        while(j<grid[0].size())
        {
            traverse(i,j,vct,grid); 
            sort(vct.begin(),vct.end());   
            for(auto it:vct)
            {
                cout<<it<<endl;
            }
            update_matrix(i,j,vct,grid); 
            vct.clear();
            j++; 
        }   

         i = 1; j = 0;
        while(i < n) {
            traverse(i, j, vct, grid); 
            sort(vct.rbegin(), vct.rend()); // descending
            update_matrix(i, j, vct, grid); 
            vct.clear();
            i++;
        }

        return grid;

    } 

    void traverse(int row,int col,vector<int>&vct,vector<vector<int>>&grid) 
    {   
        int i=row; 
        int j=col;
        while(i<grid.size() && j<grid[row].size())
        {  
        
           vct.push_back(grid[i][j]); 
           i++; 
           j++;
        } 

        
    }  

    void update_matrix(int row,int col,vector<int>&vct,vector<vector<int>>&grid) 
    {   
        int i=row; 
        int j=col; 
        int ind=0;
        while(i<grid.size() && j<grid[row].size())
        {  
        
           grid[i][j]=vct[ind];
           i++; 
           j++; 
           ind++;
        } 
    }
   
    

};
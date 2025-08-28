class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)  
    {
         int n=mat.size(); 
         int m=mat[0].size(); 

         for(int i=n-1;i>=0;i--)
         {
            traverse_sort(i,0,mat); 
            cout<<endl;
         } 
         for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                cout<<mat[i][j]<<"->";
            } 
            cout<<endl;
        }
     
         for(int j=1;j<m;j++)
         {
            traverse_sort(0,j,mat); 
            cout<<endl;
         }  

         for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                cout<<mat[i][j]<<"->";
            } 
            cout<<endl;
        }
         return mat;
    } 

    void traverse_sort(int i,int j,vector<vector<int>>&matrix)
    {
        vector<int>vct; 
        int k=i; 
        int w=j; 
        int n=matrix.size(); 
        int m=matrix[0].size();

        while(k<n && w<m)
        {
            vct.push_back(matrix[k][w]);  
            // cout<<"I am going "<<vct.back()<<endl;
            k++; 
            w++;
        } 
        
        sort(vct.begin(),vct.end()); 

        k=i; 
        w=j; 
        int ind=0; 

        while(k<n && w<m)
        {
             
            // cout<<matrix[k][w]<<"-> replace by: "<<vct[ind]<<" at : "<<k<<" "<<w<<endl; 
            matrix[k][w]=vct[ind]; 
            ind++; 
            k++;
            w++;        
        } 

       
    }
};
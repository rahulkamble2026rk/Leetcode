class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int n=grid.size(); 
        int m=grid[0].size(); 
        int count=0;

        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<m-2;j++)
            {
                if(check(i,j,grid))
                {
                    count++;
                }
            }
        } 
        return count;
    } 

    bool check(int x,int y,vector<vector<int>>& grid) 
    {
        //storing all results in the one vector and eventually check the all lastest values 
        vector<int>vct;  
        set<int>st;
         
        for(int i=x;i<x+3;i++)
        {
            int sum=0; 
            for(int j=y;j<y+3;j++)
            {  
                if(grid[i][j]>9 || grid[i][j]<1)
                {
                    return false;
                }
                sum+=grid[i][j]; 
                st.insert(grid[i][j]);
            } 

            if(vct.empty())
            {
                vct.push_back(sum);   // first reference sum
            }
            else if(vct.back()!=sum)
            {
                return false;
            }  
            else 
            {
                vct.push_back(sum);
            }
        }  

          if(st.size()!=9)
            {
                return false;
            }


        st.clear(); 

        for(int j=y;j<y+3;j++)
        {
            int sum=0; 
            for(int i=x;i<x+3;i++)
            {  
                 if(grid[i][j]>9 || grid[i][j]<1)
                {
                    return false;
                }
                sum+=grid[i][j]; 
                 st.insert(grid[i][j]);
            } 

            if(vct.empty())
            {
                vct.push_back(sum);   // first reference sum
            }
            else if(vct.back()!=sum)
            {
                return false;
            }
            else 
            {
                vct.push_back(sum);
            }
        }  

         if(st.size()!=9)
            {
                return false;
            }


        //check the diagonal elements : 

        int sum1=0;  
        int j=y;
        for(int i=x;i<x+3;i++)
        {
            sum1+=grid[i][j]; 
            j++;
        } 


        if(vct.empty())
        {
            vct.push_back(sum1);   // first reference sum
        }
        else if(vct.back()!=sum1)
        {
            return false;
        } 
        else 
        {
            vct.push_back(sum1);
        }

        int sum2=0; 
         j=y+2;
        for(int i=x;i<x+3;i++)
        {
            sum2+=grid[i][j]; 
            j--;
        }  

        if(vct.empty())
        {
            vct.push_back(sum2);   // first reference sum
        }
        else if(vct.back()!=sum2)
        {
            return false;
         } 
        else 
        {
            vct.push_back(sum2);
        } 

        return true;

    } 
};
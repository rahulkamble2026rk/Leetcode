class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid)  
    {
        //same question here the but the duplicates are also allowed and also , there is no need for the 3*3 as well , here at the end , 1 will be definetly the size 
         
         int n=grid.size(); 
        int m=grid[0].size(); 
       
        int count=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 
                int limit=Coordinate(i,j,grid);
                for(int k = limit; k >= 2; k--)
                {
                    if(check(i, j, k, grid))
                    {
                        count = max(count, k);
                        break;
                    }
                }
            }
        } 
        return count;
    }  

    int Coordinate(int x,int y,vector<vector<int>>&grid)
    {  
        int n=grid.size(); 
        int m=grid[0].size();   
        return min(n-x, m-y);
       
    }
    

     bool check(int x,int y,int limit,vector<vector<int>>& grid) 
    {  
         //storing all results in the one vector and eventually check the all lastest values 
        vector<int>vct;  
        
         
        for(int i=x;i<x+limit;i++)
        {
            int sum=0; 
            for(int j=y;j<y+limit;j++)
            {  
             
                sum+=grid[i][j]; 
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

       
        for(int j=y;j<y+limit;j++)
        {
            int sum=0; 
            for(int i=x;i<x+limit;i++)
            {  
                
                sum+=grid[i][j]; 
                
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

      

        //check the diagonal elements : 

        int sum1=0;  
        int j=y;
        for(int i=x;i<x+limit;i++)
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
         j=y+(limit-1);
        for(int i=x;i<x+limit;i++)
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
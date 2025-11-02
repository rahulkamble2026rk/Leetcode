class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)  
    {
        
        vector<vector<int>>visited(m,vector<int>(n,0)); 
        // 0 for unsafe places  , 1 -> guards , 2-> walls 

        for(int i=0;i<guards.size();i++)
        {   
            int x=guards[i][0]; 
            int y=guards[i][1];
            visited[x][y]=1;
        } 

 
        for(int i=0;i<walls.size();i++)
        {   
            int x=walls[i][0]; 
            int y=walls[i][1];
            visited[x][y]=2;
        }   



        //2. now interate over the Guards and untill that row mark it  

        for(int i=0;i<guards.size();i++)
        {
            flow(guards[i],visited);
        }

        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==0)
                {
                    count++;
                }
            }
        } 

        return count;
    } 

    void flow(vector<int>guard,vector<vector<int>>&visited)
    {
      
        int n=visited[0].size(); 
        int m=visited.size(); 

        int x=guard[0]; 
        int y=guard[1]; 

         
        //let's guard firslty go to left side , means row will be same just column will change 
         
    //      int j=y-1;
    //    while( j>=0 && visited[x][j]==0)
    //    {
    //         visited[x][j]=1;
    //         j--;
    //    }    


    //      //let's guard firslty go to right side , means row will be same just column will change 
         
    //      j=y+1;
    //    while(  j<n && visited[x][j]==0)
    //    {
    //         visited[x][j]=1;
    //         j++;
    //    }  
        

    //     //let's guard firslty go to up side , means column will be same just row will change 
         
    //      int i=x-1;
    //    while( i>=0 &&visited[i][y]==0)
    //    {
    //         visited[i][y]=1;
    //         i--;
    //    }    


        
    //     //let's guard firslty go to down side , means column will be same just row will change 
         
    //       i=x+1;
    //    while(i<m && visited[i][y]==0 )
    //    {
    //         visited[i][y]=1;
    //         i++;
    //    }
     

     for (int j = y - 1; j >= 0; j--) {
            if (visited[x][j] == 1 || visited[x][j] == 2) break;
            if (visited[x][j] == 0) visited[x][j] = 3;
        }

        // Right
        for (int j = y + 1; j < n; j++) {
            if (visited[x][j] == 1 || visited[x][j] == 2) break;
            if (visited[x][j] == 0) visited[x][j] = 3;
        }

        // Up
        for (int i = x - 1; i >= 0; i--) {
            if (visited[i][y] == 1 || visited[i][y] == 2) break;
            if (visited[i][y] == 0) visited[i][y] = 3;
        }

        // Down
        for (int i = x + 1; i < m; i++) {
            if (visited[i][y] == 1 || visited[i][y] == 2) break;
            if (visited[i][y] == 0) visited[i][y] = 3;
        }

    }
};
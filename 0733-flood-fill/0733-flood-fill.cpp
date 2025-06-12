class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)  
    {   
        int m=image.size(); 
        int n=image[0].size();  
          int originalColor = image[sr][sc];

        // If the original color is already the target color, no change needed
        if (originalColor == color) return image; 

        vector<vector<int>>visited(m,vector<int>(n,0)); 

        queue<pair<int,pair<int,int>>>que; 
        que.push({originalColor,{sr,sc}}); 
        visited[sr][sc]=1;  
        vector<int>delrow={0,0,+1,-1}; 
        vector<int>delcol={+1,-1,0,0};
        bfs(image,que,visited,delrow,delcol,originalColor,color);  
        image[sr][sc]=color;
        return image;
    } 
    void bfs(vector<vector<int>>& image,queue<pair<int,pair<int,int>>>&que,vector<vector<int>>&visited, vector<int>delrow,vector<int>delcol, int originalColor,int newcolor) 
    {  
        int m=image.size(); 
        int n=image[0].size();
        while(!que.empty())
        {
            pair<int,pair<int,int>>pt=que.front();  
            que.pop(); 
            int x=pt.second.first; 
            int y=pt.second.second; 

            for(int i=0;i<4;i++)
            {
                int new_x=x+delrow[i]; 
                int new_y=y+delcol[i]; 

                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && visited[new_x][new_y]!=1 && image[new_x][new_y]==originalColor)
                {   
                    visited[new_x][new_y]=1;  
                    image[new_x][new_y]=newcolor;
                    que.push({originalColor,{new_x,new_y}});
                }
            }
        }
    }
};
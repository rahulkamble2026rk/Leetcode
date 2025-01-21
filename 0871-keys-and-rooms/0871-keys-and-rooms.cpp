class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n=rooms.size(); 
        vector<int>visited(n,0);  
        dfs(0,visited,rooms);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {   
                return false;
            }
        } 

         return true;
    } 
    void dfs(int node,vector<int>&visited,vector<vector<int>>rooms)
    {  
        visited[node]=1;
        for(auto  it:rooms[node])
        {
            if(!visited[it])
            { 
                dfs(it,visited,rooms);
            } 
        } 
    }
};
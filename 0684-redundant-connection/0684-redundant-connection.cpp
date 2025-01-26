// class Solution {
// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) 
//     {
//         vector<vector<int>adjList(edges.size()); 
//         vector<int>visited(edges.size(),0);
//         for(int i=0;i<edges.size();i++)
//         {
//             adjList[edges[i][0]].push_back(edges[i][1]); 
//             adjList[edges[i][1]].push_back(edges[i][0]); 
//         } 
         
//          vector<int>parent(n,0); 
//          for(int i=0;i<edges.size();i++)
//          {
//             if(visited[i]==0)
//             {
//                 dfs(i,visited,adjList,parent);
//             }
//          }
//     } 

//     void dfs(int node,vector<int>&visited,vector<vector<int>>adjList,vector<int>&parent)
//     {
//         visited[node]=1; 

//         for(auto it:adjList[node])
//         {
//             parent[it]=node; 

//         }
//     }
// }; 

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    { 
        int n=edges.size(); 
        vector<int>ds(n+1); 

        for(int i=0;i<=n;i++)
        {
            ds[i]=i; //Initlization that the 2 is the parent of 2 , 1 is parent of 1
        } 

        for(vector<int>v:edges)
        {  
            //[[1,2],[1,3],[2,3]] 

            int el1=v[0]; //1
            int el2=v[1]; //2 

            int p1=findParent(el1,ds); 
            int p2=findParent(el2,ds); 
             
            if(p1==p2)
            {
                return v;
            } 
            else
            {
                ds[p2]=p1;
            }
        } 
        return {};

    } 

    int findParent(int element,vector<int>&ds)
    {
        if(ds[element]==element)
        {
            return element;
        } 
        return findParent(ds[element],ds);
    }
};
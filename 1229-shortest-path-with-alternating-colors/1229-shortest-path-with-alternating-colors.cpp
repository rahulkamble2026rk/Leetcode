class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges)  
    {
        //return answer , where answer[x] is the length of shortest path from 0 to node x such edge colors
        // step1: formation of the adjList with the color , red-> 1 , blue -> 0 

        vector< vector<pair<int,int> >>adj(n);

        for(auto it:redEdges)
        {
            adj[it[0]].push_back({it[1], 0}); 
        }  

        for(auto it:blueEdges)
        {
            adj[it[0]].push_back({it[1],1});
        }
         
         //step2: Distance array [node][lastColor]  
        vector<vector<int>>dist(n,vector<int>(2,1e9));  
        dist[0][0]=dist[0][1]=0;
 

        //step3: bfs queue =>(node , last color)

        queue<pair<int,int>>q; 
        q.push({0,-1}); 


        while(!q.empty())
        {
            pair<int,int>front=q.front(); 
            q.pop(); 

            int node=front.first; 
            int lastColor=front.second; 

            for(int i=0;i<adj[node].size();i++)
            {
                pair<int,int>edge=adj[node][i]; 
                int nbr=edge.first; 
                int edgeColor=edge.second; 

                if(edgeColor!=lastColor)
                {
                    int newDist=(lastColor==-1)?1:dist[node][lastColor]+1; 
                    if(newDist<dist[nbr][edgeColor])
                    {
                        dist[nbr][edgeColor]=newDist;  
                        q.push({nbr,edgeColor});
                    }
                }
            }
        } 

        vector<int>ans(n,-1); 
        for(int i=0;i<n;i++) 
        {
            int best=min(dist[i][0],dist[i][1]);
            ans[i]=(best==1e9)?-1:best;
        }     
        return ans;
    }
};
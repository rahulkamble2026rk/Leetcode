class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)  
    {
        //step1: formation of the adj_list 
        vector<vector<pair<int,int>>>adj_list(n+1); 
        for(auto it:times)
        {
            adj_list[it[0]].push_back({it[1],it[2]}); 
        } 

 

        //step2:decalration of the distance , and parent vector 
        vector<int>distance(n+1,1e9); 
        vector<int>parent(n+1); 
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        distance[k]=0;
        dijkstra(adj_list,distance,parent,k);   
        distance[0]=0; 
        int maxtime=0;
        for(int i=1;i<distance.size();i++)
        {
            if(distance[i]==1e9)
            {
                return -1;
            } 
            maxtime=max(maxtime,distance[i]);
        }
        return maxtime;
    } 

    void dijkstra(vector<vector<pair<int,int>>>adj_list,vector<int>&distance,vector<int>&parent,int src)
    {
        //there is use of the priority_queue means min-heap; 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
        pq.push({0,src}); 
        while(!pq.empty())
        {
            pair<int,int>pt=pq.top(); 
            pq.pop(); 
            int dist=pt.first; 
            int node=pt.second; 
            for(auto it:adj_list[node])
            {
                int adjnode=it.first; 
                int edge_weight=it.second; 
                if(dist+edge_weight<distance[adjnode])
                {
                    distance[adjnode]=dist+edge_weight; 
                    parent[adjnode]=node; 
                    pq.push({distance[adjnode],adjnode});
                }
            }
        }
    }
};
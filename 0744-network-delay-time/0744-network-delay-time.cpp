class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        //step1:  
       vector<vector<pair<int, int>>> adjList(n + 1);

        for(int i=0;i<times.size();i++)
        {
            int node=times[i][0]; 
            int endnode=times[i][1]; 
            int time=times[i][2]; 
            
            adjList[node].push_back({endnode,time}); 
        } 

        //step2: 
        vector<int>distance(n+1,INT_MAX); 
        distance[k]=0; 
         
        //step3: 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que; 
         
         if(adjList[k].empty()) 
         {
            return -1;
         }
        que.push({0,k}); 
         
        
        while(!que.empty())
        {
            auto it=que.top(); 
            int dist=it.first; 
            int node=it.second; 
            que.pop(); 

            for(auto it2:adjList[node])
            {
                int nodedist=it2.second; 
                int endnode=it2.first; 
                if(dist+nodedist<distance[endnode])
                {
                    distance[endnode]=dist+nodedist; 
                    que.push({distance[endnode],endnode});
                }
            }
        } 
        
        int maxTime = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (distance[i] == INT_MAX) 
            {
                return -1; 
            }
            maxTime = max(maxTime, distance[i]);
        }
        
        return maxTime;
    }
};
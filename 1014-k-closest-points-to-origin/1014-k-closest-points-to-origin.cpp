class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)  
    {
       
       priority_queue<
                pair<int, pair<int, int>>,                          // Heap element type
                vector<pair<int, pair<int, int>>>,                  // Underlying container
                greater<pair<int, pair<int, int>>>                  // Comparator for min-heap
                > que;
        for(auto it:points)
        {
            int x=count_distance(it); 
            que.push({x,{it[0],it[1]}});
        }  

        vector<vector<int>>ans;
        for(int i=1;i<=k;i++)
        {  
             vector<int>ans2;  
             ans2.push_back(que.top().second.first); 
             ans2.push_back(que.top().second.second);  
             que.pop();
             ans.push_back(ans2);
        } 
        return ans;
       
    } 
    int count_distance(vector<int>&vct)
    {
        int ans=pow(vct[0],2)+pow(vct[1],2);
        return ans;
    }

};
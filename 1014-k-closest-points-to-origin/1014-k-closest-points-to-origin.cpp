class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)  
    {
       
       priority_queue<
                pair<int,int>,                          // Heap element type
                vector<pair<int,int>>,                  // Underlying container
                greater<pair<int,int>>                  // Comparator for min-heap
                > que;
        for(int i=0;i<points.size();i++)
        {
            vector<int>temp= {points[i][0] , points[i][1]};
            int x=count_distance(temp); 
            que.push({x,i});
        }  

        vector<vector<int>>ans;
        for(int i=1;i<=k;i++)
        {  
            //  vector<int>ans2;  
            //  ans2.push_back(que.top().second.first); 
            //  ans2.push_back(que.top().second.second);  
             ans.push_back(points[que.top().second]);
             que.pop();
        } 
        return ans;
       
    } 
    int count_distance(vector<int>&vct)
    {
        int ans=pow(vct[0],2)+pow(vct[1],2);
        return ans;
    }

};
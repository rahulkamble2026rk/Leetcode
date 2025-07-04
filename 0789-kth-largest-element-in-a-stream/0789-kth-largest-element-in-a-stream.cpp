class KthLargest {
public: 
    int ind; 
    priority_queue<int, vector<int>, greater<int>> que; 
    
    KthLargest(int k, vector<int>& nums)  
    {   
        ind = k;
         
        for(int i=0;i<nums.size();i++)
        {
            
                que.push(nums[i]);

        }      
    }
    
    int add(int val)  
    {  
        //  cout<<ind<<" ";
         que.push(val);
        while (que.size() > ind) {
        que.pop();
    }

        return que.top();
        
    }
};
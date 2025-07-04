class KthLargest {
public: 
    int ind; 
    priority_queue<int, vector<int>, greater<int>> que; 
    
    KthLargest(int k, vector<int>& nums)  
    {
            int n = nums.size();
            ind = k;
         
         if(k<=nums.size())
         {
              for(int i=0;i<k;i++)
                {
                
                    que.push(nums[i]);
                        
            
                }  
                 for(int i=k;i<nums.size();i++)
                {
                    
                    if(nums[i]>que.top())
                    {
                        que.pop();
                        que.push(nums[i]);
                    }
                } 
         }
         else {
             for(int i=0;i<n;i++)
                {              
                    que.push(nums[i]);     
                }  
         }
     
       
         
    }
    
    int add(int val)  
    {  
         cout<<ind<<" ";
         if(que.size() < ind)
         {
            que.push(val);
         }
         else if(val>que.top())
            {  
                
                que.pop();
                que.push(val);
            }
         return que.top();
    }
};
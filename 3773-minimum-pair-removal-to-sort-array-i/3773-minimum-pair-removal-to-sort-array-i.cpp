class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) 
    {
        int steps=0;  
        
        while(!is_sorted(nums.begin(),nums.end()))
            {     

                vector<pair< int,pair<int,int>> >record; 
                for(int i=0;i<nums.size()-1;i++)
                {
                    record.push_back({nums[i]+nums[i+1],{i,i+1}});
                }  
                sort(record.begin(),record.end()); 
                int ind1=record[0].second.first; 
                int ind2=record[0].second.second; 
                
                nums[ind1]=nums[ind1]+nums[ind2] ; 
                nums.erase(nums.begin()+ind2); 
                steps++;
            } 
        return steps;
        
    }
};
class FindSumPairs {
public: 

    map<int,int>stdmap1; 
    map<int,int>stdmap2; 
    unordered_map<int,int>freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)  
    {
        // vct1=nums1; 
        // vct2=nums2; 

        for(int i=0;i<nums1.size();i++)
        {
            stdmap1[i]=nums1[i];
        } 

        for(int i=0;i<nums2.size();i++)
        {
            stdmap2[i]=nums2[i]; 
            freq[stdmap2[i]]++;
        }
    }
    
    void add(int index, int val)  
    {
        int num=stdmap2[index];  
        freq[num]--; 

        stdmap2[index]=num+val; 
        freq[stdmap2[index]]++;
    }
    
    int count(int tot)  
    {
        //counting the total pairs having the sum as the tot:   

        int count=0;
        for(auto it:stdmap1)
        {   
            int num=tot-it.second;
            if(freq.find(num)!=freq.end())
            {
                count+=freq[num];
            }
        } 
        return count;


    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
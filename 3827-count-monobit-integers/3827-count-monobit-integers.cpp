class Solution {
public:
    int countMonobit(int n)  
    {
        //an integer is called monobit if all bits in its binary represetation are same 
        // simply after the binary represtation of the number we have do the 
        // every time 0 to hoga hi , so abi zo bazta hai usme sirf check karna hai whether is it , now just remaining number will consist the only 1

        set<int>st; 
        st.insert({2,4,8,16,32,64,128,256,512}); 
        int cnt=0;
        for(int i=1;i<=n;i++)
        {  
            int element=i;
            if(st.count(i+1))
            {
                cnt++;
            }
        } 
        return cnt+1;
    }
};
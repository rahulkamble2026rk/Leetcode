class Solution {
public:
    int maxNumberOfBalloons(string text)  
    {
        map<char,int>stdmap; 

        for(int i=0;i<text.size();i++)
        {
            if(text[i]=='b')
            {
                stdmap[text[i]]++;
            } 
            else if(text[i]=='a') 
            {
                 stdmap[text[i]]++;
            } 
            else if(text[i]=='l')
            {
                 stdmap[text[i]]++;
            } 
            else if(text[i]=='o')
            {
                 stdmap[text[i]]++;
            } 
            else if(text[i]=='n')
            {
                 stdmap[text[i]]++;
            }
        } 

        //kuch nahi abhi sirf check karna kiske kitne multiple occurrances hai  

         //idally balloon ke liye 2 l and 2 o  
         int b_count=stdmap['b'];
         int a_count=stdmap['a']; 
         int l_count=stdmap['l']; 
         int o_count=stdmap['o']; 
         int n_count=stdmap['n']; 
        
        int count=0; 
         
         if(b_count<1 || a_count<1 || l_count<2 || o_count<2 || n_count<1)
         {
            return count;
         }
        while(b_count>=1 && a_count>=1 && l_count>=2 && o_count>=2 && n_count>=1) 
        { 
            b_count--; 
            a_count--; 
            l_count-=2; 
            o_count-=2; 
            n_count--;
            count++; 
            
        } 
        return count;
    }
};
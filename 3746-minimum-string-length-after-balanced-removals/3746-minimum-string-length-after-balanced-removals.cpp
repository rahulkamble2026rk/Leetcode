class Solution {
public:
    int minLengthAfterRemovals(string s)  
    {
        // string has only a and b , we have to remove any substring where a number of the characters are equal to the number of b , after removal the parts must be concated together  

        //let's count the total a and b , get the subtract:  
        int a=0,b=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
            {
                a++;
            } 
            else
            {
                b++;
            }
        } 
        return abs(a-b);

    }
};
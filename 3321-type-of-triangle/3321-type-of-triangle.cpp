class Solution {
public:
    string triangleType(vector<int>& nums)  
    {  
         
         string str="none"; 
         int x=nums[0]; 
         int y=nums[1];
         int z=nums[2]; 

         if(x+y<=z || y+z<=x || x+z<=y)
         {
            return str;
         }
       else if(x==y&&y==z&&x==z)
       {
        str="equilateral";
       } 
       else if(x==y)
       { 
           
              str="isosceles";
       }  
       else if(y==z)
       { 
              str="isosceles";
       } 
       else if(x==z)
       {
           str="isosceles";
       }
       else if(x!=y&&y!=z&&x!=z)
       {   
          int flag=0;
          if(x+y>z)
          {
             flag++;
          } 
          if(x+z>y)
          {
               flag++;
          } 
          if(y+z>x)
          {
              flag++;
          } 
          if(flag==3)
          {
            str="scalene";
          }
       } 
     
       return str;
    } 
};
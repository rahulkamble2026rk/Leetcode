# Write your MySQL query statement below

select x , y, z,
if(x+y<=z or x+z<=y or y+z<=x ,'No','Yes') as triangle
from Triangle
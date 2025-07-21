# Write your MySQL query statement below

-- step1: creating the table , by using the self 
select w1.id from Weather as w1 join Weather as w2 
    on Datediff(w1.recorddate,w2.recorddate)=1 
    where w1.temperature>w2.temperature;
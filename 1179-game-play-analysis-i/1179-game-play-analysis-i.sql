# Write your MySQL query statement below

select player_id, min( event_date ) as first_login 
from Activity
group by player_id 
order by player_id,first_login; 

#because here , we have to do the mapping acc. to the player id and then order by as well

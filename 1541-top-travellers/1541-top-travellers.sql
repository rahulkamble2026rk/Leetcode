# Write your MySQL query statement below

select Users.name as name,ifnull(sum(Rides.distance),0) as travelled_distance from Users 
left join Rides  
on Users.id=Rides.user_id
group by Users.name,Users.id 
order by travelled_distance desc,Users.name;
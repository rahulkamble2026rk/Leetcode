# Write your MySQL query statement below

select Register.contest_id,round(
    (COUNT(Register.contest_id) / (SELECT COUNT(*) FROM Users)) * 100,
    2
  )
    as percentage from Users 
    right join Register 
on Users.user_id=Register.user_id 
group by Register.contest_id 
order by percentage desc , Register.contest_id asc;
# Write your MySQL query statement below
select A1.activity_date as day,
    count(distinct A1.user_id) as active_users
    from Activity as A1 
  
    where A1.activity_date BETWEEN DATE_SUB('2019-07-27', INTERVAL 29 DAY) AND '2019-07-27'
    group by A1.activity_date 
    order by A1.activity_date asc;
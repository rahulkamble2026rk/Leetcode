# Write your MySQL query statement below

select t1.teacher_id ,count(distinct t1.subject_id) as cnt 
    from Teacher as t1 
    join Teacher as t2 on t1.subject_id=t2.subject_id 
    group by t1.teacher_id 
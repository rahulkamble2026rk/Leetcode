SELECT 
  activity.machine_id,
  ROUND(AVG(end_row.timestamp - activity.timestamp), 3) AS processing_time
FROM activity JOIN activity AS end_row
  ON activity.machine_id = end_row.machine_id
  AND activity.process_id = end_row.process_id
WHERE activity.activity_type = 'start'
  AND end_row.activity_type = 'end'
GROUP BY activity.machine_id;

# Write your MySQL query statement below
select w1.id as Id
FROM weather w1
JOIN weather w2
  ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
where w1.temperature>w2.temperature 
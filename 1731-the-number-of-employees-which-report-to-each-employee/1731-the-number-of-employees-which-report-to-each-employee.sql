# Write your MySQL query statement below
select m.employee_id, m.name, count(e.employee_id) as reports_count,
round(avg(e.age)) as average_age
from employees e 
join employees m
on m.employee_id=e.reports_to
group by m.employee_id, m.name
order by m.employee_id;
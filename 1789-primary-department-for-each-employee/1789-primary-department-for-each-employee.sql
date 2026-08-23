# Write your MySQL query statement below
select employee_id, department_id from Employee
where primary_flag='Y' or employee_id IN(
    select employee_id from employee 
    group by employee_id having count(*)=1
);
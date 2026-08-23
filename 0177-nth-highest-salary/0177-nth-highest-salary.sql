CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    SELECT MAX(e1.salary)
        FROM Employee e1
        WHERE N - 1 = (
            SELECT COUNT(DISTINCT e2.salary)
            FROM Employee e2
            WHERE e2.salary > e1.salary
        )
  );
END
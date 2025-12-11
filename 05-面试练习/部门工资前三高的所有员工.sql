-- 方法一：JOIN+子查询
SELECT d.name AS 'Department', e1.name AS 'Employee', e1.salary AS 'Salary'
FROM Employee e1
JOIN Department d ON e1.departmentId = d.id
WHERE 3 > ( #这个个数只能小于3，才能证明这个salary是前三
    SELECT count(DISTINCT e2.salary) #对于一个salary，寻找大于它的salary的个数
    FROM Employee e2
    WHERE e2.salary > e1.salary 
    AND e2.departmentId = e1.departmentId #只在同一部门内比较
)

-- 方法二：窗口函数
SELECT d.name AS 'Department', t.name AS 'Employee', t.salary AS 'Salary'
FROM (
    SELECT name, departmentId, salary,
    DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rnk
    FROM Employee
) t
JOIN Department d ON t.departmentId = d.id
WHERE rnk <= 3

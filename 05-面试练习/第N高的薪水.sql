-- 方法一：ORDER BY+LIMIT
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE M INT;
    SET M = N - 1;
  RETURN (
      SELECT DISTINCT salary
      FROM Employee
      ORDER BY salary DESC
      LIMIT M, 1
  );
END

-- 方法二：窗口函数
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT DISTINCT salary
      FROM (
        # 窗口函数就是给每行打上标签
        SELECT salary,
        DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
        FROM Employee
      ) t
      WHERE rnk = N
  );
END

connect to sample;

-- Q1
SELECT EMPNO, LASTNAME, FIRSTNME
FROM EMPLOYEE
WHERE HIREDATE >= '01-01-2000' AND HIREDATE <= '12-31-2005'
ORDER BY LASTNAME, FIRSTNME;

-- Q2
SELECT EMPNO, LASTNAME, FIRSTNME, JOB, DEPTNO, DEPTNAME
FROM EMPLOYEE
INNER JOIN DEPARTMENT
ON WORKDEPT = DEPTNO
WHERE DEPTNAME = 'OPERATIONS' OR DEPTNAME = 'PLANNING'
ORDER BY DEPTNAME;

-- Q3
SELECT EMPNO, LASTNAME, FIRSTNME, SALARY + BONUS + COMM AS COMPENSATION
FROM EMPLOYEE
ORDER BY COMPENSATION DESC;

--Q4
SELECT EMPNO, LASTNAME, FIRSTNME, SALARY + BONUS + COMM AS COMPENSATION
FROM EMPLOYEE
ORDER BY COMPENSATION
LIMIT 10;

--Q5
SELECT JOB, COUNT(*) AS TOTAL
FROM EMPLOYEE
GROUP BY JOB
ORDER BY TOTAL DESC;

--Q6
SELECT DEPTNO, DEPTNAME, COUNT(*) AS TOTAL
FROM EMPLOYEE
INNER JOIN DEPARTMENT
ON WORKDEPT = DEPTNO
GROUP BY DEPTNO, DEPTNAME
ORDER BY TOTAL;

terminate;
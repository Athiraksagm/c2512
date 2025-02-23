1. Create DEPT and EMP tables and insert data into them.
  

-- Create DEPT table
CREATE TABLE DEPT (
    DEPTNO NUMBER PRIMARY KEY,
    DNAME VARCHAR2(50),
    LOC VARCHAR2(50)
);

-- Insert data into DEPT table
INSERT INTO DEPT (DEPTNO, DNAME, LOC) VALUES
(10, 'ACCOUNTING', 'NEW YORK');
INSERT INTO DEPT (DEPTNO, DNAME, LOC) VALUES
(20, 'RESEARCH', 'DALLAS');
INSERT INTO DEPT (DEPTNO, DNAME, LOC) VALUES
(30, 'SALES', 'CHICAGO');
INSERT INTO DEPT (DEPTNO, DNAME, LOC) VALUES
(40, 'OPERATIONS', 'BOSTON');

-- Create EMP table
CREATE TABLE EMP (
    EMPNO NUMBER PRIMARY KEY,
    ENAME VARCHAR2(50),
    JOB VARCHAR2(50),
    MGR NUMBER,
    HIREDATE DATE,
    SAL NUMBER(10, 2),
    COMM NUMBER(10, 2),
    DEPTNO NUMBER,
    CONSTRAINT fk_deptno FOREIGN KEY (DEPTNO) REFERENCES DEPT(DEPTNO)
);

-- Insert data into EMP table
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7369, 'SMITH', 'CLERK', 7902, TO_DATE('2010-12-17', 'YYYY-MM-DD'), 800.00, NULL, 20);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7499, 'ALLEN', 'SALESMAN', 7698, TO_DATE('2011-02-20', 'YYYY-MM-DD'), 1600.00, 300.00, 30);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7521, 'WARD', 'SALESMAN', 7698, TO_DATE('2011-02-22', 'YYYY-MM-DD'), 1250.00, 500.00, 30);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7566, 'JONES', 'MANAGER', 7839, TO_DATE('2011-04-02', 'YYYY-MM-DD'), 2975.00, NULL, 20);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7654, 'MARTIN', 'SALESMAN', 7698, TO_DATE('2011-09-28', 'YYYY-MM-DD'), 1250.00, 1400.00, 30);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7698, 'BLAKE', 'MANAGER', 7839, TO_DATE('2011-05-01', 'YYYY-MM-DD'), 2850.00, NULL, 30);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7782, 'CLARK', 'MANAGER', 7839, TO_DATE('2011-06-09', 'YYYY-MM-DD'), 2450.00, NULL, 10);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7788, 'SCOTT', 'ANALYST', 7566, TO_DATE('2012-12-09', 'YYYY-MM-DD'), 3000.00, NULL, 20);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7839, 'KING', 'PRESIDENT', NULL, TO_DATE('2011-11-17', 'YYYY-MM-DD'), 5000.00, NULL, 10);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7844, 'TURNER', 'SALESMAN', 7698, TO_DATE('2011-09-08', 'YYYY-MM-DD'), 1500.00, 0.00, 30);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7876, 'ADAMS', 'CLERK', 7788, TO_DATE('2013-01-12', 'YYYY-MM-DD'), 1100.00, NULL, 20);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7900, 'JAMES', 'CLERK', 7698, TO_DATE('2011-12-03', 'YYYY-MM-DD'), 950.00, NULL, 30);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7902, 'FORD', 'ANALYST', 7566, TO_DATE('2011-12-03', 'YYYY-MM-DD'), 3000.00, NULL, 20);
INSERT INTO EMP (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM, DEPTNO) VALUES
(7934, 'MILLER', 'CLERK', 7782, TO_DATE('2012-01-23', 'YYYY-MM-DD'), 1300.00, NULL, 10);

-- Commit the changes
COMMIT;

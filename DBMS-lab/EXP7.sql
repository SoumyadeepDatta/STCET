CREATE table EMP(EMPNO number(2), ENAME varchar2(20), JOB char(20), MGR number(2), HIREDATE date, SAL number(2), COMM number(2), DEPTNO number(2) references DEPT(DNO));


Alter table EMP add(Phone number(10));

Alter table EMP MODIFY(JOB varchar2(20));

Alter table EMP DROP COLUMN Phone;

Alter table EMP MODIFY(EMPNO number(4));
Alter table EMP MODIFY(MGR number(4));
Alter table EMP MODIFY(SAL number(4));
Alter table EMP MODIFY(COMM number(4));

Insert into EMP(EMPNO,ENAME,JOB,MGR,HIREDATE,SAL,COMM,DEPTNO) values(7369,'Smith','Clerk',7902,'17-DEC-80',800,NULL,20);

Insert into EMP(EMPNO,ENAME,JOB,MGR,HIREDATE,SAL,COMM,DEPTNO) values(7499,'Allen','Salesman',7698,'20-FEB-81',1600,300,30);

Insert into EMP(EMPNO,ENAME,JOB,MGR,HIREDATE,SAL,COMM,DEPTNO) values(7521,'Ward','Salesman',7698,'22-FEB-81',1250,500,30);

Insert into EMP(EMPNO,ENAME,JOB,MGR,HIREDATE,SAL,COMM,DEPTNO) values(7566,'Jones','Manager',7839,'2-APR-81',2975,NULL,20);

Insert into EMP(EMPNO,ENAME,JOB,MGR,HIREDATE,SAL,COMM,DEPTNO) values(7654,'Martin','Salesman',7698,'28-SEP-81',1250,1400,30);

Insert into EMP(EMPNO,ENAME,JOB,MGR,HIREDATE,SAL,COMM,DEPTNO) values(7698,'Blake','Manager',7839,'1-MAY-81',2850,NULL,30);

Insert into EMP(EMPNO,ENAME,JOB,MGR,HIREDATE,SAL,COMM,DEPTNO) values(7782,'Clerk','Manager',7839,'9-JUN-81',2450,NULL,10);

Insert into EMP(EMPNO,ENAME,JOB,MGR,HIREDATE,SAL,COMM,DEPTNO) values(7788,'Scott','Analyst',7566,'9-DEC-82',3000,NULL,20);

Insert into EMP(EMPNO,ENAME,JOB,MGR,HIREDATE,SAL,COMM,DEPTNO) values(7839,'King','President',NULL,'17-NOV-81',5000,NULL,10);

Insert into EMP values(7844,'Turner','Salesman',7698,'8-SEP-81',1500,500,30);

Insert into EMP values(7876,'Adams','Clerk',7788,'12-JAN-83',1100,NULL,20);

Insert into EMP values(7900,'James','Clerk',7698,'3-DEC-81',950,NULL,30);

Insert into EMP values(7902,'Ford','Analyst',7566,'4-DEC-81',3000,NULL,20);

Insert into EMP values(7934,'Miller','Clerk',7782,'23-JAN-82',1300,NULL,10);


-- —------------------------------------------------------------

-- 1
select ename from emp
where sal = (select max(sal) from emp);

-- 2
select ename from emp
where sal = (select max(sal) from emp where job = 'Salesman') and job = 'Salesman';

-- 3
select ename from emp
where sal = (select min(sal) from emp where job = 'Clerk') and job = 'Clerk';

-- 4
-- select avg(sal) as avg_sal, dno from emp group by dno;

-- select dno from (select avg(sal) as avg_sal, dno from emp group by dno);

-- select dno from (select avg(sal) as avg_sal, dno from emp group by dno)
-- where avg_sal = (select max(avg_sal) from (select avg(sal) as avg_sal, dno from emp group by dno));

-- corrected
select dname from dept 
where dno = (select dno from (select avg(sal) as avg_sal, dno from emp group by dno)
where avg_sal = (select max(avg_sal) from (select avg(sal) as avg_sal, dno from emp group by dno)));

-- – - 5
select Ename, sal from emp where sal > (select sal from emp where Ename like 'Turner');

-- – - 6
select Ename from emp where Hiredate > (select Hiredate from emp where Ename like 'Allen');


-- — - 7
select dname from emp, dept
where emp.deptno = dept.dno
and emp.ename = 'Ford';


-- 8
-- select sum(sal), dno from emp group by dno;

select dname from dept 
where dno = (select dno from (select sum(sal) as sum_sal, dno from emp group by dno)
where sum_sal = (select max(sum_sal) from (select sum(sal) as sum_sal, dno from emp group by dno)));

-- – - 9
select loc from dept where dno = ( select deptno from emp where ename like 'Smith');

-- - - 10
select distinct loc from dept where dno in (select dno from emp where ename in (select ename from emp where empno in (select mgr from emp)));

-- 11
select job from emp where ename like 'Martin';

-- - - 12
select ename from emp where dno in (select dno from dept where loc like 'Dallas') and sal = (select max(sal) from emp where dno in (select dno from dept where loc like 'Dallas'));


-- - - 13
select dname from dept where dno not in (select dno from emp);

-- - - 14
select ename from emp where hiredate = (select hiredate from emp where ename like 'Adams');

-- 15
select dname from dept where dno not in (select dno from emp where comm is not null);

-- –- 16
select ename from emp outer where sal = (select min(sal) from emp where dno = outer.dno);

-- 17 (test)
 select dname from dept where dno in (select dno from emp group by dno having count(*) > 1);


-- 17 (corrected)


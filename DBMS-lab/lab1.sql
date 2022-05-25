create table dept(dno number(3) primary key, dname varchar2(20), loc
varchar2(20) );
create table emp(empno number(4) primary key, ename varchar2(20), job
varchar(20), mgr number(4), hiredate date, sal number(6), comm number(6),
dno number(3) references dept(dno));
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--

alter table emp
add phone varchar2(10);
alter table emp
modify job char(20);
alter table emp
modify job varchar2(20);
alter table emp
drop column phone;
insert into dept values(10,'Accounting','New York');
insert into dept values(20,'Research','Dallas');
insert into dept values(30,'Sales','Chicago');
insert into dept values(40,'Operations','Boston');
insert into emp(empno, ename, job, mgr, hiredate, sal, dno) values
(7369,'Smith','Clerk',7902,'17-Dec-1980',800,20);

insert into emp values (7499,'Allen','Salesman',7698,'20-Feb-
1981',1600,300,30);

insert into emp values (7521,'Ward','Salesman',7698,'22-Feb-
1981',1250,500,30);

insert into emp(empno, ename, job, mgr, hiredate, sal, dno) values
(7566,'Jones','Manager',7839,'02-Apr-1981',2975,20);

insert into emp values (7654,'Martin','Salesman',7698,'28-Sep-
1981',1250,1400,30);

insert into emp(empno, ename, job, mgr, hiredate, sal, dno) values
(7698,'Blake','Manager',7839,'01-May-1981',2850,30);
insert into emp(empno, ename, job, mgr, hiredate, sal, dno) values
(7782,'Clark','Manager',7839,'09-Jun-1981',2450,10);
insert into emp(empno, ename, job, mgr, hiredate, sal, dno) values
(7788,'Scott','Analyst',7566,'09-Dec-1982',3000,20);
insert into emp(empno, ename, job, hiredate, sal, dno) values
(7839,'King','President','17-Nov-1981',5000,10);

insert into emp values (7844,'Turner','Salesman',7698,'08-Sep-
1981',1500,500,30);

-- R o l l 2 6 P a g e | 2
insert into emp(empno, ename, job, mgr, hiredate, sal, dno) values
(7876,'Adams','Clerk',7788,'12-Jan-1983',1100,20);
insert into emp(empno, ename, job, mgr, hiredate, sal, dno) values
(7900,'James','Clerk',7698,'03-Dec-1981',950,30);
insert into emp(empno, ename, job, mgr, hiredate, sal, dno) values
(7902,'Ford','Analyst',7566,'04-Dec-1981',3000,20);
insert into emp(empno, ename, job, mgr, hiredate, sal, dno) values
(7934,'Miller','Clerk',7782,'23-Jan-1982',1300,10);
create table salespeople(snum number(3) primary key, sname varchar2(20),
city varchar2(20), comm number(4));
--------------------------------------------------------------------------
-----------------------------------------------------------------
-- Q. 10
--------------------------------------------------------------------------
------------------------------------------------------------------
create table client_master(
clientno varchar2(6) primary key check(clientno like
'C%'),
name varchar2(20) not null,
city varchar2(15),
pincode number(8),
state varchar2(15),
balancedue number(10,2));
--------------------------------------------------------------------------
--------

create table product_master(
productno varchar2(6) primary key check(productno like
'P%'),
description varchar2(15) not null,
profitpercent varchar2(6) not null,
unitmeasure varchar2(10) not null,
qtyinhand number(8) not null,
reorderlvl number(8) not null,
sellprice number(8,2) not null check(sellprice > 0),
costprice number(8,2) not null check(costprice > 0));
--------------------------------------------------------------------------
-----------
create table salesman_master(
salesmanno varchar2(6) primary key check(salesmanno like
'S%'),
name varchar2(20) not null,
address1 varchar2(10) not null,
address2 varchar2(10),
city varchar2(20),
pincode number(7),
state varchar2(20),
sal number(8,2) not null check(sal <> 0),

-- R o l l 2 6 P a g e | 3
tgttoget number(6,2),
ytdsales number(6,2),
remarks varchar2(20));
--------------------------------------------------------------------------
-------------
create table sales_order(
orderno varchar2(6) primary key check(orderno like
'O%'),
orderdate date,
clientno varchar2(6) references client_master(clientno),
delyaddress varchar2(25),
salesmanno varchar2(6) references
salesman_master(salesmanno),
delytype char(1) default 'f' check(delytype like 'p' or
delytype like 'f'),
billedyn char(1),
delydate date,
check(delydate >= orderdate),
orderstatus varchar2(10) check(orderstatus in ('in
process','fulfilled','backorder','cancelled')));

--------------------------------------------------------------------------
------------------
create table sales_order_details(
orderno varchar2(6) references sales_order(orderno),
productno varchar2(6) references
product_master(productno),
qtyordered number(8),
qtydisp number(8),
productrate number(10,2),
primary key(orderno,productno));
--------------------------------------------------------------------------
----------------
-- Insert data into tables
--------------------------------------------------------------------------
----------------
-- CLIENT_MASTER
--------------------------------------------------------------------------
----------------
insert into CLIENT_MASTER values('C00001','Ivan
Bayross','Mumbai',400054,'Maharashtra',15000);
insert into CLIENT_MASTER
values('C00002','MamataMazumdar','Madras',780001,'Tamil Nadu',0);
insert into CLIENT_MASTER
values('C00003','ChhayaBankar','Mumbai',400057,'Maharashtra',5000);
insert into CLIENT_MASTER values('C00004','Ashwini
Joshi','Bangalore',560001,'Karnataka',0);
insert into CLIENT_MASTER values('C00005','Hansel
Colaco','Mumbai',400060,'Maharashtra',2000);

-- R o l l 2 6 P a g e | 4
insert into CLIENT_MASTER values('C00006','Deepak
Sharma','Mangalore',560050,'Karnataka',0);
--------------------------------------------------------------------------
-------------------
-- product_master
--------------------------------------------------------------------------
-------------------

insert into product_master values('P00001','T-
Shirts',5,'Piece',200,50,350,250);

insert into product_master
values('P0345','Shirts',6,'Piece',150,50,500,350);
insert into product_master values('P06734','Cotton
Jeans',5,'Piece',100,20,600,450);
insert into product_master
values('P07865','Jeans',5,'Piece',100,20,750,500);
insert into product_master
values('P07868','Trousers',2,'Piece',150,50,850,550);
insert into product_master
values('P07885','Pullovers',2.5,'Piece',80,30,700,450);
insert into product_master values('P07965','Denim
Shirts',4,'Piece',100,40,350,250);
insert into product_master values('P07975','Lyers
Tops',5,'Piece',70,30,300,175);
insert into product_master
values('P08865','Skirts',5,'Piece',75,30,450,300);
--------------------------------------------------------------------------
-----------------
-- SALESMAN_MASTER
--------------------------------------------------------------------------
-------------------
insert into SALESMAN_MASTER
values('S00001','Aman','A/14','Jadavpur','Kolkata',700032,'West
Bengal',3000,100,50,'Good');
insert into SALESMAN_MASTER
values('S00002','Omkar','65','Chandni','Delhi',110006,'Delhi',3000,200,100
,'Good');

insert into SALESMAN_MASTER values('S00003','Raj','P-
7','Bandra','Mumbai',400032,'Maharashtra',3000,200,100,'Good');

insert into SALESMAN_MASTER
values('S00004','Ashish','A/5','Agara','Bengaluru',560034,'Karnataka',3500
,200,150,'Good');
--------------------------------------------------------------------------
------------------------------------------------
-- SALES_ORDER
--------------------------------------------------------------------------
------------------------------------------------
insert into SALES_ORDER values('O19001','10-Jul-2002','C00001','B/19
Saltlake','S00001','f','N','20-Jul-2002','in process');

-- R o l l 2 6 P a g e | 5
insert into SALES_ORDER values('O19002','15-Jun-2002','C00002','A/23
Beleghata','S00002','p','N','27-Jun-2002','cancelled');
insert into SALES_ORDER values('O46865','11-Feb-2002','C00003','19
Dhakuria','S00003','f','Y','20-Feb-2002','fulfilled');
insert into SALES_ORDER values('O19003','15-Mar-2002','C00001','15/A
Behala','S00001','f','Y','07-Apr-2002','fulfilled');
insert into SALES_ORDER values('O46866','12-May-2002','C00004','166
Bansdroni','S00002','p','N','22-May-2002','cancelled');
insert into SALES_ORDER values('O19008','14-Jul-2002','C00005','23
Garia','S00004','f','N','26-Jul-2002','in process');
--------------------------------------------------------------------------
-------------------------------------------------
-- SALES_ORDER_DETAILS
-- some of them will give error cause some orderno and productno are not
-- present in the parent table(s)
insert into SALES_ORDER_DETAILS values('O19001','P00001',4,4,525);
insert into SALES_ORDER_DETAILS values('O19001','P07965',2,1,8400);
insert into SALES_ORDER_DETAILS values('O19001','P07885',2,1,5250);
insert into SALES_ORDER_DETAILS values('O19002','P00001',10,0,525);
insert into SALES_ORDER_DETAILS values('O19005','P07868',3,3,3150);
insert into SALES_ORDER_DETAILS values('O19005','P07885',3,1,5250);
insert into SALES_ORDER_DETAILS values('O19005','P00001',10,10,525);
insert into SALES_ORDER_DETAILS values('O19005','P0345',4,4,1050);
insert into SALES_ORDER_DETAILS values('O19003','P03453',2,2,1050);
insert into SALES_ORDER_DETAILS values('O19003','P06734',1,1,12000);
insert into SALES_ORDER_DETAILS values('O19006','P07965',1,0,8400);
insert into SALES_ORDER_DETAILS values('O19006','P07975',1,0,1050);
insert into SALES_ORDER_DETAILS values('O19008','P00001',10,5,525);
insert into SALES_ORDER_DETAILS values('O19008','P07975',5,3,1050);
-- -----------------------------------------------------------------------
-- SALES_ORDER_DETAILS, PRODUCT_MASTER corrected
INSERT INTO SALES_ORDER_DETAILS VALUES('O46865','P07868',3,3,3150);
INSERT INTO SALES_ORDER_DETAILS VALUES('O46865','P07885',3,1,5250);
INSERT INTO SALES_ORDER_DETAILS VALUES('O46865','P00001',10,10,525);
INSERT INTO SALES_ORDER_DETAILS VALUES('O46865','P0345',4,4,1050);
INSERT INTO SALES_ORDER_DETAILS VALUES('O46866','P07965',1,0,8400);
INSERT INTO SALES_ORDER_DETAILS VALUES('O46866','P07975',1,0,1050);
INSERT INTO PRODUCT_MASTER
VALUES('P03453','Beanie',2,'Piece',100,50,300,200);
INSERT INTO SALES_ORDER_DETAILS VALUES('O19003','P03453',2,2,1050);

-- R o l l 2 6 P a g e | 6

-- Questionnaires:
-- 1.
INSERT ALL
INTO table_name (column1, column2, column_n) VALUES (expr1, expr2,
expr_n)
INTO table_name(column1, column2, column_n) VALUES (expr1, expr2,
expr_n)
INTO table_name (column1, column2, column_n) VALUES (expr1, expr2,
expr_n)
SELECT * FROM dual;
-- 2.
Create, alter, and drop.
CREATE
------
create table emp(empno number(4) primary key, ename varchar2(20), job
varchar(20), mgr number(4), hiredate date, sal number(6), comm number(6),
dno number(3) references dept(dno));
ALTER
------
alter table emp
add phone varchar2(10);
alter table emp
modify job varchar2(20);
alter table emp
drop column phone;
DROP
------
drop table SALESPEOPLE;
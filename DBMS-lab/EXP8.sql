create table salespeople(snum number(3) primary key, sname varchar2(20),  city varchar2(20), comm number(4)); 


create table orders(
onum number(3) primary key,
amt number(4),
odate date,
cnum number(3) references customer(cnum),
snum number(3) references salespeople(snum)
);


create table customer(
cnum number(3) primary key,
cname varchar2(20),
city varchar2(20),
rating number(2),
snum number(3) references salespeople(snum)
);



INSERT INTO SALESPEOPLE VALUES(110,'Ayan Ghosh','kolkata',1200);
INSERT INTO SALESPEOPLE VALUES(101,'Aradhita Dasgupta ','chennai',1500);
INSERT INTO SALESPEOPLE VALUES(102,'Shubhaiu Das','kolkata',2000);
INSERT INTO SALESPEOPLE VALUES(103,'Abhinaba De','mumbai',1600);
INSERT INTO SALESPEOPLE VALUES(104,'Snigdharup Guchait','chennai',1200);
INSERT INTO SALESPEOPLE VALUES(105,'Debasish Chakroborty','delhi',2000);
INSERT INTO SALESPEOPLE VALUES(106,'Gautam Banerjea','kolkata',1600);
INSERT INTO SALESPEOPLE VALUES(107,'Shila Ghosh','lahore',1300);
INSERT INTO SALESPEOPLE VALUES(108,'Amiya Halder','mumbai',1000);
INSERT INTO SALESPEOPLE VALUES(109,'Ishita Mosh','kolkata',900);

INSERT INTO CUSTOMER VALUES(200,'Aron Finch','Kolkata',6,100);
INSERT INTO CUSTOMER VALUES(201,'David Warner','Kolkata',5,101);
INSERT INTO CUSTOMER VALUES(202,'Smith Jones','Chennai',6,102);
INSERT INTO CUSTOMER VALUES(203,'Bruder Border','Bangalore',6,103);
INSERT INTO CUSTOMER VALUES(204,'Kellner Brown','Kolkata',4.5,103);
INSERT INTO CUSTOMER VALUES(205,'Meghan Haynes','Delhi',6,105);
INSERT INTO CUSTOMER VALUES(206,'Ammy Ellen Jones','Mumbai',6,106);
INSERT INTO CUSTOMER VALUES(207,'Micheal Vaghuan','Mumbai',8,107);
INSERT INTO CUSTOMER VALUES(208,'Adams Smith','Kolkata',7.5,107);
INSERT INTO CUSTOMER VALUES(209,'Steven Smith','Lahore',8.5,109);
insert into ORDERS values(901, 1200, '17-Dec-2021', 201, 105);
insert into ORDERS values(902, 9802, '31-Dec-2021', 202, 101);
insert into ORDERS values(903, 1008, '27-Jan-2022', 203, 109);
insert into ORDERS values(904, 5698, '27-Jan-2022', 204, 105);
insert into ORDERS values(905, 3456, '6-Feb-2022', 204, 104);
insert into ORDERs values(906, 9230, '22-Feb-2022', 208, 102);
insert into ORDERS values(907, 564, '28-Feb-2022', 206, 106);
insert into ORDERS values(908, 10, '13-Mar-2022', 202, 109);
insert into ORDERS values(909, 1680, '17-Mar-2022', 203, 107);
insert into ORDERS values(910, 121, '23-Apr-2022', 209, 103);



-- 1.
create view highest_rating as
select * from customer where rating = (select max(rating) from customer);
 select * from highest_rating;
-- 2.
 create view salesp_each_city as
 select city, count(*) as salespersons from salespeople
 group by city;
 select * from salesp_each_city;
-- 3.
 create view avg_and_total_orders as
  select snum, avg(amt) as avg_order, sum(amt) as total_order
 from orders group by snum;
 select * from avg_and_total_orders;
-- 4.

select sname from (select * from salespeople,customer
where customer.snum = salespeople.snum) group by sname
having count(*) > 1;
-- //corrected
create view sp_w_multiple_c as
select sname from (select * from salespeople,customer
where customer.snum = salespeople.snum) group by sname
having count(*) > 1;
Select * from sp_w_multiple_c as;


-- 5.
create view salespeople_customer_orders as
 select sname, cname, onum from
 salespeople, customer, orders8
 where orders.snum = salespeople.snum
 and orders.cnum = customer.cnum;
 select * from salespeople_customer_orders;
-- 6.
 select snum, comm from salespeople
where comm between 1000 and 2000;
-- // corrected
 create view salespeople_comm as
   select snum, comm from salespeople
  where comm between 1000 and 2000;
select * from salespeople_comm;





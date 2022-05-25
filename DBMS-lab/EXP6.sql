CREATE TABLE customers(
CustomerID NUMBER(3) PRIMARY KEY,
CustomerName VARCHAR2(30),
ContactName VARCHAR2(30),
Address VARCHAR2(75),
City VARCHAR2(20),
PostalCode NUMBER(5),
Country VARCHAR2(15));

CREATE TABLE Suppliers(
SupplierID NUMBER(3) PRIMARY KEY,
SupplierName VARCHAR2(30),
ContactName VARCHAR2(30),
Address VARCHAR2(75),
City VARCHAR2(20),
PostalCode NUMBER(5),
Country VARCHAR2(15));

INSERT ALL
INTO CUSTOMERS VALUES(1, 'Alfreds Futter', 'Maria Anders', 'Obere Str.57', 'Berlin', 12209, 'Germany')
INTO CUSTOMERS VALUES(2, 'Ana helados', 'Ana Trujillo', 'Avda. Construction 2222', 'Mexico D.F', 05021, 'Mexico')
INTO CUSTOMERS VALUES(3, 'Antonio Moreno', 'Antonio Moreno', 'Mataderos 2312', 'Mexico D.F', 05023, 'Mexico')
SELECT * FROM DUAL;

INSERT ALL
INTO Suppliers VALUES(1, 'Exotic Liquid', 'Charlotte Cooper', '49 Gilbert St.', 'Berlin', 12209, 'Germany')
INTO Suppliers VALUES(2, 'New Orleans Cajun Delights', 'Shelley Burke', 'P.O. Box 78934', 'Mexico D.F', 05023, 'Mexico')
INTO Suppliers VALUES(3, 'Grandma Kellys Homestead', 'Regina Murphy', '707 Oxford Rd.', 'Ann Arbor', 48104, 'USA')
SELECT * FROM DUAL;



-- 1> 
SELECT City from CUSTOMERS
UNION
SELECT City from SUPPLIERS;


-- 2>
SELECT City from CUSTOMERS
UNION ALL
SELECT City from SUPPLIERS;


-- 3>
SELECT CITY,COUNTRY from CUSTOMERS 
WHERE COUNTRY = 'Germany'
UNION ALL
SELECT CITY,COUNTRY from SUPPLIERS
WHERE COUNTRY = 'Germany'
Order By CITY;


-- 4>
SELECT CUSTOMERNAME from CUSTOMERS
INTERSECT
SELECT SUPPLIERNAME from SUPPLIERS;




-- 5> (Corrected)

SELECT country FROM suppliers
MINUS
SELECT country FROM customers;


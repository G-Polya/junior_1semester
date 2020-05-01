create table employee
(
    Fname       varchar(15)         not null,
    Minit       char,  
    Lname       varchar(15)         not null,
    Ssn         Char(9)             not null,
    Bdate       Date,
    Address     Varchar(30),
    Sex         char,
    salary      decimal(10,2),
    Super_ssn   char(9),
    Dno         int                 not null,
    primary key(Ssn)
);

insert into employee values
(
    'Franklin',
    'T',
    'Wong',
    '333445555',
    to_date('1955-12-08','yyyy-mm-dd'),
    '638 Voss, Houston, TX',
    'M',
    '40000',
    '888665555',
    '5'
);

insert into employee values
(
    'Alicia',
    'J',
    'Zelaya',
    '999887777',
    to_date('1968-01-19','yyyy-mm-dd'),
    '3321 Castle, Spring, TX',
    'F',
    '25000',
    '987654321',
    '4'
);

insert into employee values
(
    'Jennifer',
    'S',
    'Wallace',
    '987654321',
    to_date('1941-06-20','yyyy-mm-dd'),
    '291 Berry, Bellaire, TX',
    'F',
    '43000',
    '888665555',
    '4'
);

insert into employee values
(
    'Ramesh',
    'K',
    'Narayan',
    '666884444',
    to_date('1962-09-15','yyyy-mm-dd'),
    '975 Fire Oak, Humble, TX',
    'M',
    '38000',
    '33445555',
    '5'
);

insert into employee values
(
    'Joyce',
    'A',
    'English',
    '453453453',
    to_date('1972-07-31','yyyy-mm-dd'),
    '5631 Rice, Houston, TX',
    'F',
    '25000',
    '333445555',
    '5'
);

insert into employee values
(
    'Ahmad',
    'V',
    'Jabbar',
    '987987987',
    to_date('1969-03-29','yyyy-mm-dd'),
    '980 Dallas, Houston, TX',
    'M',
    '25000',
    '987654321',
    '5'
);

insert into employee values
(
    'James',
    'E',
    'Borg',
    '888665555',
    to_date('1937-11-10','yyyy-mm-dd'),
    '450 Stone, Houston, TX',
    'M',
    '55000',
    NULL,
    '1'
);
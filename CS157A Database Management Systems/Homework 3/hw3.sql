connect to cs157a;

delete from hw3.student;
delete from hw3.class;
delete from hw3.class_prereq;
delete from hw3.schedule;

INSERT INTO hw3.student VALUES
       ('90000','John','Doe','M'),
       ('90001','Jane','Doe','F');

INSERT INTO hw3.class VALUES
      ('10000','CS100W','Technical Writing Workshop'),
      ('20000','CS46A','Intro to Programming'),
      ('20001','CS46B','Intro to Data Structures'),
      ('40000','CS47','Intro to Computer Systems'),
      ('50000','CS49J','Programming in Java'),
      ('60000','CS157A','Intro to Database Mgmt Systems'),
      ('60001','CS157B','Database Management Systems II'),
      ('70000','CS160','Intro to Programming'),
      ('80000','CS146','Data Structures and Algorithms');

INSERT INTO hw3.class_prereq VALUES
       ('20001','20000'),
       ('60000','80000'),
       ('60001','60000'),
       ('80000','20001'),
       ('70000','80000'),
       ('70000','50000'),
       ('70000','10000');

INSERT INTO hw3.student VALUES ('00001','Male','Student 1','M');
INSERT INTO hw3.student VALUES ('00002','Female','Student 2','F');

-- Adding a class with no prereq (PASS)
INSERT INTO hw3.schedule VALUES ('00001','10000',1,2019,'A');
INSERT INTO hw3.schedule VALUES ('00002','20000',1,2019,'B');

-- Adding a class with 1 prereq that has been completed by student (PASS)
INSERT INTO hw3.schedule VALUES ('00002','20001',2,2019,NULL);

-- Adding a class with 1 prereq that has been NOT completed by student (FAIL)
INSERT INTO hw3.schedule VALUES ('00001','20001',3,2019,NULL);

-- Updating grade to 'F'
UPDATE hw3.schedule SET hw3.schedule.grade = 'F' where hw3.schedule.student_id = '00002' AND hw3.schedule.class_id = '20001';

-- Adding a class with 1 prereq that student failed (FAIL)
INSERT INTO hw3.schedule VALUES ('00002','80000',1,2019, NULL);

-- Adding a class with no prereq (PASS)
INSERT INTO hw3.schedule VALUES ('00001','20000',1,2019,NULL);

-- Adding a class with 1 prereq that student has null grade for (FAIL)
INSERT INTO hw3.schedule VALUES ('00001','20001',1,2019, NULL);

-- Adding a class with multiple prereqs that student has not completed (FAIL)
INSERT INTO hw3.schedule VALUES ('00002','70000',1,2019, NULL);

-- Updating grade to 'A'
UPDATE hw3.schedule SET hw3.schedule.grade = 'A' where hw3.schedule.student_id = '00002' AND hw3.schedule.class_id = '20001';

-- Adding classes needed to add CS160 (PASS)
INSERT INTO hw3.schedule VALUES ('00002','10000',1,2020,'B');
INSERT INTO hw3.schedule VALUES ('00002','50000',1,2020,'C');
INSERT INTO hw3.schedule VALUES ('00002','80000',1,2020,'A');

-- Adding a class with multiple prereqs that student has completed (PASS)
INSERT INTO hw3.schedule VALUES ('00002','70000',1,2019, NULL);

terminate;

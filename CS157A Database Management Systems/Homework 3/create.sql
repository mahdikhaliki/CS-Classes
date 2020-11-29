-- HW#3
-- Section 3
-- Student ID: 014339182
-- Khaliki, Mahdi
-- In order to run this sql script with the ^ as your line delimiter, use the follow command options
-- db2 -td"^" -f hw3_sample.sql

connect to CS157A^
DROP TRIGGER hw3.classcheck^
DROP TABLE hw3.schedule^
DROP TABLE hw3.class_prereq^
DROP TABLE hw3.class^
DROP TABLE hw3.student^

--Creating student table
CREATE TABLE hw3.student (
    student_id CHAR(5) NOT NULL PRIMARY KEY,
    first VARCHAR(20) NOT NULL,
    last VARCHAR(20) NOT NULL,
    gender CHAR(1) NOT NULL CHECK (gender = 'M' OR gender = 'F' OR gender = 'U')
)^

--Creating class table
CREATE TABLE hw3.class (
    class_id CHAR(5) NOT NULL PRIMARY KEY,
    name VARCHAR(10) NOT NULL,
    desc VARCHAR(30) NOT NULL
)^

--Creating pre-req table
CREATE TABLE hw3.class_prereq (
    class_id CHAR(5) NOT NULL,
    prereq_id CHAR(5) NOT NULL,
    FOREIGN KEY (class_id) REFERENCES hw3.class (class_id) ON DELETE CASCADE,
    FOREIGN KEY (prereq_id) REFERENCES hw3.class (class_id) ON DELETE CASCADE
)^

--Creating schedule table
CREATE TABLE hw3.schedule (
    student_id CHAR(5) NOT NULL,
    class_id CHAR(5) NOT NULL,
    semester INT NOT NULL CHECK (semester BETWEEN 1 AND 3),
    year INT NOT NULL CHECK (year BETWEEN 2013 AND 2021),
    grade CHAR(1) CHECK (grade BETWEEN 'A' AND 'D' OR grade = 'F' OR grade = 'I'),
    FOREIGN KEY (student_id) REFERENCES hw3.student (student_id) ON DELETE CASCADE,
    FOREIGN KEY (class_id) REFERENCES hw3.class (class_id) ON DELETE CASCADE
)^

--Creating trigger for pre-req
CREATE TRIGGER hw3.classcheck
NO CASCADE BEFORE INSERT ON hw3.schedule
REFERENCING NEW AS newrow
FOR EACH ROW MODE DB2SQL
WHEN ( 0 < (SELECT COUNT(*)
              FROM hw3.class_prereq
              WHERE hw3.class_prereq.class_id = newrow.class_id ) )
BEGIN ATOMIC
        DECLARE num_prereq INT;
        DECLARE prereq_pass INT;

        SET num_prereq = (SELECT COUNT(*)
                             FROM hw3.class_prereq
                             WHERE hw3.class_prereq.class_id = newrow.class_id);

        SET prereq_pass = (SELECT COUNT(*)
                              FROM hw3.schedule s
                              WHERE s.student_id = newrow.student_id
                              AND s.class_id IN (
                                  SELECT prereq_id
                                  FROM hw3.class_prereq c
                                  WHERE newrow.class_id = c.class_id
                              )
                              AND s.grade BETWEEN 'A' AND 'D');

       IF (num_prereq > prereq_pass)
            THEN SIGNAL SQLSTATE '88888' ( 'Missing Pre-req' );
       END IF;
END^

terminate;

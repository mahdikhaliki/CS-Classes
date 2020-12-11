--
-- db2 -td"@" -f p2.sql
--
CONNECT TO CS157A@

DROP PROCEDURE P2.CUST_CRT@
DROP PROCEDURE P2.CUST_LOGIN@
DROP PROCEDURE P2.ACCT_OPN@
DROP PROCEDURE P2.ACCT_CLS@
DROP PROCEDURE P2.ACCT_DEP@
DROP PROCEDURE P2.ACCT_WTH@
DROP PROCEDURE P2.ACCT_TRX@
DROP PROCEDURE P2.ADD_INTEREST@


CREATE PROCEDURE P2.CUST_CRT
(IN p_name CHAR(15), IN p_gender CHAR(1), IN p_age INTEGER, IN p_pin INTEGER, OUT id INTEGER, OUT sql_code INTEGER, OUT err_msg CHAR(100))
LANGUAGE SQL
  BEGIN
    IF p_gender != 'M' AND p_gender != 'F' THEN
      SET sql_code = -100;
      SET err_msg = 'Invalid gender';
    ELSEIF p_age <= 0 THEN
      SET sql_code = -100;
      SET err_msg = 'Invalid age';
    ELSEIF p_pin < 0 THEN
      SET sql_code = -100;
      SET err_msg = 'Invalid pin';
    ELSE
      SET sql_code = 0;

      INSERT INTO p2.customer(name, gender, age, pin) VALUES (p_name, p_gender, p_age, p2.encrypt(p_pin));

      SET id = (SELECT SYSIBM.IDENTITY_VAL_LOCAL() FROM p2.customer LIMIT 1);
    END IF;
END@

CREATE PROCEDURE P2.CUST_LOGIN
(IN p_id INTEGER, IN p_pin INTEGER, OUT valid INTEGER, OUT sql_code INTEGER, OUT err_msg CHAR(100))
LANGUAGE SQL
  BEGIN
    SET valid = (SELECT COUNT(*)
                FROM p2.customer
                WHERE id = p_id AND p2.decrypt(pin) = p_pin);

    IF valid = 1 THEN
      SET sql_code = 0;
    ELSE
      SET sql_code = -100;
      SET err_msg = 'Incorrect id or pin';
    END IF;
END@

CREATE PROCEDURE P2.ACCT_OPN
(IN p_id INTEGER, IN p_balance INTEGER, IN type CHAR(1), OUT number INTEGER, OUT sql_code INTEGER, OUT err_msg CHAR(100))
LANGUAGE SQL
  BEGIN
    DECLARE valid_id INTEGER;

    IF p_balance >= 0 THEN
      IF type = 'C' OR type = 'S' THEN
        SET valid_id = (SELECT COUNT(*)
                        FROM p2.customer
                        WHERE id = p_id);

        IF valid_id = 1 THEN
          SET sql_code = 0;

          INSERT INTO p2.account(id, balance, type, status) VALUES (p_id, p_balance, type, 'A');

          SET number = (SELECT SYSIBM.IDENTITY_VAL_LOCAL() FROM p2.account LIMIT 1);
        ELSE
          SET sql_code = -100;
          SET err_msg = 'Invalid customer id';
        END IF;
      ELSE
        SET sql_code = -100;
        SET err_msg = 'Invalid account type';
      END IF;
    ELSE
      SET sql_code = -100;
      SET err_msg = 'Invalid balance';
    END IF;
END@

CREATE PROCEDURE P2.ACCT_CLS
(IN p_number INTEGER, OUT sql_code INTEGER, OUT err_msg CHAR(100))
LANGUAGE SQL
  BEGIN
    DECLARE valid_account_num INTEGER;

    SET valid_account_num = (SELECT COUNT(*) FROM p2.account WHERE number = p_number);

    IF valid_account_num = 1 THEN
      SET sql_code = 0;

      UPDATE p2.account
      SET status = 'I', balance = 0
      WHERE number = p_number;
    ELSE
      SET sql_code = -100;
      SET err_msg = 'Invalid account number';
    END IF;
END@

CREATE PROCEDURE P2.ACCT_DEP
(IN p_number INTEGER, IN amount INTEGER, OUT sql_code INTEGER, OUT err_msg CHAR(100))
LANGUAGE SQL
  BEGIN ATOMIC
    DECLARE valid_account_num INTEGER;

    IF amount >= 0 THEN
      SET valid_account_num = (SELECT COUNT(*)
                               FROM p2.account
                               WHERE number = p_number AND status = 'A');

      IF valid_account_num = 1 THEN
        SET sql_code = 0;

        UPDATE p2.account
        SET balance = balance + amount
        WHERE number = p_number;
      ELSE
        SET sql_code = -100;
        SET err_msg = 'Invalid account number';
      END IF;
    ELSE
      SET sql_code = -100;
      SET err_msg = 'Invalid amount';
    END IF;
END@

CREATE PROCEDURE P2.ACCT_WTH
(IN p_number INTEGER, IN amount INTEGER, OUT sql_code INTEGER, OUT err_msg CHAR(100))
LANGUAGE SQL
  BEGIN ATOMIC
    DECLARE valid_account_num INTEGER;
    DECLARE available_bal INTEGER;

    IF amount >= 0 THEN
      SET valid_account_num = (SELECT COUNT(*)
                               FROM p2.account
                               WHERE number = p_number AND status = 'A');

      IF valid_account_num = 1 THEN
        SET available_bal = (SELECT balance
                             FROM p2.account
                             WHERE number = p_number);

        IF (available_bal - amount) >= 0 THEN
          SET sql_code = 0;

          UPDATE p2.account
          SET balance = balance - amount
          WHERE number = p_number;
        ELSE
          SET sql_code = -100;
          SET err_msg = 'Not enough funds';
        END IF;
      ELSE
        SET sql_code = -100;
        SET err_msg = 'Invalid account number';
      END IF;
    ELSE
      SET sql_code = -100;
      SET err_msg = 'Invalid amount';
    END IF;
END@

CREATE PROCEDURE P2.ACCT_TRX
(IN source_account INTEGER, IN destination_account INTEGER, IN amount INTEGER, OUT sql_code INTEGER, OUT err_msg CHAR(100))
LANGUAGE SQL
  BEGIN ATOMIC
    CALL p2.ACCT_WTH(source_account, amount, sql_code, err_msg);

    IF sql_code = 0 THEN
      CALL p2.ACCT_DEP(destination_account, amount, sql_code, err_msg);

      IF sql_code != 0 THEN
        CALL p2.ACCT_DEP(source_account, amount, sql_code, err_msg);
        SET sql_code = -100;
        SET err_msg = 'Invalid destination account number';
      END IF;
    END IF;
END@

CREATE PROCEDURE P2.ADD_INTEREST
(IN savings_rate DECIMAL(5,2), IN checking_rate DECIMAL(5,2), OUT sql_code INTEGER, OUT err_msg CHAR(100))
LANGUAGE SQL
  BEGIN ATOMIC

    UPDATE p2.account
    SET balance = balance * (1 + savings_rate)
    WHERE status = 'A' AND type = 'S' AND balance > 0;

    UPDATE p2.account
    SET balance = balance * (1 + checking_rate)
    WHERE status = 'A' AND type = 'C' AND balance > 0;
END@

TERMINATE@

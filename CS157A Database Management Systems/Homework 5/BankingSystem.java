import javax.xml.catalog.Catalog;
import java.io.FileInputStream;
import java.sql.*;
import java.util.HashSet;
import java.util.Properties;

/**
 * Manage connection to database and perform SQL statements.
 */
public class BankingSystem {
	// Connection properties
	private static String driver;
	private static String url;
	private static String username;
	private static String password;
	
	// JDBC Objects
	private static Connection con;
	private static Statement stmt;
	private static ResultSet rs;
	private static String query;

	/**
	 * Initialize database connection given properties file.
	 * @param filename name of properties file
	 */
	public static void init(String filename) {
		try {
			Properties props = new Properties();						// Create a new Properties object
			FileInputStream input = new FileInputStream(filename);	// Create a new FileInputStream object using our filename parameter
			props.load(input);										// Load the file contents into the Properties object
			driver = props.getProperty("jdbc.driver");				// Load the driver
			url = props.getProperty("jdbc.url");						// Load the url
			username = props.getProperty("jdbc.username");			// Load the username
			password = props.getProperty("jdbc.password");			// Load the password
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * Test database connection.
	 */
	public static void testConnection() {
		System.out.println(":: TEST - CONNECTING TO DATABASE");
		try {
			Class.forName(driver);
			con = DriverManager.getConnection(url, username, password);
			con.close();
			System.out.println(":: TEST - SUCCESSFULLY CONNECTED TO DATABASE");
		} catch (Exception e) {
			System.out.println(":: TEST - FAILED CONNECTED TO DATABASE");
			e.printStackTrace();
		}
	}

	/**
	 * Create a new customer.
	 * @param name customer name
	 * @param gender customer gender
	 * @param age customer age
	 * @param pin customer pin
	 */
	public static Integer newCustomer(String name, String gender, String age, String pin)
	{
		System.out.println(":: CREATE NEW CUSTOMER - RUNNING");
				/* insert your code here */

		if(name == null || name.isEmpty()) {
			System.out.println(":: CREATE NEW CUSTOMER - ERROR - NO NAME WAS PROVIDED");
			return null;
		}
		if(!validPin(pin)) {
			System.out.println(":: CREATE NEW CUSTOMER - ERROR - INVALID PIN");
			return null;
		}
		if(gender.length() != 1 || (gender.charAt(0) != 'M' && gender.charAt(0) != 'F')) {
			System.out.println(":: CREATE NEW CUSTOMER - ERROR - INVALID GENDER");
			return null;
		}

		try {
			int intAge = Integer.parseInt(age);
			if(intAge < 0)
				throw new Exception();
		} catch(Exception e) {
			System.out.println(":: CREATE NEW CUSTOMER - ERROR - INVALID AGE");
			return null;
		}

		try {
			openConnection();
			stmt = con.createStatement();
			query = "INSERT INTO p1.customer(name, gender, age, pin) " +
					"VALUES('" + name + "','" + gender + "'," + age + "," + pin + ")";
			stmt.executeUpdate(query);

			query = "SELECT SYSIBM.IDENTITY_VAL_LOCAL() FROM p1.customer LIMIT 1";
			rs = stmt.executeQuery(query);

			System.out.println(":: CREATE NEW CUSTOMER - SUCCESS");
			if(rs.next())
				return rs.getInt(1);

		} catch (SQLException e) {
			System.out.println(e);
			closeConnection();
		} finally {
			closeConnection();
		}
		return null;
	}

	/**
	 * Open a new account.
	 * @param id customer id
	 * @param type type of account
	 * @param amount initial deposit amount
	 */
	public static Integer openAccount(String id, String type, String amount)
	{
		System.out.println(":: OPEN ACCOUNT - RUNNING");
				/* insert your code here */
		if(!validId(id)) {
			System.out.println(":: OPEN ACCOUNT - ERROR - INVALID ID");
			return null;
		}
		if(!validAmount(amount)) {
			System.out.println(":: OPEN ACCOUNT - ERROR - INVALID AMOUNT");
			return null;
		}
		if(!type.equals("C") && !type.equals("S")) {
			System.out.println(":: OPEN ACCOUNT - ERROR - INVALID ACCOUNT TYPE");
			return null;
		}

		try {
			openConnection();
			stmt = con.createStatement();
			query = "SELECT id FROM p1.customer WHERE id = "+id;
			rs = stmt.executeQuery(query);

			if(!rs.next()) {
				System.out.println(":: OPEN ACCOUNT - ERROR - NO CUSTOMER WITH GIVEN ID");
				return null;
			}

			query = "INSERT INTO p1.account(id, balance, type, status) " +
					"VALUES("+id+","+amount+",'"+type+"', 'A')";
			int i = stmt.executeUpdate(query);

			if(i == 1) {
				query = "SELECT SYSIBM.IDENTITY_VAL_LOCAL() FROM p1.account LIMIT 1";
				rs = stmt.executeQuery(query);

				System.out.println(":: OPEN ACCOUNT - SUCCESS");
				if(rs.next())
					return rs.getInt(1);
			}
			else {
				return null;
			}

		} catch (SQLException e) {
			System.out.println(e);
		} finally {
			closeConnection();
		}
		return null;
	}

	/**
	 * Close an account.
	 * @param accNum account number
	 */
	public static boolean closeAccount(String accNum)
	{
		System.out.println(":: CLOSE ACCOUNT - RUNNING");
				/* insert your code here */
		if(!validAccNumber(accNum)) {
			System.out.println(":: CLOSE ACCOUNT - ERROR - INVALID ACCOUNT NUMBER");
			return false;
		}

		try {
			openConnection();
			stmt = con.createStatement();
			query = "UPDATE p1.account SET status = 'I', balance = 0 WHERE number = "+accNum;
			int rows = stmt.executeUpdate(query);

			if(rows == 0) {
				throw new InvalidAccountNumberException();
			}
			else {
				System.out.println(":: CLOSE ACCOUNT - SUCCESS");
				return true;
			}
		}catch (SQLException e) {
			System.out.println(e);
		} catch (InvalidAccountNumberException e) {
			System.out.println(":: CLOSE ACCOUNT - ERROR - INVALID ACCOUNT NUMBER");
		} finally {
			closeConnection();
		}
		return false;
	}

	/**
	 * Deposit into an account.
	 * @param accNum account number
	 * @param amount deposit amount
	 */
	public static boolean deposit(String accNum, String amount)
	{
		System.out.println(":: DEPOSIT - RUNNING");
				/* insert your code here */
		if(!validAccNumber(accNum)) {
			System.out.println(":: DEPOSIT - ERROR - INVALID ACCOUNT NUMBER");
			return false;
		}
		if(!validAmount(amount)) {
			System.out.println(":: DEPOSIT - ERROR - INVALID AMOUNT");
			return false;
		}

		try {
			openConnection();
			stmt = con.createStatement();
			query = "UPDATE p1.account SET balance = balance + "+amount+" WHERE number = "+accNum+" AND status = 'A'";
			int rows = stmt.executeUpdate(query);

			if(rows == 0) {
				throw new InvalidAccountNumberException();
			}
			else {
				System.out.println(":: DEPOSIT - SUCCESS");
				return true;
			}
		} catch (SQLException e) {
			System.out.println(e);
		} catch (InvalidAccountNumberException e) {
			System.out.println(":: DEPOSIT - ERROR - INVALID ACCOUNT NUMBER");
		} finally {
			closeConnection();
		}
		return false;
	}

	/**
	 * Withdraw from an account.
	 * @param accNum account number
	 * @param amount withdraw amount
	 */
	public static boolean withdraw(String accNum, String amount)
	{
		System.out.println(":: WITHDRAW - RUNNING");
				/* insert your code here */
		if(!validAccNumber(accNum)) {
			System.out.println(":: WITHDRAW - ERROR - INVALID ACCOUNT NUMBER");
			return false;
		}
		if(!validAmount(amount)) {
			System.out.println(":: WITHDRAW - ERROR - INVALID AMOUNT");
			return false;
		}
		try {
			openConnection();
			stmt = con.createStatement();
			query = "SELECT balance FROM p1.account WHERE number = "+accNum+" AND status = 'A'";

			rs = stmt.executeQuery(query);

			if(rs.next()) {
				int balance = rs.getInt(1);
				int new_balance = balance - Integer.parseInt(amount);

				if (new_balance >= 0) {
					query = "UPDATE p1.account SET balance = "+new_balance+" WHERE number = "+accNum;
					stmt.executeUpdate(query);
					System.out.println(":: WITHDRAW - SUCCESS");
					return true;
				}
				else {
					throw new InsufficientFundsException();
				}
			}
			else {
				throw new InvalidAccountNumberException();
			}
		} catch (SQLException e) {
			System.out.println(e);
		} catch (InvalidAccountNumberException e) {
			System.out.println(":: WITHDRAW - ERROR - INVALID ACCOUNT NUMBER");
		} catch (InsufficientFundsException e) {
			System.out.println(":: WITHDRAW - ERROR - NOT ENOUGH FUNDS");
		} finally {
			closeConnection();
		}
		return false;
	}

	/**
	 * Transfer amount from source account to destination account. 
	 * @param srcAccNum source account number
	 * @param destAccNum destination account number
	 * @param amount transfer amount
	 */
	public static boolean transfer(String srcAccNum, String destAccNum, String amount)
	{
		System.out.println(":: TRANSFER - RUNNING");
				/* insert your code here */
		if(!validAmount(srcAccNum) || !validAmount(destAccNum)) {
			System.out.println(":: TRANSFER - ERROR - INVALID ACCOUNT NUMBER");
			return false;
		}
		if(!validAmount(amount)) {
			System.out.println(":: TRANSFER - ERROR - INVALID AMOUNT");
			return false;
		}

		try {
			openConnection();
			stmt = con.createStatement();
			query = "SELECT number FROM p1.account WHERE number = "+srcAccNum;

			rs = stmt.executeQuery(query);

			if(!rs.next())
				throw new InvalidAccountNumberException();

			query = "SELECT number FROM p1.account WHERE number = "+destAccNum;
			rs = stmt.executeQuery(query);

			if(!rs.next())
				throw new InvalidAccountNumberException();

			query = "SELECT balance FROM p1.account WHERE number = "+srcAccNum;
			rs = stmt.executeQuery(query);

			if(rs.next()) {
				int srcBalance = rs.getInt(1);
				int newSrcBalance = srcBalance - Integer.parseInt(amount);

				if(newSrcBalance >= 0) {
					query = "UPDATE p1.account SET balance = "+newSrcBalance+" WHERE number = "+srcAccNum;
					stmt.executeUpdate(query);

					query = "UPDATE p1.account SET balance = balance + "+amount+" WHERE number = "+destAccNum;
					stmt.executeUpdate(query);

					System.out.println(":: TRANSFER - SUCCESS");
					return true;
				}
				else {
					throw new InsufficientFundsException();
				}
			}

		} catch (SQLException e) {
			System.out.println(e);
		} catch (InvalidAccountNumberException e) {
			System.out.println(":: TRANSFER - ERROR - INVALID ACCOUNT NUMBER");
		} catch (InsufficientFundsException e) {
			System.out.println(":: TRANSFER - ERROR - NOT ENOUGH FUNDS");
		} finally {
			closeConnection();
		}
		return false;
	}

	/**
	 * Display account summary.
	 * @param cusID customer ID
	 */
	public static void accountSummary(String cusID) 
	{
		System.out.println(":: ACCOUNT SUMMARY - RUNNING");
				/* insert your code here */
		if(!validId(cusID)) {
			System.out.println(":: ACCOUNT SUMMARY - ERROR - INVALID ID");
			return;
		}

		try {
			openConnection();
			stmt = con.createStatement();
			query = "SELECT number, balance FROM p1.customer c INNER JOIN p1.account a ON c.id = a.id WHERE c.id = "+cusID+" AND status != 'I'";

			rs = stmt.executeQuery(query);
			int total = 0;

			System.out.format("%-12s", "NUMBER");
			System.out.format("%-11s", "BALANCE");
			System.out.println("\n----------- -----------");

			while(rs.next()) {
				String accountNumber = rs.getString(1);
				String balance = rs.getString(2);
				total += Integer.parseInt(balance);

				System.out.format("%11s", accountNumber);
				System.out.format("%12s", balance);
				System.out.println();
			}
			System.out.println("-----------------------");
			System.out.format("%-12s", "TOTAL");
			System.out.format("%11s", total);
			System.out.println("\n:: ACCOUNT SUMMARY - SUCCESS");
		} catch(SQLException e) {
			System.out.println(e);
		} finally {
			closeConnection();
		}

	}

	/**
	 * Display Report A - Customer Information with Total Balance in Decreasing Order.
	 */
	public static void reportA() 
	{
		System.out.println(":: REPORT A - RUNNING");
				/* insert your code here */
		try {
			openConnection();
			stmt = con.createStatement();
			query = "SELECT c.id, NAME, GENDER, AGE, total  " +
					"FROM p1.customer c " +
					"LEFT JOIN (SELECT id, SUM(balance) as total FROM p1.account WHERE status != 'I' GROUP BY id) a " +
					"ON c.id = a.id " +
					"ORDER BY ISNULL(total, 0) DESC";
			rs = stmt.executeQuery(query);

			printHeader();
			while(rs.next()) {
				printRow(rs.getString(1), rs.getString(2), rs.getString(3),
						rs.getString(4), rs.getString(5));
			}
			System.out.println(":: REPORT A - SUCCESS");
		} catch(SQLException e) {
			System.out.println(e);
		} finally {
			closeConnection();
		}
	}

	/**
	 * Display Report B - Customer Information with Total Balance in Decreasing Order.
	 * @param min minimum age
	 * @param max maximum age
	 */
	public static void reportB(String min, String max) 
	{
		System.out.println(":: REPORT B - RUNNING");
				/* insert your code here */
		try {
			int intMin = Integer.parseInt(min);
			int intMax = Integer.parseInt(max);

			if(intMin < 0 || (intMin > intMax))
				throw new Exception();
		}catch (Exception e) {
			System.out.println(":: REPORT B - ERROR - INVALID MIN OR MAX");
			return;
		}

		try {
			openConnection();
			stmt = con.createStatement();
			query = "SELECT AVG(total)  " +
					"FROM p1.customer c " +
					"INNER JOIN (SELECT id, SUM(balance) as total FROM p1.account WHERE status != 'I' GROUP BY id) a " +
					"ON c.id = a.id " +
					"WHERE age BETWEEN "+min+" AND "+max;
			rs = stmt.executeQuery(query);

			System.out.format("%-11s", "AVERAGE");
			System.out.println("\n-----------");

			while(rs.next()) {
				System.out.format("%12s", rs.getString(1)+"\n");
			}
			System.out.println(":: REPORT B - SUCCESS");
		} catch(SQLException e) {
			System.out.println(e);
		} finally {
			closeConnection();
		}
	}

	/**
	 * Login to a customer account.
	 * @param id customer id
	 * @param pin customer pin
	 * @return HashSet<String> A set of a customer's accounts
	 */
	public static HashSet<String> login(String id, String pin) {
		if(!validId(id) || !validPin(pin)) {
			return null;
		}

		try {
			openConnection();
			stmt = con.createStatement();
			query = "SELECT * FROM p1.customer WHERE id = "+id+" AND pin = "+pin;
			rs = stmt.executeQuery(query);

			if(rs.next()) {
				HashSet<String> accounts = new HashSet<>();
				query = "SELECT number FROM p1.account WHERE id = "+id+" AND status = 'A'";
				rs = stmt.executeQuery(query);

				while(rs.next()) {
					accounts.add(rs.getString(1));
				}
				return accounts;
			}
			else
				return null;
		} catch (SQLException e) {
			System.out.println(e);
		} finally {
			closeConnection();
		}
		return null;
	}

	/**
	 * Validates an account number.
	 * @param accNumber customer account number
	 * @return boolean value true if valid, false if invalid
	 */
	public static boolean validAccNumber(String accNumber) {
		try {
			int intAccNumber = Integer.parseInt(accNumber);
			if (intAccNumber < 0)
				return false;
		} catch (NumberFormatException e) {
			return false;
		}

		return true;
	}

	/**
	 * Validates an monetary amount.
	 * @param amount monetary amount with no cents
	 * @return boolean value true if valid, false if invalid
	 */
	public static boolean validAmount(String amount) {
		try {
			int intAmount = Integer.parseInt(amount);
			if (intAmount < 0)
				return false;
		} catch (NumberFormatException e) {
			return false;
		}

		return true;
	}

	/**
	 * Validates a customer id.
	 * @param id customer id
	 * @return boolean value true if valid, false if invalid
	 */
	public static boolean validId(String id) {
		try {
			int intId = Integer.parseInt(id);
			if (intId < 0)
				return false;
		} catch (NumberFormatException e) {
			return false;
		}

		return true;
	}

	/**
	 * Validates a customer pin.
	 * @param pin customer pin number
	 * @return boolean value true if valid, false if invalid
	 */
	public static boolean validPin(String pin) {
		try {
			int intPin = Integer.parseInt(pin);
			if (intPin < 0)
				throw new Exception();
		} catch (Exception e) {
			return false;
		}
		return true;
	}

	/**
	 * Opens a connection to the database.
	 */
	public static void openConnection() {
		try {
			Class.forName(driver);
			con = DriverManager.getConnection(url, username, password);
		} catch (Exception e) {
			System.out.println(":: OPEN CONNECTION - FAILED CONNECTED TO DATABASE");
			e.printStackTrace();
		}
	}

	/**
	 * Closes the connection to the database.
	 */
	public static void closeConnection() {
		try {
			con.close();
		} catch (Exception e) {
			System.out.println(":: CLOSE CONNECTION - FAILED CLOSE CONNECTION");
			e.printStackTrace();
		}
	}

	/**
	 * Prints a header to console for reportA().
	 */
	private static void printHeader() {
		System.out.format("%-12s", "ID");
		System.out.format("%-16s", "NAME");
		System.out.format("%-7s", "GENDER");
		System.out.format("%-12s", "AGE");
		System.out.format("%-12s", "TOTAL");
		System.out.println("\n----------- --------------- ------ ----------- -----------");
	}

	/**
	 * Prints a single record to console for reportA().
	 */
	private static void printRow(String id, String name, String gender, String age, String total) {
		System.out.format("%12s", id+" ");
		System.out.format("%-16s", name+" ");
		System.out.format("%-7s", gender+" ");
		System.out.format("%11s", age);

		total = total == null ? "0" : total;

		System.out.format("%12s", total);
		System.out.println();
	}

	static class InsufficientFundsException extends Exception {
		public InsufficientFundsException() {
			super();
		}
	}

	static class InvalidAccountNumberException extends Exception {
		public InvalidAccountNumberException() {
			super();
		}
	}

}

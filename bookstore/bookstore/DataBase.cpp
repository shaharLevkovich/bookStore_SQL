#include "Database.h"

Database *Database::instance = 0;

Database::Database() : driver(get_driver_instance()) {
	connection_properties["hostName"] = DB_HOST;
	connection_properties["port"] = DB_PORT;
	connection_properties["userName"] = DB_USER;
	connection_properties["password"] = DB_PASS;
	connection_properties["OPT_RECONNECT"] = true;

	// use database
	try {
		Connection *con = driver->connect(connection_properties);
		try {
			con->setSchema("bookstore");
		}
		catch (SQLException &e) {
			Statement *stmt = con->createStatement();
			stmt->execute(
				"CREATE DATABASE IF NOT EXISTS bookstore");
			con->setSchema("bookstore"); // switch database
			stmt->execute("CREATE TABLE IF NOT EXISTS book("
				"authorName varchar(20) not null,"
				"bookName varchar(20) not null,"
				"bookPrice float,"
				"amount int unsigned,"
				"PRIMARY KEY(bookName)"
			")");
			stmt->execute("CREATE TABLE IF NOT EXISTS customer("
				"customerName varchar(20) not null,"
				"customerNumber int unsigned,"
				"cellphone int unsigned,"
				"totalPurchase float,"
				"PRIMARY KEY(customerNumber)"
			")");
			stmt->execute("CREATE TABLE IF NOT EXISTS supplier("
				"supplierName varchar(20) not null,"
				"supplierrNumber int unsigned,"
				"PRIMARY KEY(supplierrNumber)"
			")");
			stmt->execute("CREATE TABLE IF NOT EXISTS seller("
				"sellerNumber int unsigned,"
				"sellerName varchar(20) not null,"
				"PRIMARY KEY(sellerNumber)"
			")");

			stmt->execute("CREATE TABLE IF NOT EXISTS transaction("
				"transNumber int unsigned auto_increment,"
				"transDate date,"
				"totalPrice float,"
				"PRIMARY KEY(transNumber)"
			")");
			stmt->execute("CREATE TABLE IF NOT EXISTS orderBook("
				"dateOrder date,"
				"orderNumber int unsigned,"
				"statusOrder int unsigned,"
				"PRIMARY KEY(orderNumber)"
			")");
			stmt->execute("CREATE TABLE globalDiscount("
				"startDate date,"
				"endDate date,"
				"discountPrice float,"
				"discountNumber int unsigned,"
				"discountName varchar(20) not null,"
				"bookName varchar(20) not null,"
				"primary key(discountNumber)"
				"foreign key(bookName) references book(bookName)"
			")");
			stmt->execute("CREATE TABLE IF NOT EXISTS personalDiscount("
				"discountNumber int unsigned,"
				"startDate date,"
				"endDate date,"
				"discountPrice int unsigned,"
				"PRIMARY KEY(discountNumber),"
				"FOREIGN KEY(customerNumber) REFERENCES customer(customerNumber)"
			")");
			stmt->execute("CREATE TABLE supply ("
				"supplierPrice int unsigned,"
				"supplierNumber int unsigned,"
				"bookName varchar(20) NOT NULL,"
				"PRIMARY KEY(bookName),"
				"FOREIGN KEY(supplierNumber) REFERENCES supplier(supplierNumber),"
				"FOREIGN KEY(bookName) REFERENCES book(bookName)"
			")");
			stmt->execute("CREATE TABLE place_an ("
				"orderNumber int(10) unsigned,"
				"customerNumber int(10) unsigned,"
				"bookName varchar(20) NOT NULL,"
				"PRIMARY KEY(orderNumber),"
				"FOREIGN KEY(orderNumber) REFERENCES orderbook(`orderNumber),"
				"FOREIGN KEY(customerNumber) REFERENCES customer(customerNumber),"
				"FOREIGN KEY(bookName) REFERENCES book(bookName)"
			")");
			stmt->execute("CREATE TABLE IF NOT EXISTS make_an("
				"totalPrice float,"
				"transNumber int unsigned auto_increment,"
				"customerNumber int unsigned,"
				"sellerNumber int unsigned,"
				"bookName varchar(20) not null,"
				"PRIMARY KEY(transNumber),"
				"foreign key(transNumber) references transaction(transNumber),"
				"foreign key(sellerNumber) references seller(sellerNumber),"
				"foreign key(customerNumber) references customer(customerNumber),"
				"foreign key(bookName) references book(bookName)"
			")");

			delete stmt;
		}

		delete con;
	}
	catch (SQLException &e) {
		cout << e.getErrorCode() << " " << e.what() << " " << e.getSQLState();
	}
}

Database & Database::getInstance() {
	if (Database::instance == 0) {
		instance = new Database();
	}
	return *instance;
}

Connection * Database::getConnection() {
	try {
		Connection *con = driver->connect(connection_properties);
		con->setSchema(DB_NAME);
		return con;
	}
	catch (SQLException &e) {
		cout << e.what();
	}
	return 0;
}
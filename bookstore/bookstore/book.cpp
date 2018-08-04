#include "book.h"

void printAllBooks() {
	int n = 0;
	int i = 1;
	int j = 0;

	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM book LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		/* Fetch in reverse = descending order! */
		if (!res->next() && n>0)                            //if there is no next
		{
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM book LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout <<  "Book name: " << res->getString("bookName") << endl << "Book author: " << res->getString("authorName") 
				<< endl << "Book price: " << res->getString("bookPrice") << endl << "Amount: " 
				<< res->getString("amount") << endl << endl;           
			i++;
			j++;
		}

		cout << endl << endl << "1.Next books" << endl << "2.Previous books" << endl << "3.Return to main menu" << endl;
		int choose;
		cout << "Your choice:";
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

void printCustomers() {
	int n = 0, i = 1, j = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM customer LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		if (!res->next() && n > 0)                            //if there is no next
		{
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM customer LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "Customer name: " << res->getString("customerName") << endl << "Customer number: " << res->getString("customerNumber")
				<< endl << "Cellphone: " << res->getString("cellphone") << endl << "Total purchase: " << res->getString("totalPurchase") << endl<< endl;
			i++;
			j++;
		}
		cout << endl << endl << "1.Next books" << endl << "2.Previous books" << endl << "3.Return to main menu" << endl;
		int choose;
		cout << "Your choice:";
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}
void openOrders() {
	int n = 0, i = 1, j = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM orderBook where statusOrder<5 LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		if (!res->next() && n > 0)                            //if there is no next
		{
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM orderBook where statusOrder<5 LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "Order number: " << res->getString("orderNumber") << endl << "status: " << res->getString("statusOrder")
				<< endl << "Date order: " << res->getString("dateOrder") << endl << endl;
			i++;
			j++;
		}
		cout << endl << endl << "1.Next books" << endl << "2.Previous books" << endl << "3.Return to main menu" << endl;
		int choose;
		cout << "Your choice:";
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

void printSupplier() {
	int n = 0, i = 1, j = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM supplier LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		if (!res->next() && n > 0)                            //if there is no next
		{
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM supplier LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "Supplier name: " << res->getString("supplierName") << endl << "Supplier number: " << res->getString("supplierNumber") << endl << endl;
			i++;
			j++;
		}
		cout << endl << endl << "1.Next books" << endl << "2.Previous books" << endl << "3.Return to main menu" << endl;
		int choose;
		cout << "Your choice:";
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

void transactionByDate(string startDate, string endDate) {
	int n = 0, i = 1, j = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("select * from transaction where transDate between ? and ? LIMIT 5 OFFSET ?");
		pstmt->setString(1, startDate);
		pstmt->setString(2, endDate);
		pstmt->setInt(3, n);
		ResultSet *res = pstmt->executeQuery();
		if (!res->next() && n > 0)                            //if there is no next
		{
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("select * from transaction where transDate between ? and ? LIMIT 5 OFFSET ?");
			pstmt->setString(1, startDate);
			pstmt->setString(2, endDate);
			pstmt->setInt(3, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{		
			cout << "Transaction number: "<< res->getString("transNumber") <<"Transaction Date: " << res->getString("transDate") << endl << endl;
			i++;
			j++;
		}
		cout << endl << endl << "1.Next books" << endl << "2.Previous books" << endl << "3.Return to main menu" << endl;
		int choose;
		cout << "Your choice:";
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

void globalDiscount() {
	int n = 0, i = 1, j = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("select * from globalDiscount LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		if (!res->next() && n > 0)                            //if there is no next
		{
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("select * from globalDiscount LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "Book name: " << res->getString("bookName")<<endl << "Discount name: " << res->getString("discountName")<<endl<<"Discount price: "<< res->getString("discountPrice") <<"%"<< endl << endl;
			i++;
			j++;
		}
		cout << endl << endl << "1.Next books" << endl << "2.Previous books" << endl << "3.Return to main menu" << endl;
		int choose;
		cout << "Your choice:";
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

void isAvailable() {
	int flag=0, choice;
	string bookName, bookAuthor;
	PreparedStatement *pstmt;
	ResultSet *res;
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		cout << "Check availbility \n1.By book name\n2.By author\n3.Both\nYour choice: ";
		cin >> choice;
		switch (choice) {
		case 1: 
			cout << "Enter book name: ";
			getchar();
			getline(cin, bookName);
			pstmt = con->prepareStatement("select * from book where bookName=? and amount>0 LIMIT 5 OFFSET ?");
			pstmt->setString(1, bookName);
			res = pstmt->executeQuery();
			res->beforeFirst();
			while (res->next())
			{
				cout << "\n\nBook name: " << res->getString("bookName") << endl << "Amount: " << res->getString("amount") << endl << endl;
				flag=1;
			}
			if (flag == 0)
			{
				cout << "The book is not available" << endl;
			}
			delete res;
			delete con;
			delete pstmt;
			return;
		case 2:
			cout << "Enter book author: ";
			getchar();
			getline(cin, bookAuthor);
			pstmt = con->prepareStatement("select * from book where authorName=? and amount>0 LIMIT 5 OFFSET ?");
			pstmt->setString(1, bookAuthor);
			res = pstmt->executeQuery();
			res->beforeFirst();
			while (res->next())
			{
				cout << "\n\nBook name: " << res->getString("bookName") << endl << "Book author: " << res->getString("authorName") << endl << "Amount: " << res->getString("amount") << endl << endl;
				flag=1;
			}
			if (flag == 0)
			{
				cout << "The book is not available" << endl;
			}
			delete res;
			delete con;
			delete pstmt;
			return;
		case 3:
			cout << "Enter book name: ";
			getchar();
			getline(cin, bookName);
			cout << "Enter book author: ";
			getline(cin, bookAuthor);
			pstmt = con->prepareStatement("select * from book where bookName=? and authorName=? and amount>0");
			pstmt->setString(1, bookName);
			pstmt->setString(2, bookAuthor);
			res = pstmt->executeQuery();
			res->beforeFirst();
			while (res->next())
			{
				cout << "\n\nBook name: " << res->getString("bookName") << endl << "Book author: " << res->getString("authorName") << endl << "Amount: " << res->getString("amount") << endl << endl;
				flag=1;
			}
			if (flag == 0)
			{
				cout << "The book is not available" << endl;
			}
			delete res;
			delete con;
			delete pstmt;
			return;
		}
}


void isSupplier() {
	int flag = 0, choice;
	string bookName, bookAuthor;
	PreparedStatement *pstmt;
	ResultSet *res;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Check supplier \n1.By book name\n2.By author\n3.Both\nYour choice: ";
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Enter book name: ";
		getchar();
		getline(cin, bookName);
		pstmt = con->prepareStatement("select supply.*, book.authorName, supplier.supplierName from supply inner join book on book.bookName = supply.bookName inner join supplier on supplier.supplierNumber=supply.supplierNumber where book.bookName=?");
		pstmt->setString(1, bookName);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			cout << "\n\nBook name: " << res->getString("bookName") << endl << "Supplier name: " << res->getString("supplierName") << endl << endl;
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "The book is not available" << endl;
		}
		delete res;
		delete con;
		delete pstmt;
		return;
	case 2:
		cout << "Enter book author: ";
		getchar();
		getline(cin, bookAuthor);
		pstmt = con->prepareStatement("select supply.*, book.authorName, supplier.supplierName from supply inner join book on book.bookName = supply.bookName inner join supplier on supplier.supplierNumber = supply.supplierNumber where book.authorName = ? ");
		pstmt->setString(1, bookAuthor);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			cout << "\n\nBook name: " << res->getString("bookName") << endl << "Book author: " << res->getString("authorName") << endl << "Supplier name: " << res->getString("supplierName") << endl << endl;
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "The book is not available" << endl;
		}
		delete res;
		delete con;
		delete pstmt;
		return;
	case 3:
		cout << "Enter book name: ";
		getchar();
		getline(cin, bookName);
		cout << "Enter book author: ";
		getline(cin, bookAuthor);
		pstmt = con->prepareStatement("select supply.*, book.authorName, supplier.supplierName from supply inner join book on book.bookName = supply.bookName inner join supplier on supplier.supplierNumber=supply.supplierNumber where book.bookName=? and book.authorName=?");
		pstmt->setString(1, bookName);
		pstmt->setString(2, bookAuthor);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			cout << "\n\nBook name: " << res->getString("bookName") << endl << "Book author: " << res->getString("authorName") << endl << "Supplier name: " << res->getString("supplierName") << endl << endl;
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "The book is not available" << endl;
		}
		delete res;
		delete con;
		delete pstmt;
		return;
	}
}

void HowManySold() {
	int flag = 0, choice, count=0;
	string bookName, bookAuthor, saleDate;
	PreparedStatement *pstmt;
	ResultSet *res;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Check quantity \n1.By book name\n2.By author\n3.Both\nYour choice: ";
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Enter book name: ";
		getchar();
		getline(cin, bookName);
		cout << "Enter date (YYYY-MM-DD): ";
		cin >> saleDate;
		pstmt = con->prepareStatement("select transaction.transDate, make_an.bookName, book.authorName from transaction inner join make_an on transaction.transNumber = make_an.transNumber inner join book on make_an.bookName = book.bookName where book.bookName=? and transDate > ?");
		pstmt->setString(1, bookName);
		pstmt->setString(2, saleDate);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			flag = 1;
			count++;
		}
		cout << "Quantity purchased: " << count << endl << endl;
		if (flag == 0)
		{
			cout << "The book was not purchased" << endl;
		}
		delete res;
		delete con;
		delete pstmt;
		return;
	case 2:
		cout << "Enter book author: ";
		getchar();
		getline(cin, bookAuthor);
		cout << "Enter date (YYYY-MM-DD): ";
		cin >> saleDate;
		pstmt = con->prepareStatement("select transaction.transDate, make_an.bookName, book.authorName from transaction inner join make_an on transaction.transNumber = make_an.transNumber inner join book on make_an.bookName = book.bookName where book.authorName = ? and transDate > ?");
		pstmt->setString(1, bookAuthor);
		pstmt->setString(2, saleDate);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			flag = 1;
			count++;
		}
		if (flag == 0)
		{
			cout << "The book was not purchased" << endl;
		}
		cout << "Quantity purchased: " << count << endl << endl;
		delete res;
		delete con;
		delete pstmt;
		return;
	case 3:
		cout << "Enter book name: ";
		getchar();
		getline(cin, bookName);
		cout << "Enter book author: ";
		getline(cin, bookAuthor);
		cout << "Enter date (YYYY-MM-DD): ";
		cin >> saleDate;
		pstmt = con->prepareStatement("select transaction.transDate, make_an.bookName, book.authorName from transaction inner join make_an on transaction.transNumber = make_an.transNumber inner join book on make_an.bookName = book.bookName where book.bookName=? and book.authorName=? and transDate > ?");
		pstmt->setString(1, bookName);
		pstmt->setString(2, bookAuthor);
		pstmt->setString(3, saleDate);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			flag = 1;
			count++;
		}
		cout << "Quantity purchased: " << count << endl << endl;
		if (flag == 0)
		{
			cout << "The book is not available" << endl;
		}
		delete res;
		delete con;
		delete pstmt;
		return;
	}
}

void clientBuy() {
	int flag = 0, choice, count = 0;
	string customerName,customerNumber,cellphone, saleDate;
	PreparedStatement *pstmt;
	ResultSet *res;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Check quantity \n1.By customer name\n2.By customer number\n3.customer cellphone\n4.All the above\nYour choice: ";
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Enter customer name: ";
		getchar();
		getline(cin, customerName);
		cout << "Enter date (YYYY-MM-DD): ";
		cin >> saleDate;
		pstmt = con->prepareStatement("select transaction.transDate, make_an.bookName, customer.customerName, make_an.customerNumber, customer.cellphone from transaction inner join make_an on transaction.transNumber = make_an.transNumber inner join customer on make_an.customerNumber = customer.customerNumber where customer.customerName=? and transDate > ?");
		pstmt->setString(1, customerName);
		pstmt->setString(2, saleDate);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			flag = 1;
			count++;
		}
		cout << "Quantity purchased: " << count << endl << endl;
		if (flag == 0)
		{
			cout << "The book was not purchased" << endl;
		}
		delete res;
		delete con;
		delete pstmt;
		return;
	case 2:
		cout << "Enter customer nummber: ";
		getchar();
		getline(cin, customerNumber);
		cout << "Enter date (YYYY-MM-DD): ";
		cin >> saleDate;
		pstmt = con->prepareStatement("select transaction.transDate, make_an.bookName, customer.customerName, make_an.customerNumber, customer.cellphone from transaction inner join make_an on transaction.transNumber = make_an.transNumber inner join customer on make_an.customerNumber = customer.customerNumber where customer.customerNumber = ? and transDate > ?");
		pstmt->setString(1, customerNumber);
		pstmt->setString(2, saleDate);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			flag = 1;
			count++;
		}
		if (flag == 0)
		{
			cout << "The book was not purchased" << endl;
		}
		cout << "Quantity purchased: " << count << endl << endl;
		delete res;
		delete con;
		delete pstmt;
		return;
	case 3:
		cout << "Enter customer cellphone (5XXXXXXXX): ";
		getchar();
		getline(cin, cellphone);
		cout << "Enter date (YYYY-MM-DD): ";
		cin >> saleDate;
		pstmt = con->prepareStatement("select transaction.transDate, make_an.bookName, customer.customerName, make_an.customerNumber, customer.cellphone from transaction inner join make_an on transaction.transNumber = make_an.transNumber inner join customer on make_an.customerNumber = customer.customerNumber where customer.cellphone=? and transDate > ?");
		pstmt->setString(1, cellphone);
		pstmt->setString(2, saleDate);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			flag = 1;
			count++;
		}
		cout << "Quantity purchased: " << count << endl << endl;
		if (flag == 0)
		{
			cout << "The book is not available" << endl;
		}
		delete res;
		delete con;
		delete pstmt;
		return;
	case 4:
		cout << "Enter customer name: ";
		getchar();
		getline(cin, customerName);
		cout << "Enter customer number: ";
		getline(cin, customerNumber);
		cout << "Enter customer cellphone (5XXXXXXXX): ";
		getline(cin, cellphone);
		cout << "Enter date (YYYY-MM-DD): ";
		cin >> saleDate;
		pstmt = con->prepareStatement("select transaction.transDate, make_an.bookName, customer.customerName, make_an.customerNumber, customer.cellphone from transaction inner join make_an on transaction.transNumber = make_an.transNumber inner join customer on make_an.customerNumber = customer.customerNumber where customer.customerName=? and customer.customerNumber=? and customer.cellphone=? and transDate > ?");
		pstmt->setString(1, customerName);
		pstmt->setString(2, customerNumber);
		pstmt->setString(3, cellphone);
		pstmt->setString(4, saleDate);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			flag = 1;
			count++;
		}
		cout << "Quantity purchased: " << count << endl << endl;
		if (flag == 0)
		{
			cout << "The book is not available" << endl;
		}
		delete res;
		delete con;
		delete pstmt;
		return;
	}
}

void mostBuyer() {
	string saleDate;
	PreparedStatement *pstmt;
	ResultSet *res;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Enter date (YYYY-MM-DD): ";
	cin >> saleDate;
	pstmt = con->prepareStatement("select transaction.transDate, make_an.bookName, customer.customerName, make_an.customerNumber, customer.cellphone from transaction inner join make_an on transaction.transNumber = make_an.transNumber inner join customer on make_an.customerNumber = customer.customerNumber where transDate > ? group by customerNumber order by count(*) desc limit 1");
	pstmt->setString(1, saleDate);
	res = pstmt->executeQuery();
	res->beforeFirst();
	while (res->next())
	{
		cout << "\n\nCustomer name: " << res->getString("customerName") << endl << "Customer Number: " << res->getString("customerNumber") << endl << "Customer ceiiphone: " << res->getString("cellphone") << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;
	return;
}

void mostSupplier() {
	string saleDate;
	PreparedStatement *pstmt;
	ResultSet *res;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Enter date (YYYY-MM-DD): ";
	cin >> saleDate;
	pstmt = con->prepareStatement("select orderBook.dateOrder, supply.supplierNumber, supplier.supplierName from orderBook inner join place_an on orderBook.orderNumber = place_an.orderNumber inner join supply on place_an.bookName = supply.bookName inner join supplier on supply.supplierNumber = supplier.supplierNumber where dateOrder >= ? group by supplierNumber order by count(*) desc limit 1 ");
	pstmt->setString(1, saleDate);
	res = pstmt->executeQuery();
	res->beforeFirst();
	while (res->next())
	{
		cout << "\n\nSupplier name: " << res->getString("supplierName") << endl << "Supplier Number: " << res->getString("supplierNumber") << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;
	return;
}


void howMuchOrders() {
	int count = 0;
	string startDate, endDate;
	PreparedStatement *pstmt;
	ResultSet *res;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Enter start date (YYYY-MM-DD): ";
	cin >> startDate;
	cout << "Enter end date (YYYY-MM-DD): ";
	cin >> endDate;
	pstmt = con->prepareStatement("select * from orderBook where dateOrder between ? and ? ");
	pstmt->setString(1, startDate);
	pstmt->setString(2, endDate);
	res = pstmt->executeQuery();
	res->beforeFirst();
	while (res->next())
	{
		count++;
	}
	cout << "Quantity orders: " << count << endl;
	delete res;
	delete con;
	delete pstmt;
	return;
}

void howMuchSales() {
	int count = 0;
	string startDate, endDate;
	PreparedStatement *pstmt;
	ResultSet *res;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Enter start date (YYYY-MM-DD): ";
	cin >> startDate;
	cout << "Enter end date (YYYY-MM-DD): ";
	cin >> endDate;
	pstmt = con->prepareStatement("select orderBook.dateOrder, transaction.transDate, orderBook.orderNumber, transaction.transNumber, place_an.customerNumber, make_an.customerNumber from orderBook inner join place_an on orderBook.orderNumber = place_an.orderNumber inner join make_an on place_an.customerNumber = make_an.customerNumber inner join transaction on transaction.transNumber = make_an.transNumber where place_an.bookName = make_an.bookName and dateOrder between ? and ?");
	pstmt->setString(1, startDate);
	pstmt->setString(2, endDate);
	res = pstmt->executeQuery();
	res->beforeFirst();
	while (res->next())
	{
		count++;
	}
	cout << "Quantity orders: " << count << endl;
	delete res;
	delete con;
	delete pstmt;
	return;
}

void howMuchDiscount() {
	int count = 0, choice=0; 
	float totalPrice = 0, discount = 0, temp = 0, totalDiscount=0;
	string discountDate, customerName, customerNumber, cellphone;
	PreparedStatement *pstmt;
	ResultSet *res;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Check discount \n1.By customer name\n2.By customer number\n3.customer cellphone\n4.All the above\nYour choice: ";
	cin >> choice;
	switch (choice) {
	case 1:
		getchar();
		cout << "Enter customer name: ";
		getline(cin, customerName);
		cout << "Enter start date (YYYY-MM-DD): ";
		cin >> discountDate;
		pstmt = con->prepareStatement("select globaldiscount.startDate,globaldiscount.endDate, transaction.transDate, transaction.totalPrice, globaldiscount.discountPrice, customer.customerName from globaldiscount inner join transaction on transDate between startDate and endDate inner join make_an on globaldiscount.bookName = make_an.bookName inner join customer on make_an.customerNumber = customer.customerNumber where transDate >= ? and customerName = ?");
		pstmt->setString(1, discountDate);
		pstmt->setString(2, customerName);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			totalPrice = res->getInt("totalPrice");
			temp = res->getInt("discountPrice");
			temp /= 100;
			temp = 1 - temp;
			discount = totalPrice / temp;
			discount = discount - totalPrice;
			cout << endl << "Total global discount: " << discount << "$" << endl << endl;
			count++;
		}
		if (count == 0)
		{
			cout << "The customer didn't get global discount since this date";
		}
		delete res;
		delete pstmt;
		pstmt = con->prepareStatement("select customer.totalPurchase, customer.customerName, make_an.totalPrice, transaction.transDate from customer inner join make_an on customer.customerNumber = make_an.customerNumber inner join transaction on transaction.transNumber = make_an.transNumber where totalPurchase>1000 and transDate >= ? and customerName = ?");
		pstmt->setString(1, discountDate);
		pstmt->setString(2, customerName);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			totalPrice = res->getInt("totalPrice");
			discount = totalPrice / 0.9;
			discount = discount - totalPrice;
			totalDiscount += discount;
			count++;
		}
		if (count > 0)
		{
			cout << endl << "Total personal discount: " << totalDiscount << "$" << endl << endl;
		}
		if (count == 0)
		{
			cout << "The customer didn't get personal discount since this date";
		}

		delete res;
		delete pstmt;
		delete con;
		return;
	case 2:
		getchar();
		cout << "Enter customer number: ";
		getline(cin, customerNumber);
		cout << "Enter start date (YYYY-MM-DD): ";
		cin >> discountDate;
		pstmt = con->prepareStatement("select globaldiscount.startDate,globaldiscount.endDate, transaction.transDate, transaction.totalPrice, globaldiscount.discountPrice, customer.customerNumber from globaldiscount inner join transaction on transDate between startDate and endDate inner join make_an on globaldiscount.bookName = make_an.bookName inner join customer on make_an.customerNumber = customer.customerNumber where transDate >= ? and customer.customerNumber = ?");
		pstmt->setString(1, discountDate);
		pstmt->setString(2, customerNumber);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			totalPrice = res->getInt("totalPrice");
			temp = res->getInt("discountPrice");
			temp /= 100;
			temp = 1 - temp;
			discount = totalPrice / temp;
			discount = discount - totalPrice;
			cout << endl << "Total global discount: " << discount << "$" << endl << endl;
			count++;
		}
		if (count == 0)
		{
			cout << "The customer didn't get global discount since this date";
		}
		delete res;
		delete pstmt;
		pstmt = con->prepareStatement("select customer.totalPurchase, customer.customerNumber, make_an.totalPrice, transaction.transDate from customer inner join make_an on customer.customerNumber = make_an.customerNumber inner join transaction on transaction.transNumber = make_an.transNumber where totalPurchase>1000 and transDate >= ? and customer.customerNumber = ?");
		pstmt->setString(1, discountDate);
		pstmt->setString(2, customerNumber);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			totalPrice = res->getInt("totalPrice");
			discount = totalPrice / 0.9;
			discount = discount - totalPrice;
			totalDiscount += discount;
			count++;
		}
		if (count > 0)
		{
			cout << endl << "Total personal discount: " << totalDiscount << "$" << endl << endl;
		}
		if (count == 0)
		{
			cout << "The customer didn't get personal discount since this date";
		}

		delete res;
		delete pstmt;
		delete con;
		return;
	case 3:
		getchar();
		cout << "Enter customer cellphone: ";
		getline(cin, cellphone);
		cout << "Enter start date (YYYY-MM-DD): ";
		cin >> discountDate;
		pstmt = con->prepareStatement("select globaldiscount.startDate,globaldiscount.endDate, transaction.transDate, transaction.totalPrice, globaldiscount.discountPrice, customer.cellphone from globaldiscount inner join transaction on transDate between startDate and endDate inner join make_an on globaldiscount.bookName = make_an.bookName inner join customer on make_an.customerNumber = customer.customerNumber where transDate >= ? and cellphone = ?");
		pstmt->setString(1, discountDate);
		pstmt->setString(2, cellphone);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			totalPrice = res->getInt("totalPrice");
			temp = res->getInt("discountPrice");
			temp /= 100;
			temp = 1 - temp;
			discount = totalPrice / temp;
			discount = discount - totalPrice;
			cout << endl << "Total global discount: " << discount << "$" << endl << endl;
			count++;
		}
		if (count == 0)
		{
			cout << "The customer didn't get global discount since this date";
		}
		delete res;
		delete pstmt;
		pstmt = con->prepareStatement("select customer.totalPurchase, customer.cellphone, make_an.totalPrice, transaction.transDate from customer inner join make_an on customer.customerNumber = make_an.customerNumber inner join transaction on transaction.transNumber = make_an.transNumber where totalPurchase>1000 and transDate >= ? and cellphone = ?");
		pstmt->setString(1, discountDate);
		pstmt->setString(2, cellphone);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			totalPrice = res->getInt("totalPrice");
			discount = totalPrice / 0.9;
			discount = discount - totalPrice;
			totalDiscount += discount;
			count++;
		}
		if (count > 0)
		{
			cout << endl << "Total personal discount: " << totalDiscount << "$" << endl << endl;
		}
		if (count == 0)
		{
			cout << "The customer didn't get personal discount since this date";
		}

		delete res;
		delete pstmt;
		delete con;
		return;
	case 4:
		getchar();
		cout << "Enter customer name: ";
		getline(cin, customerName);
		cout << "Enter customer number: ";
		getline(cin, customerNumber);
		cout << "Enter customer cellphone: ";
		getline(cin, cellphone);
		cout << "Enter start date (YYYY-MM-DD): ";
		cin >> discountDate;
		pstmt = con->prepareStatement("select globaldiscount.startDate,globaldiscount.endDate, transaction.transDate, transaction.totalPrice, globaldiscount.discountPrice, customer.customerName, customer.customerNumber, customer.cellphone from globaldiscount inner join transaction on transDate between startDate and endDate inner join make_an on globaldiscount.bookName = make_an.bookName inner join customer on make_an.customerNumber = customer.customerNumber where transDate >= ? and customer.customerName=? and customer.customerNumber=? and customer.cellphone=?");
		pstmt->setString(1, discountDate);
		pstmt->setString(2, customerName);
		pstmt->setString(3, customerNumber);
		pstmt->setString(4, cellphone);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			totalPrice = res->getInt("totalPrice");
			temp = res->getInt("discountPrice");
			temp /= 100;
			temp = 1 - temp;
			discount = totalPrice / temp;
			discount = discount - totalPrice;
			cout << endl << "Total global discount: " << discount << "$" << endl << endl;
			count++;
		}
		if (count == 0)
		{
			cout << "The customer didn't get global discount since this date";
		}
		delete res;
		delete pstmt;
		pstmt = con->prepareStatement("select customer.totalPurchase, customer.customerName,  customer.customerNumber,  customer.cellphone, make_an.totalPrice, transaction.transDate from customer inner join make_an on customer.customerNumber = make_an.customerNumber inner join transaction on transaction.transNumber = make_an.transNumber where totalPurchase>1000 and transDate >= ? and customer.customerName=? and customer.customerNumber=? and customer.cellphone=?");
		pstmt->setString(1, discountDate);
		pstmt->setString(2, customerName);
		pstmt->setString(3, customerNumber);
		pstmt->setString(4, cellphone);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			totalPrice = res->getInt("totalPrice");
			discount = totalPrice / 0.9;
			discount = discount - totalPrice;
			totalDiscount += discount;
			count++;
		}
		if (count > 0)
		{
			cout << endl << "Total personal discount: " << totalDiscount << "$" << endl << endl;
		}
		if (count == 0)
		{
			cout << "The customer didn't get personal discount since this date";
		}
		delete con;
		delete res;
		delete pstmt;
		return;
	}
}

void howMuchQuarter() {
	int count = 0, totalPrice = 0;
	char* year = new char[10];
	char* date = new char[10];
	char* date1 = new char[10];
	PreparedStatement *pstmt;
	ResultSet *res;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Enter year: ";
	cin >> year;
	strcpy(date, year);
	strcpy(date1, year);
	strcat(date, "-01-01");
	strcat(date1, "-03-31");
	pstmt = con->prepareStatement("select * from transaction where transDate between ? and ?");
	pstmt->setString(1, date);
	pstmt->setString(2, date1);
	res = pstmt->executeQuery();
	res->beforeFirst();
	while (res->next())
	{
		totalPrice+= res->getInt("totalPrice");
	}
	cout << "total Q1: " << totalPrice << endl;
	delete res;
	delete pstmt;
	totalPrice = 0;
	strcpy(date, year);
	strcpy(date1, year);
	strcat(date, "-04-01");
	strcat(date1, "-06-30");
	pstmt = con->prepareStatement("select * from transaction where transDate between ? and ?");
	pstmt->setString(1, date);
	pstmt->setString(2, date1);
	res = pstmt->executeQuery();
	res->beforeFirst();
	while (res->next())
	{
		totalPrice += res->getInt("totalPrice");
	}
	cout << "Total Q2: " << totalPrice << endl;
	delete res;
	delete pstmt;
	totalPrice = 0;
	strcpy(date, year);
	strcpy(date1, year);
	strcat(date, "-07-01");
	strcat(date1, "-09-30");
	pstmt = con->prepareStatement("select * from transaction where transDate between ? and ?");
	pstmt->setString(1, date);
	pstmt->setString(2, date1);
	res = pstmt->executeQuery();
	res->beforeFirst();
	while (res->next())
	{
		totalPrice += res->getInt("totalPrice");
	}
	cout << "Total Q3: " << totalPrice <<endl;
	delete res;
	delete pstmt;
	totalPrice = 0;
	strcpy(date, year);
	strcpy(date1, year);
	strcat(date, "-10-01");
	strcat(date1, "-12-31");
	pstmt = con->prepareStatement("select * from transaction where transDate between ? and ?");
	pstmt->setString(1, date);
	pstmt->setString(2, date1);
	res = pstmt->executeQuery();
	res->beforeFirst();
	while (res->next())
	{
		totalPrice += res->getInt("totalPrice");
	}
	cout << "Total Q4: " << totalPrice <<endl;
	delete res;
	delete pstmt;


	delete con;
	return;
}

void newCutomers() {
	int count = 0, countCustomer=0;
	string startDate, customerName, newCustomerName;
	PreparedStatement *pstmt;
	ResultSet *res, *res2;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Enter start date (YYYY-MM-DD): ";
	cin >> startDate;
	pstmt = con->prepareStatement("select transaction.transDate, make_an.customerNumber, customer.customerName from transaction inner join make_an on transaction.transNumber = make_an.transNumber inner join customer on make_an.customerNumber = customer.customerNumber where transDate >= ? group by customer.customerName order by 1");
	pstmt->setString(1, startDate);
	res = pstmt->executeQuery();
	res->beforeFirst();
	while (res->next())
	{
		customerName = res->getString("customerName");
		delete pstmt;
		pstmt = con->prepareStatement("select transaction.transDate, make_an.customerNumber, customer.customerName from transaction inner join make_an on transaction.transNumber = make_an.transNumber inner join customer on make_an.customerNumber = customer.customerNumber where transDate < ? group by customer.customerName order by 1");
		pstmt->setString(1, startDate);
		res2 = pstmt->executeQuery();
		res2->beforeFirst();
		while (res2->next())
		{
			newCustomerName = res2->getString("customerName");
			if (customerName == newCustomerName)
			{
				count++;
			}
		}
		if (count == 0)
		{
			countCustomer++;
		}
	}
	
	cout << "New customers: " << countCustomer << endl;
	delete res;
	delete res2;
	delete con;
	delete pstmt;
	return;
}

void howMuchSupplier() {
	int count = 0, totalPurchase=0;
	string startDate, endDate, supplierNumber;
	PreparedStatement *pstmt;
	ResultSet *res;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Enter start date (YYYY-MM-DD): ";
	cin >> startDate;
	cout << "Enter end date (YYYY-MM-DD): ";
	cin >> endDate;
	cout << "Enter supplier number: ";
	cin >> supplierNumber;
	pstmt = con->prepareStatement("select supplier.supplierNumber, supplier.supplierName, supply.supplierPrice, transaction.transDate from supplier inner join supply on supplier.supplierNumber = supply.supplierNumber inner join make_an on make_an.bookName = supply.bookName inner join transaction on transaction.transNumber = make_an.transNumber where transDate between ? and ? and supplier.supplierNumber=?");
	pstmt->setString(1, startDate);
	pstmt->setString(2, endDate);
	pstmt->setString(3, supplierNumber);
	res = pstmt->executeQuery();
	res->beforeFirst();
	while (res->next())
	{
		totalPurchase+=res->getInt("supplierPrice");
	}
	cout << "Total purchase: " << totalPurchase << endl;
	delete res;
	delete con;
	delete pstmt;
	return;
}

void howMuchSeller() {
	int count = 0, totalPurchase = 0, choice=0;
	string startDate, endDate, sellerNumber, sellerName;
	PreparedStatement *pstmt;
	ResultSet *res;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	cout << "Check total purchase \n1.By seller name\n2.By seller number\n3.both\nYour choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Enter start date (YYYY-MM-DD): ";
		cin >> startDate;
		cout << "Enter end date (YYYY-MM-DD): ";
		cin >> endDate;
		cout << "Enter seller name: ";
		getchar();
		getline(cin, sellerName);
		pstmt = con->prepareStatement("select make_an.totalPrice, make_an.sellerNumber, seller.sellerName, transaction.transDate from seller inner join make_an on seller.sellerNumber = make_an.sellerNumber inner join transaction on transaction.transNumber = make_an.transNumber where transDate between ? and ? and seller.sellerName=?");
		pstmt->setString(1, startDate);
		pstmt->setString(2, endDate);
		pstmt->setString(3, sellerName);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			totalPurchase += res->getInt("totalPrice");
		}
		cout << "Total purchase: " << totalPurchase << endl;
		delete res;
		delete con;
		delete pstmt;
		return;
	case 2:
		cout << "Enter start date (YYYY-MM-DD): ";
		cin >> startDate;
		cout << "Enter end date (YYYY-MM-DD): ";
		cin >> endDate;
		cout << "Enter seller number: ";
		cin >> sellerNumber;
		pstmt = con->prepareStatement("select make_an.totalPrice, make_an.sellerNumber, seller.sellerName, transaction.transDate from seller inner join make_an on seller.sellerNumber = make_an.sellerNumber inner join transaction on transaction.transNumber = make_an.transNumber where transDate between ? and ? and seller.sellerNumber=?");
		pstmt->setString(1, startDate);
		pstmt->setString(2, endDate);
		pstmt->setString(3, sellerNumber);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			totalPurchase += res->getInt("totalPrice");
		}
		cout << "Total purchase: " << totalPurchase << endl;
		delete res;
		delete con;
		delete pstmt;
		return;
	case 3:
		cout << "Enter start date (YYYY-MM-DD): ";
		cin >> startDate;
		cout << "Enter end date (YYYY-MM-DD): ";
		cin >> endDate;
		cout << "Enter seller name: ";
		getchar();
		getline(cin, sellerName);
		cout << "Enter seller number: ";
		cin >> sellerNumber;
		pstmt = con->prepareStatement("select make_an.totalPrice, make_an.sellerNumber, seller.sellerName, transaction.transDate from seller inner join make_an on seller.sellerNumber = make_an.sellerNumber inner join transaction on transaction.transNumber = make_an.transNumber where transDate between ? and ? and seller.sellerName=? and seller.sellerNumber=?");
		pstmt->setString(1, startDate);
		pstmt->setString(2, endDate);
		pstmt->setString(3, sellerName);
		pstmt->setString(4, sellerNumber);
		res = pstmt->executeQuery();
		res->beforeFirst();
		while (res->next())
		{
			totalPurchase += res->getInt("totalPrice");
		}
		cout << "Total purchase: " << totalPurchase << endl;
		delete res;
		delete con;
		delete pstmt;
		return;
	}
}

void best10() {
	int n = 0, i = 1, j = 0, count=0;
	string startDate, endDate;
	cout << "Enter start date (YYYY-MM-DD): ";
	cin >> startDate;
	cout << "Enter end date (YYYY-MM-DD): ";
	cin >> endDate;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("select transaction.transDate, make_an.bookName , count(*) as most from transaction join make_an on transaction.transNumber = make_an.transNumber where transDate between ? and ? group by bookName order by most desc LIMIT 5 OFFSET ?");
		pstmt->setString(1, startDate);
		pstmt->setString(2, endDate);
		pstmt->setInt(3, n);
		ResultSet *res = pstmt->executeQuery();
		if (!res->next() && n > 0)                            //if there is no next
		{
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("select transaction.transDate, make_an.bookName , count(*) as most from transaction join make_an on transaction.transNumber = make_an.transNumber where transDate between ? and ? group by bookName order by most desc LIMIT 5 OFFSET ?");
			pstmt->setString(1, startDate);
			pstmt->setString(2, endDate);
			pstmt->setInt(3, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "Book name: " << res->getString("bookName") << endl << endl;
			i++;
			j++;
			count += res->getInt("most");
		}
		
		cout << endl << endl << "1.Next books" << endl << "2.Previous books" << endl << "3.Return to main menu" << endl;
		int choose;
		cout << "Your choice:";
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			break;
		}
		default:
		{
			if (count < 10)
			{
				cout << "10 books were not sold on these dates" << endl;
			}
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}



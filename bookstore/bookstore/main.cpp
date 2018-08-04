#include <iostream>
#include <mysql_connection.h>
#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Database.h"
#include "book.h"

#define NAMESPACES using namespace boost::posix_time;using namespace boost::gregorian;using namespace std;using namespace sql;

NAMESPACES;
int main(int argc, const char * argv[]) {
	int choice = 0;
	string dateTransStart, dateTransEnd, bookName;
	
	while (1)
	{
		cout << "\n1.Show all books in stock\n2.Displays all (open) invitations to books\n3.Displays a list of all customers\n4.Lists all vendors\n5.Show all transactions between date ??? And a date ??? ";
		cout << "\n6.View all globally discounted books\n7.Check whether the X book is currently in stock in the store\n8.List all suppliers of Book X\n9.How many copies of the book X have been sold since Y";
		cout << "\n10.How many books since Y purchased customer Z\n11.Details of the customer who has purchased the most books in the store since Y\n12.Supplier details from which the most books have been ordered since Y";
		cout << "\n13.The total number of book orders made between a date ??? And date ???\n14.The amount of all book orders between a date ??? And date ??? Which eventually became sales\n15.What is the total discount customer Z received since Y";
		cout << "\n16.Sales revenue of the store during Q3, Q2, Q1 and Q4 quarter in the year ???\n17.The number of new customers has been added since Y\n18.Total purchases from ??? Between ??? To- ???\n19.What is the total sales of a seller ??? In store between date ??? And the ???";
		cout << "\n20.List of 10 best-selling titles from the date ??? And date ???\n21.To exit\nYour choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			printAllBooks();
			break;
		case 2:
			openOrders();
			break;
		case 3:
			printCustomers();
			break;
		case 4:
			printSupplier();
			break;
		case 5:
			cout << "Enter start date (YYYY-MM-DD): ";
			cin >> dateTransStart;
			cout << "Enter end date (YYYY-MM-DD): ";
			cin >> dateTransEnd;
			transactionByDate(dateTransStart, dateTransEnd);
			break;
		case 6:
			globalDiscount();
			break;
		case 7:
			isAvailable();
			break;
		case 8:
			isSupplier();
			break;
		case 9:
			HowManySold();
			break;
		case 10:
			clientBuy();
			break;
		case 11:
			mostBuyer();
			break;
		case 12:
			mostSupplier();
			break;
		case 13:
			howMuchOrders();
			break;
		case 14:
			howMuchSales();
			break;
		case 15:
			howMuchDiscount();
			break;
		case 16:
			howMuchQuarter();
			break;
		case 17:
			newCutomers();
			break;
		case 18:
			howMuchSupplier();
			break;
		case 19:
			howMuchSeller();
			break;
		case 20:
			best10();
			break;
		case 21:
			return 0;
			break;
		}
	}
	return 0;
}

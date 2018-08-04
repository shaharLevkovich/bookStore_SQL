#ifndef book_h
#define book_h

#include <stdio.h>
#include <stdlib.h>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "mysql_connection.h"

#include "Database.h"
#include <iostream>
#include <string.h>
#define NAMESPACES using namespace boost::posix_time;using namespace boost::gregorian;using namespace std;using namespace sql;


void printAllBooks();
void openOrders();
void printCustomers();
void printSupplier();
void transactionByDate(string, string);
void globalDiscount();
void isAvailable();
void isSupplier();
void HowManySold();
void clientBuy();
void mostBuyer();
void mostSupplier();
void howMuchOrders();
void howMuchSales();
void howMuchDiscount();
void howMuchQuarter();
void newCutomers();
void howMuchSupplier();
void howMuchSeller();
void best10();

#endif


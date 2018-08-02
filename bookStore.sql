-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: localhost    Database: bookstore
-- ------------------------------------------------------
-- Server version	5.7.21-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `book`
--

DROP TABLE IF EXISTS `book`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `book` (
  `authorName` varchar(20) NOT NULL,
  `bookName` varchar(20) NOT NULL,
  `bookPrice` float DEFAULT NULL,
  `amount` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`bookName`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book`
--

LOCK TABLES `book` WRITE;
/*!40000 ALTER TABLE `book` DISABLE KEYS */;
INSERT INTO `book` VALUES ('Hilary Thomas','Bevis Robbins',68,58),('Zahir Marquez','Duncan Valencia',98,92),('Jeremy Hodges','Harriet Cherry',76,75),('Imani Wolf','Katelyn Doyle',50,0),('Emily Lott','Maggy Willis',77,62),('Lydia Montoya','Odysseus Mcbride',56,98),('Merrill Chang','Randall Wagner',84,14),('Kyle Wynn','Sybil Sanchez',118,69),('Lavinia Mcintyre','Taylor Dale',53,19),('Tallulah Fisher','Yasir Huber',108,58);
/*!40000 ALTER TABLE `book` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer` (
  `customerName` varchar(20) NOT NULL,
  `customerNumber` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `cellphone` int(10) unsigned DEFAULT NULL,
  `totalPurchase` float DEFAULT NULL,
  PRIMARY KEY (`customerNumber`)
) ENGINE=InnoDB AUTO_INCREMENT=7704 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES ('Seth Lancaster',2717,545267404,1802),('Hamilton Hill',4436,586946649,416),('Norman Vargas',5374,516682286,1899),('Kasper Tate',6095,546455053,899),('Cyrus Hopper',6201,534281425,1472),('Mark Hardin',6395,514036274,988),('Mark Glenn',6733,544306940,1802),('Kamal Chavez',6767,545877304,858),('Candice Schwartz',7539,538571022,854),('Bo Acevedo',7703,567520917,140);
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `globaldiscount`
--

DROP TABLE IF EXISTS `globaldiscount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `globaldiscount` (
  `startDate` date DEFAULT NULL,
  `endDate` date DEFAULT NULL,
  `discountPrice` int(10) unsigned DEFAULT NULL,
  `discountNumber` int(10) unsigned NOT NULL,
  `discountName` varchar(20) NOT NULL,
  `bookName` varchar(20) NOT NULL,
  PRIMARY KEY (`discountNumber`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `globaldiscount`
--

LOCK TABLES `globaldiscount` WRITE;
/*!40000 ALTER TABLE `globaldiscount` DISABLE KEYS */;
INSERT INTO `globaldiscount` VALUES ('2018-08-01','2018-08-30',30,2,'back to school','Bevis Robbins'),('2017-09-02','2017-09-12',20,4,'rosh hashana','Duncan Valencia'),('2018-01-04','2018-02-05',30,7,'month book','Harriet Cherry'),('2017-02-17','2017-03-22',50,8,'1+1','Katelyn Doyle'),('2018-10-27','2018-11-16',10,10,'special sale','Maggy Willis'),('2017-10-16','2017-10-23',50,11,'week book','Odysseus Mcbride'),('2018-06-01','2018-06-30',30,13,'summer sale','Randall Wagner'),('2017-04-03','2017-04-17',20,15,'passover','Sybil Sanchez'),('2017-01-12','2017-02-11',40,16,'Clearance sale','Taylor Dale'),('2017-12-15','2018-01-01',20,17,'new years','Yasir Huber');
/*!40000 ALTER TABLE `globaldiscount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `make_an`
--

DROP TABLE IF EXISTS `make_an`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `make_an` (
  `totalPrice` float DEFAULT NULL,
  `transNumber` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `customerNumber` int(10) unsigned DEFAULT NULL,
  `sellerNumber` int(10) unsigned DEFAULT NULL,
  `bookName` varchar(20) NOT NULL,
  PRIMARY KEY (`transNumber`),
  KEY `customerNumber` (`customerNumber`),
  KEY `sellerNumber` (`sellerNumber`),
  KEY `bookName` (`bookName`),
  CONSTRAINT `make_an_ibfk_1` FOREIGN KEY (`transNumber`) REFERENCES `transaction` (`transNumber`),
  CONSTRAINT `make_an_ibfk_2` FOREIGN KEY (`customerNumber`) REFERENCES `customer` (`customerNumber`),
  CONSTRAINT `make_an_ibfk_3` FOREIGN KEY (`sellerNumber`) REFERENCES `seller` (`sellerNumber`),
  CONSTRAINT `make_an_ibfk_4` FOREIGN KEY (`bookName`) REFERENCES `book` (`bookName`)
) ENGINE=InnoDB AUTO_INCREMENT=9735 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `make_an`
--

LOCK TABLES `make_an` WRITE;
/*!40000 ALTER TABLE `make_an` DISABLE KEYS */;
INSERT INTO `make_an` VALUES (120,2848,2717,134,'Bevis Robbins'),(375,3742,4436,169,'Duncan Valencia'),(106,4018,5374,173,'Harriet Cherry'),(186,4823,6095,203,'Katelyn Doyle'),(77,5456,6201,409,'Maggy Willis'),(246,7240,6395,512,'Yasir Huber'),(53,8439,6733,553,'Taylor Dale'),(107,8519,7539,583,'Randall Wagner'),(77,9281,7703,689,'Maggy Willis'),(202,9734,2717,850,'Sybil Sanchez');
/*!40000 ALTER TABLE `make_an` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orderbook`
--

DROP TABLE IF EXISTS `orderbook`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orderbook` (
  `dateOrder` date DEFAULT NULL,
  `orderNumber` int(10) unsigned NOT NULL,
  `statusOrder` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`orderNumber`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orderbook`
--

LOCK TABLES `orderbook` WRITE;
/*!40000 ALTER TABLE `orderbook` DISABLE KEYS */;
INSERT INTO `orderbook` VALUES ('2018-05-30',3154,5),('2018-01-01',3254,4),('2018-05-08',4435,5),('2018-05-15',5508,4),('2018-07-11',5916,3),('2018-02-13',6705,3),('2018-04-18',6807,1),('2018-03-12',7004,3),('2018-02-01',8962,3),('2017-09-21',9705,3);
/*!40000 ALTER TABLE `orderbook` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `personaldiscount`
--

DROP TABLE IF EXISTS `personaldiscount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `personaldiscount` (
  `startDate` date DEFAULT NULL,
  `endDate` date DEFAULT NULL,
  `discountPrice` float DEFAULT NULL,
  `customerNumber` int(10) unsigned NOT NULL,
  PRIMARY KEY (`customerNumber`),
  CONSTRAINT `personaldiscount_ibfk_1` FOREIGN KEY (`customerNumber`) REFERENCES `customer` (`customerNumber`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `personaldiscount`
--

LOCK TABLES `personaldiscount` WRITE;
/*!40000 ALTER TABLE `personaldiscount` DISABLE KEYS */;
INSERT INTO `personaldiscount` VALUES ('2018-01-01','2018-12-31',10,2717),('2018-01-01','2018-12-31',10,4436),('2018-01-01','2018-12-31',10,5374),('2018-01-01','2018-12-31',10,6095),('2018-01-01','2018-12-31',10,6201),('2018-01-01','2018-12-31',10,6395),('2018-01-01','2018-12-31',10,6733),('2018-01-01','2018-12-31',10,6767),('2018-01-01','2018-12-31',10,7539),('2018-01-01','2018-12-31',10,7703);
/*!40000 ALTER TABLE `personaldiscount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `place_an`
--

DROP TABLE IF EXISTS `place_an`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `place_an` (
  `orderNumber` int(10) unsigned NOT NULL,
  `customerNumber` int(10) unsigned DEFAULT NULL,
  `bookName` varchar(20) NOT NULL,
  PRIMARY KEY (`orderNumber`),
  KEY `customerNumber` (`customerNumber`),
  KEY `bookName` (`bookName`),
  CONSTRAINT `place_an_ibfk_1` FOREIGN KEY (`orderNumber`) REFERENCES `orderbook` (`orderNumber`),
  CONSTRAINT `place_an_ibfk_2` FOREIGN KEY (`customerNumber`) REFERENCES `customer` (`customerNumber`),
  CONSTRAINT `place_an_ibfk_3` FOREIGN KEY (`bookName`) REFERENCES `book` (`bookName`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `place_an`
--

LOCK TABLES `place_an` WRITE;
/*!40000 ALTER TABLE `place_an` DISABLE KEYS */;
INSERT INTO `place_an` VALUES (3154,2717,'Bevis Robbins'),(3254,4436,'Duncan Valencia'),(4435,5374,'Harriet Cherry'),(5508,6095,'Katelyn Doyle'),(5916,6201,'Odysseus Mcbride'),(6705,6395,'Yasir Huber'),(6807,6733,'Taylor Dale'),(7004,7539,'Randall Wagner'),(8962,7703,'Maggy Willis'),(9705,6767,'Sybil Sanchez');
/*!40000 ALTER TABLE `place_an` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `seller`
--

DROP TABLE IF EXISTS `seller`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `seller` (
  `sellerNumber` int(10) unsigned NOT NULL,
  `sellerName` varchar(20) NOT NULL,
  PRIMARY KEY (`sellerNumber`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `seller`
--

LOCK TABLES `seller` WRITE;
/*!40000 ALTER TABLE `seller` DISABLE KEYS */;
INSERT INTO `seller` VALUES (134,'Cain Smith'),(169,'Byron Oneal'),(173,'Orlando Taylor'),(203,'Samuel Dyer'),(409,'Cain Nunez'),(512,'Bruce Mcintyre'),(553,'Maile Frank'),(583,'Perry Peterson'),(689,'Chaney Giles'),(850,'Patience Dominguez');
/*!40000 ALTER TABLE `seller` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `supplier`
--

DROP TABLE IF EXISTS `supplier`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `supplier` (
  `supplierName` varchar(20) NOT NULL,
  `supplierNumber` int(10) unsigned NOT NULL,
  PRIMARY KEY (`supplierNumber`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `supplier`
--

LOCK TABLES `supplier` WRITE;
/*!40000 ALTER TABLE `supplier` DISABLE KEYS */;
INSERT INTO `supplier` VALUES ('Non Inc.',100),('Odio Nam Industries',101),('Posuere Vulputate',102),('Sit Amet Inc.',103),('Nunc Inc.',104),('Vitae Associates',106),('Etiam Industries',107),('Varius Et Company',108),('Vel Company',109),('Ac Vel Corporation',110);
/*!40000 ALTER TABLE `supplier` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `supply`
--

DROP TABLE IF EXISTS `supply`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `supply` (
  `supplierPrice` int(10) unsigned DEFAULT NULL,
  `supplierNumber` int(10) unsigned DEFAULT NULL,
  `bookName` varchar(20) NOT NULL,
  PRIMARY KEY (`bookName`),
  KEY `supplierNumber` (`supplierNumber`),
  CONSTRAINT `supply_ibfk_1` FOREIGN KEY (`supplierNumber`) REFERENCES `supplier` (`supplierNumber`),
  CONSTRAINT `supply_ibfk_2` FOREIGN KEY (`bookName`) REFERENCES `book` (`bookName`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `supply`
--

LOCK TABLES `supply` WRITE;
/*!40000 ALTER TABLE `supply` DISABLE KEYS */;
INSERT INTO `supply` VALUES (38,102,'Bevis Robbins'),(68,109,'Duncan Valencia'),(46,108,'Harriet Cherry'),(20,100,'Katelyn Doyle'),(47,106,'Maggy Willis'),(26,100,'Odysseus Mcbride'),(44,107,'Randall Wagner'),(88,110,'Sybil Sanchez'),(23,104,'Taylor Dale'),(78,103,'Yasir Huber');
/*!40000 ALTER TABLE `supply` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transaction`
--

DROP TABLE IF EXISTS `transaction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transaction` (
  `transNumber` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `transDate` date DEFAULT NULL,
  `totalPrice` float DEFAULT NULL,
  PRIMARY KEY (`transNumber`)
) ENGINE=InnoDB AUTO_INCREMENT=9735 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transaction`
--

LOCK TABLES `transaction` WRITE;
/*!40000 ALTER TABLE `transaction` DISABLE KEYS */;
INSERT INTO `transaction` VALUES (2848,'2018-02-04',120),(3742,'2017-12-14',375),(4018,'2018-04-25',106),(4823,'2018-03-22',186),(5456,'2017-09-08',31),(7240,'2018-04-04',246),(8439,'2018-03-02',53),(8519,'2017-10-19',107),(9281,'2018-06-07',77),(9734,'2018-07-02',202);
/*!40000 ALTER TABLE `transaction` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-08-02 13:42:33

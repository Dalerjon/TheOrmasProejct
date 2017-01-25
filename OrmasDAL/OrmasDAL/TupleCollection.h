#ifndef TUPLECOLLECTION_H
#define TUPLECOLLECTION_H

namespace DataLayer{
	typedef std::tuple<int, std::string, std::string, std::string, std::string> companiesCollection;
	
	typedef std::tuple<int, int, std::string, std::string, int, bool> currenciesCollection;
	
	typedef std::tuple<int, std::string, std::string, int> measuresCollection;
	
	typedef std::tuple<int, int, std::string, int, int, double, int, int> ordersCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, 
		std::string, int, double, std::string, int, int, int, int> ordersViewCollection;
	
	typedef std::tuple<int, int, int, int, int, int, double, int, int> productListCollection;
	
	typedef std::tuple<int, int, int, int, std::string, double, std::string, double, std::string, int, double, std::string, std::string, 
		int, int, int> productListViewCollection;
	
	typedef std::tuple<int, std::string, std::string> productTypeCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string> productionCollection;
	
	typedef std::tuple<int, int, std::string, double, int, double, int, int, int> productsCollection;
	
	typedef std::tuple<int, std::string, double, std::string, double, std::string, std::string, int, std::string, int, int,
		int, int> productsViewCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string> locationsCollection;
	
	typedef std::tuple<int, int, std::string, int, int, double, int, int> returnsCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, int, double, std::string, int, int, int, int> returnsViewCollection;
	
	typedef std::tuple<int, std::string, std::string> rolesCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string> statusCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, int, int, 
		std::string, bool> usersCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, bool, int, int> usersViewCollection;
}

#endif //TUPLECOLLECTION_H
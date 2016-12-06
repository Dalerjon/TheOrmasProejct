#ifndef TUPLECOLLECTION_H
#define TUPLECOLLECTION_H

namespace DataLayer{
	typedef std::tuple<int, std::string, std::string, std::string, std::string> companiesCollection;
	typedef std::tuple<int, int, std::string, std::string> currenciesCollection;
	typedef std::tuple<int, std::string, std::string> measuresCollection;
	typedef std::tuple<int, int, std::string, int> ordersCollection;
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		int, int> ordersViewCollection;
	typedef std::tuple<int, int, int, int, int> productListCollection;
	typedef std::tuple<int, std::string, std::string> productTypeCollection;
	typedef std::tuple<int, int, std::string, float, int, float, int, int> productsCollection;
	typedef std::tuple<int, std::string, std::string, std::string, std::string> locationsCollection;
	typedef std::tuple<int, int, std::string, int> returnsCollection;
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		int, int> returnsViewCollection;
	typedef std::tuple<int, std::string, std::string> rolesCollection;
	typedef std::tuple<int, std::string, std::string, std::string> statusCollection;
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, int, int, 
		std::string, bool> usersCollection;
}

#endif //TUPLECOLLECTION_H
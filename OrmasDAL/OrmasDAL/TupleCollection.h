#ifndef TUPLECOLLECTION_H
#define TUPLECOLLECTION_H

namespace DataLayer{
	typedef std::tuple<int, std::string, std::string, std::string, std::string> companiesCollection;
	typedef std::tuple<int, int, std::string, std::string> currenciesCollection;
	typedef std::tuple<int, std::string, std::string> measuresCollection;
	typedef std::tuple<int, int, std::string, int, std::string> ordersCollection;
	typedef std::tuple<int, int, int, int, int> productListCollection;
	typedef std::tuple<int, std::string, std::string> productTypeCollection;
	typedef std::tuple<int, int, std::string, float, int, float, int, std::string, std::string> productsCollection;
	typedef std::tuple<int, std::string, std::string> regionsCollection;
	typedef std::tuple<int, int, std::string, int, std::string> returnsCollection;
	typedef std::tuple<int, std::string, std::string> rolesCollection;
	typedef std::tuple<int, std::string, std::string, std::string> statusCollection;
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, int, int, std::string> usersCollection;
}

#endif //TUPLECOLLECTION_H
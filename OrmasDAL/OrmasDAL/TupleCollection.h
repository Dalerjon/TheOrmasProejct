#ifndef TUPLECOLLECTION_H
#define TUPLECOLLECTION_H

namespace DataLayer{
	typedef std::tuple<int, std::string, std::string, std::string> accessItemsCollection;

	typedef std::tuple<int, int, int> accessesCollection;
	
	typedef std::tuple<int, int, double, int> balancesCollection;

	typedef std::tuple<int,std::string, std::string, double, std::string, int, int> balancesViewCollection;

	typedef std::tuple<int, std::string, std::string, int> clientsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, 
		std::string, std::string, std::string, std::string, bool, int, int> clientsViewCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string> companiesCollection;
	
	typedef std::tuple<int, int, std::string, std::string, int, bool> currenciesCollection;

	typedef std::tuple<int, int, std::string, std::string> employeesCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, 
		std::string, std::string, std::string, bool, int, int> employeesViewCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string> locationsCollection;
	
	typedef std::tuple<int, std::string, std::string, int> measuresCollection;

	typedef std::tuple<int, int, int, int, double, int, int> orderListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> orderListViewCollection;
	
	typedef std::tuple<int, int, std::string, int, int, double, int, int> ordersCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, int, double, std::string, int, int, int, int> ordersViewCollection;

	typedef std::tuple<int, std::string, double, int, int> paymentsCollection;

	typedef std::tuple<int, std::string, double, std::string, int, int> paymentsViewCollection;

	typedef std::tuple<int, int, int, std::string> photosCollection;

	typedef std::tuple<int, std::string> positionsCollection;

	typedef std::tuple<int, std::string, double, int, int> pricesCollection;

	typedef std::tuple<int, std::string, std::string, double, std::string, double, std::string, int, int> pricesViewCollection;
	
	typedef std::tuple<int, std::string, std::string> productTypeCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string> productionCollection;

	typedef std::tuple<int, int, int, int, double, int, int> productionListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> productionListViewCollection;
	
	typedef std::tuple<int, int, std::string, double, int, double, int, int, int> productsCollection;

	typedef std::tuple<int, std::string, double, std::string, double, std::string, std::string, int, std::string, int, int,
		int, int> productsViewCollection;

	typedef std::tuple<int, std::string, std::string> relationTypeCollection;

	typedef std::tuple<int, int, int, int> relationsCollection;

	typedef std::tuple<int, int, int, int, double, int, int> returnListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> returnListViewCollection;
	
	typedef std::tuple<int, int, std::string, int, int, double, int, int> returnsCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, int, double, std::string, int, int, int, int> returnsViewCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string> rolesCollection;

	typedef std::tuple<int, int, double, int, int, std::string, bool> salariesCollection;

	typedef std::tuple<int, int, std::string, std::string, std::string, std::string, double, std::string, 
		std::string, int, int, bool> salariesViewCollection;

	typedef std::tuple<int, std::string, std::string> salaryTypeCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string> statusCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, int, 
		std::string, bool> usersCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, bool, int> usersViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> writeOffListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> writeOffListViewCollection;
	
	typedef std::tuple<int, int, std::string, int, int, double, int, int> writeOffsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, int, double, std::string, int, int, int, int> writeOffsViewCollection;
}

#endif //TUPLECOLLECTION_H
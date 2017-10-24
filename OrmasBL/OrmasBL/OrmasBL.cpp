// OrmasBL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "OrmasBL.h"
#include <typeinfo>
#include <math.h>

namespace BusinessLayer{
	
	OrmasBL::OrmasBL()
	{
	}
	
	OrmasBL::OrmasBL(const OrmasBL &oBL)
	{ 
		ormasDal = oBL.ormasDal; 
	}
	
	OrmasBL::~OrmasBL()
	{
	}

	bool OrmasBL::ConnectToDB(std::string dbname, std::string username, std::string password, std::string host, int port)
	{
		if (ormasDal.ConnectToDB(dbname, username, password, host, port))
			return true;
		return false;
	}
	
	DataLayer::OrmasDal& OrmasBL::GetOrmasDal()
	{
		return ormasDal;
	}

	int OrmasBL::GenerateID()
	{
		return ormasDal.GenerateID();
	}

	bool OrmasBL::StartTransaction(std::string& errorMessage)
	{
		return ormasDal.StartTransaction(errorMessage);
	}
	bool OrmasBL::CommitTransaction(std::string& errorMessage)
	{
		return ormasDal.CommitTransaction(errorMessage);
	}
	bool OrmasBL::CancelTransaction(std::string& errorMessage)
	{
		return ormasDal.CancelTransaction(errorMessage);
	}

	template<>
	std::vector<Access> OrmasBL::GetAllDataForClass<Access>(std::string& errorMessage, std::string filter)
	{
		std::vector<Access> vecForAccess;
		std::vector<DataLayer::accessesCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetAccesses(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetAccesses(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForAccess.push_back(Access(data));
			}
		}
		return vecForAccess;
	}

	template<>
	std::vector<AccessItem> OrmasBL::GetAllDataForClass<AccessItem>(std::string& errorMessage, std::string filter)
	{
		std::vector<AccessItem> vecForAccessItems;
		std::vector<DataLayer::accessItemsCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetAccessItems(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetAccessItems(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForAccessItems.push_back(AccessItem(data));
			}
		}
		return vecForAccessItems;
	}

	template<>
	std::vector<BalanceView> OrmasBL::GetAllDataForClass<BalanceView>(std::string& errorMessage, std::string filter)
	{
		std::vector<BalanceView> vecForBalance;
		std::vector<DataLayer::balancesViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetBalances(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetBalances(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForBalance.push_back(BalanceView(data));
			}
		}
		return vecForBalance;
	}

	template<>
	std::vector<ClientView> OrmasBL::GetAllDataForClass<ClientView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ClientView> vecForClient;
		std::vector<DataLayer::clientsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetClients(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetClients(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForClient.push_back(ClientView(data));
			}
		}
		return vecForClient;
	}

	template<>
	std::vector<Company> OrmasBL::GetAllDataForClass<Company>(std::string& errorMessage, std::string filter)
	{
		std::vector<Company> vecForCompany;
		std::vector<DataLayer::companiesCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetCompanies(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetCompanies(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForCompany.push_back(Company(data));
			}
		}
		return vecForCompany;
	}

	template<>
	std::vector<Currency> OrmasBL::GetAllDataForClass<Currency>(std::string& errorMessage, std::string filter)
	{
		std::vector<Currency> vecForCurrency;
		std::vector<DataLayer::currenciesCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetCurrencies(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetCurrencies(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForCurrency.push_back(Currency(data));
			}
		}
		return vecForCurrency;
	}

	template<>
	std::vector<EmployeeView> OrmasBL::GetAllDataForClass<EmployeeView>(std::string& errorMessage, std::string filter)
	{
		std::vector<EmployeeView> vecForEmployee;
		std::vector<DataLayer::employeesViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetEmployees(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetEmployees(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForEmployee.push_back(EmployeeView(data));
			}
		}
		return vecForEmployee;
	}

	template<>
	std::vector<Location> OrmasBL::GetAllDataForClass<Location>(std::string& errorMessage, std::string filter)
	{
		std::vector<Location> vecForLocation;
		std::vector<DataLayer::locationsCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetLocations(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetLocations(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForLocation.push_back(Location(data));
			}
		}
		return vecForLocation;
	}

	template<>
	std::vector<Measure> OrmasBL::GetAllDataForClass<Measure>(std::string& errorMessage, std::string filter)
	{
		std::vector<Measure> vecForMeasure;
		std::vector<DataLayer::measuresCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetMeasures(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetMeasures(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForMeasure.push_back(Measure(data));
			}
		}
		return vecForMeasure;
	}

	template<>
	std::vector<OrderView> OrmasBL::GetAllDataForClass<OrderView>(std::string& errorMessage, std::string filter)
	{
		std::vector<OrderView> vecForOrder;
		std::vector<DataLayer::ordersViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetOrders(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetOrders(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForOrder.push_back(OrderView(data));
			}
		}
		return vecForOrder;
	}

	template<>
	std::vector<OrderListView> OrmasBL::GetAllDataForClass<OrderListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<OrderListView> vecForOrderList;
		std::vector<DataLayer::orderListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetOrderList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetOrderList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForOrderList.push_back(OrderListView(data));
			}
		}
		return vecForOrderList;
	}

	template<>
	std::vector<PaymentView> OrmasBL::GetAllDataForClass<PaymentView>(std::string& errorMessage, std::string filter)
	{
		std::vector<PaymentView> vecForPayment;
		std::vector<DataLayer::paymentsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetPayments(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetPayments(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForPayment.push_back(PaymentView(data));
			}
		}
		return vecForPayment;
	}

	template<>
	std::vector<Photo> OrmasBL::GetAllDataForClass<Photo>(std::string& errorMessage, std::string filter)
	{
		std::vector<Photo> vecForPhoto;
		std::vector<DataLayer::photosCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetPhotos(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetPhotos(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForPhoto.push_back(Photo(data));
			}
		}
		return vecForPhoto;
	}

	template<>
	std::vector<Position> OrmasBL::GetAllDataForClass<Position>(std::string& errorMessage, std::string filter)
	{
		std::vector<Position> vecForPosition;
		std::vector<DataLayer::positionsCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetPositions(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetPositions(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForPosition.push_back(Position(data));
			}
		}
		return vecForPosition;
	}

	template<>
	std::vector<PriceView> OrmasBL::GetAllDataForClass<PriceView>(std::string& errorMessage, std::string filter)
	{
		std::vector<PriceView> vecForPrices;
		std::vector<DataLayer::pricesViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetPrices(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetPrices(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForPrices.push_back(PriceView(data));
			}
		}
		return vecForPrices;
	}

	template<>
	std::vector<ProductView> OrmasBL::GetAllDataForClass<ProductView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductView> vecForProduct;
		std::vector<DataLayer::productsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProducts(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProducts(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProduct.push_back(ProductView(data));
			}
		}
		return vecForProduct;
	}

	
	template<>
	std::vector<Production> OrmasBL::GetAllDataForClass<Production>(std::string& errorMessage, std::string filter)
	{
		std::vector<Production> vecForProduction;
		std::vector<DataLayer::productionCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProduction(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProduction(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProduction.push_back(Production(data));
			}
		}
		return vecForProduction;
	}

	template<>
	std::vector<ProductionListView> OrmasBL::GetAllDataForClass<ProductionListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductionListView> vecForProductionList;
		std::vector<DataLayer::productionListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProductionList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProductionList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductionList.push_back(ProductionListView(data));
			}
		}
		return vecForProductionList;
	}

	template<>
	std::vector<ProductType> OrmasBL::GetAllDataForClass<ProductType>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductType> vecForProductType;
		std::vector<DataLayer::productTypeCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProductTypes(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProductTypes(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductType.push_back(ProductType(data));
			}
		}
		return vecForProductType;
	}


	template<>
	std::vector<Relation> OrmasBL::GetAllDataForClass<Relation>(std::string& errorMessage, std::string filter)
	{
		std::vector<Relation> vecForRelation;
		std::vector<DataLayer::relationsCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetRelations(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetRelations(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForRelation.push_back(Relation(data));
			}
		}
		return vecForRelation;
	}

	template<>
	std::vector<RelationType> OrmasBL::GetAllDataForClass<RelationType>(std::string& errorMessage, std::string filter)
	{
		std::vector<RelationType> vecForRelationType;
		std::vector<DataLayer::relationTypeCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetRelationType(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetRelationType(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForRelationType.push_back(RelationType(data));
			}
		}
		return vecForRelationType;
	}


	template<>
	std::vector<ReturnView> OrmasBL::GetAllDataForClass<ReturnView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ReturnView> vecForReturn;
		std::vector<DataLayer::returnsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetReturns(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetReturns(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForReturn.push_back(ReturnView(data));
			}
		}
		return vecForReturn;
	}

	template<>
	std::vector<ReturnListView> OrmasBL::GetAllDataForClass<ReturnListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ReturnListView> vecForReturnList;
		std::vector<DataLayer::returnListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetReturnList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetReturnList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForReturnList.push_back(ReturnListView(data));
			}
		}
		return vecForReturnList;
	}

	template<>
	std::vector<Role> OrmasBL::GetAllDataForClass<Role>(std::string& errorMessage, std::string filter)
	{
		std::vector<Role> vecForRole;
		std::vector<DataLayer::rolesCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetRoles(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetRoles(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForRole.push_back(Role(data));
			}
		}
		return vecForRole;
	}

	template<>
	std::vector<SalaryView> OrmasBL::GetAllDataForClass<SalaryView>(std::string& errorMessage, std::string filter)
	{
		std::vector<SalaryView> vecForSalary;
		std::vector<DataLayer::salariesViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetSalaries(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetSalaries(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForSalary.push_back(SalaryView(data));
			}
		}
		return vecForSalary;
	}

	template<>
	std::vector<SalaryType> OrmasBL::GetAllDataForClass<SalaryType>(std::string& errorMessage, std::string filter)
	{
		std::vector<SalaryType> vecForSalaryType;
		std::vector<DataLayer::salaryTypeCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetSalaryType(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetSalaryType(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForSalaryType.push_back(SalaryType(data));
			}
		}
		return vecForSalaryType;
	}

	template<>
	std::vector<Status> OrmasBL::GetAllDataForClass<Status>(std::string& errorMessage, std::string filter)
	{
		std::vector<Status> vecForStatus;
		std::vector<DataLayer::statusCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetStatus(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetStatus(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForStatus.push_back(Status(data));
			}
		}
		return vecForStatus;
	}

	template<>
	std::vector<UserView> OrmasBL::GetAllDataForClass<UserView>(std::string& errorMessage, std::string filter)
	{
		std::vector<UserView> vecForUser;
		std::vector<DataLayer::usersViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetUsers(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetUsers(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForUser.push_back(UserView(data));
			}
		}
		return vecForUser;
	}
	
	template<>
	std::vector<WriteOffView> OrmasBL::GetAllDataForClass<WriteOffView>(std::string& errorMessage, std::string filter)
	{
		std::vector<WriteOffView> vecForWriteOff;
		std::vector<DataLayer::writeOffsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetWriteOffs(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetWriteOffs(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForWriteOff.push_back(WriteOffView(data));
			}
		}
		return vecForWriteOff;
	}

	template<>
	std::vector<WriteOffListView> OrmasBL::GetAllDataForClass<WriteOffListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<WriteOffListView> vecForWriteOffList;
		std::vector<DataLayer::writeOffListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetWriteOffList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetWriteOffList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForWriteOffList.push_back(WriteOffListView(data));
			}
		}
		return vecForWriteOffList;
	}

	/// \brief	Creates the access.///
	///
	/// \param [in,out] access			If non-null, the access.
	/// \param [in,out] errorMessage	Message describing the error.
	///
	/// \return	true if it succeeds, false if it fails.
	
	bool OrmasBL::CreateAccess(BusinessLayer::Access* access, std::string& errorMessage)
	{
		try
		{
			if (0 != access->GetRoleID() && 0 != access->GetAccessItemID())
			{
				return access->CreateAccess(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Access item or role must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateAccess(BusinessLayer::Access* access, std::string& errorMessage)
	{
		try
		{
			if (0 != access->GetRoleID() && 0 != access->GetAccessItemID())
			{
				return access->UpdateAccess(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Access item or role must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteAccess(BusinessLayer::Access* access, std::string& errorMessage)
	{
		try
		{
			if (0 != access->GetID())
			{
				return access->DeleteAccess(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Access ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
	
	bool OrmasBL::CreateAccessItem(BusinessLayer::AccessItem* accessItem, std::string& errorMessage)
	{
		try
		{
			if (!accessItem->GetNameEng().empty() && !accessItem->GetNameRu().empty() && !accessItem->GetDivision().empty())
			{
				return accessItem->CreateAccessItem(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! English item name or Russiam item name also division must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateAccessItem(BusinessLayer::AccessItem* accessItem, std::string& errorMessage)
	{
		try
		{
			if (!accessItem->GetNameEng().empty() && !accessItem->GetNameRu().empty() && !accessItem->GetDivision().empty())
			{
				return accessItem->UpdateAccessItem(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! English item name or Russiam item name also division must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteAccessItem(BusinessLayer::AccessItem* accessItem, std::string& errorMessage)
	{
		try
		{
			if (0 != accessItem->GetID())
			{
				return accessItem->DeleteAccessItem(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Access item ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateBalance(BusinessLayer::Balance* balance, std::string& errorMessage)
	{
		try
		{
			if (0 != balance->GetUserID() && 0 != balance->GetCurrencyID())
			{
				return balance->CreateBalance(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, currency and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateBalance(BusinessLayer::Balance* balance, std::string& errorMessage)
	{
		try
		{
			if (0 != balance->GetUserID() && 0 != balance->GetCurrencyID())
			{
				return balance->UpdateBalance(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, currency and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteBalance(BusinessLayer::Balance* balance, std::string& errorMessage)
	{
		try
		{
			if (0 != balance->GetID())
			{
				return balance->DeleteBalance(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Balance ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateClient(BusinessLayer::Client* client, std::string& errorMessage)
	{
		try
		{
			if (!client->GetName().empty() && !client->GetSurname().empty() && !client->GetPhone().empty()
				&& !client->GetAddress().empty() && !client->GetPassword().empty() && 0 != client->GetRoleID() && !client->GetFirm().empty()
				&& !client->GetFirmNumber().empty() && 0 != client->GetLocationID())
			{
				return client->CreateClient(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateClient(BusinessLayer::Client* client, std::string& errorMessage)
	{
		try
		{
			if (!client->GetName().empty() && !client->GetSurname().empty() && !client->GetPhone().empty()
				&& !client->GetAddress().empty() && !client->GetPassword().empty() && 0 != client->GetRoleID() && !client->GetFirm().empty()
				&& !client->GetFirmNumber().empty() && 0 != client->GetLocationID())
			{
				return client->UpdateClient(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteClient(BusinessLayer::Client* client, std::string& errorMessage)
	{
		try
		{
			if (0 != client->GetID())
			{
				return client->DeleteClient(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Client ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	/// \brief	Creates a company. Creation section
	///
	/// \param [in,out] company			If non-null, the company.
	/// \param [in,out] errorMessage	Message describing the error.
	///
	/// \return	true if it succeeds, false if it fails.

	bool OrmasBL::CreateCompany(BusinessLayer::Company* company, std::string& errorMessage)
	{
		try
		{
			if (!company->GetName().empty() && !company->GetAddress().empty() && !company->GetPhone().empty())
			{
				return company->CreateCompany(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company name, address and phone must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateCompany(BusinessLayer::Company* company, std::string& errorMessage)
	{
		try
		{
			if (!company->GetName().empty() && !company->GetAddress().empty() && !company->GetPhone().empty())
			{
				return company->UpdateCompany(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company name, address and phone must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteCompany(BusinessLayer::Company* company, std::string& errorMessage)
	{
		try
		{
			if (0 != company->GetID())
			{
				return company->DeleteCompany(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateCurrency(BusinessLayer::Currency* currency, std::string& errorMessage)
	{
		try
		{
			if (0 != currency->GetCode() && !currency->GetName().empty() && !currency->GetShortName().empty() && 0 != currency->GetUnit())
			{
				return currency->CreateCurrency(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Currency code, name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateCurrency(BusinessLayer::Currency* currency, std::string& errorMessage)
	{
		try
		{
			if (0 != currency->GetCode() && !currency->GetName().empty() && !currency->GetShortName().empty() && 0 != currency->GetUnit())
			{
				return currency->UpdateCurrency(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Currency code, name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteCurrency(BusinessLayer::Currency* currency, std::string& errorMessage)
	{
		try
		{
			if (0 != currency->GetID())
			{
				return currency->DeleteCurrency(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Currency ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
    
	bool OrmasBL::CreateEmployee(BusinessLayer::Employee* employee, std::string& errorMessage)
	{
		try
		{
			if (!employee->GetName().empty() && !employee->GetSurname().empty() && !employee->GetPhone().empty()
				&& !employee->GetAddress().empty() && !employee->GetPassword().empty() && 0 != employee->GetRoleID() 
				&& !employee->GetBirthDate().empty() && !employee->GetHireDate().empty() && 0 != employee->GetPositionID())
			{
				return employee->CreateEmployee(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateEmployee(BusinessLayer::Employee* employee, std::string& errorMessage)
	{
		try
		{
			if (!employee->GetName().empty() && !employee->GetSurname().empty() && !employee->GetPhone().empty()
				&& !employee->GetAddress().empty() && !employee->GetPassword().empty() && 0 != employee->GetRoleID()
				&& !employee->GetBirthDate().empty() && !employee->GetHireDate().empty() && 0 != employee->GetPositionID())
			{
				return employee->UpdateEmployee(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteEmployee(BusinessLayer::Employee* employee, std::string& errorMessage)
	{
		try
		{
			if (0 != employee->GetID())
			{
				return employee->DeleteEmployee(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Employee ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateLocation(BusinessLayer::Location* location, std::string& errorMessage)
	{
		try
		{
			if (!location->GetCountryName().empty() && !location->GetCountryCode().empty() && !location->GetRegionName().empty()
				&& !location->GetCityName().empty())
			{
				return location->CreateLocation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Location code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateLocation(BusinessLayer::Location* location, std::string& errorMessage)
	{
		try
		{
			if (!location->GetCountryName().empty() && !location->GetCountryCode().empty() && !location->GetRegionName().empty()
				&& !location->GetCityName().empty())
			{
				return location->UpdateLocation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Location code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteLocation(BusinessLayer::Location* location, std::string& errorMessage)
	{
		try
		{
			if (0 != location->GetID())
			{
				return location->DeleteLocation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Location ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateMeasure(BusinessLayer::Measure* measure, std::string& errorMessage)
	{
		try
		{
			if (!measure->GetName().empty() && !measure->GetShortName().empty() && 0 != measure->GetUnit())
			{
				return measure->CreateMeasure(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Measure name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateMeasure(BusinessLayer::Measure* measure, std::string& errorMessage)
	{
		try
		{
			if (!measure->GetName().empty() && !measure->GetShortName().empty() && 0 != measure->GetUnit())
			{
				return measure->UpdateMeasure(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Measure name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteMeasure(BusinessLayer::Measure* measure, std::string& errorMessage)
	{
		try
		{
			if (0 != measure->GetID())
			{
				return measure->DeleteMeasure(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Measure ID is 0. Some thing goes wrong!";
			}			
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider."; 
		}
		return false;
	}

	bool OrmasBL::CreateOrder(BusinessLayer::Order* order, std::string& errorMessage)
	{
		try
		{
			if (!order->GetDate().empty() && 0 != order->GetClientID() && 0 != order->GetCount()
				&& 0 != order->GetSum() && 0 != order->GetStatusID() && 0 != order->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, order->GetCurrencyID(), errorMessage))
				{
					roundSum = round(order->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				order->SetSum(roundSum);
				return order->CreateOrder(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateOrder(BusinessLayer::Order* order, std::string& errorMessage)
	{
		try
		{
			if (!order->GetDate().empty() && 0 != order->GetClientID() && 0 != order->GetCount()
				&& 0 != order->GetSum() && 0 != order->GetStatusID() && 0 != order->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, order->GetCurrencyID(), errorMessage))
				{
					roundSum = round(order->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				order->SetSum(roundSum);
				return order->UpdateOrder(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteOrder(BusinessLayer::Order* order, std::string& errorMessage)
	{
		try
		{
			if (0 != order->GetID())
			{
				return order->DeleteOrder(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Order ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}


	bool OrmasBL::CreateOrderList(BusinessLayer::OrderList* orderList, std::string& errorMessage)
	{
		try
		{
			if (0 != orderList->GetOrderID() && 0 != orderList->GetProductID()
				&& 0 != orderList->GetCount() && 0 != orderList->GetSum() && 0 != orderList->GetStatusID()
				&& 0 != orderList->GetCurrencyID())
			{
				return orderList->CreateOrderList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateOrderList(BusinessLayer::OrderList* orderList, std::string& errorMessage)
	{
		try
		{
			if (0 != orderList->GetOrderID() && 0 != orderList->GetProductID()
				&& 0 != orderList->GetCount() && 0 != orderList->GetSum() && 0 != orderList->GetStatusID()
				&& 0 != orderList->GetCurrencyID())
			{
				return orderList->UpdateOrderList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteOrderList(BusinessLayer::OrderList* orderList, std::string& errorMessage)
	{
		try
		{
			if (0 != orderList->GetID())
			{
				return orderList->DeleteOrderList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Order list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreatePayment(BusinessLayer::Payment* payment, std::string& errorMessage)
	{
		try
		{
			if (0 != payment->GetUserID() && 0.0 != payment->GetValue() && 0 != payment->GetCurrencyID() && !payment->GetDate().empty())
			{
				return payment->CreatePayment(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdatePayment(BusinessLayer::Payment* payment, std::string& errorMessage)
	{
		try
		{
			if (0 != payment->GetUserID() && 0.0 != payment->GetValue() && 0 != payment->GetCurrencyID() && !payment->GetDate().empty())
			{
				return payment->UpdatePayment(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeletePayment(BusinessLayer::Payment* payment, std::string& errorMessage)
	{
		try
		{
			if (0 != payment->GetID())
			{
				return payment->DeletePayment(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Payment ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreatePhoto(BusinessLayer::Photo* photo, std::string& errorMessage)
	{
		try
		{
			if ((0 != photo->GetUserID() || 0 != photo->GetProductID()) && !photo->GetSource().empty())
			{
				return photo->CreatePhoto(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, product and source must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdatePhoto(BusinessLayer::Photo* photo, std::string& errorMessage)
	{
		try
		{
			if ((0 != photo->GetUserID() || 0 != photo->GetProductID()) && !photo->GetSource().empty())
			{
				return photo->UpdatePhoto(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, product and source must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeletePhoto(BusinessLayer::Photo* photo, std::string& errorMessage)
	{
		try
		{
			if (0 != photo->GetID())
			{
				return photo->DeletePhoto(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Photo ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreatePosition(BusinessLayer::Position* position, std::string& errorMessage)
	{
		try
		{
			if (!position->GetName().empty())
			{
				return position->CreatePosition(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdatePosition(BusinessLayer::Position* position, std::string& errorMessage)
	{
		try
		{
			if (!position->GetName().empty())
			{
				return position->UpdatePosition(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeletePosition(BusinessLayer::Position* position, std::string& errorMessage)
	{
		try
		{
			if (0 != position->GetID())
			{
				return position->DeletePosition(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Position ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreatePrice(BusinessLayer::Price* price, std::string& errorMessage)
	{
		try
		{
			if (0 != price->GetProductID() && 0.0 != price->GetValue() && 0 != price->GetCurrencyID() && !price->GetDate().empty())
			{
				return price->CreatePrice(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product , currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdatePrice(BusinessLayer::Price* price, std::string& errorMessage)
	{
		try
		{
			if (0 != price->GetProductID() && 0.0 != price->GetValue() && 0 != price->GetCurrencyID() && !price->GetDate().empty())
			{
				return price->UpdatePrice(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeletePrice(BusinessLayer::Price* price, std::string& errorMessage)
	{
		try
		{
			if (0 != price->GetID())
			{
				return price->DeletePrice(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Price ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateProduct(BusinessLayer::Product* product, std::string& errorMessage)
	{
		try
		{
			if (0 != product->GetCompanyID() && !product->GetName().empty() && 0 != product->GetVolume() && 0 != product->GetMeasureID()
				&& 0 != product->GetPrice() && 0 != product->GetProductTypeID() && 0 != product->GetShelfLife() && 0 != product->GetCurrencyID())
			{
				double roundPrice = 0;
				double roundVolume = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, product->GetCurrencyID(), errorMessage))
				{
					roundPrice = round(product->GetPrice() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				Measure *mea = new Measure();
				if (mea->GetMeasureByID(ormasDal, product->GetMeasureID(), errorMessage))
				{
					roundVolume = round(product->GetVolume() * mea->GetUnit()) / mea->GetUnit();
				}
				else
				{
					return false;
				}
				delete mea;
				product->SetVolume(roundVolume);
				product->SetPrice(roundPrice);
				return product->CreateProduct(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProduct(BusinessLayer::Product* product, std::string& errorMessage)
	{
		try
		{
			if (0 != product->GetCompanyID() && !product->GetName().empty() && 0 != product->GetVolume() && 0 != product->GetMeasureID()
				&& 0 != product->GetPrice() && 0 != product->GetProductTypeID() && 0 != product->GetShelfLife() && 0 != product->GetCurrencyID())
			{
				double roundPrice = 0;
				double roundVolume = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, product->GetCurrencyID(), errorMessage))
				{
					roundPrice = round(product->GetPrice() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				Measure *mea = new Measure();
				if (mea->GetMeasureByID(ormasDal, product->GetMeasureID(), errorMessage))
				{
					roundVolume = round(product->GetVolume() * mea->GetUnit()) / mea->GetUnit();
				}
				else
				{
					return false;
				}
				delete mea;
				product->SetVolume(roundVolume);
				product->SetPrice(roundPrice);
				return product->UpdateProduct(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteProduct(BusinessLayer::Product* product, std::string& errorMessage)
	{
		try
		{
			if (0 != product->GetID())
			{
				return product->DeleteProduct(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateProduction(BusinessLayer::Production* production, std::string& errorMessage)
	{
		try
		{
			if (!production->GetProductionDate().empty() && !production->GetExpiryDate().empty() && !production->GetSessionStart().empty()
				&& !production->GetSessionEnd().empty())
			{
				return production->CreateProduction(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProduction(BusinessLayer::Production* production, std::string& errorMessage)
	{
		try
		{
			if (!production->GetProductionDate().empty() && !production->GetExpiryDate().empty() && !production->GetSessionStart().empty()
				&& !production->GetSessionEnd().empty())
			{
				return production->UpdateProduction(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteProduction(BusinessLayer::Production* production, std::string& errorMessage)
	{
		try
		{
			if (0 != production->GetID())
			{
				return production->DeleteProduction(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Production ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;

	}

	bool OrmasBL::CreateProductionList(BusinessLayer::ProductionList* productionList, std::string& errorMessage)
	{
		try
		{
			if (0 != productionList->GetProductionID() && 0 != productionList->GetProductID()
				&& 0 != productionList->GetCount() && 0 != productionList->GetSum() && 0 != productionList->GetStatusID()
				&& 0 != productionList->GetCurrencyID())
			{
				return productionList->CreateProductionList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProductionList(BusinessLayer::ProductionList* productionList, std::string& errorMessage)
	{
		try
		{
			if (0 != productionList->GetProductionID() && 0 != productionList->GetProductID()
				&& 0 != productionList->GetCount() && 0 != productionList->GetSum() && 0 != productionList->GetStatusID()
				&& 0 != productionList->GetCurrencyID())
			{
				return productionList->UpdateProductionList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteProductionList(BusinessLayer::ProductionList* productionList, std::string& errorMessage)
	{
		try
		{
			if (0 != productionList->GetID())
			{
				return productionList->DeleteProductionList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Production list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateProductType(BusinessLayer::ProductType* pType, std::string& errorMessage)
	{
		try
		{
			if (!pType->GetName().empty() && !pType->GetShortName().empty())
			{
				return pType->CreateProductType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product type name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProductType(BusinessLayer::ProductType* pType, std::string& errorMessage)
	{
		try
		{
			if (!pType->GetName().empty() && !pType->GetShortName().empty())
			{
				return pType->UpdateProductType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product type name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteProductType(BusinessLayer::ProductType* pType, std::string& errorMessage)
	{
		try
		{
			if (0 != pType->GetID())
			{
				return pType->DeleteProductType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product type ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateRelation(BusinessLayer::Relation* relation, std::string& errorMessage)
	{
		try
		{
			if (0 != relation->GetUser1ID() && 0.0 != relation->GetUser2ID() && 0 != relation->GetRelationTypeID())
			{
				return relation->CreateRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User 1, user 2 and relation type must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateRelation(BusinessLayer::Relation* relation, std::string& errorMessage)
	{
		try
		{
			if (0 != relation->GetUser1ID() && 0.0 != relation->GetUser2ID() && 0 != relation->GetRelationTypeID())
			{
				return relation->UpdateRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User 1, user 2 and relation type must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteRelation(BusinessLayer::Relation* relation, std::string& errorMessage)
	{
		try
		{
			if (0 != relation->GetID())
			{
				return relation->DeleteRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Relation ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateRelationType(BusinessLayer::RelationType* relationType, std::string& errorMessage)
	{
		try
		{
			if (!relationType->GetName().empty())
			{
				return relationType->CreateRelationType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Relation type name must not be empty. Please fill up it!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateRelationType(BusinessLayer::RelationType* relationType, std::string& errorMessage)
	{
		try
		{
			if (!relationType->GetName().empty())
			{
				return relationType->UpdateRelationType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Relation type name must not be empty. Please fill up it!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteRelationType(BusinessLayer::RelationType* relationType, std::string& errorMessage)
	{
		try
		{
			if (0 != relationType->GetID())
			{
				return relationType->DeleteRelationType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Relation type ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateReturn(BusinessLayer::Return* ret, std::string& errorMessage)
	{
		try
		{
			if (!ret->GetDate().empty() && 0 != ret->GetClientID() && 0 != ret->GetCount()
				&& 0 != ret->GetSum() && 0 != ret->GetStatusID() && 0 != ret->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, ret->GetCurrencyID(), errorMessage))
				{
					roundSum = round(ret->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				ret->SetSum(roundSum);
				return ret->CreateReturn(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateReturn(BusinessLayer::Return* ret, std::string& errorMessage)
	{
		try
		{
			if (!ret->GetDate().empty() && 0 != ret->GetClientID() && 0 != ret->GetCount()
				&& 0 != ret->GetSum() && 0 != ret->GetStatusID() && 0 != ret->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, ret->GetCurrencyID(), errorMessage))
				{
					roundSum = round(ret->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				ret->SetSum(roundSum);
				return ret->UpdateReturn(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteReturn(BusinessLayer::Return* ret, std::string& errorMessage)
	{
		try
		{
			if (0 != ret->GetID())
			{
				return ret->DeleteReturn(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Return ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
	
	bool OrmasBL::CreateReturnList(BusinessLayer::ReturnList* returnList, std::string& errorMessage)
	{
		try
		{
			if (0 != returnList->GetReturnID() && 0 != returnList->GetProductID()
				&& 0 != returnList->GetCount() && 0 != returnList->GetSum() && 0 != returnList->GetStatusID()
				&& 0 != returnList->GetCurrencyID())
			{
				return returnList->CreateReturnList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateReturnList(BusinessLayer::ReturnList* returnList, std::string& errorMessage)
	{
		try
		{
			if (0 != returnList->GetReturnID() && 0 != returnList->GetProductID()
				&& 0 != returnList->GetCount() && 0 != returnList->GetSum() && 0 != returnList->GetStatusID()
				&& 0 != returnList->GetCurrencyID())
			{
				return returnList->UpdateReturnList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteReturnList(BusinessLayer::ReturnList* returnList, std::string& errorMessage)
	{
		try
		{
			if (0 != returnList->GetID())
			{
				return returnList->DeleteReturnList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Return list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateRole(BusinessLayer::Role* role, std::string& errorMessage)
	{
		try
		{
			if (!role->GetCode().empty() && !role->GetName().empty())
			{
				return role->CreateRole(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Role name and code must not be empty. Please fill up it!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateRole(BusinessLayer::Role* role, std::string& errorMessage)
	{
		try
		{
			if (!role->GetCode().empty() && !role->GetName().empty())
			{
				return role->UpdateRole(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Role name and code must not be empty. Please fill up it!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteRole(BusinessLayer::Role* role, std::string& errorMessage)
	{
		try
		{
			if (0 != role->GetID())
			{
				return role->DeleteRole(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Role ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateSalary(BusinessLayer::Salary* salary, std::string& errorMessage)
	{
		try
		{
			if (0 != salary->GetUserID() && 0.0 != salary->GetValue() && 0 != salary->GetCurrencyID() && 0 != salary->GetSalaryTypeID()
				&& !salary->GetDate().empty())
			{
				return salary->CreateSalary(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product , currency, date, salary type and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateSalary(BusinessLayer::Salary* salary, std::string& errorMessage)
	{
		try
		{
			if (0 != salary->GetUserID() && 0.0 != salary->GetValue() && 0 != salary->GetCurrencyID() && 0 != salary->GetSalaryTypeID()
				&& !salary->GetDate().empty())
			{
				return salary->UpdateSalary(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product , currency, date, salary type and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteSalary(BusinessLayer::Salary* salary, std::string& errorMessage)
	{
		try
		{
			if (0 != salary->GetID())
			{
				return salary->DeleteSalary(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Salary ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateSalaryType(BusinessLayer::SalaryType* salaryType, std::string& errorMessage)
	{
		try
		{
			if (!salaryType->GetCode().empty() && !salaryType->GetName().empty())
			{
				return salaryType->CreateSalaryType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Salary type code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateSalaryType(BusinessLayer::SalaryType* salaryType, std::string& errorMessage)
	{
		try
		{
			if (!salaryType->GetCode().empty() && !salaryType->GetName().empty())
			{
				return salaryType->UpdateSalaryType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Salary type code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteSalaryType(BusinessLayer::SalaryType* salaryType, std::string& errorMessage)
	{
		try
		{
			if (0 != salaryType->GetID())
			{
				return salaryType->DeleteSalaryType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Salary type ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}


	bool OrmasBL::CreateStatus(BusinessLayer::Status* status, std::string& errorMessage)
	{
		try
		{
			if (!status->GetCode().empty() && !status->GetName().empty())
			{
				return status->CreateStatus(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Status code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateStatus(BusinessLayer::Status* status, std::string& errorMessage)
	{
		try
		{
			if (!status->GetCode().empty() && !status->GetName().empty())
			{
				return status->UpdateStatus(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Status code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteStatus(BusinessLayer::Status* status, std::string& errorMessage)
	{
		try
		{
			if (0 != status->GetID())
			{
				return status->DeleteStatus(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Status ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateUser(BusinessLayer::User* user, std::string& errorMessage)
	{
		try
		{
			if (!user->GetName().empty() && !user->GetSurname().empty() && !user->GetPhone().empty() && !user->GetAddress().empty()
				&& !user->GetPassword().empty() && 0 != user->GetRoleID())
			{
				return user->CreateUser(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateUser(BusinessLayer::User* user, std::string& errorMessage)
	{
		try
		{
			if (!user->GetName().empty() && !user->GetSurname().empty() && !user->GetPhone().empty() && !user->GetAddress().empty()
				&& !user->GetPassword().empty()  && 0 != user->GetRoleID())
			{
				return user->UpdateUser(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteUser(BusinessLayer::User* user, std::string& errorMessage)
	{
		try
		{
			if (0 != user->GetID())
			{
				return user->DeleteUser(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
	
	bool OrmasBL::CreateWriteOff(BusinessLayer::WriteOff* writeOff, std::string& errorMessage)
	{
		try
		{
			if (!writeOff->GetDate().empty() && 0 != writeOff->GetClientID() && 0 != writeOff->GetCount()
				&& 0 != writeOff->GetSum() && 0 != writeOff->GetStatusID() && 0 != writeOff->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, writeOff->GetCurrencyID(), errorMessage))
				{
					roundSum = round(writeOff->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				writeOff->SetSum(roundSum);
				return writeOff->CreateWriteOff(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateWriteOff(BusinessLayer::WriteOff* writeOff, std::string& errorMessage)
	{
		try
		{
			if (!writeOff->GetDate().empty() && 0 != writeOff->GetClientID() && 0 != writeOff->GetCount()
				&& 0 != writeOff->GetSum() && 0 != writeOff->GetStatusID() && 0 != writeOff->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, writeOff->GetCurrencyID(), errorMessage))
				{
					roundSum = round(writeOff->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				writeOff->SetSum(roundSum);
				return writeOff->UpdateWriteOff(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteWriteOff(BusinessLayer::WriteOff* writeOff, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOff->GetID())
			{
				return writeOff->DeleteWriteOff(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Write-off ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateWriteOffList(BusinessLayer::WriteOffList* writeOffList, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOffList->GetWriteOffID() && 0 != writeOffList->GetProductID()
				&& 0 != writeOffList->GetCount() && 0 != writeOffList->GetSum() && 0 != writeOffList->GetStatusID()
				&& 0 != writeOffList->GetCurrencyID())
			{
				return writeOffList->CreateWriteOffList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateWriteOffList(BusinessLayer::WriteOffList* writeOffList, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOffList->GetWriteOffID() && 0 != writeOffList->GetProductID()
				&& 0 != writeOffList->GetCount() && 0 != writeOffList->GetSum() && 0 != writeOffList->GetStatusID()
				&& 0 != writeOffList->GetCurrencyID())
			{
				return writeOffList->UpdateWriteOffList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteWriteOffList(BusinessLayer::WriteOffList* writeOffList, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOffList->GetID())
			{
				return writeOffList->DeleteWriteOffList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Write-off list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
}
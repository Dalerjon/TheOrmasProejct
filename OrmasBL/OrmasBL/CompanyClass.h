#ifndef COMPANYCLASS_H
#define COMPANYCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Company
	{
		int id = 0;
		std::string name;
		std::string address;
		std::string phone;
		std::string comment;
	public:
		Company(){};
		Company(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment) :id(cID),
			name(cName), address(cAddress), phone(cPhone), comment(cComment){};
		Company(DataLayer::companiesCollection);
		~Company(){};
			
		//Company class Accessors
		int GetID();
		std::string GetName();
		std::string GetAddress();
		std::string GetPhone();
		std::string GetComment();
		
		//Company class Mutators
		void SetID(int);
		void SetName(std::string);
		void SetAddress(std::string);
		void SetPhone(std::string);
		void SetComment(std::string);

		// Create, delete and update company
		bool CreateCompany(DataLayer::OrmasDal& ormasDal, std::string cName, std::string cAddress, std::string cPhone, std::string cComment);
		bool DeleteCompany(DataLayer::OrmasDal& ormasDal);
		bool UpdateCompany(DataLayer::OrmasDal& ormasDal, std::string cName, std::string cAddress, std::string cPhone, std::string cComment);
	};
}
#endif //COMPANYCLASS_H
#ifndef COMPANYCLASS_H
#define COMPANYCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Company
	{
		int ID;
		std::string name;
		std::string address;
		std::string phone;
		std::string comment;
	public:
		Company(){};
		Company(int ID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment) :ID(ID),
			name(cName), address(cAddress), phone(cPhone), comment(cComment){};
		Company(DataLayer::companiesCollection);
		~Company(){};
		int CreateCompany(int ID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment){};
		
		//Company class Accessors
		int GetID();
		std::string GetName();
		std::string GetAddress();
		std::string GetPhone();
		std::string GetComment();

		// Please implement Mutators
	};
}
#endif //COMPANYCLASS_H
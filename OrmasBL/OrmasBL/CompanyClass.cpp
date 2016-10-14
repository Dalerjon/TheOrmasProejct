#include "stdafx.h"
#include "CompanyClass.h"

namespace BusinessLayer{

	Company::Company(DataLayer::companiesCollection compCollection)
	{
		ID = std::get<0>(compCollection);
		name = std::get<1>(compCollection);
		address = std::get<2>(compCollection);
		phone = std::get<3>(compCollection);
		comment = std::get<3>(compCollection);
	}
	
	int Company::GetID()
	{
		return ID;
	}

	std::string Company::GetName()
	{
		return name;
	}

	std::string Company::GetAddress()
	{
		return address;
	}

	std::string Company::GetPhone()
	{
		return phone;
	}

	std::string Company::GetComment()
	{
		return comment;
	}
}


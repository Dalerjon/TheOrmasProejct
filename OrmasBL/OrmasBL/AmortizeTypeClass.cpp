#include "stdafx.h"
#include "AmortizeTypeClass.h"
#include <boost/algorithm/string.hpp>

namespace BusinessLayer{
	AmortizeType::AmortizeType(DataLayer::amortizeTypeCollection aCollection)
	{
		id = std::get<0>(aCollection);
		name = std::get<1>(aCollection);
		code = std::get<2>(aCollection);
		percent = std::get<3>(aCollection);
		valueDependsOnSales = std::get<4>(aCollection);
		year = std::get<5>(aCollection);
		coefficient = std::get<6>(aCollection);
	}
	AmortizeType::AmortizeType()
	{
		id = 0;
		name = "";
		code = "";
		percent = 0;
		valueDependsOnSales = 0.0;
		year = 0;
		coefficient = 0.0;
	}

	int AmortizeType::GetID()
	{
		return id;
	}

	std::string AmortizeType::GetName()
	{
		return name;
	}

	std::string AmortizeType::GetCode()
	{
		return code;
	}

	int AmortizeType::GetPercent()
	{
		return percent;
	}

	double AmortizeType::GetValueDependsOnSales()
	{
		return valueDependsOnSales;
	}

	int AmortizeType::GetYear()
	{
		return year;
	}

	double AmortizeType::GetCoefficient()
	{
		return coefficient;
	}

	void AmortizeType::SetID(int aID)
	{
		id = aID;
	}

	void AmortizeType::SetName(std::string aName)
	{
		name = aName;
	}

	void AmortizeType::SetCode(std::string aCode)
	{
		code = aCode;
	}
	
	void AmortizeType::SetPercent(int aPercent)
	{
		percent = aPercent;
	}

	void AmortizeType::SetValueDependsOnSales(double dOnSales)
	{
		valueDependsOnSales = dOnSales;
	}

	void AmortizeType::SetYear(int aYear)
	{
		year = aYear;
	}

	void AmortizeType::SetCoefficient(double aCoef)
	{
		coefficient = aCoef;
	}

	bool AmortizeType::CreateAmortizeType(DataLayer::OrmasDal &ormasDal, std::string aName, std::string aCode, int aPercent, double dOnSales,
		int aYear, double aCoef, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, aCode, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		name = aName;
		code = aCode;
		percent = aPercent;
		valueDependsOnSales = dOnSales;
		year = aYear;
		coefficient = aCoef;
		if (0 != id && ormasDal.CreateAmortizeType(id, name, code, percent, valueDependsOnSales, year, coefficient, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool AmortizeType::CreateAmortizeType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (ormasDal.CreateAmortizeType(id, name, code, percent, valueDependsOnSales, year, coefficient, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool AmortizeType::DeleteAmortizeType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteAmortizeType(id, errorMessage))
		{
			Clear();
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}

	bool AmortizeType::UpdateAmortizeType(DataLayer::OrmasDal &ormasDal, std::string aName, std::string aCode, int aPercent, double dOnSales,
		int aYear, double aCoef, std::string& errorMessage)
	{
		name = aName;
		code = aCode;
		percent = aPercent;
		valueDependsOnSales = dOnSales;
		year = aYear;
		coefficient = aCoef;
		if (0 != id && ormasDal.UpdateAmortizeType(id, name, code, percent, valueDependsOnSales, year, coefficient, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool AmortizeType::UpdateAmortizeType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.UpdateAmortizeType(id, name, code, percent, valueDependsOnSales, year, coefficient, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string AmortizeType::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !name.empty() || !code.empty() || 0 != percent || 0 != valueDependsOnSales || 0 != year || 0 != coefficient)
		{
			return ormasDal.GetFilterForAmortizeType(id, name, code, percent, valueDependsOnSales, year, coefficient);
		}
		return "";
	}

	bool AmortizeType::GetAmortizeTypeByID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage)
	{
		if (aID <= 0)
			return false;
		id = aID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::amortizeTypeCollection> amortizeTypeVector = ormasDal.GetAmortizeType(errorMessage, filter);
		if (0 != amortizeTypeVector.size())
		{
			id = std::get<0>(amortizeTypeVector.at(0));
			name = std::get<1>(amortizeTypeVector.at(0));
			code = std::get<2>(amortizeTypeVector.at(0));
			percent = std::get<3>(amortizeTypeVector.at(0));
			valueDependsOnSales = std::get<4>(amortizeTypeVector.at(0));
			year = std::get<5>(amortizeTypeVector.at(0));
			coefficient = std::get<6>(amortizeTypeVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find Amortize type with this id";
		}
		return false;
	}

	bool AmortizeType::GetAmortizeTypeByCode(DataLayer::OrmasDal& ormasDal, std::string aCode, std::string& errorMessage)
	{
		if (!aCode.empty())
			return false;
		code = aCode;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::amortizeTypeCollection> amortizeTypeVector = ormasDal.GetAmortizeType(errorMessage, filter);
		if (0 != amortizeTypeVector.size())
		{
			id = std::get<0>(amortizeTypeVector.at(0));
			name = std::get<1>(amortizeTypeVector.at(0));
			code = std::get<2>(amortizeTypeVector.at(0));
			percent = std::get<3>(amortizeTypeVector.at(0));
			valueDependsOnSales = std::get<4>(amortizeTypeVector.at(0));
			year = std::get<5>(amortizeTypeVector.at(0));
			coefficient = std::get<6>(amortizeTypeVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find Amortize type with this id";
		}
		return false;
	}

	bool AmortizeType::IsEmpty()
	{
		if (0 == id && name.empty() && code.empty() && 0 == percent && 0 == valueDependsOnSales && 0 == year && 0 == coefficient)
			return true;
		return false;
	}

	void AmortizeType::Clear()
	{
		id = 0;
		name = "";
		code="";
		percent = 0;
		valueDependsOnSales = 0.0;
		year = 0;
		coefficient = 0.0;
	}

	bool AmortizeType::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string aCode, std::string& errorMessage)
	{
		AmortizeType amortizeType;
		amortizeType.Clear();
		errorMessage.clear();
		amortizeType.SetCode(aCode);
		std::string filter = amortizeType.GenerateFilter(ormasDal);
		std::vector<DataLayer::amortizeTypeCollection> amortizeTypeVector = ormasDal.GetAmortizeType(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == amortizeTypeVector.size())
		{
			return false;
		}
		errorMessage = "Amortize type with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool AmortizeType::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		AmortizeType amortizeType;
		amortizeType.Clear();
		errorMessage.clear();
		amortizeType.SetCode(code);
		std::string filter = amortizeType.GenerateFilter(ormasDal);
		std::vector<DataLayer::amortizeTypeCollection> amortizeTypeVector = ormasDal.GetAmortizeType(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == amortizeTypeVector.size())
		{
			return false;
		}
		errorMessage = "Amortize type with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

}
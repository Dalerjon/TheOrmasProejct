#ifndef AMORTIZETYPECLASS_H
#define AMORTIZETYPECLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class AmortizeType{
	protected:
		int id = 0;
		std::string name = "";
		std::string code = "";
		int percent = 0;
		double valueDependsOnSales = 0.0;
		int year = 0;
		double coefficient = 0.0;
	public:
		AmortizeType();
		AmortizeType(int aID, std::string tName, std::string tCode, int tPercent, double vDepOnSales, int aYear, double aCoef) :id(aID), 
			name(tName), code(tCode), percent(tPercent), valueDependsOnSales(vDepOnSales), year(aYear), coefficient(aCoef){};
		AmortizeType(DataLayer::amortizeTypeCollection);
		~AmortizeType(){};

		std::string errorMessage = "";

		//AmortizeType class Accessors
		int GetID();
		std::string GetName();
		std::string GetCode();
		int GetPercent();
		double GetValueDependsOnSales();
		int GetYear();
		double GetCoefficient();

		//AmortizeType class Mutators
		void SetID(int);
		void SetName(std::string);
		void SetCode(std::string);
		void SetPercent(int);
		void SetValueDependsOnSales(double);
		void SetYear(int);
		void SetCoefficient(double);

		// Create, delete and update AmortizeType
		bool CreateAmortizeType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateAmortizeType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteAmortizeType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateAmortizeType(DataLayer::OrmasDal &ormasDal, std::string aName, std::string aCode, int aPercent, double dOnSales,
			int aYear, double aCoef, std::string& errorMessage);
		bool UpdateAmortizeType(DataLayer::OrmasDal &ormasDal, std::string aName, std::string aCode, int aPercent, double dOnSales,
			int aYear, double aCoef, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetAmortizeTypeByID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage);
		bool GetAmortizeTypeByCode(DataLayer::OrmasDal& ormasDal, std::string aCode, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string aCode, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //AmortizeTypeCLASS_H
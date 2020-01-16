#ifndef AMORTIZETYPECLASS_H
#define AMORTIZETYPECLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class AmortizeType{
	protected:
		int id = 0;
		std::string name = "";
		std::string code = "";
	public:
		AmortizeType();
		AmortizeType(int aID, std::string tName, std::string tCode) :id(aID), 
			name(tName), code(tCode){};
		AmortizeType(DataLayer::amortizeTypeCollection);
		~AmortizeType(){};

		std::string errorMessage = "";

		//AmortizeType class Accessors
		int GetID();
		std::string GetName();
		std::string GetCode();

		//AmortizeType class Mutators
		void SetID(int);
		void SetName(std::string);
		void SetCode(std::string);

		// Create, delete and update AmortizeType
		bool CreateAmortizeType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateAmortizeType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteAmortizeType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateAmortizeType(DataLayer::OrmasDal &ormasDal, std::string aName, std::string aCode, std::string& errorMessage);
		bool UpdateAmortizeType(DataLayer::OrmasDal &ormasDal, std::string aName, std::string aCode, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetAmortizeTypeByID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage);
		bool GetAmortizeTypeByCode(DataLayer::OrmasDal& ormasDal, std::string aCode, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		void TrimStrings(std::string&, std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string aCode, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //AmortizeTypeCLASS_H
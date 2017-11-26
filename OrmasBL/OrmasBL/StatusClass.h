#ifndef STATUSCLASS_H
#define STATUSCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class Status
	{
		int id = 0;
		std::string code = "";
		std::string name = "";
		std::string comment = "";
	public:
		Status(int sID, std::string sCode, std::string sName, std::string comment):id(sID), code(sCode),
			name(sName), comment(comment){};
		Status(DataLayer::statusCollection);
		Status(){};
		~Status(){};

		//Status class Accessors
		int GetID();
		std::string GetCode();
		std::string GetName();
		std::string GetComment();

		//Mutators
		void SetID(int);
		void SetCode(std::string);
		void SetName(std::string);
		void SetComment(std::string);
		
		//Create, delete, update methods
		bool CreateStatus(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateStatus(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteStatus(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateStatus(DataLayer::OrmasDal& ormasDal, std::string sCode, std::string sName, std::string sComment, 
			std::string& errorMessage);
		bool UpdateStatus(DataLayer::OrmasDal& ormasDal, std::string sCode, std::string sName, std::string sComment, 
			std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetStatusByID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
		static std::map<std::string, int> GetStatusesAsMap(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	private:
		void TrimStrings(std::string&, std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string sCode, std::string sName, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif // STATUSCLASS_H
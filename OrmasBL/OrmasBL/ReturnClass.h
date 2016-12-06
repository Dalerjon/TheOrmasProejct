#ifndef RETURNCLASS_H
#define RETURNCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Return
	{
	protected:
		int id = 0;
		int userID = 0;
		std::string date = "";
		int workerID = 0;
	public:
		Return(int rID, int uID, std::string rDate, int wID) :id(rID), userID(uID),
			date(rDate), workerID(wID){};
		Return(DataLayer::returnsCollection);
		Return(){};
		~Return(){};
		
		//Return class Accessors
		int GetID();
		int GetUserID();
		std::string GetDate();
		int GetWorkerID();
		
		//Please implement Mutators
		void SetID(int);
		void SetUserID(int);
		void SetDate(std::string);
		void SetWorkerID(int);
		
		//Create, delete, update methods
		bool CreateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage){};
		bool UpdateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage){};
		bool DeleteReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string& errorMessage);
		bool UpdateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string& errorMessage);
	};
}
#endif //RETURNCLASS_H
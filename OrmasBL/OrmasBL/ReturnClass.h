#ifndef RETURNCLASS_H
#define RETURNCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Return
	{
		int id=0;
		int userID;
		std::string date;
		int workerID;
		std::string firmName;
	public:
		Return(int rID, int uID, std::string rDate, int wID, std::string fName) :id(rID), userID(uID),
			date(rDate), workerID(wID), firmName(fName){};
		Return(DataLayer::returnsCollection);
		Return(){};
		~Return(){};
		
		//Return class Accessors
		int GetID();
		int GetUserID();
		std::string GetDate();
		int GetWorkerID();
		std::string GetFirmName();

		//Please implement Mutators
		void SetID(int);
		void SetUserID(int);
		void SetDate(std::string);
		void SetWorkerID(int);
		void SetFirmName(std::string);
		
		//Create, delete, update methods
		bool CreateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string fName);
		bool DeleteReturn(DataLayer::OrmasDal& ormasDal);
		bool UpdateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string fName);
	};
}
#endif //RETURNCLASS_H
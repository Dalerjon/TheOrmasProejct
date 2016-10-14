#ifndef RETURNCLASS_H
#define RETURNCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Return
	{
		int ID;
		int userID;
		std::string returnDate;
		int workerID;
		std::string firmName;
	public:
		Return(int rID, int uID, std::string rDate, int wID, std::string fName) :ID(rID), userID(uID),
			returnDate(rDate), workerID(wID), firmName(fName){};
		Return(DataLayer::returnsCollection);
		Return(){};
		~Return(){};
		int CreateReturn(int rID, int uID, std::string rDate, int wID, std::string fName){};

		//Return class Accessors
		int GetID();
		int GetUserID();
		std::string GetReturnDate();
		int GetWorkerID();
		std::string GetFirmName();

		//Please implement Mutators
	};
}
#endif //RETURNCLASS_H
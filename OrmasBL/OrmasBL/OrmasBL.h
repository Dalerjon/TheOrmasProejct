#ifndef ORMASBL_H
#define ORMASBL_H

#include "AllClassHeaders.h"

namespace BusinessLayer
{
	class OrmasBL
	{
		DataLayer::OrmasDal ormasDal;
	public:
		OrmasBL();
		OrmasBL(const OrmasBL &oBL);
		~OrmasBL();
		
		OrmasBL& operator=(const OrmasBL& ob)
		{
			if (this == &ob)
			{
				return *this;
			}
			else
			{
				ormasDal = ob.ormasDal;
			}
			return *this;
		}

		void setDBParams(std::string dbname, std::string username, std::string password, std::string host, int port);
		template<class T>
		std::vector<T> getAllDataForClass();
		
	};
}
#endif
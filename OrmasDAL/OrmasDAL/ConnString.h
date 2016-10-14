#ifndef CONNSTRING_H
#define CONNSTRING_H
#include <string>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>
#include <vector>

namespace DataLayer{
	class ConnectionString
	{
	public:
		ConnectionString();
		ConnectionString(std::string dbname, std::string username, std::string password, std::string host, int port);
		ConnectionString(const ConnectionString&);
		~ConnectionString();
		std::string GetConString();
		void InitFromConfigFile(std::string path);
		void SetDBParams(std::string dbname, std::string username, std::string password, std::string host, int port);
		
		//overloaded operators
		ConnectionString& operator=(const ConnectionString& cs)
		{
			if (this == &cs)
			{
				return *this;
			}
			else
			{
				dbname = cs.dbname;
				username = cs.username;
				password = cs.password;
				host = cs.host;
				port = cs.port;
			}
			return *this;
		}
	private:
		std::string dbname;
		std::string username;
		std::string password;
		std::string host;
		int port;
	};
}
#endif //CONNSTRING_H
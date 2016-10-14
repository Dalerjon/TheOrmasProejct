#include "stdafx.h"
#include "ConnString.h"

namespace DataLayer{
	ConnectionString::ConnectionString()
	{
	}
	ConnectionString::~ConnectionString()
	{
	}
	ConnectionString::ConnectionString(const ConnectionString& conStr)
	{
		dbname = conStr.dbname;
		username = conStr.username;
		password = conStr.password;
		host = conStr.host;
		port = conStr.port;
	}

	ConnectionString::ConnectionString(std::string dbname, std::string username, std::string password, std::string host, int port)
	{
		this->dbname = dbname;
		this->username = username;
		this->password = password;
		this->host = host;
		this->port = port;
	}
	

	std::string ConnectionString::GetConString()
	{
		return "dbname =" + dbname + " user =" + username + " password =" + password + " hostaddr =" + host + " port =" + std::to_string(port);
	}

	void ConnectionString::InitFromConfigFile(std::string path)
	{
		// config file contains DB parameters in CSV format
		try{
			boost::filesystem::path path = path;
			if (boost::filesystem::exists(path))
			{
				if (boost::filesystem::is_regular_file(path))
				{

					boost::filesystem::ifstream is(path, std::ios_base::in);
					std::string line;
					std::getline(is, line);
					if (!line.empty())
					{
						std::vector<std::string> vec;
						boost::tokenizer<boost::escaped_list_separator<char> > tk(
							line, boost::escaped_list_separator<char>('\\', ',', '\"'));
						for (boost::tokenizer<boost::escaped_list_separator<char> >::iterator i(tk.begin());
							i != tk.end(); ++i)
						{
							vec.push_back(*i);
						}
						dbname = vec.at(0);
						username = vec.at(1);
						password = vec.at(2);
						host = vec.at(3);
						port = std::stoi(vec.at(4));
					}
					else
					{
						//LOG(_FILE_,_LINE_,"DB config is empty");
						throw;
					}
				}
				else
				{
					//LOG(_FILE_,_LINE_,"DB config file is not in correct format");
					throw;
				}
			}
			else
			{
				//LOG(_FILE_,_LINE_,"DB config file doesn't exist");
				throw;
			}
		}
		catch (...)
		{
			//LOG(_FILE_,_LINE_,"Unexpected exception");
			throw;
		}

	}
	
	void ConnectionString::SetDBParams(std::string dbname, std::string username, std::string password, std::string host, int port)
	{
		this->dbname = dbname;
		this->username = username;
		this->password = password;
		this->host = host;
		this->port = port;
	}
}
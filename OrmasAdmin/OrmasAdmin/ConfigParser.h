#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <string>
#include "TinyXML/tinystr.h"
#include "TinyXML/tinyxml.h"

class ConfigParser
{
public:
	ConfigParser();
	~ConfigParser(){};
	bool LoadConfig(const char* fileName);
	std::string dbName = "";
	std::string dbUsername = "";
	std::string dbPassword = "";
	std::string dbIPAddress = "";
	int port = 0;
	bool IsEmpty();
};

#endif
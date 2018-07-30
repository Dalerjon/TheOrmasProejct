#include "stdafx.h"
#include "ConfigParser.h"

ConfigParser::ConfigParser()
{
}

bool ConfigParser::LoadConfig(const char* fileName)
{
	TiXmlDocument doc(fileName);
	bool loadOkay = doc.LoadFile();
	if (loadOkay)
	{
		TiXmlHandle hDoc(&doc);
		TiXmlElement* pFirstElem;		
		TiXmlElement* pConnectionElem;
		TiXmlHandle hRoot(0);

		pFirstElem = hDoc.FirstChild("configuration").ToElement();
		if (!pFirstElem)
			return false;
		hRoot = TiXmlHandle(pFirstElem);

		pConnectionElem = hRoot.FirstChild("connectionStrings").FirstChild("connection").ToElement();
		if (pConnectionElem)
		{
			dbName = pConnectionElem->Attribute("baseName");
			dbUsername = pConnectionElem->Attribute("userName");
			dbPassword = pConnectionElem->Attribute("userPassword");
			dbIPAddress = pConnectionElem->Attribute("ipAddress");
			pConnectionElem->Attribute("port", &port);
			return true;
		}
	}
	return false;
}

bool ConfigParser::IsEmpty()
{
	if (dbName.empty() && dbUsername.empty() && dbPassword.empty() && dbIPAddress.empty() && 0 == port)
		return true;
	return false;
}
/*
** Created by Victor Lucas
*/

#include <string>
#include <fstream>
#include "hostname_username.hpp"

HostUserModule::HostUserModule()
{
	std::ofstream fichier("tmp", std::ios::out | std::ios::trunc);
	if(fichier)
	{
		std::system("hostname >> tmp");
		std::system("whoami >> tmp");
		fichier.close();
	}

	std::ifstream temp("tmp");
	if(temp)
	{
		std::getline(temp, _hostname);
		std::getline(temp, _username);
		temp.close();
	}
	remove("tmp");
	_statut = true;
}

HostUserModule::~HostUserModule()
{
}

const std::string &HostUserModule::getHostname() const
{
	return _hostname;
}

const std::string &HostUserModule::getUsername() const
{
	return _username;
}

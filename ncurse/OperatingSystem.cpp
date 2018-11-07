/*
** Created by Victor Lucas
*/

#include "OperatingSystem.hpp"
#include <fstream>

OperatingSystem::OperatingSystem()
{
	std::ifstream stream;
	std::string tmp;
	int pos;
	int turn = 0;;

	stream.open("/etc/lsb-release");
	while (getline(stream, tmp)){
		pos = tmp.find("=");
		tmp.erase(0,pos+1);
		switch (turn) {
		case 0:
			this->_id = tmp;
			break;
		case 1:
			this->_release = tmp;
			break;
		case 2:
			this->_codeName = tmp;
			break;
		case 3:
			this->_description = tmp;
			break;
		}
		turn += 1;
	}
	_statut = true;
}

OperatingSystem::~OperatingSystem()
{
}

const std::string OperatingSystem::getID() const
{
	return this->_id;
}

const std::string OperatingSystem::getRelease() const
{
	return this->_release;
}

const std::string OperatingSystem::getCodeName() const
{
	return this->_codeName;
}

const std::string OperatingSystem::getDescription() const
{
	return this->_description;
}


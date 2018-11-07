/*
** Created by Victor Lucas
*/

#include "Ram.hpp"
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <algorithm>

Ram::Ram()
{
	std::ofstream outfile("Free.gg");
	std::ifstream stream("Free.gg");;
	std::string command("free -h >> Free.gg ");
	std::string tmp;
	int pos;

	std::system(command.c_str());
	getline(stream, tmp);
	getline(stream, tmp);
	std::replace(tmp.begin(), tmp.end(), ',', '.');
	pos = tmp.find(":");
	tmp.erase(0, pos+1);
	this->_totalGB = std::atof(tmp.c_str());

	pos = tmp.find("G");
	tmp.erase(0, pos+1);
	this->_usedGB = std::atof(tmp.c_str());

	pos = tmp.find("G");
	tmp.erase(0, pos+1);
	this->_freeGB = std::atof(tmp.c_str());

	pos = tmp.find("M");
	tmp.erase(0, pos+1);
	this->_cache = std::atof(tmp.c_str());

	pos = tmp.find("G");
	tmp.erase(0, pos+1);
	this->_available = std::atof(tmp.c_str());
	std::remove("Free.gg");
	_statut = true;
}

Ram::~Ram()
{

}

float Ram::getTotalGB() const
{
	return this->_totalGB;
}

float Ram::getUsedGB() const
{
	return this->_usedGB;
}

float Ram::getFreeGB() const
{
	return this->_freeGB;
}

float Ram::getCacheGB() const
{
	return this->_cache;
}

float Ram::getAvailable() const
{
	return this->_available;
}

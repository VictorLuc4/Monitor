/*
** Created by Victor Lucas
*/

#include "Network.hpp"
#include "CPU.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <sstream>
#include <iterator>
#include <iomanip>

Network::Network()
{
    _data = this->setData();
    _ip = geteur("", "myIp", "hostname -i");
    _statut = true;
}

Network::~Network()
{
}

std::string Network::getIpOK()
{
	return _ip;
}

std::vector<float> Network::getData()
{
	return this->_data;
}

std::vector<float> Network::setData()
{
    std::vector<float> data;
    std::ifstream fileStat("/proc/net/dev");
	std::string line;
    size_t i = 0;

	while(i < 4) {
        std::getline(fileStat, line);
        i += 1;
    }
    std::istringstream ss(line);
    std::istream_iterator<std::string> begin(ss), end;
    std::vector<std::string> tab(begin, end);
    i = 0;
    tab.erase(tab.begin());
    while (i != tab.size()) {
        if (tab[i] != "0")
            data.push_back(atof(tab[i].c_str()));
        i += 1;
    }
    return data;
}

/*
** Created by Victor Lucas
*/

#ifndef NETWORK_HPP_
# define NETWORK_HPP_
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

class Network {
public:
	Network();
	~Network();
	std::vector<float> setData();
	std::vector<float> getData();
	std::string getIpOK();
	bool _statut;
private:
	std::vector<float> _data;
	std::string _ip;
};


#endif

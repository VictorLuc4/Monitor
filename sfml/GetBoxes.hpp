/*
** Created by Victor Lucas
*/

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Box.hpp"
#include "../ncurse/hostname_username.hpp"
#include "../ncurse/DateTime.hpp"
#include "../ncurse/OperatingSystem.hpp"
#include "../ncurse/Kernel.hpp"
#include "../ncurse/Ram.hpp"
#include "../ncurse/CPU.hpp"
#include "../ncurse/Network.hpp"

#ifndef GETBOXES_H
#define GETBOXES_H
std::vector<BoxSF> &getHostBox(std::vector<BoxSF> &boxes);
std::vector<BoxSF> &getDateTimeBox(std::vector<BoxSF> &boxes);
std::vector<BoxSF> &KernelBox(std::vector<BoxSF> &boxes);
std::vector<BoxSF> &getOsBox(std::vector<BoxSF> &boxes);
std::vector<BoxSF> &getRamBox(std::vector<BoxSF> &boxes);
std::vector<BoxSF> &getTitleBox(std::vector<BoxSF> &boxes);
std::vector<BoxSF> &getCPUBox(std::vector<BoxSF> &boxes);
std::vector<BoxSF> &getNetworkBox(std::vector<BoxSF> &boxes);
std::vector<BoxSF> &getInformationsBox(std::vector<BoxSF> &boxes);

template <typename T>
std::string convertType(T num)
{
	std::ostringstream buff;
	std::string tmp;
	buff << num;
	tmp = buff.str();
	buff.str("");
	buff.clear();
	return tmp;
}
#endif

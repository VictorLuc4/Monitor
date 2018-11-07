/*
** Created by Victor Lucas
*/

#include "GetBoxes.hpp"
#include "../ncurse/BoxNcurse.hpp"
#include "../ncurse/Network.hpp"
#include <iomanip>
#include <sstream>


std::vector<BoxSF> &getHostBox(std::vector<BoxSF> &boxes)
{
	std::string tmp;
	HostUserModule host;

	BoxSF box(sf::Vector2f(2, 2), sf::Vector2f(400, 80));
	tmp = "Hostname : " + host.getHostname() + "\n";
	tmp = tmp + "Username : " + host.getUsername() + "\n";
	box.setTextWithString(tmp.c_str(), sf::Vector2f(10,10));
	boxes.push_back(box);
	return boxes;
}

std::vector<BoxSF> &getDateTimeBox(std::vector<BoxSF> &boxes)
{
	std::string tmp;
	DateTime dateT;

	BoxSF box(sf::Vector2f(798, 2), sf::Vector2f(400, 40));
	tmp = dateT.getDateTime();
	box.setTextWithString(tmp.c_str(), sf::Vector2f(813,10));
	boxes.push_back(box);
	return boxes;
}

std::vector<BoxSF> &KernelBox(std::vector<BoxSF> &boxes)
{
	std::string tmp;
	Kernel k;

	BoxSF box(sf::Vector2f(450, 101), sf::Vector2f(300, 150));
	tmp = "Kernel name : " + k.getName() + "\n";
	tmp = tmp + "Release : " + k.getRelease() + "\n";
	tmp = tmp + "ProcessorType : " + k.getProcessorType() + "\n";
	box.setTextWithString(tmp.c_str(), sf::Vector2f(460,120));
	boxes.push_back(box);
	return boxes;
}

std::vector<BoxSF> &getOsBox(std::vector<BoxSF> &boxes)
{
	std::string tmp;
	OperatingSystem op;

	BoxSF box(sf::Vector2f(2, 101), sf::Vector2f(400, 150));
	tmp = "Distribution : " + op.getID() + "\nCode name : " + op.getCodeName();
	tmp = tmp + "\nRelease : " + op.getRelease();
	tmp = tmp + "\nTotal Description : " + op.getDescription();
	box.setTextWithString(tmp.c_str(), sf::Vector2f(10, 120));
	boxes.push_back(box);
	return boxes;
}

std::vector<BoxSF> &getRamBox(std::vector<BoxSF> &boxes)
{
	std::string tmp;
	Ram r;

	BoxSF box(sf::Vector2f(17, 433), sf::Vector2f(1166, 130));
	tmp = "";
	tmp = tmp + "Total RAM : " + convertType(r.getTotalGB()) + "GB\n";
	tmp = tmp + "RAM available : " + convertType(r.getAvailable()) + "GB\n";
	tmp = tmp + "RAM used : " + convertType(r.getUsedGB()) + "GB\n";
	tmp = tmp + "RAM free : " + convertType(r.getFreeGB()) + "GB\n";
	box.setTextWithString(tmp.c_str(), sf::Vector2f(27,440));
	boxes.push_back(box);
	return boxes;
}

std::vector<BoxSF> &getTitleBox(std::vector<BoxSF> &boxes)
{
	std::string tmp;

	BoxSF box(sf::Vector2f(500, 2), sf::Vector2f(200, 40));
	tmp = "Our Monitor !";
	box.setTextWithString(tmp.c_str(), sf::Vector2f(545,10));
	boxes.push_back(box);
	return boxes;
}

std::vector<BoxSF> &getCPUBox(std::vector<BoxSF> &boxes)
{
	std::string tmp;
	CPUStat c;

	int b = 1;
	std::vector<float> Cpu;

	BoxSF cpu(sf::Vector2f(17, 280), sf::Vector2f(1166, 130));
	tmp = "Nombre de Core : " + convertType(c.getNbcore()) + "\n";
	tmp = tmp + "Frequence du CPU : " + convertType(c.getFrequency()) + "MHz\n";
	Cpu = getCPUStat();
	tmp = tmp + "Pourcentage CPU : " + convertType(Cpu[0]) + "%\n";
	while (b < 5) {
		tmp = tmp + "Pourcentage Core " + convertType(b)
			+ " : " + convertType(Cpu[b]) + "%\t\t\t\t";
		tmp = tmp + "Pourcentage Core " + convertType(b + 1)
			+ " : " + convertType(Cpu[b + 1]) + "%\n";
		b += 2;
	}
	cpu.setTextWithString(tmp.c_str(), sf::Vector2f(27,285));
	boxes.push_back(cpu);
	return boxes;
}

std::string convertTo(std::string T)
{
	std::stringstream stream;
	std::string s;

	stream << std::fixed << std::setprecision(100) << T;
	s = stream.str();
	return s;
}

std::vector<BoxSF> &getNetworkBox(std::vector<BoxSF> &boxes)
{
	std::string tmp;
	Network n;
	std::vector<float> data;

	BoxSF box(sf::Vector2f(798, 101), sf::Vector2f(400, 150));
	tmp = "Ip : " + n.getIpOK() + "\n";
	data = n.getData();
        tmp = tmp + "Ascending Mb :" + convertTo(convertType(data[0] / 8000)) + "\n";
	tmp = tmp + "Package : " + convertTo(convertType(data[1] / 8000))  + "\n";
	tmp = tmp + "Descending bytes " + convertTo(convertType(data[2] / 8000)) + "\n";
	tmp = tmp + "Package " + convertTo(convertType(data[3] / 8000)) + "\n";
	box.setTextWithString(tmp.c_str(), sf::Vector2f(820,120));
	boxes.push_back(box);
	return boxes;
}

std::vector<BoxSF> &getInformationsBox(std::vector<BoxSF> &boxes)
{
	std::string tmp;

	BoxSF box(sf::Vector2f(17, 586), sf::Vector2f(1166, 130));
	tmp = "Informations : Merci";
	box.setTextWithString(tmp.c_str(), sf::Vector2f(27,590));
	boxes.push_back(box);
	return boxes;
}

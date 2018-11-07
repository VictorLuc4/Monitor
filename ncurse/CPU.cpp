/*
** Created by Victor Lucas
*/

#include "CPU.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstring>


CPUStat::CPUStat()
{
    std::string nb = geteur("CPU(s):", "nbCore", "lscpu");
    std::string Mhz = geteur("Vitesse",
     "frequency", "lscpu");
    std::string name = geteur("Model name:", "nameCore", "lscpu");
    nb = nb.substr(8);
    size_t j = 0;
    j = Mhz.find(':');
    Mhz = Mhz.erase(0, j + 1);
    name = name.substr(11);
    remove_if(name.begin(), name.end(), isspace);

    _name = name;
    _frequency = atoi(Mhz.c_str());
     _nb_core = atoi(nb.c_str());
     _statut = true;
}

CPUStat::~CPUStat()
{
}

std::string geteur(std::string s, std::string name, std::string cmd)
{
    std::string del("rm ");
    std::string command(cmd);
    std::string tmp;
    std::ifstream stream;

    command += " | grep \"";
    command += s;
    command += "\" >> ";
    command += name;
    del += name;

    std::system(command.c_str());
    stream.open(name.c_str());
    getline(stream, tmp);
    std::system(del.c_str());

   return tmp;
}


void ReadStatsCPU(std::vector<CPU> &entries)
{
	std::ifstream fileStat("/proc/stat");
	std::string line;
	const std::string STR_CPU("cpu");
	const std::size_t LEN_STR_CPU = STR_CPU.size();
	const std::string STR_TOT("tot");

	while(std::getline(fileStat, line))
	{
		if(!line.compare(0, LEN_STR_CPU, STR_CPU))
		{
			std::istringstream ss(line);
			entries.emplace_back(CPU());
			CPU & entry = entries.back();
			ss >> entry.cpu;
			if(entry.cpu.size() > LEN_STR_CPU)
				entry.cpu.erase(0, LEN_STR_CPU);
			else
				entry.cpu = STR_TOT;
			for(int i = 0; i < NUM_CPU_STATES; ++i)
				ss >> entry.times[i];
		}
	}
}

size_t GetIdleTime(const CPU & cpu)
{
    return  cpu.times[S_IDLE] + cpu.times[S_IOWAIT];
}

size_t GetActiveTime(const CPU & e)
{
    return  e.times[S_USER] +
            e.times[S_NICE] +
            e.times[S_SYSTEM] +
            e.times[S_IRQ] +
            e.times[S_SOFTIRQ] +
            e.times[S_STEAL] +
            e.times[S_GUEST] +
            e.times[S_GUEST_NICE];
}

void CPUStat::setStat(const std::vector<CPU> & entries1, const std::vector<CPU> & entries2)
{
    const size_t NUM_ENTRIES = entries1.size();

	for(size_t i = 0; i < NUM_ENTRIES; ++i)
	{
		const CPU & e1 = entries1[i];
		const CPU & e2 = entries2[i];

		const float ACTIVE_TIME	= static_cast<float>(GetActiveTime(e2) - GetActiveTime(e1));
		const float IDLE_TIME	= static_cast<float>(GetIdleTime(e2) - GetIdleTime(e1));
		const float TOTAL_TIME	= ACTIVE_TIME + IDLE_TIME;
        _stat_Actif.push_back(100.f * ACTIVE_TIME / TOTAL_TIME);
        _stat_Inactif.push_back(100.f * IDLE_TIME / TOTAL_TIME);
	}
}

std::vector<float> CPUStat::get_actif()
{
    return _stat_Actif;
}

std::vector<float> CPUStat::get_inactif()
{
    return _stat_Inactif;
}

int CPUStat::getNbcore()
{
    return _nb_core;
}

int CPUStat::getFrequency()
{
    return _frequency;
}

std::string CPUStat::getModele()
{
    return _name;
}

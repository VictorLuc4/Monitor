/*
** Created by Victor Lucas
*/

#ifndef CPU_HPP_
# define CPU_HPP_

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

const int NUM_CPU_STATES = 10;

enum CPUStates
{
    S_USER = 0,
    S_NICE,
    S_SYSTEM,
    S_IDLE,
    S_IOWAIT,
    S_IRQ,
    S_SOFTIRQ,
    S_STEAL,
    S_GUEST,
    S_GUEST_NICE
};

typedef struct CPU
{
	std::string cpu;
	size_t times[NUM_CPU_STATES];
} CPU;

class CPUStat
{
public:
    CPUStat();
    ~CPUStat();
    void setStat(const std::vector<CPU> &e1, const std::vector<CPU> &e2);
    std::vector<float> get_actif();
    std::vector<float> get_inactif();
    int getNbcore();
    int getFrequency();
    std::string getModele();
	bool _statut;
private:
    std::vector<float> _stat_Actif;
    std::vector<float> _stat_Inactif;
    int _nb_core;
    int _frequency;
    std::string _name;
};


void ReadStatsCPU(std::vector<CPU> & entries);
std::string geteur(std::string s, std::string name, std::string cmd);

#endif

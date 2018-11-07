/*
** Created by Victor Lucas
*/

#ifndef BOXNCURSE_HPP_
# define BOXNCURSE_HPP_

#include "DateTime.hpp"
#include "hostname_username.hpp"
#include "IMonitorModule.hpp"
#include "OperatingSystem.hpp"
#include "Ram.hpp"
#include "Kernel.hpp"
#include "Network.hpp"
#include "CPU.hpp"
#include <ncurses.h>

class Ncurse : public IMonitorModule{
public:
	Ncurse();
	~Ncurse();
	void refresh_scr();
	void print_date_host_user(int key, DateTime &date, HostUserModule &host);
	void print_kernel(int key, Kernel &kernel);
	void print_operating_system(int key, OperatingSystem &osys);
	void print_ram(int key, Ram &ram);
	void print_network(int key, Network &netw);
	void print_cpu(int key, CPUStat &cpu);
	void print_monitor();
	void print_help();
	void printEaster();
	WINDOW *_init;
	bool _easter;
	std::vector<int> _color;
	int pos1;
	int pos2;
private:
};

std::string easterEgg();
std::vector<float> getCPUStat();
#endif

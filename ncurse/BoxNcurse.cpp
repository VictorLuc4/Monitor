/*
** Created by Victor Lucas
*/

#include "DateTime.hpp"
#include "hostname_username.hpp"
#include "OperatingSystem.hpp"
#include "IMonitorModule.hpp"
#include "Ram.hpp"
#include "Kernel.hpp"
#include "Network.hpp"
#include "CPU.hpp"
#include "BoxNcurse.hpp"

Ncurse::Ncurse()
	:IMonitorModule()
{
	_easter = false;
	_init = initscr();

	pos1 = 0;
	pos2 = 2;
	_color.push_back(0);
	_color.push_back(1);
	_color.push_back(2);
	_color.push_back(3);
	_color.push_back(4);
	_color.push_back(5);
	_color.push_back(6);
	_color.push_back(7);
}

Ncurse::~Ncurse()
{
	endwin();
}

void Ncurse::refresh_scr()
{
	refresh();
}

void Ncurse::print_monitor()
{
	WINDOW *box_monitor;

	start_color();
	init_pair(1, _color[pos1], _color[pos2]);
	box_monitor = subwin(_init, 5, 40, 1, 75);
	box(box_monitor, ACS_VLINE, ACS_HLINE);
	wbkgd(box_monitor, COLOR_PAIR(1));
	mvwprintw(box_monitor, 2, 14, "Our Monitor !");
}

void Ncurse::print_help()
{
	WINDOW *box_help;

	start_color();
	init_pair(2, _color[pos1], _color[pos2]);
	box_help = subwin(_init, 6, 0, 46, 2);
	box(box_help, ACS_VLINE, ACS_HLINE);
	wbkgd(box_help, COLOR_PAIR(2));
	mvwprintw(box_help, 0, 2, "|  Help  |");
	mvwprintw(box_help, 2, 2, "A = Display/hide Date, Z = Display/hide Names, E = Display/hide Kernel, R = Display/hide Operating System, T = Display/hide Ram.");
	mvwprintw(box_help, 4, 2, "Y = Display/hide Network, U = Display/hide CPU, Q = Change Color randomly, F = Flatdesign.");
}


std::string easterEgg()
{
	std::ifstream myfile("ncurse/easter-EGG");
	std::string line;
	std::string tmp;


	if (myfile.is_open()) {
	        while (std::getline(myfile, line)){
		tmp += line + '\n';
		}
		myfile.close();
	}
	std::cout << tmp.c_str() << std::endl;
	return tmp;
}

void Ncurse::printEaster()
{
	std::string easter = easterEgg();

        printw("%s", easter.c_str(), 0, 0);
}


void Ncurse::print_date_host_user(int key, DateTime &date, HostUserModule &host)
{
	WINDOW *box_date;
	WINDOW *box_host;
	DateTime tmp;

	start_color();
	init_pair(3, _color[pos1], _color[pos2]);
	init_pair(4, _color[pos1], _color[pos2]);
	box_date = subwin(_init, 5, 40, 1, 165);
	box_host = subwin(_init, 7, 40, 1, 2);
	if (key == 97)
		date._statut = !date._statut;
	if (date._statut == true){
		box(box_date, ACS_VLINE, ACS_HLINE);
		wbkgd(box_date, COLOR_PAIR(3));
		mvwprintw(box_date, 0, 2, "|  Date  |");
		mvwprintw(box_date, 2, 2, "%s", tmp.getDateTime().c_str());
	} else if (date._statut == false)
		wclear(box_date);
	if (key == 122)
		host._statut = !host._statut;
	if (host._statut == true){
		box(box_host, ACS_VLINE, ACS_HLINE);
		wbkgd(box_host, COLOR_PAIR(4));
		mvwprintw(box_host, 0, 2, "|  Names  |");
		mvwprintw(box_host, 2, 2, "%s %s", "Host :", host.getHostname().c_str());
		mvwprintw(box_host, 4, 2, "h%s %s", "User :", host.getUsername().c_str());
	}
	else if (host._statut == false)
		wclear(box_host);

}

void Ncurse::print_kernel(int key, Kernel &kernel)
{
	WINDOW *box_kernel;

	start_color();
	init_pair(5, _color[pos1], _color[pos2]);
	box_kernel = subwin(_init, 20, 70, 24, 2);
	if (key == 101)
		kernel._statut = !kernel._statut;
	if (kernel._statut == true){
		box(box_kernel, ACS_VLINE, ACS_HLINE);
		wbkgd(box_kernel, COLOR_PAIR(5));
		mvwprintw(box_kernel, 0, 2, "|  Kernel  |");
		mvwprintw(box_kernel, 2, 2, "Kernel Name : %s", kernel.getName().c_str());
		mvwprintw(box_kernel, 4, 2, "Network Hostname : %s",
			  kernel.getNetworkHostname().c_str());
		mvwprintw(box_kernel, 6, 2, "Release : %s", kernel.getRelease().c_str());
		mvwprintw(box_kernel, 8, 2, "Version : %s", kernel.getVersion().c_str());
		mvwprintw(box_kernel, 10, 2, "%s %s", "Hardware Name :",
			  kernel.getHardwareName().c_str());
		mvwprintw(box_kernel, 12, 2, "%s %s", "Processor Type :",
			  kernel.getProcessorType().c_str());
		mvwprintw(box_kernel, 14, 2, "%s %s", "OS :", kernel.getOS().c_str());
	}
	else if (kernel._statut == false)
		wclear(box_kernel);
}

void Ncurse::print_operating_system(int key, OperatingSystem &osys)
{
	WINDOW *box_os;

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	box_os = subwin(_init, 13, 70, 10, 2);
	if (key == 114)
		osys._statut = !osys._statut;
	if (osys._statut == true){
		box(box_os, ACS_VLINE, ACS_HLINE);
		wbkgd(box_os, COLOR_PAIR(1));
		mvwprintw(box_os, 0, 2, "|  Operating System  |");
		mvwprintw(box_os, 2, 2, "%s %s", "ID :", osys.getID().c_str());
		mvwprintw(box_os, 4, 2, "%s %s", "Release :", osys.getRelease().c_str());
		mvwprintw(box_os, 6, 2, "%s %s", "Code Name :",
			  osys.getCodeName().c_str());
		mvwprintw(box_os, 8, 2, "%s %s", "Description :",
			  osys.getDescription().c_str());
	}
	else if (osys._statut == false)
		wclear(box_os);
}

void Ncurse::print_ram(int key, Ram &ram)
{
	WINDOW *box_ram;
	Ram tmp;

	start_color();
	init_pair(8, _color[pos1], _color[pos2]);
	box_ram = subwin(_init, 13, 40, 10, 165);
	if (key == 116)
		ram._statut = !ram._statut;
	if (ram._statut == true){
		box(box_ram, ACS_VLINE, ACS_HLINE);
		wbkgd(box_ram, COLOR_PAIR(8));
		mvwprintw(box_ram, 0, 2, "|  RAM  |");
		mvwprintw(box_ram, 2, 2, "%s %f", "Total GB :", tmp.getTotalGB());
		mvwprintw(box_ram, 4, 2, "%s %f", "Used GB :", tmp.getUsedGB());
		mvwprintw(box_ram, 6, 2, "%s %f", "Free GB :", tmp.getFreeGB());
		mvwprintw(box_ram, 8, 2, "%s %f", "Cache GB :", tmp.getCacheGB());
		mvwprintw(box_ram, 10, 2, "%s %f", "Available GB :", tmp.getAvailable());
	}
	else if (ram._statut == false)
		wclear(box_ram);
}

void Ncurse::print_network(int key, Network &netw)
{
	WINDOW *box_netw;
	Network tmp;
	std::vector<float> data = tmp.getData();

	start_color();
	init_pair(9, _color[pos1], _color[pos2]);
	box_netw = subwin(_init, 13, 85, 10, 75);
	if (key == 121)
		netw._statut = !netw._statut;
	if (netw._statut == true){
		box(box_netw, ACS_VLINE, ACS_HLINE);
		wbkgd(box_netw, COLOR_PAIR(9));
		mvwprintw(box_netw, 0, 2, "|  Network  |");
		mvwprintw(box_netw, 2, 2, "My Ip : %s", netw.getIpOK().c_str());
		mvwprintw(box_netw, 4, 2, "Bytes : %f", data[0]);
		mvwprintw(box_netw, 6, 2, "Nb Packages : %f", data[1]);
		mvwprintw(box_netw, 8, 2, "Bytes : %f", data[2]);
		mvwprintw(box_netw, 10, 2, "Nb Packages : %f", data[3]);
	}
	else if (netw._statut == false)
		wclear(box_netw);
}

std::vector<float> getCPUStat()
{
	std::vector<CPU> entrie1;
	std::vector<CPU> entrie2;
	std::vector<float> tmp;
	CPUStat t;

	ReadStatsCPU(entrie1);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	ReadStatsCPU(entrie2);
	t.setStat(entrie1, entrie2);
	tmp = t.get_actif();
	return tmp;
}

void Ncurse::print_cpu(int key, CPUStat &cpu)
{
	WINDOW *box_cpu;
	std::vector<float> actif = getCPUStat();

	start_color();
	init_pair(10, _color[pos1], _color[pos2]);
	box_cpu = subwin(_init, 20, 70, 24, 75);
	if (key == 117)
		cpu._statut = !cpu._statut;
	if (cpu._statut == true){
		box(box_cpu, ACS_VLINE, ACS_HLINE);
		wbkgd(box_cpu, COLOR_PAIR(10));
		mvwprintw(box_cpu, 0, 2, "|  CPU  |");
		mvwprintw(box_cpu, 2, 2, "CPU : %f %%", actif[0]);
		mvwprintw(box_cpu, 4, 2, "Core 1 : %f %%", actif[1]);
		mvwprintw(box_cpu, 6, 2, "Core 2 : %f %%", actif[2]);
		mvwprintw(box_cpu, 8, 2, "Core 3 : %f %%", actif[3]);
		mvwprintw(box_cpu, 10, 2, "Core 4 : %f %%", actif[4]);
		mvwprintw(box_cpu, 12, 2, "NbCore : %d", cpu.getNbcore());
		mvwprintw(box_cpu, 14, 2, "Frequence : %d MHz", cpu.getFrequency());
		mvwprintw(box_cpu, 16, 2, "Name : %s", cpu.getModele().c_str());
	}
	else if (cpu._statut == false)
		wclear(box_cpu);
}

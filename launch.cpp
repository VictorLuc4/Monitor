/*
** Created by Victor Lucas
*/

#include "ncurse/DateTime.hpp"
#include "ncurse/hostname_username.hpp"
#include "ncurse/Kernel.hpp"
#include "ncurse/OperatingSystem.hpp"
#include "ncurse/Ram.hpp"
#include "ncurse/Network.hpp"
#include "ncurse/BoxNcurse.hpp"
#include <ncurses.h>
#include <thread>
#include <chrono>

void launchNcurse()
{
	Ncurse curse;
	DateTime date;
	HostUserModule host;
	Kernel kernel;
	OperatingSystem osys;
	Ram ram;
	Network netw;
	CPUStat cpu;
	int key = 0;

	while (1){
		noecho();
		curs_set(0);
		halfdelay(1);
		key = getch();
		if (key == 27)
			break;
		clear();
		if (key == 99) {
			if (curse._easter == false)
				curse._easter = true;
			else
				curse._easter = false;
		}
		if (key == 113) {
			curse.pos1 = rand() % 7;
			curse.pos2 = rand() % 7;
		}
		if (key == 102) {
			curse.pos1 = rand() % 7 + 1;
			curse.pos2 = 0;
		}
		if (curse._easter == false){
			curse.print_date_host_user(key, date, host);
			curse.print_kernel(key, kernel);
			curse.print_operating_system(key, osys);
			curse.print_ram(key, ram);
			curse.print_cpu(key, cpu);
			curse.print_monitor();
			curse.print_help();
			curse.print_network(key, netw);
	 		curse.refresh_scr();
	 		std::this_thread::sleep_for(std::chrono::milliseconds(9));
		}
		else {
			clear();
			curse.printEaster();
			curse.refresh_scr();
		}
	 }
}

/*
** Created by Victor Lucas
*/

#include "Kernel.hpp"

Kernel::Kernel()
{
	std::ofstream outfile("Kernel.gg");
	std::ifstream stream;
	std::string command;
	int turn = 0;

	stream.open("Kernel.gg");
	while (turn < 7) {
		switch (turn) {
		case 0:
			command = "uname -s >> Kernel.gg";
			system(command.c_str());
			getline(stream, this->_name);
			break;
		case 1:
			command = "uname -n >> Kernel.gg";
			system(command.c_str());
			getline(stream, this->_networkHostname);
			break;
		case 2:
			command = "uname -r >> Kernel.gg";
			system(command.c_str());
			getline(stream, this->_release);
			break;
		case 3:
			command = "uname -v >> Kernel.gg";
			system(command.c_str());
			getline(stream, this->_version);
			break;
		case 4:
			command = "uname -m >> Kernel.gg";
			system(command.c_str());
			getline(stream, this->_hardwareName);
			break;
		case 5:
			command = "uname -p >> Kernel.gg";
			system(command.c_str());
			getline(stream, this->_processorType);
			break;
		case 6:
			command = "uname -o >> Kernel.gg";
			system(command.c_str());
			getline(stream, this->_os);
			break;
		}
		turn += 1;
	}
	stream.close();
	std::remove("Kernel.gg");
	_statut = true;
}

Kernel::~Kernel()
{
}

const std::string Kernel::getName() const
{
	return this->_name;
}

const std::string Kernel::getNetworkHostname() const
{
	return this->_networkHostname;
}

const std::string Kernel::getRelease() const
{
	return this->_release;
}

const std::string Kernel::getVersion() const
{
	return this->_version;
}

const std::string Kernel::getHardwareName() const
{
	return this->_hardwareName;
}

const std::string Kernel::getProcessorType() const
{
	return this->_processorType;
}

const std::string Kernel::getOS() const
{
	return this->_os;
}

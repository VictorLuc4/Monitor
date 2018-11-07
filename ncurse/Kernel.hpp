/*
** Created by Victor Lucas
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

#ifndef KERNEL_H
#define KERNEL_H
class Kernel {
public:
	Kernel();
	virtual ~Kernel();
	const std::string getName() const;
	const std::string getNetworkHostname() const;
	const std::string getRelease() const;
	const std::string getVersion() const;
	const std::string getHardwareName() const;
	const std::string getProcessorType() const;
	const std::string getOS() const;
	bool _statut;
private:
	std::string _name;
	std::string _networkHostname;
	std::string _release;
	std::string _version;
	std::string _hardwareName;
	std::string _processorType;
	std::string _os;
};
#endif

/*
** Created by Victor Lucas
*/

#ifndef HOSTNAME_USERNAME_HPP_
# define HOSTNAME_USERNAME_HPP_

#include <iostream>
#include <cstdlib>

class HostUserModule{
public:
	HostUserModule();
	~HostUserModule();
	const std::string &getHostname() const;
	const std::string &getUsername() const;
	bool _statut;
private:
	std::string _hostname;
	std::string _username;
};

#endif

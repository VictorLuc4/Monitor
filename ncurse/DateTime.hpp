/*
** Created by Victor Lucas
*/

#ifndef DATETIME_HPP_
# define DATETIME_HPP_

#include <iostream>
#include <ctime>

class DateTime{
public:
	DateTime();
	~DateTime();
	const std::string &getDateTime() const;
	bool _statut;
private:
	std::string _datetime;
};

#endif

/*
** Created by Victor Lucas
*/

#include "DateTime.hpp"

DateTime::DateTime()
{
	char *test;
	time_t now = time(0);
	int i = 0;

	test = ctime(&now);
	while (test[i]){
		if (test[i] == '\n')
			test[i] = '\0';
		i++;
	}
	_datetime = test;
	_statut = true;
}

DateTime::~DateTime()
{}

const std::string &DateTime::getDateTime() const
{
	return _datetime;
}

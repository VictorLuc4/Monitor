/*
** Created by Victor Lucas
*/

#include <iostream>
#ifndef OPERATING_H
#define OPERATING_H
class OperatingSystem {
public:
	OperatingSystem();
	virtual ~OperatingSystem();
	const std::string getID() const;
	const std::string getRelease() const;
	const std::string getCodeName() const;
	const std::string getDescription() const;
	bool _statut;
private:
	std::string _id;
	std::string _release;
	std::string _codeName;
	std::string _description;
};
#endif

/*
** Created by Victor Lucas
*/

#include <iostream>
#ifndef RAM_H
#define RAM_H
class Ram {
public:
	Ram();
	~Ram();
	float getTotalGB() const;
	float getUsedGB() const;
	float getFreeGB() const;
	float getCacheGB() const;
	float getAvailable() const;
	bool _statut;
private:
	float _totalGB;
	float _usedGB;
	float _freeGB;
	float _cache;
	float _available;
};
#endif

#ifndef AMICPR_H
#define AMICPR_H

#include "../util/util.h"
#include "../darray/darray.h"


static bool verbose = true;

class amicable {

public:

	amicable(int limit) : _array(limit), _sumArray(nullptr), _tempArray(nullptr), _primeArray(nullptr), _limit(limit), _count(0) {

		_sumArray = new int[_limit];
		_tempArray = new bool [_limit];
		_primeArray = new int[_limit];

		calcPrimes();
		fillPrimeArray();
		
		init();

	}

	~amicable() {

		delete[] _tempArray;
		delete[] _sumArray;
		delete[] _primeArray;
	}
	
	void generateFactors(int n);
	void calcPrimes();
	void strikeOutMultiples(int n);
	void fillPrimeArray();
	void init();

	
private :

	darray <darray<int>> _array;
	int* _sumArray;
	bool* _tempArray;
	int* _primeArray;
	int _limit;
	static bool _display;
	int _count;

};


#endif
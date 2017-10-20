#ifndef AMICPR_H
#define AMICPR_H

#include "../util/util.h"
#include "../darray/darray.h"


static bool verbose = true;

class amicable {

public:

	amicable(int limit) : _array(limit), _sumArray(nullptr), _tempArray(nullptr), _limit(limit), _count(0) {

		if (_display) {

			cout << "In amicPr const" << endl;
		}

		_sumArray = new int[_limit];
		_tempArray = new bool [_limit];

		calcPrimes();
		//fillPrimeArray();
		//strikeOutMultiples(limit);
		
		//cout << _primeArray[0];
		

	}

	~amicable() {

		if (_display) {

			cout << "In amicPr dest" << endl;
		}

		delete[] _tempArray;
		//delete[] _sumArray;
	}
	
	void populateArray(int n);
	int populateArray1(int n);
	void generateFactors(int n);
	void displayArray(int row, int col);
	bool ifPresent(int index, int limit, int n);
	int addFactors(int n);
	void verifySums(int n);
	void calcPrimes();
	void strikeOutMultiples(int n);
	void fillPrimeArray();



private :

	darray <darray<int>> _array;
	int* _sumArray;
	bool* _tempArray;
	//darray<bool> _primeArray;
	int _limit;
	static bool _display;
	int _count;

};


#endif
#ifndef AMICPR_H
#define AMICPR_H

#include "../util/util.h"
#include "../darray/darray.h"


static bool verbose = true;

class amicable {

public:

	amicable(int limit) : _array(limit), _a{ 2,3,5,7 }, _limit(limit), _count(0) {

		if (_display) {

			cout << "In amicPr const" << endl;
		}

		//init();

	}

	amicable() {

		if (_display) {

			cout << "In amicPr dest" << endl;
		}
	}
	
	void calcPairs(int n);
	void init();
	void populateArray(int n);
	void displayArray(int row, int col);
	void calcFactors(int n);
	bool ifPresent(int index, int limit, int n);



private :

	darray <darray<int>> _array;
	int _a[4];
	int _limit;
	static bool _display;
	int _count;

};


#endif
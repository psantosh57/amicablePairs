#ifndef AMICPR_H
#define AMICPR_H

#include "../util/util.h"
#include "../darray/darray.h"


static bool verbose = true;

class amicable {

public:

	amicable(int limit) : _array(limit), _limit(limit), _count(0) {

		if (_display) {

			cout << "In amicPr const" << endl;
		}

	}

	amicable() {

		if (_display) {

			cout << "In amicPr dest" << endl;
		}
	}
	
	void populateArray(int n);
	void displayArray(int row, int col);
	bool ifPresent(int index, int limit, int n);
	int addFactors(int n);
	void verifySums(int n);



private :

	darray <darray<int>> _array;
	//int _a[5];
	int _limit;
	static bool _display;
	int _count;

};


#endif
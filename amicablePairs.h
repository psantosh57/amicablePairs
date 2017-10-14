#ifndef AMICPR_H
#define AMICPR_H

#include "../util/util.h"
#include "../darray/darray.h"


static bool verbose = true;

class amicPr {

public:

	amicPr(int limit) : _array (limit), _limit(limit), _display(verbose) {

		if (_display) {

			cout << "In amicPr const" << endl;
		}

		init();

	}

	amicPr() {

		if (_display) {

			cout << "In amicPr dest" << endl;
		}
	}
	
	void calcPairs(int n);
	void init();

private :

	darray <int> _array;
	int _limit;
	bool _display;

};


#endif
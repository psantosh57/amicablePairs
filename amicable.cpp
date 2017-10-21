#include "amicable.h"

void amicable::calcPrimes() {

	_tempArray[0] = false;
	_tempArray[1] = false;
	for (int i = 2; i < _limit; ++i) {
		_tempArray[i] = true;

	}

	int index = 0;
	int count = 0;
	int arrayCnt = 0;

	for (int i = 2; i < _limit; ++i) {

		if (_tempArray[i]) {
		
			strikeOutMultiples(i);

		}
		
	}

}

void amicable::strikeOutMultiples(int n) {

	int index = n + n;
	int k = 0;
	while (index < _limit) {

		if (_tempArray[index]) {
			_tempArray[index] = false;
		}

		index += n;

	}


}

void amicable::fillPrimeArray() {

	int i = 0;
	int k = 0;
	_primeArray[k++] = -1;
	_primeArray[k++] = -1;
	while (i < _limit) {

		if (_tempArray[i]) {

			_primeArray[k++] = i;
		}
		
		i++;

	}

}



void amicable::generateFactors(int n) {

	if (n % 6 != 0) {

		_array[n - 1][0] = n;
		int j = 1;
		int tempSum = 1;
		int product = 1;

		if (!_tempArray[n]) {

			int fact = 2;
			int m = n;
			int mod = m % _primeArray[fact];
			int div = m / _primeArray[fact];

			while (_primeArray[fact] <= sqrt(m)) {

				if (_tempArray[_primeArray[fact]]) {

					mod = m % _primeArray[fact];
					div = m / _primeArray[fact];
					int factInd = 1;
					if (mod == 0 && div != 1) {

						_array[n - 1][j++] = _primeArray[fact];
						if (div == _primeArray[fact]) {

							_array[n - 1][j++] = 2;
							break;

						}
						else if (div % _primeArray[fact] == 0) {
							factInd++;
							while (_array[div - 1][factInd] != 0) {

								if (j == 2 && factInd == 2) {

									_array[n - 1][j++] = _array[div - 1][factInd++] + 1;

								}
								else {

									_array[n - 1][j++] = _array[div - 1][factInd++];

								}

							}

							break;

						}
						else if (_array[div - 1][factInd] == 1)  {
							_array[n - 1][j++] = 1;
							factInd--;
							while (_array[div - 1][factInd] != 0) {

								_array[n - 1][j++] = _array[div - 1][factInd++];

							}

							break;
						}
						else {
							_array[n - 1][j++] = 1;
							while (_array[div - 1][factInd] != 0) {

								_array[n - 1][j++] = _array[div - 1][factInd++];

							}

							break;

						}

						m = div;

					}

				}

				fact++;

			}


		}
		else {

			_array[n - 1][j++] = 1;

		}

		_array[n - 1][j] = 0;

		if (_array[n - 1][1] != 1) {

			int k = 1;
			int base = _array[n - 1][k];
			while (base != 0) {

				int temp = _array[n - 1][k + 1];
				while (temp > 0) {

					tempSum += pow(base, temp);
					temp--;
				}

				product *= tempSum;
				tempSum = 1;
				k += 2;
				base = _array[n - 1][k];
			}

			product -= n;

		}
		else {

			product = 1;

		}

		_sumArray[n] = product;

		if (product % 6 != 0) {

			if (product < n) {

				int product2 = _sumArray[product];

				if ((product % 2 == 0 && product2 % 2 == 0) || (product % 2 != 0 && product2 % 2 != 0)) {

					if (_sumArray[product] == n) {

						cout << _count << " : " << product << " and " << n << " are amicable pairs!" << endl;
						_count++;

					}

				}
			}

		}

	}

}

void amicable::init() {

	for (int i = 2; i < _limit; i++) {
		generateFactors(i);
	}

}
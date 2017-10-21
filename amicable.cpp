#include "amicable.h"

void amicable::populateArray(int n) {
	
	int m = n;
	int j = 1;
	int i = 0;
	int fact = 2;
	int sum = 1;
	//int mod = m % _a[i];
	int mod = m % fact;
	int div = m;
	int count = 4;
	bool divBy2 = false;

	_array[n - 1][0] = m;

	if (n == 1) {

		_array[n - 1][1] = 0;

	}

	//cout << "Number is " << n << endl;

	while (fact <= sqrt(n) || div > fact) {

		//mod = m % _a[i];
		//div = m / _a[i];
		mod = m % fact;
		div = m / fact;

		if (mod == 0 && div != 1) {

			//_array[n - 1][j++] = _a[i];
			//cout << "Factor is " << fact << endl;
			_array[n - 1][j++] = fact;
			sum += fact;
			
			int k = 0;
			
			m /= fact;

			int temp = _array[m - 1][k];

			//Dont add factor again - eg 121 = 11*11

			if (m != fact) {

				_array[n - 1][j++] = temp;
				sum += temp;

			}

			if (_array[m - 1][k + 1] != 0) {
				
				k++;

				while (_array[m - 1][k] != 0) {

					temp = _array[m - 1][k];

					if (!ifPresent((n - 1), j, temp)) {
						//cout << "Factor is " << temp << endl;
						_array[n - 1][j++] = _array[m - 1][k];
						sum += temp;
					
					}
					
					//temp = _a[i] * _array[m - 1][k++];
					temp = fact * _array[m - 1][k++];
					
					if (!ifPresent((n - 1), j, temp)) {
						//cout << "Factor is " << temp << endl;
						_array[n - 1][j++] = temp;
						sum += temp;

					}
						
				}

				break;

			}

		}

		fact++;

	}
	
	_array[n - 1][j++] = 0;

	//_sumArray[n - 1] = sum;

#if 0
	if (((n - 1) > sum) && (_sumArray[sum - 1] == n)) {

		cout << _count << ": " << sum << " and " << n << " are amicable pairs!" << endl;
		_count++;

	}

#endif // 0

	

}


int amicable::populateArray1(int n) {

	_array[n - 1][0] = n;

	if (n % 6 != 0 && !_tempArray[n]) {
		
		int m = n;
		int j = 1;
		int i = 0;
		int fact = 2;
		int sum = 1;
		//int mod = m % _a[i];
		int mod = m % fact;
		int div = m;
		int count = 4;
		bool divBy2 = false;
		int tempSum = 1;
		int primeInd = 0;
		int product = 1;
		//int count = 0; 

		

#if 0
		if (n == 1) {

			_array[n - 1][1] = 0;

		}
#endif // 0

#if 0
		if (_tempArray[n]) {

			_array[n - 1][j] = 1;

		}
#endif // 0



		while (fact <= sqrt(m)) {

			//mod = m % _primeArray[primeInd];
			//div = m / _primeArray[primeInd];
			mod = m % fact;
			div = m / fact;
			int factInd = 1;
			if (mod == 0) {

				_array[n - 1][j++] = fact;
				if (_array[fact][factInd] == 0) {

					_array[n - 1][j++] = 1;
				}
				else if (div % fact == 0) {
					factInd++;
					_array[n - 1][j++] = _array[fact][factInd] + 1;

				}




#if 0
			else if (_tempArray[div]) {

				_array[m][fact] = 1;
				_array[m][div] = div;
				break;

			}
#endif // 0


				m = div;
				fact++;

				
				
				
				
				
				
				
				
				
				int count = 0;
				while (mod == 0 && m != 1) {

					//_array[n - 1][fact] = ++count;
					count++;
					tempSum += pow(fact, count);
					m /= fact;
					mod = m % fact;

				}

#if 0
				while (count >= 0) {

					tempSum += pow(fact, count);
					count--;
				}
#endif // 0

				product *= tempSum;
				tempSum = 1;


			} //ending if mod == 0

			fact++;

		}

		if (m > 1) {

			tempSum += m;
			product *= tempSum;

		}

		product -= n;

		//cout << "Sum of factors for " << n << " is " << product << endl;
		return product;
		//_sumArray[n - 1] = sum;

	}
	else {

		_array[n - 1][1] = 0;

		(n + 1);

	}

}



void amicable::displayArray(int row, int col) {

	cout << _array[row][col] << endl;

}

bool amicable::ifPresent(int index, int limit, int n) {

	for (int i = 0; i < limit; i++) {

		if (_array[index][i] == n) {

			return true;
		}
	}

	return false;

}


int amicable::addFactors(int n) {

	if (n == 1) {

		return 1;
	}
	else {
		
		int sum = 1;
		int i = 1;

		while (_array[n - 1][i] != 0) {

			sum += _array[n - 1][i];
			i++;
		}

		return sum;

	}

	
}

void amicable::verifySums(int n) {

	int s1 = addFactors(n);
	//cout << "Sum of " << n << " is " << s1 << endl;
	if (s1 < n) {

		int s2 = addFactors(s1);
		//cout << "Sum of " << s1 << " is " << s2 << endl;

		if (s2 == n) {

			cout << _count << ": " << s1 << " and " << n << " are amicable pairs!" << endl;
			_count++;
		}
		else {

			//cout << "Not amicable pairs" << endl;
		}

	}
	

}

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

#if 0
	for (int i = 0; i < _limit; ++i) {

		if (_tempArray[i] != -1) {

			arrayCnt++;
			//_numPrimes[n]++;
		}
	}
#endif // 0


}


void amicable::strikeOutMultiples(int n) {

	int index = n + n;
	int k = 0;
	while (index < _limit) {

		if (_tempArray[index]) {
			_tempArray[index] = false;
			//_primeArray[k++] = _tempArray[index];
		}

		index += n;

	}


}

#if 1
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
#endif // 0


void amicable::generateFactors(int n) {

	if (n % 6 != 0) {

		_array[n - 1][0] = n;
		int j = 1;
		int tempSum = 1;
		int product = 1;

		if (!_tempArray[n]) {

			int fact = 2;
			//int j = 1;
			int m = n;
			//int mod = m % fact;
			//int div = m / fact;
			int mod = m % _primeArray[fact];
			int div = m / _primeArray[fact];

			//Changing fact to _primeArray[fact]
			while (_primeArray[fact] <= sqrt(m)) {

				if (_tempArray[_primeArray[fact]]) {

					mod = m % _primeArray[fact];
					div = m / _primeArray[fact];
					//mod = m % fact;
					//div = m / fact;
					int factInd = 1;
					if (mod == 0 && div != 1) {

						//_array[n - 1][j++] = fact;
						_array[n - 1][j++] = _primeArray[fact];
						//_array[n - 1][j++] = 1;
						if (div == _primeArray[fact]) {

							_array[n - 1][j++] = 2;
							//tempSum += pow(fact, 2);
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
							//factInd++;
							//_array[n - 1][j++] = _array[fact][factInd] + 1;

						}
						else if (_array[div - 1][factInd] == 1) {
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
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

		_array[n - 1][0] = m;

#if 0
		if (n == 1) {

			_array[n - 1][1] = 0;

		}
#endif // 0

		if (_tempArray[n]) {

			_array[n - 1][j] = 1;

		}


		while (fact <= sqrt(m)) {

			//mod = m % _primeArray[primeInd];
			//div = m / _primeArray[primeInd];
			mod = m % fact;
			div = m / fact;

			if (mod == 0) {
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

#if 0
void amicable::fillPrimeArray() {

	int i = 0;
	int k = 0;
	while (i < _limit) {

		if (_tempArray[i]) {

			_primeArray[k++] = true;
		}
		else {

			_primeArray[k++] = false;

		}
		i++;

	}

}
#endif // 0

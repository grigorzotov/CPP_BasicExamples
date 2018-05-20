#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void
didYouMeanRecurtion()
{
	cout << "Did you mean recursion?";

	char response;
	do
	{
		cout << " [y/N]: ";
		cin >> response;

		if ('y' == response) {
			didYouMeanRecurtion();
		}
		else if ('N' == response) {
			return;
		}
	} while (response != 'y' && response != 'N');
}

void
reverseTraverseNumber(int n)
{
	if (0 == n) {
		return;
	}

	cout << n % 10 << " ";

	reverseTraverseNumber(n / 10);
}

void
traverseNumber(int n)
{
	if (0 == n) {
		return;
	}

	traverseNumber(n / 10);

	cout << n % 10 << " ";
}

/// Second version of the function
int
traverseNumber_(int n)
{
	if (n < 10) {
		return n;
	}

	int prevDigit = traverseNumber_(n / 10);

	cout << prevDigit << " ";

	return n % 10;
}

/*
int main()
{
	didYouMeanRecurtion();

	int n;

	cin >> n;

	reverseTraverseNumber(n);
	cout << endl;

	traverseNumber(n);
	cout << endl;

	/// Call the second version of the function
	/// We need to print the last digit explicitly.
	int lastDigit = traverseNumber_(n);
	cout << lastDigit << endl;

	return 0;
	}*/
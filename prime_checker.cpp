/*
 * prime_checker.cpp
 *
 * simply checks if a number is prime or not
 * working algorithm
 *
 * created by john van note
 * created on 9/16/13
 * last update: 9/19/13
 */

#include <iostream>
#include <cstdlib>
using namespace std;

/* prototypes, details in definition below */
bool isPrime(int n);
int fermats_little(int a, int p);
int gcd(unsigned int a, unsigned int b);
unsigned long long int int_pow(int a, int x);

int main(void) {
	/* gets the value from the user */
	int value;
	cout << "Enter a value: ";
  cin >> value;

	/* prime numbers are greater than 1 by definition */
	if(value<2) {
		cout << value << " is Not a prime number.";
	}
	else if(isPrime(value)) {
		cout << value << " is a prime number.";
	}
	else {
		cout << value << " is Not a prime number.";
	}
	cout << endl;

	return 0;
}

/*
 * isPrime: uses GCD and fermat's little theorem to determine
 * if an int is prime
 * @param n: the number in question
 * @return: true if the number is prime, false otherwise (1/1048574
 * accuracy)
 */
bool isPrime(int n) {
  /* special cases */
	if((n == 2) || (n == 3)) {
		return true;
	}
	/* easy way to cut iterations on evens */
  if((n%2) == 0) {
		return false;
	}

	int iterations = 0;
	bool primality = false;
	while((iterations < 20) && (primality != true)) {
		/* find a, a random int in the rand [2, n-2] */
		int a = (rand() % (n-3)) + 2;
		cout << "A: " << a << " N: " << n << endl ;
		if(gcd(a,n) != 1)
		{
			cout << "Here" << endl;
			//primality = false;
		}
		else if(fermats_little(a,n) != 1)
		{
			cout << "there" << endl;
			//return false;
		}
		else 
		{
			cout << "Everywhere" << endl;
			primality = true;
		}
		iterations++;
	}

	return primality;
}

/*
 * fermats_little: calculates a^(p-1) mod p
 * @param a: a is the random number in the range [2, p-1]
 * @param p: the "prime" number in question
 * @return: a^(p-1) mod p
 */
int fermats_little(int a, int p) {
	unsigned long long int power = int_pow(a, p-1);
	int remainder = power % p;
	cout << "Remainder: " << remainder << endl;
	return remainder;
}

/* 
 * gcd: determines greatest common denominator 
 * @param a: one int
 * @param b: another int
 * @return: the GCD
 */
int gcd(unsigned int a, unsigned int b) {
	unsigned int temp;
	while(b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	cout << "GCD: " << a << endl;
	return a;
}

/*
 * int_pow: calculates a^x, got tired of using cmath.h and static casting
 * @param a: base
 * @param x: exponent
 * @return: a^x
 */
unsigned long long int int_pow(int a, int x) {
	if(x == 0)
		return 1;
	unsigned long long int solution = 1;
	for(int i=0; i<x; i++) {
		solution = solution * a;
	}
	cout << "Solution: " << solution << endl;
	return solution;
}

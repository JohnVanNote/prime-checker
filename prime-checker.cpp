/*
 * prime_checker.cpp
 *
 * simply checks if a number is prime or not
 * working algorithm
 *
 * created by John Van Note
 * created on 2013-09-16
 * last update: 2016-09-20
 */

#include <iostream>
#include <cstdlib>
using namespace std;

/* prototypes, details in definition below */
bool isPrime(unsigned long int n);
bool fermats_little(unsigned long long int a, unsigned long long int p);
unsigned long long int gcd(unsigned long long int a, unsigned long long int b);
unsigned long long int int_pow(unsigned long long int a, unsigned long long int x);

int main(int argc, char *argv[]) {

        if(argc > 2) {
                cerr << "Too many arguments" << endl;
                return 1;
        }
        
        int value;
        string strPrime;

        /* takes argument or gets user input */
        if(argc == 2) {
                value = stoi(argv[1]);
        }
        else {
                cout << "Enter a value: ";
                cin >> value;
        }
        /* prime numbers are greater than 1 by definition */
        if((value<2) || !isPrime(value)) { 
                strPrime = " NOT ";
        }
        else {
                strPrime = " ";
        }

        cout << value << " is" + strPrime + "a prime number." << endl;

        return 0;
}

/*
 * isPrime: uses GCD and fermat's little theorem to determine
 * if an int is prime
 * @param n: the number in question
 * @return: true if the number is prime, false otherwise (1/1048574
 * accuracy)
 */
bool isPrime(unsigned long int n) {
        /* special cases */
        if((n == 2) || (n == 3)) {
                return true;
        }
      
        /* easy way to cut iterations on evens */
        if((n%2) == 0) {
                return false;
        }

        int iterations = 0;
        bool primality = true;
        int iter_max = 1;

        while((iterations < iter_max) && (primality == true)) {
                cout << "iter: " << iterations << " prime: " << primality << endl;
                
                /* find a, a random int in the rand [2, n-1] */
                srand(time(NULL) + iterations);
                unsigned long long int random = rand();
                unsigned long long int a = (random % (n-3)) + 2;
                /* temp */
                a = 11;
                
                cout << "A: " << a << " N: " << n << endl ;
                
                /*if(!(gcd(a, n) == 1)) { 
                        primality = false;
                }*/

                if (fermats_little(a, n)) {
                        primality = false;
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
bool fermats_little(unsigned long long int a, unsigned long long int p) {
        unsigned long long int atop= int_pow(a, p);
        //unsigned long long int remainder = power % p;
        //cout << "Remainder: " << remainder << endl;
        return !((atop % p) == a);
}

/* 
 * gcd: determines greatest common denominator 
 * @param a: one int
 * @param b: another int
 * @return: the GCD
 */
unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
        unsigned long long int temp;
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
unsigned long long int int_pow(unsigned long long int a, unsigned long long int x) {
        if(x == 0)
                return 1;
        uint64_t solution = 1;
        for(unsigned long long int i=0; i<x; i++) {
                solution = solution * a;
                cout << "\tsolution: " << solution << endl;
        }
        cout << "Solution: " << solution << endl;
        return solution;
}

// C++ program to implement bitwise Sieve
// of Eratosthenes.
#include <bits/stdc++.h>
using namespace std;

#define MX 1000004
int prime[MX];
// Checks whether x is prime or composite
bool ifnotPrime(int x)
{
	// checking whether the value of element
	// is set or not. Using prime[x/64], we find
	// the slot in prime array. To find the bit
	// number, we divide x by 2 and take its mod
	// with 32.
	return (prime[x/64] & (1 << ((x >> 1) & 31)));
}

// Marks x composite in prime[]
bool makeComposite(int x)
{
	// Set a bit corresponding to given element.
	// Using prime[x/64], we find the slot in prime
	// array. To find the bit number, we divide x
	// by 2 and take its mod with 32.
	prime[x/64] |= (1 << ((x >> 1) & 31));
}
// Prints all prime numbers smaller than n.
void bitWiseSieve()
{
	// Assuming that n takes 32 bits, we reduce
	// size to n/64 from n/2.

	// Initializing values to 0 .
	memset(prime, 0, sizeof(prime));
	// 2 is the only even prime so we can ignore that
	// loop starts from 3 as we have used in sieve of
	// Eratosthenes .
	for (int i = 3; i * i <= MX; i += 2) {

		// If i is prime, mark all its multiples as
		// composite
		if (!ifnotPrime(i))
			for (int j = i * i, k = i << 1; j < MX; j += k)
				makeComposite(j);
	}
    /*
	// writing 2 separately
	printf("2 ");

	// Printing other primes
	for (int i = 3; i <= n; i += 2)
		if (!ifnotPrime(prime, i))
			printf("%d ", i);
    */
}

// Driver code
int main()
{
	int n = 30;
	bitWiseSieve();
	return 0;
}

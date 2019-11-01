/// generate power set in : all possible subsequence of a string
/// lexicographic order.
///Time : O(2^n)
#include <bits/stdc++.h>
using namespace std;

// str : Stores input string
// n : Length of str.
// curr : Stores current permutation
// index : Index in current permutation, curr
void printSubSeqRec(string str, int n,
		int index = -1, string curr = "")
{
	// base case
	if (index == n)
		return;

	cout << curr << "\n";
	for (int i = index + 1; i < n; i++) {

		curr += str[i];
		printSubSeqRec(str, n, i, curr);

		// backtracking
		curr = curr.erase(curr.size() - 1);
	}
	return;
}

// Generates power set in lexicographic
// order.
void printSubSeq(string str)
{
	printSubSeqRec(str, str.size());
}

// Driver code
int main()
{
	string str;
	cin>>str;
	printSubSeq(str);
	return 0;
}

//* https://www.codingninjas.com/studio/contests/weekend-contest-81/8894371/problems/25184

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)                                  {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int minimumJumps(int x, int y) {
	// Write your code here.
	if(x == 0 && y == 0){
		return 0;
	}
	int g = gcd(x, y);

	return x/g + y/g; // (x + y)/g
}
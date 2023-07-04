//* https://www.codingninjas.com/studio/contests/weekend-contest-80/8875464/problems/25147

int badMemories(long long n, long long x) {
    // Write your code here.

    long long correct = (x + 3) / 4;
    long long incorrect = 4 * correct - x;

    if(correct + incorrect <= n){
        return 1;
    }
    else{
        return 0;
    }
}



/*
Maths
Approach:

Since the constraints are too high, we think of this problem mathematically. (Assume all divisions to be floored.)
Let us find the minimum number of questions we need to obtain a total score of 'X' and if 'N' > 'X' the other 'N - X' questions can just be skipped.
If we answer '(X + 3) / 4' questions correctly, our total score reaches the smallest multiple of 4 greater than or equal to 'X'.
Now to deal with the difference between the current total score and 'X', we answer '4 * ((X + 3) / 4) - X' questions incorrectly.
Thus '(X + 3) / 4 + (4 * ((X + 3) / 4) - X)' is the minimum questions needed to obtain a total score of 'X'.

Algorithm:

Initialize a variable 'correct' with 'ceil(x / 4) = (x + 3) / 4'.
Initialize a variable 'incorrect' with '4 * correct - x'
If ( correct + incorrect <= n ):
Return 1
else:
Return 0
Time Complexity
O(1).


Since we are performing a constant number of operations, the time complexity is of the order O(1).

Space Complexity
O(1).


Since we are using constant extra space, the space complexity is of the order O(1).



* Code->

> Time Complexity: O(1)
> Space Complexity: O(1)


int badMemories(long long n, long long x) {
	// Calculate the minimum number of correct answers needed.
	long long correct = (x + 3) / 4;
	// Calculate the corresponding number of incorrect answers needed.
	long long incorrect = correct * 4 - x;

	// Compare the minimum total answers needed with 'N' and return 1 or 0 accordingly.
	if (correct + incorrect <= n) {
		return 1;
	}
	else {
		return 0;
	}
}
*/
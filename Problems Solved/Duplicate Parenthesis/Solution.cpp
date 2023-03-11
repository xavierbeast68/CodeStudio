//* https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/
//* https://www.codingninjas.com/codestudio/problem-details/duplicate-parenthesis_2663296
//* https://www.codingninjas.com/codestudio/problems/duplicate-parenthesis_2663296


#include <bits/stdc++.h> 

bool isDuplicate(string& s){
	stack<char> st;

	for(char ch : s){
		if(ch == ')'){
			int count = 0;
			while(st.top() != '('){
				count++;
                st.pop();
			}
			if(count < 1){
				return true;
			}
            else{
                st.pop();
            }
		}
		else{
			st.push(ch);
		}
	}
	return false;
}

bool duplicateParanthesis(string &expr)
{
    // Write your code here

    return isDuplicate(expr);
}

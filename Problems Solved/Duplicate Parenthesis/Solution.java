//* https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/
//* https://www.codingninjas.com/codestudio/problem-details/duplicate-parenthesis_2663296
//* https://www.codingninjas.com/codestudio/problems/duplicate-parenthesis_2663296


import java.util.* ;
import java.io.*; 

public class Solution {

	public static boolean isDuplicate(String s){
		Stack<Character> st = new Stack<>();

		for(int i = 0 ; i < s.length() ; ++i){
			char ch = s.charAt(i);

			if(ch == ')'){
				int count = 0;

				while(st.pop() != '('){
					count++;
				}

				if(count < 1){
					return true;
				}
			}
			else{
				st.push(ch);
			}
		}
		return false;
	}
	public static boolean duplicateParanthesis(String expr) {
		// Write your code here

		return isDuplicate(expr);
	}

}

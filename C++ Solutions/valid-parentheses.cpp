//* https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?leftPanelTab=0


bool isValidParenthesis(string s)
{
    // Write your code here.

    // Your code here
        
        stack<char> st;
        for(auto& ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else if(st.size() > 0){
                char c = st.top();
                if((c=='(' && ch == ')') || (c=='[' && ch == ']') || (c=='{' && ch == '}'))
                {
                    st.pop();
                } else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

        if(st.size() > 0){
            return false;
        } else{
            return true;
        }
}
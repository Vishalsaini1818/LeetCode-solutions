class Solution {
public:
    int perform_operation(int first, int second, string& op){
        if(op=="/")return first/second;
        else if(op=="-")return first-second;
        else if(op=="*")return first*second;
        return first+second;
    }

    bool check_operator(string &s){
        if(s=="+" ||s=="-" ||s=="/" ||s=="*")return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i=0;i<tokens.size();i++){
            if(!check_operator(tokens[i]))st.push(tokens[i]);
            else{
                int a=stoi(st.top());
                st.pop();
                int b=stoi(st.top());
                st.pop();
                int num=perform_operation(b,a,tokens[i]);
                st.push(to_string(num));
            }
        }
        int ans=stoi(st.top());
        return ans;
    }
};
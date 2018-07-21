#include<bits/stdc++.h>

using namespace std;
int check(char a)
{
    if(a == '^')
        return 3;
    else if(a=='*' || a=='/')
        return 2;
    else if(a=='+' || a=='-')
        return 1;
    else
        return -1;
}
string postfix(string infix)
{
    stack<char>st;
    st.push('N');
    string result;
    int Size = infix.size();
    for(int i=0;i<Size;i++)
    {
        if(isalnum(infix[i]))
            result+=infix[i];
        else if(infix[i] == '(')
            st.push('(');
        else if(infix[i] == ')')
        {
            while(st.top()!='N' && st.top()!='(')
            {
                result+=st.top();
                st.pop();
            }
            if(st.top() == '(')
                st.pop();
        }
        else
        {
            while(st.top()!='N' && check(infix[i])<=check(st.top()))
            {
                result+=st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while(st.top() != 'N')
    {
        result+=st.top();
        st.pop();
    }
    return result;
}
int main()
{
    string infix,post;
    cin>>infix;
    post = postfix(infix);
    cout<<"Postfix : "<<post<<endl;
    return 0;
}

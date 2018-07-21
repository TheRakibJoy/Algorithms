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
string prefix(string infix)
{
    string result;
    reverse(infix.begin(),infix.end());
    int Size = infix.size();
    for(int i=0;i<Size;i++)
    {
        if(infix[i] == ')')
            infix[i]='(';
        else if(infix[i] == '(')
            infix[i]=')';
    }
    result=postfix(infix);
    reverse(result.begin(),result.end());
    return result;
}
int main()
{
    string infix,pre;
    cin>>infix;
    pre = prefix(infix);
    cout<<"Prefix : "<<pre<<endl;
    return 0;
}


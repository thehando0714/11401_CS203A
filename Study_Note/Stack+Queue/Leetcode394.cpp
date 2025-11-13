class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        stack<int>st2;
        string cur;
        int num=0;
        for(int i=0;i<s.size();i++){        
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }     
            else if(s[i]=='['){
                st.push(cur);
                st2.push(num);
                cur="";
                num=0;
            }
            else if(s[i]==']'){
                int rep=st2.top();
                st2.pop();
                string pre=st.top();
                st.pop();
                string tmp;
                for(int k=0;k<rep;k++){
                    tmp+=cur;
                }
                cur=pre+tmp;
            }
            else{
                cur+=s[i];
            }
        }
        return cur;
    }
};

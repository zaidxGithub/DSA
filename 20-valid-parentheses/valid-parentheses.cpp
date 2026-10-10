class Solution {
public:
    bool isValid(string s) {
         
         stack<char>st;
         for(int i=0;i<s.length();i++){
            char ch=s[i];

            //1step:

            //Open bracket th to store else comparion

            if(ch=='{' ||ch=='[' ||ch=='('){
                //direclty insert
                st.push(ch);

            }else{
                //closing bracket found --> check if top value mathces or not
                if(st.empty()) return false;

                if(ch=='}' && st.top()!='{') return false;
                if(ch==']' && st.top()!='[') return false;
                if(ch==')' && st.top()!='(') return false;

                //means we have the same ch on top and curr
                st.pop();
            }

         }
            //ye case i usulayy forgot *** very important
            return st.empty();


         
        
    }
};
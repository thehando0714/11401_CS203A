class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty()){
                st.push(asteroids[i]);
            }
            else if((st.top()>0&&asteroids[i]<0)){
                while(!st.empty()&&st.top()>0&&asteroids[i]<0&&abs(asteroids[i])>abs(st.top())){
                        st.pop();
                }
                if(!st.empty()&&abs(asteroids[i])<abs(st.top())&&st.top()>0&&asteroids[i]<0){
                    continue;
                }
                bool eq=false;
                if(!st.empty()&&abs(asteroids[i])==abs(st.top())&&st.top()>0&&asteroids[i]<0){
                    eq=true;
                    st.pop();
                }   
                if(!eq){
                    st.push(asteroids[i]);
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int>vt;
        while(!st.empty()){
            vt.push_back(st.top());
            st.pop();
        }
        reverse(vt.begin(),vt.end());
        return vt;
    }
};

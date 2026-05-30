class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       list <int>lt;

       for(int i=0; i< asteroids.size(); i++){
        if(asteroids[i]>0) lt.push_back(asteroids[i]);

        else{
            while(!lt.empty() && lt.back()>0 && lt.back()< abs(asteroids[i])){
            lt.pop_back();
            }

        if(asteroids[i]<0 && ( lt.back()<0 || lt.empty() ) ) {
            lt.push_back(asteroids[i]);
            }
        else if(!lt.empty() && lt.back() == abs(asteroids[i])) {
            lt.pop_back();
        }
        
        }
        
       }
    return vector<int>(lt.begin(), lt.end());
    }
};
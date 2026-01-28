#include<iostream>
#include <cstdlib> 
using namespace std;

class Bug{
    private:
    int initial_pos;
    int x;

    public: 
    
    Bug(int x){
    initial_pos = x;
    }

    void turn(){
        initial_pos -= 2;
    }
     
    void move(){
        initial_pos += 1;     
    }

    int get_position(){
        return initial_pos;
    }
};


int main(){
    Bug bugsy(100);
    for (int i=0; i<= 100; i++){
        int rand_int = rand();
        if (rand_int % 2 == 0){
            bugsy.turn();
        }
        bugsy.move();
        if (i==25 | i==50 | i==75 | i==100){
            int position = bugsy.get_position();
            cout << "Bugs position = " << position<< " after " << i << " moves." << endl;
        }
    }
    // bugsy.move();
    // int result1 = bugsy.get_position();
    // cout << result1 << endl;
    // bugsy.turn();
    // bugsy.move();
    // int result2 = bugsy.get_position();
    // cout << result2;
    return 0;
}

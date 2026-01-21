#include <iostream>
using namespace std;


class HotelRoom{
    protected :
        int bedroom_num;
        int bathroom_num;
        
    public :
        HotelRoom(){
            bedroom_num = 0;
            bathroom_num = 0; }
        HotelRoom(int bedrooms, int bathrooms){
            bedroom_num = bedrooms;
            bathroom_num = bathrooms; 
            }
        virtual int get_price() const{
            return 50*bedroom_num +  100*bathroom_num ;
        }
    };

class Apartment : 

    public HotelRoom{
        public:
        Apartment(int bedrooms, int bathrooms) : HotelRoom(bedrooms, bathrooms) {};
        virtual int get_price() const override {
            return HotelRoom::get_price() + 100;
        }
    };


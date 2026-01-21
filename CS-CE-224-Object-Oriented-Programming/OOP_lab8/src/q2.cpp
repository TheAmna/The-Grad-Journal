#include <iostream>
#include <string>
using namespace std;

//Write Your Code Here
class Publication{
    private: 
        string title;
        float price;

    public:
        virtual void getdata(){
            getline(cin, title);
            cin >> price;
        }

        virtual void putdata(){
            cout << "Publication title : " << title << endl;
            cout << "Publication price : " << price << endl;
        }
};

class book : public Publication{
    private:
        int page_count;

    public: 
        void getdata() override {
            Publication::getdata();
            cin >> page_count;
        }

        void putdata() override{
            Publication:: putdata();
            cout << "Book page count : " << page_count << endl;
        }
};

class tape : public Publication{

    private:
        float playing_time;

    public:
    void getdata() override {
        Publication::getdata();
        cin >> playing_time;
    }

    void putdata() override {
        Publication:: putdata();
        cout << "Tape's playing time " << playing_time << endl;
    }
};


int main()
{
    book b;
    tape t;
    b.getdata();
    cin.ignore();
    t.getdata();
    b.putdata();
    t.putdata();
}
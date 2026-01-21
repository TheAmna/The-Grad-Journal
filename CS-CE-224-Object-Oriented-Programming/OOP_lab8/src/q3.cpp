#include <iostream>
using namespace std;

//Write Your Code Here
class Payment{
	private:
		double amount;

	public:

		virtual void paymentDetails(){
			cout << amount   << endl;
		}

		virtual void setAmount(double amt){
			amount = amt;
		}

	double getAmount(){
		return amount;
	}
};

class CashPayment : public Payment{
	private:
	public:
		CashPayment(double cash) {
			Payment :: setAmount(cash);
		}

		void paymentDetails() override {
			cout << "Amount of cash payment: " << Payment::getAmount() <<endl;
		}
};


class CreditCardPayment : public Payment{
	private :
	string cardName;
	string exp_date;
	string creditCardNum;

	public:
		CreditCardPayment(double amt, string name, string exp, string creditNum ){
			Payment::setAmount(amt);
			cardName = name;
			exp_date = exp;
			creditCardNum = creditNum;
		}

		void paymentDetails() override {
			cout << "Amount of credit card payment : $" << Payment::getAmount() << endl;
			cout << "Name on the credit card: " << cardName << endl; 
			cout << "Expiration date: " << exp_date << endl;
			cout << "Credit card number: " << creditCardNum <<  endl;
		}
};



int main()
{
	CashPayment cp1(75.25);
	CashPayment cp2(36.95);
	CreditCardPayment ccp1(95.15, "Smith", "12/21/2009", "321654987");
	CreditCardPayment ccp2(45.75, "James", "10/30/2008", "963852741");

	cout << "Details of Cash #1..." << endl;
	cp1.paymentDetails();
	
	cout << "\nDetails of Cash #2..." << endl;
	cp2.paymentDetails();
	
	cout << "\nDetails of Credit Card #1..." << endl;
	ccp1.paymentDetails();
	
	cout << "\nDetails of Credit Card #2..." << endl;
	ccp2.paymentDetails();
		
	return 0;
}
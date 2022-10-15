#ifndef W2inputs_h
#define W2inputs_h
class W2inputs
{
private:
	int GrossIncome;
	double RetainedTax;
	double State_Tax_Paid;
	double State_Fed_Paid;

public:

	int TaxableIncome(int GrossIncome);
	double NetReturn(int RetainedTax, double State_Tax_Paid, double State_Fed_Paid);

};
#endif


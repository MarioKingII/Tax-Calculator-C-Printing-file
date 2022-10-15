#ifndef TaxBrake_h
#define TaxBrake_h



class TaxBrake {

private:
	int Tax;
	double TaxFedBracket;
	double TaxStateBracket;

public:

	double TaxFed_to_pay(int Tax, double TaxFedBracket);
	double TaxState_to_pay(int Tax, double TaxStateBracket);

};
#endif

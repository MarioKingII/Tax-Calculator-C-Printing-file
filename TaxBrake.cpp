#include "TaxBrake.h"


//Calculate the Federal Tax 
double TaxBrake:: TaxFed_to_pay(int Tax, double TaxFedBracket)
{
	double Taxes;
	Taxes = Tax * TaxFedBracket;
	return Taxes;
}
//Calculate the State Tax 
double TaxBrake:: TaxState_to_pay(int Tax, double TaxStateBracket)
{
	double Taxes;
	Taxes = Tax * TaxStateBracket;
	return Taxes;
}


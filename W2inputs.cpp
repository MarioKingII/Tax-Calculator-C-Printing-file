#include "W2inputs.h"
#include <iostream>

using namespace std;

//Calculate the Net income
int W2inputs::TaxableIncome(int GrossIncome)
{
    int NetIncome;
    cout <<"Enter your income: ";
    cin >> GrossIncome;
    int Deduction = 12200;
    NetIncome = GrossIncome - Deduction;
    return NetIncome;
}

//Calculate the amoung to be paid
double W2inputs::NetReturn(int RetainedTax, double State_Tax_Paid, double State_Fed_Paid)
{
    double Total;
    cout <<"How much was retained during the year: ";
    cin >> RetainedTax;
    Total = RetainedTax - State_Tax_Paid - State_Fed_Paid;
    return Total;
}

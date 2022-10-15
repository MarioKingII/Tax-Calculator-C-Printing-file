#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <numeric> 
#include <string> 
#include <fstream> 
#include "TaxBrake.h"  //adding class
#include "W2inputs.h"  //adding class 
using namespace std;


// Determine if the user gets a refund or has to pay. 
void Refund_or_Payment(double Return)
{
    double NReturn = Return;
    if (NReturn >= 0)
    {
        cout <<"Your Refund is: " << NReturn << endl;
    }
    else
    {
        NReturn = NReturn * -1;
        cout <<"The amount due is: "<< NReturn << endl;
    }
} 


int main() {

    int RetainedTax = 0;
    double TaxStateBracket;
    double TaxFedBracket;
    int GrossIncome = 0;
    int State_Tax_Paid = 0;
    int State_Fed_Paid =0;

    W2inputs tax;

    int Tax = tax.TaxableIncome(GrossIncome);


    //Depending on user's income will determine the tax brake
    if (Tax <= 20000)
    {
        TaxStateBracket = 0.05;
        TaxFedBracket = 0.15;
    }
    else if (Tax >= 20000 || Tax < 40000)
    {
        TaxStateBracket = 0.08;
        TaxFedBracket = 0.20;
    }
    else if (Tax >= 40000 || Tax < 100000)
    {
        TaxStateBracket = 0.10;
        TaxFedBracket = 0.25;
    }
    else if (Tax >= 100000 || Tax < 140000)
    {
        TaxStateBracket = 0.11;
        TaxFedBracket = 0.27;
    }
    else if (Tax >= 140000 || Tax < 180000)
    {
        TaxStateBracket = 0.12;
        TaxFedBracket = 0.29;
    }
    else if (Tax >= 180000 || Tax < 250000)
    {
        TaxStateBracket = 0.13;
        TaxFedBracket = 0.32;
    }
    else if (Tax >= 250000)
    {
        TaxStateBracket = 0.14;
        TaxFedBracket = 0.34;
    }
    else
    {
        TaxStateBracket = 0.15;
        TaxFedBracket = 0.36;
    }

    // Calling classes methods 
    TaxBrake F;
    TaxBrake S;
    W2inputs N;
    string m;
    double Federal = F.TaxFed_to_pay(Tax, TaxFedBracket);
    double State = S.TaxState_to_pay(Tax, TaxStateBracket);
    double Return = N.NetReturn(RetainedTax, State, Federal);


    // Printing output
    cout << "Your Taxable Income was: " << Tax << endl;
    cout << "Your State Taxes was: " << State << endl;
    cout << "Your Federal Taxes was: " << Federal << endl;
    Refund_or_Payment(Return);

    // Crate a file Called 'YourReturn' with the results
    fstream Form;
    Form.open("YourReturn.txt", ios::app);
    if (Form.is_open()) {
        Form << "Your Taxable Income was: " << Tax << endl;
        Form << "Your State Taxes was: " << State << endl;
        Form << "Your Federal Taxes was: " << Federal << endl;
        Form << "----------------" << Return << endl;
        cout << "A file called 'YourReturn' has been created" << endl;
        }
    Form.close();
};


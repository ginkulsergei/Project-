//
//  main.cpp
//  Project Case 1
//
//  Created by Serhii Hinkul on 20/04/2019.
//  Copyright © 2019 Serhii Hinkul. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    double Pi, p, R, r;
    int FQ, month, year, i, N, Rate;
    
    cout<< "Provide Number of periods(only integer) "<<endl;//check for input errors do it later
    cin>>N;
    
    double Openbalance[N];
    double Interest[N];
    double Closingbalance[N];
    double PMTi[N];

    cout<< "Provide Present value"<<endl;
    cin>>p;
    /* if(cin.fail()) //cin.fail() checks to see if the value in the cin
     //stream is the correct type, if not it returns true,
     //false otherwise.
     {
     cin.clear(); //This corrects the stream.
     cin.ignore(); //This skips the left over stream data.
     cout << "Please enter an Integer only for Present value." << endl;
     cin>>p;
     // valid = false; //The cin was not an integer so try again.
     }*/
    cout<< "Provide Intrest Rate (in percentage)"<<endl;// make a boundary check fr errors
    cin>>R;
    cout<< "Provide Frequency (quarterly = 1 /n, semiannualy = 2 /n, annualy = 3)"<< "FQ"<<endl; //check for input errors do it
    cin>>FQ;
    if(FQ==1)
    {r=R/(4*100);}
    if(FQ==2)
    {r=R/(2*100);}
    if(FQ==3)
    {r=R/100;}

    //cout<< "Provide Starting month and year in the format MM/YYYY"<<endl;//check for input errors do it later
    //cin>>month>>year;
    
    

    
    Pi=p/N; //principal
    
    // interest
    //instalment

    
     //assigning the value of yearly rate
    //N=n; assigning the number of periods according to the frequency of payments
   
    Openbalance[0]=p;

    
    char listSeparator=';';
    ofstream csvFile;
    ofstream outputFile;
    csvFile.open ("Payments1.csv");
    csvFile  << "Period #"<< listSeparator <<"Opening Balance"<< listSeparator\
    <<"Principal"<< listSeparator <<"Periodic Interest rate"<< listSeparator <<\
    "Interest"<< listSeparator <<"Instalment"<< listSeparator <<"Closing Balance\n";
    
    
    
    for(int i=0; i<=N-1;i++) //computing the PV, PMT, Pi for every period by using loop
    //for(PViclose; PViclose>=0; PViclose=PViclose-Pi)
    {
       // PMTi=PVi1*r*(1+(1/((pow(1+r,N)-1))));

            //Pi[i]=PVi1-Pi;
        Interest[i]=Openbalance[i]*r;
        PMTi[i]=Pi+Interest[i];
        Closingbalance[i]=Openbalance[i]-Pi;
        Openbalance[i+1]=Closingbalance[i];
        
        Rate=r*100;
        
        csvFile << i+1 << listSeparator  << Openbalance[i] << listSeparator << Pi\
        << listSeparator << Rate<<"%" << listSeparator << Interest[i] << listSeparator <<\
        PMTi[i] << listSeparator << Closingbalance[i] << "\n";
        
        cout<<Openbalance[i]<<endl;
        cout<<Pi<<endl;
        cout<<Rate<<"%"<<endl;
        cout<<Interest[i]<<endl;
        cout<<PMTi[i]<<endl;
        cout<<Closingbalance[i]<<endl;
        cout << "====" << i << endl;



    }
    csvFile.close();
    
    cout << "Files saved!" ;
    //cin<<"Provide PVi1";
    //PMTi=Pi+Inti;
   // Inti=PVi1*R;
    

//print the results in Arrays,
        
}

#include<iostream>
#include<windows.h>
#include<limits>
#include<time.h>
#include<cmath>
#include <algorithm>
#undef max

using namespace std;

float l; //length of the needle thrown
float d; //distance between the lines on the surface
long long int t; //number of throws to be made
int r; // the number of positive results, i.e. times when the needle crossed one of vertical lines on the surface
double Pi; //the result of estimating Pi number
float x; //distance of the middle point of the needle to the nearest vertical line on the surface
int ang; //an angle between the thrown needle and the line parallel to the vertical line on the surface (in degrees)

int main()
{
    cout<<endl<<"This program estimates the value of the Pi number using the Buffon's Needle method"<<endl;
    Sleep(1000);
    cout<<endl<<"Programming language used: C++. Author: Jacek Motyka";
    cout<<endl<<"*******************************************************************"<<endl<<endl;
    Sleep(1000);
    once_again: //the label allowing the user to re-try the whole process after the program ends
    srand(time(NULL));
    cout<<"What is the distance between the vertical lines?"<<endl;
    cin>>d;

    /* THE BLOCK VALIDATING THE TYPE OF DATA INPUT FOR d */

    bool if_error_d = cin.fail();
    while (if_error_d==true)
    {
        cin.clear();
        cin.ignore(numeric_limits < streamsize >::max(), '\n' );
        cout << "Whoops! You've put wrong type of data. Try again!"<< endl;
        cout << "What is the distance then?" << endl;
        cin >>d;
        if (!(cin.fail()))
            break;
    }
//***********************************************************************************
    cout<<endl<<"What is the length of the needle?"<<endl;

l_data_type_verification: //label marking data input re-try for the l variable

    cin>>l;

    /* THE BLOCK VALIDATING THE TYPE OF DATA INPUT FOR l */

    bool if_error_l = cin.fail();
    if (if_error_l==true)
    {
        cin.clear();
        cin.ignore(numeric_limits < streamsize >::max(), '\n' );
        cout << "Whoops! You've put wrong type of data. Try again!"<< endl << "Again, what is the length of the needle?"<<endl;
        goto l_data_type_verification;
    }
    else if(l>d)
    {
        cin.clear();
        cin.ignore(numeric_limits < streamsize >::max(), '\n' );
        cout<<"The needle cannot be longer then distance between the lines! Try again!"<<endl;
        goto l_data_type_verification;
    }
    /* ************************************************************************************************* */
    cout<<endl<<"How many times would you like to throw the needle?"<<endl;
    cin>>t;

    /* THE BLOCK VALIDATING THE TYPE OF DATA INPUT FOR t */

    bool if_error_t = cin.fail();
    while (if_error_t==true)
    {
        cin.clear();
        cin.ignore(numeric_limits < streamsize >::max(), '\n' );
        cout << "Whoops! You've put wrong type of data. Try again!"<< endl;
        cout << "How many throws would you like to do?" << endl;
        cin >>t;
        if (!(cin.fail()))
            break;
    }
//***********************************************************************************

    cout<<endl<<"Distance between the vertical lines: "<<d<<". Length of the needle: "<<l<<"."<<endl;
    cout<<endl<<"I will throw the needle "<<t<<" times! Throwing in progress..."<<endl;

/* a loop throwing the needle "t" times and increasing the number of positive results "r" if the needle crossed any of the lines */

        for (int i = 0; i<t; i++)
        {
            float crossed;
            ang = static_cast <int> (rand()) / (static_cast <int> (RAND_MAX/180)); //random angle
            float sinus=sin(ang/57.295); //radians to degrees and calculation of sin(ang)
            x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(l/2))); //random distance from the middle of the needle to the closest line (cannot be longer than l/2)
            crossed = ((l/2)*sinus);
            if (x<=crossed)
            {
                r++;
            }
        }
 //*****************************************************************************************************************************
    cout<<endl<<"Number of positive trials: "<<r<<endl;
    Pi = (2*l*t)/(d*r);
//******************************************************************************************************************************

    cout<<endl<<"The estimated value of the Pi number is: "<<Pi<<"."<<endl<<"Would you like to try again? (Y/N)"<<endl<<endl;
    char choice;
    cin>>choice;
    if (choice=='Y' || choice=='y')
    {
        cout<<endl<<"*******************************************************************"<<endl<<endl;
        r=0; //r has to be zeroed out if restarting the program
        goto once_again;
    }
    else
        return (0);
}

#include <iostream>
#include <windows.h>
#include "Needle.h"

using namespace std;

int main()
{
    float distance_input, length_input;
    int throws_input;
    char choice;

cout<<endl<<"This program estimates the value of the Pi number using the Buffon's Needle method"<<endl;
Sleep(1000);
cout<<"It has been written using OOP methods"<<endl;
Sleep(1000);
cout<<endl<<"Programming language used: C++. Author: Jacek Motyka";
cout<<endl<<"*******************************************************************"<<endl<<endl;

do
{
    Sleep(1000);

    Needle my_needle;

    cout<<"What is the length of the needle?"<<endl;
    length_input = my_needle.Float_Valid_Input();
    my_needle.set_length(length_input);

    cout<<"What is the distance between the vertical lines?"<<endl;
    do
    {
    distance_input = my_needle.Float_Valid_Input();
    if (distance_input<length_input) cout<<"The needle cannot be longer than the distance between the lines! Try again: "<<endl;
    } while (distance_input<length_input);

    my_needle.set_distance(distance_input);

    cout<<"How many times would you like to throw your needle?"<<endl;
    throws_input = my_needle.Integer_Valid_Input();
    my_needle.set_throws(throws_input);

    cout<<"The estimated value of Pi number using";
    cout<<" Buffon's Needle method is: "<<my_needle.get_Pi(distance_input, length_input, throws_input)<<endl;

    Sleep(1000);

    cout<<"Would you like to start again? [Y/N]"<<endl;
    cin>>choice;

  if (choice=='Y' || choice=='y')
   {
    cout<<endl<<"*******************************************************************"<<endl<<endl;
   }
    else break;

} while(true);

cout<<"Thank you!"<<endl;

system("pause");

return (0);
}

#include "Needle.h"
#include<iostream>
#include<windows.h>
#include<limits>
#include<time.h>
#include<cmath>

using namespace std;

Needle::Needle()
{
    len=0;
    dist=0;
    throws=0;
}

void Needle::set_length(float length_input)
{
    len=length_input;
}

void Needle::set_throws(int throws_input)
{
    throws=throws_input;
}

void Needle::set_distance(float distance_input)
{
    dist=distance_input;
}

double Needle::get_Pi(float distance_input, float length_input, int throws_input)
{
    srand(time(NULL));
    int positives=0;
    for (int i = 0; i<throws_input; i++)
    {
    int temp_angle = static_cast <int> (rand()) / (static_cast <int> (RAND_MAX/180)); //random angle
    float sinus=sin(temp_angle/57.295); //radians to degrees and calculation of sin(ang)
    float temp_distance;
    temp_distance = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(length_input/2))); //random distance from the middle of the needle to the closest line (cannot be longer than l/2)
    float crossed = (((length_input)/2)*sinus);
    if (temp_distance<=crossed)
        {
            positives++;
        }
    }
    double Pi = (2*length_input*throws_input)/(distance_input*positives);
    return Pi;
}

int Needle::Integer_Valid_Input()
{
    int x;
    cin >> x;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You have typed wrong type of data. Try again: ";
        cin >> x;
    }
    return x;
}

float Needle::Float_Valid_Input()
{
    float x;
    cin >> x;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You have typed wrong type of data. Try again: ";
        cin >> x;
    }
    return x;
}
/*
Needle::~Needle()
{
    //dtor
}
*/

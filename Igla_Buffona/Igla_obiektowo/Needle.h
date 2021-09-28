#pragma once
#ifndef NEEDLE_H
#define NEEDLE_H

class Needle
{
    float len, dist;
    int throws;

    public:

        Needle();
        //Needle(float);
        //Needle(float, float);
        //Needle(float, float, int);

        void set_length(float);
        void set_throws(int);
        void set_distance(float);

        double get_Pi(float, float, int);

        int Integer_Valid_Input();
        float Float_Valid_Input();
};

#endif // NEEDLE_H

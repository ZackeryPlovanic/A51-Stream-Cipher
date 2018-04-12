/*
 * A51.h
 *
 *  Created on: Apr 10, 2018
 *      Author: ME
 */
#ifndef A51_H_
#define A51_H_

class A51{
    public:
        //the 64 bit Key initializes the 3 registers with their start values
        A51(bool key[64]);

        //Generates the keystream used for Encrypting
        //Input:    the size of the needed keystream
        //Output:   A dynamically allocated boolean array filled with
        //          the Keystream bits. The size of the array is the
        //          equal to the Input parameter
        bool* generateKeystream(int sizeOfKeystream);

    private:

        const int majIndexX=10;
        const int majIndexY=12;
        const int majIndexZ=14;

        bool regX [20];
        bool regY [22];
        bool regZ [22];

        //A51();

        //Used to calculate the majority value in each register's majority index
        bool calcMaj();

        //Calculates the value that is placed in regX[0] during a rotate
        bool rotateValX();

        ////Calculates the value that is placed in regY[0] during a rotate
        bool rotateValY();

        ////Calculates the value that is placed in regZ[0] during a rotate
        bool rotateValZ();

        //Rotates the 3 registers dependent if their majIndex is equal to the calcMaj() value
        void rotateReg();

        //Generates the Keystream bit dependent on the last index in each register
        bool outputBit();
};

#endif /* A51_H_ */

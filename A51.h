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

        A51();

        //the 64 bit Key initializes the 3 registers with their start values
        A51(bool secret_key[64]);

        //fills the three registers with a new secret key
        //Input:    A 64 bit key in the form of a bool array
        //Output:   NULL
        void infillRegisters(bool secret_key[64]);

        //Generates the keystream used for Encrypting
        //Input:    the size of the needed keystream
        //Output:   A dynamically allocated boolean array filled with
        //          the Keystream bits. The size of the array is the
        //          equal to the Input parameter
        void generateKeystream(bool keystream[],int sizeOfKeystream);

    private:

        const int majority_Index_X=8;
        const int majority_Index_Y=10;
        const int majority_Index_Z=10;
        const int regX_size = 19;
        const int regY_size = 22;
        const int regZ_size = 23;

        bool regX [19];
        bool regY [22];
        bool regZ [23];

        //Used to calculate the majority value in each register's majority index
        //Input:    NULL
        //Output:   returns true if most of the values in the majority_Index's are true
        //          returns false if most of the values in the majority_Index's are false
        bool calcMaj();

        //Calculates the value that is placed in regX[0] during a rotate
        //Input:    NULL
        //Output:   Returns the value that is to be placed into regX[0] once the register shifts
        bool rotateValX();

        //Calculates the value that is placed in regY[0] during a rotate
        //Input:    NULL
        //Output:   Returns the value that is to be placed into regY[0] once the register shifts
        bool rotateValY();

        //Calculates the value that is placed in regZ[0] during a rotate
        //Input:    NULL
        //Output:   Returns the value that is to be placed into regZ[0] once the register shifts
        bool rotateValZ();

        //Rotates the 3 registers depending if their majority_Index is equal to the calcMaj() value
        //Input:    NULL
        //Output:   NULL
        void rotateReg();

        //Generates the keystream bit dependent on the last index in each register
        //Input:    NULL
        //Output:   Returns the keystream bit that will be used to produce the ciphertext
        bool outputBit();
};

#endif /* A51_H_ */

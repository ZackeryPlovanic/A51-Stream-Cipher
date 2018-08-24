/*
 * A51.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: ME
 */
#include "A51.h"
#include <iostream>
using namespace std;

A51::A51(){

}

A51::A51(bool secret_key[64]){

   infillRegisters(secret_key);
}

void A51::infillRegisters(bool secret_key[64]){
    for(int i=0; i<64; i++){
           if (i < regX_size)
           {
               regX[i] = secret_key[i];
           }
           else if (i < (regX_size+regY_size))
           {
               regY[i-regX_size] = secret_key[i];
           }
           else
           {
               regZ[i-(regX_size + regY_size)] = secret_key[i];
           }
       }
}

bool A51::calcMaj(){
    int sum = 0;

    if(regX[majority_Index_X]) sum++;
    if(regY[majority_Index_Y]) sum++;
    if(regZ[majority_Index_Z]) sum++;

    if(sum >= 2)  return(true);
    else        return(false);
}

bool A51::rotateValX(){
    return (regX[12]^regX[15]^regX[16]^regX[18]^regX[19]);
}

bool A51::rotateValY(){
    return (regY[11]^regY[14]^regY[16]);
}

bool A51::rotateValZ(){
    return (regZ[7]^regZ[13]^regZ[15]^regX[20]^regX[21]);
}

void A51::rotateReg(){

    bool majority = calcMaj();

    if(regX[majority_Index_X] == majority){
        for(int i=19; i>=1; i--){
            regX[i] = regX[i-1];      //shift right
        }
        regX[0] = rotateValX();       //rotate new value in
    }//end if

    if(regY[majority_Index_Y] == majority){
            for(int i=21; i>=1; i--){
                regY[i] = regY[i-1];
            }
            regY[0] = rotateValY();
        }//end if

    if(regZ[majority_Index_Z] == majority){
            for(int i=21; i>=1; i--){
                regZ[i] = regZ[i-1];
            }
            regZ[0] = rotateValZ();
        }//end if

}


bool A51::outputBit(){
    return ( regX[19]^regY[21]^regZ[21] );
}

void A51::generateKeystream(bool keystream[], int sizeOfKeystream){

    for(int i=0; i < sizeOfKeystream; i++){
        keystream[i] = outputBit();
        rotateReg();
    }
}

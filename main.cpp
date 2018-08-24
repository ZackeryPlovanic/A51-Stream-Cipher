//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "A51.h"
using namespace std;

int main() {
    bool keystream[4];
    bool key[64];
    for(int i =0; i<64; i++)  (i%2) ? key[i] = true : key[i] = false;

    A51 cipher(key);
    cipher.generateKeystream(keystream, 4);

    cout<<keystream[0]<<" "<<keystream[1]<<" "<<keystream[2]<<" "<<keystream[3];
    return 0;
}

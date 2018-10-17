/*
 * sigTest.cpp driver file
 *
*/

// Headers
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "sighandler.h"

int main() {
    int iret = 0;

    try {
        SigHand sigHandler;

        // Register signal to handle kill signal
        sigHandler.setupSigHands();

        // Infinite loop until ctrl-c (KILL) received
        while(!sigHandler.getExitSig())
            sleep(1);

        iret = EXIT_SUCCESS;
    }
    catch(SigExcp &exception) {
        std::cerr << "SigExcp: " << exception.what() << "\n";
        iret = EXIT_FAILURE;
    }

    return iret;
}


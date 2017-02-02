#include <iostream>

#include "KnnIris.h"
#include "LRFire.h"

static std::string help(){
    std::cout << "usage: DataMiningExample [--version] [--help] [--algo={knniris,forestfire}]" << std::endl;
}

int main(int argc, char* argv[]) {
    if(argc == 2) {
        std::string command(argv[1]);

        if (command == "--help") {
            help();
        } else if (command == "--algo=knniris") {
            KnnIris irisProblem;
            irisProblem.irisEvaluation();
        }  else if (command == "--algo=forestfire") {
            LRFire lr;
            lr.fireEvaluation();
        } else {
            help();
        }
    } else {
        help();
    }

    return 0;
}
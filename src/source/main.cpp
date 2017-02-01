#include <iostream>

#include "KnnIris.h"

static std::string help(){
    std::cout << "usage: DataMiningExample [--version] [--help] [--algo={knniris}]" << std::endl;
}

int main(int argc, char* argv[]) {
    if(argc == 2) {
        std::string command(argv[1]);

        if (command == "--help") {
            help();
        } else if (command == "--algo=knniris") {
            KnnIris irisProblem;
            irisProblem.irisEvaluation();
        } else {
            help();
        }
    } else {
        help();
    }

    return 0;
}
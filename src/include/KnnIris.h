//
// Created by Thibaud Ecarot on 01/02/17.
//

#ifndef DATAMININGEXAMPLE_KNNIRIS_H
#define DATAMININGEXAMPLE_KNNIRIS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>

/**
 *
 */
class Iris {
public:
    double petalLength;
    double petalWidth;
    double sepalLength;
    double sepalWidth;
    std::string speciename;

    Iris(double petalLength, double petalWidth, double sepalLength, double sepalWidth, std::string specie);
    ~Iris();
    double euclideanDistance(Iris other);
};

class Fitness {
public:
    double score;
    std::string specie;

    Fitness(double score, std::string specie) {
        this->score = score;
        this->specie = specie;
    }
};

class KnnIris {

public:
    std::vector<Iris> irisList;
    std::vector<Iris> learnbase;

    std::string speciesPrediction(double petalLength, double petalWidth, double sepalLength, double sepalWidth);
    void loadData(std::string filepath);
    void irisEvaluation();
};


#endif //DATAMININGEXAMPLE_KNNIRIS_H

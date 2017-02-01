//
// Created by Thibaud Ecarot on 01/02/17.
//

#include "KnnIris.h"

using namespace std;

Iris::Iris(double petalLength, double petalWidth, double sepalLength, double sepalWidth, std::string specie) {
    this->petalLength = petalLength;
    this->petalWidth = petalWidth;
    this->sepalLength = sepalLength;
    this->sepalWidth = sepalWidth;
    this->speciename = specie;
}
Iris::~Iris() {}

/**
 * Using Euclidean Distance in N-Dimension to compare two Iris.
 * @param other
 * @return
 */
double Iris::euclideanDistance(Iris other) {
    return std::sqrt(std::pow(this->sepalLength - other.sepalLength, 2) + std::pow(this->sepalWidth - other.sepalWidth, 2)
                     + std::pow(this->petalLength - other.petalLength, 2) + std::pow(this->petalWidth - other.petalWidth, 2));
}

/**
 * Load Iris Data with different species
 * @param filepath
 */
void KnnIris::loadData(std::string filepath) {
    ifstream dataFile(filepath);
    std::string line;
    std::string field;
    stringstream ss(line);

    if(dataFile)
    {
        std::string petalLength;
        std::string petalWidth;
        std::string sepalLength;
        std::string sepalWidth;
        std::string speciename;
        while(std::getline( dataFile, line))
        {
            std::istringstream iss(line);
            std::getline(iss, sepalLength, ',');
            std::getline(iss, sepalWidth, ',');
            std::getline(iss, petalLength, ',');
            std::getline(iss, petalWidth, ',');
            std::getline(iss, speciename);

            Iris iris(std::stod(petalLength), std::stod(petalWidth), std::stod(sepalLength), std::stod(sepalWidth), speciename);
            irisList.push_back(iris);
        }
    } else
    {
        cout << "While opening a file an error is encountered" << endl;
    }
}

/**
 * Using KNN algorithm to find specie of specific Iris
 * @param petalLength
 * @param petalWidth
 * @param sepalLength
 * @param sepalWidth
 * @return string predicted Specie
 */
std::string KnnIris::speciesPrediction(double petalLength, double petalWidth, double sepalLength, double sepalWidth) {
    Iris unknownIris(petalLength, petalWidth, sepalLength, sepalWidth, "");
    std::vector<Fitness> fitnessList;
    for(Iris &item: learnbase) {
        fitnessList.push_back(Fitness(unknownIris.euclideanDistance(item), item.speciename));
    }
    std::sort(fitnessList.begin(), fitnessList.end(), [](Fitness a, Fitness b) {
        return b.score > a.score;
    });

    int k=6;
    std::map<std::string, int> countkspecie;
    if(k >= fitnessList.size()) {
        cout << "/!\\ The number of neighbors can not be greater than the number of knowledge" << endl;
        exit(1);
    } else {
        for (int i = 0; i < k; ++i) {
            std::string specie = fitnessList.at(i).specie;
            std::map<std::string, int>::iterator it = countkspecie.find(specie);
            if(it != countkspecie.end() ) {
                it->second = it->second+1;
            } else {
                countkspecie.insert(std::pair<std::string, int>(specie,1));
            }
        }
    }

    double bestfitness = 0.0;
    std::string bestspecie;
    for (const auto &p : countkspecie) {
        if (bestfitness < p.second) {
            bestspecie = p.first;
        }
    }


    return bestspecie;
}

/**
 * Evaluation of KNN Algorithm for Iris Classification
 */
void KnnIris::irisEvaluation() {
    cout << "Starting Iris Data Evaluation..." << endl;
    cout << "Loading Iris Data..." << endl;
    this->loadData("../data/iris_data.csv");

    srand(time(0));
    std::random_shuffle ( irisList.begin(), irisList.end() );
    int middle = irisList.size() / 2;
    learnbase = std::vector<Iris>(irisList.begin(), irisList.end() - middle);
    std::vector<Iris> testbase(irisList.begin(), irisList.end() - middle);

    int error=0;

    for(auto &item: testbase) {
        std::string prediction = this->speciesPrediction(item.petalLength, item.petalWidth, item.sepalLength, item.sepalWidth);
        if(item.speciename.compare(prediction) != 0) {
            error++;
        }
    }
    cout << "Nb Error: " << error << "\t" << " Error Rate: " << ((error*100)/testbase.size()) << "%" << endl;

}
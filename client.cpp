//
// Created by Sztajer on 2018-12-30.
//
#include "client.h"
#include "exceptions.h"


std::string Client::getIdNumber() {
    return client_IdNumber;
}

std::string Client::getFullName() {
    return client_fullName;
}

int Client::getPriority() {
    return client_priority;
}

const std::string &Client::getBiometricData() {
    return client_biometricData;
}

Client::~Client() = default;

Client::Client(const std::string &IdNumber) {
    this->client_IdNumber=IdNumber;
    this->client_priority=0;
}

void Client::setFullName(const std::string &fullName) {
    this->client_fullName=fullName;

}

void Client::updatePriority(int priority) {
    this->client_priority=priority;
}

void Client::updateBiometricData(const std::string &biometricData) {

    for( char znak: biometricData ) {
        if( !(znak=='G'||znak=='T'||znak=='C'||znak=='A')) throw IncorrectBiometricDataException("bad DNA");}
    this->client_biometricData=biometricData;
}
double similarityScore(char a,char b) {
    return (a == b) ? 3 : -3;
}
bool Client::verifyBiometricData(const std::string &biometricData, double threshold) {
    for( char znak: biometricData ) {
        if( !(znak=='G'||znak=='T'||znak=='C'||znak=='A')) throw IncorrectBiometricDataException("bad DNA");
}

        // initialize some variables
        int penalty=2;
        int lengthSeqA = biometricData.length();
        int lengthSeqB = client_biometricData.length();

        // initialize matrix
        double matrix[lengthSeqA+1][lengthSeqB+1];
        for(int i=0;i<=lengthSeqA;i++)
        {
            for(int j=0;j<=lengthSeqB;j++)
            {
                matrix[i][j]=0;
            }
        }

        double traceback[4];

        for (int i=1;i<=lengthSeqA;i++)
        {
            for(int j=0;j<=lengthSeqB;j++)
            {   double max=0;
                traceback[0] = matrix[i-1][j-1]+similarityScore(biometricData[i-1],client_biometricData[j-1]);
                traceback[1] = matrix[i-1][j]+penalty;
                traceback[2] = matrix[i][j-1]+penalty;
                traceback[3] = 0;
                for(int k=1; i<4; i++)
                {
                    if(traceback[k] > max)
                    {
                        max = traceback[k];
                    }
                }
                matrix[i][j] = max;
            }
        }

        // find the max score in the matrix
        double matrix_max = 0;
        int i_max=0, j_max=0;
        for(int i=1;i<lengthSeqA;i++)
        {
            for(int j=1;j<lengthSeqB;j++)
            {
                if(matrix[i][j]>matrix_max)
                {
                    matrix_max = matrix[i][j];
                    i_max=i;
                    j_max=j;
                }
            }
        }

    double maxScore = matrix[i_max][j_max];
    double shorterSequence = (lengthSeqA < lengthSeqB) ? lengthSeqA : lengthSeqB;
    double normalizedScore = maxScore / shorterSequence;

    return normalizedScore > threshold;
}

void Client::newPackage(const std::string &packageId) {
    for(auto &i :packages){
        if (i == packageId)
            throw PackageExistsException("same package");
    }
    this->packages.push_back(packageId);
}

std::vector<std::string> Client::awaitingPackages() {
    return packages;
}

void Client::packagesCollected() {
    packages.erase(packages.begin(),packages.end());

}




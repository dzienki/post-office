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

Client::~Client() {

}

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
    this->client_biometricData=biometricData;
}

bool Client::verifyBiometricData(const std::string &biometricData, double threshold) {
//    double similarityScore(char a, char b)
//    {
//        double result;
//        if(a==b)
//        {
//            result=1;
//        }
//        else
//        {
//            result=penalty;
//        }
//        return result;
//    }
//
//    double findMax(double array[], int length)
//    {
//        double max = array[0];
//        ind = 0;
//
//        for(int i=1; i<length; i++)
//        {
//            if(array[i] > max)
//            {
//                max = array[i];
//                ind=i;
//            }
//        }
//        return max;
//    }
//
//    int main()
//    {
//        string seqA; // sequence A
//        string seqB; // sequence B
//        cout << "Sequence A" << endl;
//        cin >> seqA;
//        cout << "Sequence B" << endl;
//        cin >> seqB;
//        cout << "You typed in " << endl << seqA << endl << seqB << endl;
//
//        // initialize some variables
//        int lengthSeqA = seqA.length();
//        int lengthSeqB = seqB.length();
//
//        // initialize matrix
//        double matrix[lengthSeqA+1][lengthSeqB+1];
//        for(int i=0;i<=lengthSeqA;i++)
//        {
//            for(int j=0;j<=lengthSeqB;j++)
//            {
//                matrix[i][j]=0;
//            }
//        }
//
//        double traceback[4];
//        int I_i[lengthSeqA+1][lengthSeqB+1];
//        int I_j[lengthSeqA+1][lengthSeqB+1];
//
//
//        for (int i=1;i<=lengthSeqA;i++)
//        {
//            for(int j=0;j<=lengthSeqB;j++)
//            {
//                cout << i << " " << j << endl;
//                traceback[0] = matrix[i-1][j-1]+similarityScore(seqA[i-1],seqB[j-1]);
//                traceback[1] = matrix[i-1][j]+penalty;
//                traceback[2] = matrix[i][j-1]+penalty;
//                traceback[3] = 0;
//                matrix[i][j] = findMax(traceback,4);
//            }
//        }
//
//        // print the scoring matrix to console
//        for(int i=1;i<lengthSeqA;i++)
//        {
//            for(int j=1;j<lengthSeqB;j++)
//            {
//                cout << matrix[i][j] << " ";
//            }
//            cout << endl;
//        }
//
//        // find the max score in the matrix
//        double matrix_max = 0;
//        int i_max=0, j_max=0;
//        for(int i=1;i<lengthSeqA;i++)
//        {
//            for(int j=1;j<lengthSeqB;j++)
//            {
//                if(matrix[i][j]>matrix_max)
//                {
//                    matrix_max = matrix[i][j];
//                    i_max=i;
//                    j_max=j;
//                }
//            }
//        }
//
       return true;
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


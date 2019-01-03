//
// Created by Sztajer on 2018-12-30.
//

#ifndef POCZTA_CLIENT_H
#define POCZTA_CLIENT_H

#include "iclient.h"

class Client: public IClient {
public:
    explicit Client(const std::string &IdNumber); //done
    ~Client() override;
    std::string getIdNumber() override; //done
    std::string getFullName() override; //done
    int getPriority() override;  //done
    const std::string &getBiometricData() override; //done
    void setFullName(const std::string &fullName) override; //done
    void updatePriority(int priority) override; //done
    void updateBiometricData(const std::string &biometricData) override; //done
    bool verifyBiometricData(const std::string &biometricData, double threshold) override;
    void newPackage(const std::string &packageId) override; //bez exceptation
    std::vector<std::string> awaitingPackages() override; //done
    void packagesCollected() override; //done

private:
    std::vector<std::string> packages;
    std::string client_IdNumber;
    std::string client_fullName;
    std::string client_biometricData;
    int client_priority;


};


#endif //POCZTA_CLIENT_H

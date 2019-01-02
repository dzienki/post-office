//
// Created by Sztajer on 2018-12-30.
//

#include "client.h"


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
    return false;
}

void Client::newPackage(const std::string &packageId) {

}

std::vector<std::string> Client::awaitingPackages() {
    return packages;
}

void Client::packagesCollected() {

}

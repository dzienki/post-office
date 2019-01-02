//
// Created by Sztajer on 2018-12-30.
//

#include "client.h"


std::string Client::getIdNumber() {
    return m_IdNumber;
}

std::string Client::getFullName() {
    return m_fullName;
}

int Client::getPriority() {
    return m_priority;
}

const std::string &Client::getBiometricData() {
    return m_biometricData;
}

Client::~Client() {

}

Client::Client(const std::string &IdNumber) {

}

void Client::setFullName(const std::string &fullName) {
    this->m_fullName=fullName;

}

void Client::updatePriority(int priority) {
    this->m_priority=priority;
}

void Client::updateBiometricData(const std::string &biometricData) {
    this->m_biometricData=biometricData;
}

bool Client::verifyBiometricData(const std::string &biometricData, double threshold) {
    return false;
}

void Client::newPackage(const std::string &packageId) {

}

std::vector<std::string> Client::awaitingPackages() {
    return std::vector<std::string>();
}

void Client::packagesCollected() {

}

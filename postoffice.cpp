//
// Created by Sztajer on 2018-12-30.
//

#include "postoffice.h"
std::shared_ptr<IPostOffice> IPostOffice::create(unsigned gate_count) {
    return std::shared_ptr<IPostOffice>(new Postoffice(gate_count));
}

Postoffice::Postoffice(unsigned gate_count) {
    this->gateCounter=gate_count;

}

Postoffice::~Postoffice() {

}

std::vector<std::string> Postoffice::getStatus() {
    return std::vector<std::string>();
}

std::shared_ptr<IClient> Postoffice::getClient(const std::string &identificationNumber) {

    return post_clients;
}

void Postoffice::enqueueClient(const std::shared_ptr<IClient> &client) {

}

void Postoffice::gateReady(unsigned gateIndex) {

}

void Postoffice::collectPackages(unsigned gateIndex) {

}


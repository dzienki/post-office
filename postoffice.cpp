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
//    for(int i=0; i<=post_clients.size();i++){
//        if(post_clients[i]==identificationNumber){
//            return post_clients[i];
//        }
//    }
    post_clients.push_back(std::shared_ptr<IClient>(new Client(identificationNumber)));
    return post_clients[post_clients.size()];
}

void Postoffice::enqueueClient(const std::shared_ptr<IClient> &client) {

}

void Postoffice::gateReady(unsigned gateIndex) {

}

void Postoffice::collectPackages(unsigned gateIndex) {

}



//
// Created by Sztajer on 2018-12-30.
//

#include "postoffice.h"
#include "client.h"

std::shared_ptr<IPostOffice> IPostOffice::create(unsigned gate_count) {
    return std::shared_ptr<IPostOffice>(new Postoffice(gate_count));
}

Postoffice::Postoffice(unsigned gate_count) {
    this->gateCounter=gate_count;
    startqueue();
}

Postoffice::~Postoffice() {

}

std::vector<std::string> Postoffice::getStatus() {
    return std::vector<std::string>();
}

std::shared_ptr<IClient> Postoffice::getClient(const std::string &identificationNumber) {
    for (auto &i :post_clients) {
        if (i->getIdNumber() == identificationNumber)
            return i;
    }
    post_clients.push_back(std::shared_ptr<IClient>(new Client(identificationNumber)));
    return post_clients.back();

}

void Postoffice::enqueueClient(const std::shared_ptr<IClient> &client) {

    post_queue.push_back(client);
    //client->packagesCollected();

}

void Postoffice::gateReady(unsigned gateIndex) {
    if (post_gate[gateIndex]== nullptr){
       post_gate.erase(post_gate.begin()+gateIndex);
      post_gate.insert(post_gate.begin()+gateIndex,post_queue.front());
    }

}

void Postoffice::collectPackages(unsigned gateIndex) {
    if(post_gate[gateIndex]!= nullptr){
        post_gate[gateIndex]->packagesCollected();
        post_gate.erase(post_gate.begin()+gateIndex);
        post_gate.insert(post_gate.begin()+gateIndex, nullptr);
        post_queue.erase(post_queue.begin());
    }
}

void Postoffice::startqueue() {
    post_gate.push_back(nullptr);
    for(int i=1; i <gateCounter;++i){
        post_gate.push_back(nullptr);
    }

}



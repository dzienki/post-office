//
// Created by Sztajer on 2018-12-30.
//

#include "postoffice.h"
#include "client.h"
#include "exceptions.h"

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
    std::vector<std::string> status;
    for(auto &i : post_gate){
        if(i== nullptr) status.emplace_back("");
        else status.push_back(i->getFullName());
    }
    return status;
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
    int j=0;
    if(post_queue.empty()){
        post_queue.push_back(client);
    }
    else{
    for(auto &i :post_queue)
    {
        if(client->getPriority()>i->getPriority()){
            post_queue.insert(post_queue.begin()+j,client);
            break;
        }
        j++;
    }}
    //post_queue.push_back(client);
    //client->packagesCollected();

}

void Postoffice::gateReady(unsigned gateIndex) {

    if(gateIndex>=gateCounter){
        throw IncorrectGateException("gate don't exist");
    }
//    if(post_gate[gateIndex]== nullptr){
        post_gate[gateIndex]=post_queue.front();
        post_queue.erase(post_queue.begin());
//    }
//    if(post_queue.empty()){
//        for(int i=0; i<gateCounter; ++i){
//            post_gate[i]= nullptr;
//        }
//
//    }


}

void Postoffice::collectPackages(unsigned gateIndex) {
    if(post_gate[gateIndex]== nullptr)
        throw IncorrectGateException("there is noone at gate");
    if(gateIndex>=gateCounter)
        throw IncorrectGateException("gate don't exist");

    if(post_gate[gateIndex]!= nullptr){
        post_gate[gateIndex]->packagesCollected();
//        post_gate.erase(post_gate.begin()+gateIndex);
//        post_gate.insert(post_gate.begin()+gateIndex, nullptr);
    }
}

void Postoffice::startqueue() {
    post_gate.push_back(nullptr);
    for(int i=1; i <gateCounter;++i){
        post_gate.push_back(nullptr);
    }

}



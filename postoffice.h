//
// Created by Sztajer on 2018-12-30.
//

#ifndef POCZTA_POSTOFFICE_H
#define POCZTA_POSTOFFICE_H
#include "ipostoffice.h"
#include <string>
#include <fstream>
#include <iostream>

class Postoffice: public IPostOffice {
public:
    explicit Postoffice(unsigned gate_count);
    ~Postoffice() override;
    std::vector<std::string> getStatus() override;
    std::shared_ptr<IClient> getClient(const std::string &identificationNumber) override;
    void enqueueClient(const std::shared_ptr<IClient> &client) override;
    void gateReady(unsigned gateIndex) override;
    void collectPackages(unsigned gateIndex) override;

private:
    unsigned gateCounter;
    std::vector<std::shared_ptr<IClient>> post_queue;
    std::vector<std::shared_ptr<IClient>> post_gate;
    std::vector<std::shared_ptr<IClient>> post_clients;

};


#endif //POCZTA_POSTOFFICE_H

#include <iostream>
#include "ipostoffice.h"
#include <cassert>
#include "exceptions.h"
#include <vector>
//#include "postoffice.h"
//#include "client.h"

int main() {

//    auto post_office = IPostOffice::create(5);
//
//    auto client0 = post_office->getClient("96052791812");
//    client0->setFullName("Jan Kowalski");
//    auto client1 = post_office->getClient("69100839677");
//    client1->setFullName("Adam Nowak");
//    client1->updatePriority(1);
//
//    post_office->enqueueClient(client0);
//    post_office->enqueueClient(client1);
//
//    post_office->gateReady(3);
//    auto status = post_office->getStatus();
//    assert(status[3] == "Adam Nowak");
//
//    post_office->gateReady(3);
//    status = post_office->getStatus();
//    assert(status[3] == "Jan Kowalski");

    try {
        auto post_office = IPostOffice::create(5);

        auto client0 = post_office->getClient("96052791813");
        auto client1 = post_office->getClient("96052791813");
        auto client2 = post_office->getClient("54100839676");
        auto client3 = post_office->getClient("32100839674");
        auto client4 = post_office->getClient("23100839656");
        auto client5 = post_office->getClient("65100839344");
        auto client6 = post_office->getClient("53030411234");
        auto client7 = post_office->getClient("64040322333");



        client0->setFullName("Jan Kowalski");
        client0->newPackage("Moja Paczka");
        client0->newPackage("Moja Paczk");
        client0->newPackage("Moja Pacz");
        client0->newPackage("Moja Pac");
        client0->updatePriority(1);
        client0->updateBiometricData("GGTTGACTA");
//
        client1->setFullName("Alek Nosal");
        client1->newPackage("aMoja Paczka");
        client1->newPackage("aMoja Paczk");
        client1->newPackage("aMoja Pacz");
        client1->newPackage("aMoja Pac");
        client1->updatePriority(2);
        client1->updateBiometricData("GGTTGACTA");

        client2->setFullName("Liga Lis");
        client2->newPackage("Moja Paczka");
        client2->newPackage("Moja Paczk");
        client2->newPackage("Moja Pacz");
        client2->newPackage("Moja Pac");
        client2->updatePriority(3);
        client2->updateBiometricData("GGTTGACTA");

        client3->setFullName("Adam Kuliks");
        client3->newPackage("Moja Paczka");
        client3->newPackage("Moja Paczk");
        client3->newPackage("Moja Pacz");
        client3->newPackage("Moja Pac");
        client3->updatePriority(4);
        client3->updateBiometricData("GGTTGACTA");

        client4->setFullName("Piotr Obierz");
        client4->newPackage("Moja Paczka");
        client4->newPackage("Moja Paczk");
        client4->newPackage("Moja Pacz");
        client4->newPackage("Moja Pac");
        client4->updatePriority(3);
        client4->updateBiometricData("GGTTGACTA");

        client5->setFullName("Kacper Obierzak");
        client5->newPackage("Moja Paczka");
        client5->newPackage("Moja Paczk");
        client5->newPackage("Moja Pacz");
        client5->newPackage("Moja Pac");
        client5->updatePriority(2);
        client5->updateBiometricData("GGTTGACTA");

        client6->setFullName("John Smith");
        client6->newPackage("Moja Paczka");
        client6->newPackage("Moja Paczk");
        client6->newPackage("Moja Pacz");
        client6->newPackage("Moja Pac");
        client6->updatePriority(8);
        client6->updateBiometricData("GGTTGACTA");

        client7->setFullName("Mia Khalifa");
        client7->newPackage("Moja Paczka");
        client7->newPackage("Moja Paczk");
        client7->newPackage("Moja Pacz");
        client7->newPackage("Moja Pac");
        client7->updatePriority(8);
        client7->updateBiometricData("GGTTGACTA");

        std::cout<<client0->verifyBiometricData("TGTTACGG", 2.0)<<std::endl;
        std::cout<<client1->verifyBiometricData("TGTTACGG", 2.0)<<std::endl;
        std::cout<<client2->verifyBiometricData("TGTTACGG", 2.0)<<std::endl;
        std::cout<<client3->verifyBiometricData("TGTTACGG", 2.0)<<std::endl;
        std::cout<<client4->verifyBiometricData("TGTTACGG", 2.0)<<std::endl;
        std::cout<<client5->verifyBiometricData("TGTTACGG", 2.0)<<std::endl;
        std::cout<<client6->verifyBiometricData("TGTTACGG", 2.0)<<std::endl;
        std::cout<<client7->verifyBiometricData("GGTTGACT", 2.0)<<std::endl;

        post_office->enqueueClient(client0);
        post_office->enqueueClient(client1);
        post_office->enqueueClient(client2);
        post_office->enqueueClient(client3);
        post_office->enqueueClient(client4);
        post_office->enqueueClient(client5);
        post_office->enqueueClient(client6);
        post_office->enqueueClient(client7);

        auto str0 = client0->awaitingPackages();
        auto str1 = client1->awaitingPackages();
        auto str2 = client2->awaitingPackages();
        auto str3 = client3->awaitingPackages();
        auto str4 = client4->awaitingPackages();
        auto str5 = client5->awaitingPackages();
        auto str6 = client6->awaitingPackages();
        auto str7 = client7->awaitingPackages();


        post_office->gateReady(0);
        post_office->collectPackages(6);
        post_office->gateReady(1);
        post_office->collectPackages(1);
        post_office->gateReady(2);
        post_office->collectPackages(2);
        post_office->gateReady(3);
        post_office->collectPackages(3);
        post_office->gateReady(4);
        auto status = post_office->getStatus();
        post_office->collectPackages(4);
        post_office->gateReady(0);
        post_office->collectPackages(0);
        post_office->gateReady(1);
        post_office->collectPackages(1);
        post_office->gateReady(2);
        post_office->collectPackages(2);

//        post_office->gateReady(3);
//        post_office->collectPackages(3);
//        post_office->gateReady(4);
//        post_office->collectPackages(4);
//        post_office->gateReady(0);
//        post_office->collectPackages(0);
//        post_office->gateReady(1);
//        post_office->collectPackages(1);
//        post_office->gateReady(2);
//        post_office->collectPackages(2);


//        post_office->gateReady(3);
//        post_office->gateReady(3);
        //assert(status[3] == "Adam Nowak");
        //status = post_office->getStatus();
        //assert(status[1] == "Jan Kowalski");

    } catch (const IncorrectGateException &e) {
        std::cout << "IncorrectGateException: " << e.what() << std::endl;
    } catch (const PackageExistsException &e) {
        std::cout << "PackageExistsException: " << e.what() << std::endl;
    } catch (IncorrectBiometricDataException &e) {
        std::cout << "IncorrectBiometricDataException: " << e.what() << std::endl;
    }

    return 0;
}
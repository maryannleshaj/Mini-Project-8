#include "RoutingEngine.hpp"
#include <memory>

int main() {
    //using unique_ptr for modern memory management
    unique_ptr<RoutingEngine> myEngine = make_unique<RoutingEngine>();

    myEngine->buildGraph("network.txt");

    //test 1: high bandwidth
    myEngine->findPath("Router-A", "Server-Beta", 700);

    //test 2: low bandwidth
     myEngine->findPath("Router-A", "Server-Beta", 100);

    //test 3: impossible path
    myEngine->findPath("Router-A", "NonExistentDevice", 10);

    return 0;
}
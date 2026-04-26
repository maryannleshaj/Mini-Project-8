# Mini Project 8: Network Routing Engine
**Author:** Maryann Leshaj  
**Course:** EECE2140

## Project Overview
This project implements a Network Routing Engine that constructs a graph of network devices (nodes) and connections (edges). It uses a Depth-First Search (DFS) algorithm to find a feasible path between two devices that satisfies a minimum bandwidth requirement.

## Memory Management Decisions
In accordance with modern C++ standards and the project rubric, I made the following design decisions regarding memory:

* **Smart Pointers:** I utilized `std::unique_ptr<Node>` within a `std::vector` to manage the lifecycle of the graph nodes. 
* **Ownership:** The `RoutingEngine` class acts as the primary owner of the nodes. By using `unique_ptr`, each node is automatically deallocated when the `RoutingEngine` object goes out of scope or is destroyed.
* **Safety:** This approach eliminates the need for manual `delete` calls and a custom destructor, significantly reducing the risk of memory leaks and "use-after-free" bugs.
* **Valgrind Verification:** Running the program through Valgrind confirms that "All heap blocks were freed -- no leaks are possible," securing a clean memory profile.

## Algorithm Design
* **Graph Construction:** The engine reads from `network.txt` and builds an adjacency list.
* **Pathfinding:** A recursive DFS explores the graph. It maintains a `visited` set to prevent infinite loops in network cycles and checks the `bandwidth` of each edge against the `minBW` constraint before traversing.

## AI Visualization (Bonus)
**Prompt used:** *"A high-tech digital map showing a network of glowing nodes and fiber optic connections. Some paths are glowing bright blue to represent high bandwidth, while others are dim. Minimalist, futuristic data visualization style."*



## How to Run
1. Compile: `g++ -std=c++17 main.cpp -o routing_test`
2. Run: `./routing_test`
3. Memory Check: `valgrind --leak-check=full ./routing_test`
#include <iostream>
#include <random>
#include <ctime>
#include <unordered_set>
using namespace std;
string IDGeneration(){
// This Function Generated a number consisting of 9 Digits of a random numbers , and it must be unique
    // Set up a random number generator
    mt19937 rng(time(0));
    uniform_int_distribution<int> distribution(0, 9);
    unordered_set<string> generatedIDs;
    while (true) {
        string id;
        for (int i = 0; i < 9; ++i) {
            id += to_string(distribution(rng));
        }

        // Check if the ID is unique
        if (generatedIDs.find(id) == generatedIDs.end()) {
            generatedIDs.insert(id);
            return id;
        }else{
            return "Error: Failed to generate a unique ID.";
        }
    }
}
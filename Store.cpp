#include <fstream>
#include <sstream>
#include "Store.h"

using namespace std;

Store::Store() {
    // Initialize cart total to zero
    cartTotal = 0.0;
}

void Store::initInventory(std::string dataFile) {
    ifstream file(dataFile);
    if (file.is_open()) {
        uint32_t itemNum;
        float price;
        while (file >> itemNum >> price) {
            // Populate the inventory unordered_map
            inventory[itemNum] = price;
        }
        file.close();
    }
}

void Store::clearCart() {
    // Set cart total to zero
    cartTotal = 0.0;
}

void Store::addToCart(uint32_t itemNum, uint32_t quantity) {
    // Check if the item exists in the inventory
    if (inventory.find(itemNum) != inventory.end()) {
        // Add the cost of the item to the cart total
        cartTotal += inventory[itemNum] * quantity;
    } 
}

float Store::getCost(uint32_t itemNum) {
    // Check if the item exists in the inventory
    if (inventory.find(itemNum) != inventory.end()) {
        // Return the cost of the item
        return inventory[itemNum];
    }
}

float Store::getTotal() {
    // Return the current cart total
    return cartTotal;
}
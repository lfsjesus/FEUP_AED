#include "product.h"

Product::Product(string i, float p, float w): id(i), price(p), weight(w) {}

string Product::getId() const {
    return id;
}

float Product::getPrice() const {
    return price;
}

float Product::getWeight() const {
    return weight;
}

bool Product::operator<(Product &product) {
    if (price != product.price) {
        return price < product.price;
    }
    else {
        return weight < product.weight;
    }
    return false;
}

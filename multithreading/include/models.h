#ifndef MODELS_H
#define MODELS_H

#include <string>

using namespace std;

struct Customer {
    int custkey;
    int nationkey;
};

struct Order {
    int orderkey;
    int custkey;
    string orderdate;
};

struct LineItem {
    int orderkey;
    int suppkey;
    double extendedprice;
    double discount;
};

struct Supplier {
    int suppkey;
    int nationkey;
};

struct Nation {
    int nationkey;
    string name;
    int regionkey;
};

struct Region {
    int regionkey;
    string name;
};

// structures of the keyed value needed for Q5
#endif // MODELS_H

#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include "models.h"
#include <string>
#include <vector>

using namespace std;

void load_customers(const string& file, vector<Customer>& customers);
void load_orders(const string& file, vector<Order>& orders);
void load_lineitems(const string& file, vector<LineItem>& lineitems);
void load_suppliers(const string& file, vector<Supplier>& suppliers);
void load_nations(const string& file, vector<Nation>& nations);
void load_regions(const string& file, vector<Region>& regions);

// Method declaration for loading of input data

#endif // DATA_LOADER_H

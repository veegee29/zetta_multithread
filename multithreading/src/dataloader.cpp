#include "../include/dataloader.h"
#include "../include/utility.h"
#include <fstream>
#include <sstream>

void load_customers(const string& file, vector<Customer>& customers) {
    ifstream fin(file);
    string line;
    while (getline(fin, line)) {
        auto tokens = split(line, '|');
        Customer c;
        c.custkey = stoi(tokens[0]);
        c.nationkey = stoi(tokens[3]);
        customers.push_back(c);
    }
}   /* Method name: load_customer | type : void
    arguments : file | data type : string reference
                customers | data type vector of structure customer reference
    variable  : line | data type : string | scope : local
                tokens             auto             local
                c                  object of Customer   local
                custkey            integer structure variable of object c   local
                nationkey          integer structure variable of object c   local
    nested method : split | feature : refer utility.cpp
    
    Method feature: To input load data from file input using tokens as marked location address based on TPC-H documents
                     into a vector named customers
    */
    /* Below methods have the similar characteristics and follow adjacent feature .*/

void load_orders(const string& file, vector<Order>& orders) {
    ifstream fin(file);
    string line;
    while (getline(fin, line)) {
        auto tokens = split(line, '|');
        Order o;
        o.orderkey = stoi(tokens[0]);
        o.custkey = stoi(tokens[1]);
        o.orderdate = tokens[4];
        orders.push_back(o);
    }
}

void load_lineitems(const string& file, vector<LineItem>& lineitems) {
    ifstream fin(file);
    string line;
    while (getline(fin, line)) {
        auto tokens = split(line, '|');
        LineItem l;
        l.orderkey = stoi(tokens[0]);
        l.suppkey = stoi(tokens[2]);
        l.extendedprice = stod(tokens[5]);
        l.discount = stod(tokens[6]);
        lineitems.push_back(l);
    }
}

void load_suppliers(const string& file, vector<Supplier>& suppliers) {
    ifstream fin(file);
    string line;
    while (getline(fin, line)) {
        auto tokens = split(line, '|');
        Supplier s;
        s.suppkey = stoi(tokens[0]);
        s.nationkey = stoi(tokens[3]);
        suppliers.push_back(s);
    }
}

void load_nations(const string& file, vector<Nation>& nations) {
    ifstream fin(file);
    string line;
    while (getline(fin, line)) {
        auto tokens = split(line, '|');
        Nation n;
        n.nationkey = stoi(tokens[0]);
        n.name = tokens[1];
        n.regionkey = stoi(tokens[2]);
        nations.push_back(n);
    }
}

void load_regions(const string& file, vector<Region>& regions) {
    ifstream fin(file);
    string line;
    while (getline(fin, line)) {
        auto tokens = split(line, '|');
        Region r;
        r.regionkey = stoi(tokens[0]);
        r.name = tokens[1];
        regions.push_back(r);
    }
}

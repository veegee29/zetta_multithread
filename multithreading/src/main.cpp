// Project: Multithreading C++11 Implementation
// Author : VeeGee

// Directory Structure:
// ├── Makefile
// ├── include/
// │   ├── dataloader.h
// │   ├── models.h
// │   └── utility.h
// ├── src/
// │   ├── main.cpp
// │   └── DataLoader.cpp
// └── build/ (post-compilation generated)


#include "../include/dataloader.h"
#include "../include/models.h"
#include "../include/utility.h"
#include <fstream>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

mutex mtx;
map<string, double> global_revenue;

void worker(int tid, int total_threads, const vector<Order>& orders, 
            const unordered_map<int, Customer>& cust_map, 
            const vector<LineItem>& lineitems,
            const unordered_map<int, Supplier>& supp_map, 
            const unordered_map<int, Nation>& nation_map, 
            const unordered_set<int>& valid_nationkeys,
            const string& start_date, const string& end_date) {

    map<string, double> local_revenue;

    for (size_t i = tid; i < orders.size(); i += total_threads) {
        const Order& o = orders[i];
        if (o.orderdate < start_date || o.orderdate >= end_date) continue;

        auto cust_it = cust_map.find(o.custkey);
        if (cust_it == cust_map.end()) continue;
        int cust_nationkey = cust_it->second.nationkey;

        for (const LineItem& l : lineitems) {
            if (l.orderkey != o.orderkey) continue;
            auto supp_it = supp_map.find(l.suppkey);
            if (supp_it == supp_map.end()) continue;
            if (cust_nationkey != supp_it->second.nationkey) continue;
            if (valid_nationkeys.find(cust_nationkey) == valid_nationkeys.end()) continue;

            string nation_name = nation_map.at(cust_nationkey).name;
            double revenue = l.extendedprice * (1 - l.discount);
            local_revenue[nation_name] += revenue;
        }
    }

    lock_guard<mutex> lock(mtx);
    for (const auto& kv : local_revenue) {
        global_revenue[kv.first] += kv.second;
    }
}/* Method name: worker | type : void
    arguments : tid              | data type : integer 
                total_threads    | data type : integer 
                orders           | data type : vector of structure Order reference 
                cust_map         | data type : unordered map of integer and structure Customer reference
                lineitems        | data type : vector of structure LineItem reference 
                supp_map         | data type : unordered map of integer and structure Supplier reference
                nation_map       | data type : unordered map of integer and structure Nation reference 
                valid_nationkeys | data type : unordered set of integers reference 
                start_date       | data type : string reference
                end_date         | data type : string reference
    variable  : local_revenue    | data type : map of string and double 
                o                            : object of structure Order            
                cust_it                      : auto -> map of int and structure Customer   
                cust_nationkey               : integer 
                supp_it                      : auto -> map of int and structure Supplier
                nation_name                  : string
                revenue                      : double
    nested method : most feaatures of unordered_map are used to determine postition of data and perform the feature
    
    Method feature: To perform common key join of multiple data sets i.e., here 6 and 3,
                    iow cenetered logic to perform the inner join 
    */ 

   /* Rest below part of code is just scanning data from the user input
      And assign threads */


int main(int argc, char* argv[]) {
    if (argc < 12) {
        cerr << "Usage: ./tpchdata <customer> <orders> <lineitem> <supplier> <nation> <region> <start_date> <end_date> <region_name> <threads> <result_file>\n";
        return 1;
    }

    string customer_file = argv[1];
    string order_file = argv[2];
    string lineitem_file = argv[3];
    string supplier_file = argv[4];
    string nation_file = argv[5];
    string region_file = argv[6];
    string start_date = argv[7];
    string end_date = argv[8];
    string region_name = argv[9];
    int thread_count = stoi(argv[10]);
    string output_file = argv[11];

    vector<Customer> customers;
    vector<Order> orders;
    vector<LineItem> lineitems;
    vector<Supplier> suppliers;
    vector<Nation> nations;
    vector<Region> regions;

    load_customers(customer_file, customers);
    load_orders(order_file, orders);
    load_lineitems(lineitem_file, lineitems);
    load_suppliers(supplier_file, suppliers);
    load_nations(nation_file, nations);
    load_regions(region_file, regions);

    unordered_map<int, Customer> cust_map;
    for (const Customer& c : customers) {
        cust_map[c.custkey] = c;
    }

    unordered_map<int, Supplier> supp_map;
    for (const Supplier& s : suppliers) {
        supp_map[s.suppkey] = s;
    }

    unordered_map<int, Nation> nation_map;
    for (const Nation& n : nations) {
        nation_map[n.nationkey] = n;
    }

    unordered_set<int> valid_nationkeys;
    for (const Nation& n : nations) {
        for (const Region& r : regions) {
            if (n.regionkey == r.regionkey && r.name == region_name) {
                valid_nationkeys.insert(n.nationkey);
                break;
            }
        }
    }

    vector<thread> threads;
    for (int i = 0; i < thread_count; ++i) {
        threads.emplace_back(worker, i, thread_count, cref(orders), cref(cust_map), cref(lineitems),
                             cref(supp_map), cref(nation_map), cref(valid_nationkeys), start_date, end_date);
    }

    for (thread& t : threads) {
        t.join();
    }

    vector<pair<string, double>> results(global_revenue.begin(), global_revenue.end());
    sort(results.begin(), results.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return b.second < a.second;
    });

    ofstream out(output_file);
    for (const auto& entry : results) {
        out << entry.first << "," << entry.second << endl;
    }

    return 0;
}

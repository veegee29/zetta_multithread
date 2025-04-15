# 🚀 TPC-H Query 5 Multithreaded in C++11

This project is a multithreaded implementation of **TPC-H Query 5** (Local Supplier Volume) using **C++11**, without using any external database system.

The solution reads `.tbl` files generated via the **TPC-H `dbgen` tool**, parses the necessary tables, and processes the query using multiple threads for better performance.

---

## 📌 Objective

Implement **TPC-H Query 5** using:
- C++11 with Standard Library
- Efficient use of Multithreading
- Clean OOP Design (Classes, Modular Files)
- Command-line Interface (CLI) Support
- Custom Makefile for building the project

---

## 📊 TPC-H Query 5 Summary

This query computes revenue for each nation from orders placed in a given year by customers in that region.

> **Official SQL (Simplified):**
```sql
SELECT n_name, SUM(l_extendedprice * (1 - l_discount)) AS revenue
FROM customer, orders, lineitem, supplier, nation, region
WHERE c_custkey = o_custkey
  AND l_orderkey = o_orderkey
  AND l_suppkey = s_suppkey
  AND c_nationkey = s_nationkey
  AND s_nationkey = n_nationkey
  AND n_regionkey = r_regionkey
  AND r_name = 'ASIA'
  AND o_orderdate >= '1994-01-01'
  AND o_orderdate < '1995-01-01'
GROUP BY n_name
ORDER BY revenue DESC;



Tables Used:

customer.tbl

orders.tbl

lineitem.tbl

supplier.tbl

nation.tbl

region.tbl



🛠️ Project Structure


├── include/
│   ├── DataLoader.h      # Handles data loading from .tbl files
│   ├── Models.h          # Structs for all tables (Customer, Order, etc.)
│   └── Utils.h           # Utility functions
│
├── src/
│   ├── main.cpp          # Main logic for parsing, processing, threading
│   ├── DataLoader.cpp    # Definitions for data loading
│   └── Utils.cpp         # Definitions for utility functions
│
├── Makefile              # Build script
├── tpchdata/             # Place your .tbl data files here (ignored in Git)
├── result.tbl            # Output result file (nation, revenue)
└── README.md             # Project documentation


🧪 Sample CLI Usage

./build/tpch_q5 \
  tpchdata/customer.tbl \
  tpchdata/orders.tbl \
  tpchdata/lineitem.tbl \
  tpchdata/supplier.tbl \
  tpchdata/nation.tbl \
  tpchdata/region.tbl \
  1994-01-01 \
  1995-01-01 \
  ASIA \
  4 \





🧵 Multithreading Approach
Orders are divided among threads.

Each thread processes its portion, matching joins and calculating revenue.

Mutex ensures thread-safe aggregation of partial results.


📝 Output Format
The result is written to a CSV file with the format:

python-repl
Copy
Edit
NATION_NAME,REVENUE
INDONESIA,55502041.1697
VIETNAM,55295086.9967
...



📁 .gitignore
The project ignores:

.DS_Store

build/

*.tbl, *.csv

.vscode/

(See full .gitignore in the repo)



🧼 Cleanup

To clean build files:
make clean

Author
Vaibhav Gupta
C++ Developer | Passionate about performance and multithreading

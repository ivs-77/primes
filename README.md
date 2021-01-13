# Constexpr prime numbers calculator
Usage:  
```bash
user@host:~$ time g++ -std=c++20 -DMAX_PRIMES=100000 -fconstexpr-ops-limit=100000000000 primes.cpp


real	3m19,279s
user	3m3,571s
sys	0m6,533s
```

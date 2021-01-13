# Constexpr prime numbers calculator
Constexpr usage:  
```bash
[user@host primes]$ time g++ -std=c++20 -DMAX_PRIMES=100000 -fconstexpr-ops-limit=100000000000 primes.cpp && time ./a.out>./primes.dat

real	3m7,390s
user	2m54,585s
sys	0m6,265s

real	0m0,027s
user	0m0,007s
sys	0m0,014s
```  
Runtime usage:  
```bash
[user@host primes]$ time g++ -std=c++20 -O2 -DMAX_PRIMES=100000 -DNO_CONSTEXPR_PRIMES primes.cpp && time ./a.out>./primes.dat

real	0m9,884s
user	0m9,479s
sys	0m0,370s

real	0m0,132s
user	0m0,121s
sys	0m0,010s
```

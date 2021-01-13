# Constexpr prime numbers calculator
## Constexpr usage:  
```bash
$ time g++ -std=c++20 -DMAX_PRIMES=100000 -fconstexpr-ops-limit=100000000000 primes.cpp && time ./a.out>./primes.dat

real	2m53,384s
user	2m42,015s
sys	0m6,023s

real	0m0,026s
user	0m0,010s
sys	0m0,011s
```  
## Runtime usage:  
```bash
$ time g++ -std=c++20 -O2 -DMAX_PRIMES=100000 -DNO_CONSTEXPR_PRIMES primes.cpp && time ./a.out>./primes2.dat

real	0m9,312s
user	0m8,894s
sys	0m0,338s

real	0m0,114s
user	0m0,108s
sys	0m0,006s
```

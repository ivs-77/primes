# Constexpr prime numbers calculator
## Constexpr usage:  
```bash
$ time g++ -std=c++20 -DMAX_PRIMES=1299710 -fconstexpr-loop-limit=1000000000 -fconstexpr-ops-limit=100000000000 primes.cpp

real	6m59,057s
user	6m53,217s
sys	0m2,108s

$ time ./a.out>primes3.dat

real	0m0,030s
user	0m0,014s
sys	0m0,016s

```  
## Runtime usage:  
```bash
$ time g++ -std=c++20 -O2 -DMAX_PRIMES=1299710 -DNO_CONSTEXPR_PRIMES primes.cpp

real	0m5,911s
user	0m5,732s
sys	0m0,151s

$ time ./a.out>primes4.dat

real	0m0,027s
user	0m0,010s
sys	0m0,017s
```

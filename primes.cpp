#include <iostream>
#include <iomanip>
#include <array>

#if !defined(MAX_PRIMES)
#define MAX_PRIMES 100
#endif

#if defined(NO_CONSTEXPR_PRIMES)
#define CONSTEXPR_PRIMES
#else
#define CONSTEXPR_PRIMES constexpr
#endif

template<size_t N>
constexpr bool is_prime(const std::array<unsigned, N>& primes, const std::array<unsigned, N>& primes_squares, const unsigned next)
{
    for(auto prime_index = 0;
        primes_squares[prime_index] <= next;
        ++prime_index)
    {
        if(next % primes[prime_index] == 0)
            return false;
    }
    return true;
}

template<size_t N>
constexpr void make_prime(std::array<unsigned, N>& primes, std::array<unsigned, N>& primes_squares, size_t prime_index)
{
    auto& next = primes[prime_index];
    if(prime_index < 2)
    {
        next = 2 + prime_index;
    }
    else
    {
        next = primes[prime_index - 1] + 2;
        while(!is_prime(primes, primes_squares, next))
            next += 2;
    };
    primes_squares[prime_index] = next * next;
}

template<size_t N>
constexpr std::array<unsigned, N> make_primes()
{
    std::array<unsigned, N> primes{};
    std::array<unsigned, N> primes_squares{};
    for(auto prime_index = 0; prime_index < N; ++prime_index)
        make_prime(primes, primes_squares, prime_index);
    return primes;
}

int main()
{
    CONSTEXPR_PRIMES auto primes = make_primes<MAX_PRIMES>();
    for(auto prime_index = 0; prime_index < primes.size(); ++prime_index)
    {
        std::cout << std::setw(10) << primes[prime_index];
        if((prime_index + 1) % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

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
constexpr bool make_prime(std::array<unsigned, N>& primes, std::array<bool, N>& numbers, size_t prime_index)
{
    auto& next = primes[prime_index];
    if(prime_index < 2)
    {
        next = 2 + prime_index;
    }
    else
    {
        auto number = primes[prime_index - 1] + 2;
        while(number < N)
        {
            if(!numbers[number])
            {
                next = number;
                break;
            }
            number += 2;
        }
        if(next == 0)
            return false;
    };
    for(auto number = 3 * next; number < N; number += next)
        numbers[number] = true;
    return true;
}

template<size_t N>
constexpr std::array<unsigned, N> make_primes()
{
    std::array<unsigned, N> primes{};
    std::array<bool, N> numbers{};
    for(auto prime_index = 0; prime_index < N; ++prime_index)
        if(!make_prime(primes, numbers, prime_index))
            break;
    return primes;
}

int main()
{
    CONSTEXPR_PRIMES auto primes = make_primes<MAX_PRIMES>();
    for(auto prime_index = 0; primes[prime_index]; ++prime_index)
    {
        std::cout << std::setw(10) << primes[prime_index];
        if((prime_index + 1) % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

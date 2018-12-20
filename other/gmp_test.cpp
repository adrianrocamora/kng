#include <iostream>
// To get around the pesky ::max_align error when using -std=c++11
// NOTE: Seems to work for g++, but not for clang++
#include <cstddef>
#include <gmp.h>

// sudo apt-get install libgmp-dev
// g++ -lgmp -o run -std=c++11


int main() {
    mpz_t a,b,c;
    mpz_inits(a,b,c,NULL);

    mpz_set_str(a, "1234", 10);
    mpz_set_str(b,"-5678", 10); //Decimal base

    mpz_add(c,a,b);

    std::cout<<"\nThe exact result is:";
    mpz_out_str(stdout, 10, c); //Stream, numerical base, var
    std::cout<<std::endl;

    mpz_abs(c, c);
    std::cout<<"The absolute value result is:";
    mpz_out_str(stdout, 10, c);
    std::cout<<std::endl;

    std::cin.get();
}

//roflanpotsan
#include <fact.h>

long long fact(const long long &input) {
    if (input < 0) throw std::logic_error("Cant calculate a factorial of a negative number");
    if (input == 0 || input == 1) return 1;
    else return input * fact(input - 1);
}

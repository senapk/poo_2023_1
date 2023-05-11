#include <iostream>
#include <iomanip>
#include <fn.hpp>







struct Coisa {
    double a;
    std::vector<float> b;
    std::string c;

    Coisa(double a, std::vector<float> b, std::string c): a(a), b(b), c(c){}

    std::string str() {
        //(a)[b, b, b] - c
        // std::stringstream ss;
        // ss << "(" << std::fixed << std::setprecision(2) << a << ")[";
        // for (int i = 0; i < (int) b.size(); i++)
        //     ss << (i == 0 ? "" : ", ") << b[i];
        // ss << "] - " << c;

        return fn::format("({%.2f}){} - {}", a, fn::join(b, ":"), c);   
    }
};

int main() {
    Coisa c(3.45, {2,1,2,3}, "banan");
    std::cout << c.str() << '\n';
}


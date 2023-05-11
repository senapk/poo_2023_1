





#include <vector> 
#include <map> //o jardineiro eh Deus e as arveres somos nozes
#include <iostream>
#include <algorithm>
#include <fn.hpp>

struct Kid {
    std::string nome;
    int idade;
};
std::ostream& operator<<(std::ostream&os, Kid k) {
    return os << k.nome << ":" << k.idade;
}

void inserir_crianca(std::map<int, Kid> &mapa, std::string nome, int idade) {
    mapa[idade] = Kid{nome, idade};
}


int main() {
    // std::vector<Kid> kids = {{"maria", 7}, {"joao", 3}, {"bia", 11}, 
    // {"jose", 6}, {"lucas", 9}};

    // std::sort(kids.begin(), kids.end(), [](auto a, auto b) {
    //     return a.nome < b.nome;
    // });

    // fn::write(kids);

    std::map<int, Kid> arvere;
    inserir_crianca(arvere, "maria", 7);
    inserir_crianca(arvere, "joao", 3);
    inserir_crianca(arvere, "andre", 9);
    inserir_crianca(arvere, "bia", 3);

    for (auto par : arvere) {
        auto [chave, valor] = par;
        std::cout << valor << " ";
    }


}

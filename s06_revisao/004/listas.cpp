#include <iostream>
#include <list>




struct Pessoa {
    std::string nome;
    int idade;
    Pessoa(std::string nome, int idade): nome(nome), idade(idade) {}
    
    void setNome(std::string nome) {
        this->nome = nome;
    }
    std::string getNome() const {
        return nome;
    }
    std::string str() const {
        return nome + ":" + std::to_string(idade);
    }
};



int main() {
    std::list<Pessoa*> pessoas = {
        new Pessoa("Joao", 20),
        new Pessoa("Maria", 30),
        new Pessoa("Jose", 40),
        new Pessoa("Ana", 50),
        new Pessoa("Pedro", 60),
    };

    for (auto& pessoa: pessoas) { //for range
        std::cout << pessoa->str() << '\n';
    }
    for (auto it = pessoas.begin(); it != pessoas.end();) {
        auto kid = *it;
        if ((*it)->getNome() == "Maria") {
            it = pessoas.erase(it);
        } else {
            ++it;
        }
    }
}
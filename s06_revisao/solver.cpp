#include <iostream>




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




void show(const int& value) {
    std::cout << value << '\n';
}

int main() {
    int x = 5;
    show(7);

}
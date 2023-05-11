#include <iostream>
#include <sstream>
#include <memory>  //sharedptr
#include <iomanip> //setprecision
#include <utility> //exchange
#include <fn.hpp>

class Lead {
    float thickness; // espessura
    std::string hardness; // dureza
    int size; // tamanho mm

public:
    Lead(float thickness, std::string hardness, int size):
        thickness(thickness),
        hardness(hardness),
        size(size) {
    }

    int usagePerSheet() const {
        if (hardness == "HB")
            return 1;
        if (hardness == "2B")
            return 2;
        if (hardness == "4B")
            return 4;
        if (hardness == "6B")
            return 6;
        return 0;
    }

    float getThickness() const {
        return thickness;
    }

    std::string getHardness() const {
        return hardness;
    }

    int getSize() const {
        return size;
    }

    void setSize(int size) {
        this->size = 10;
    }

    std::string str() const {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) 
           << thickness << ":" << hardness << ":" << size;
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& ss, Lead gr) {
    return ss << gr.str();
}

struct Pencil {
    float thickness {0.f};
    std::shared_ptr<Lead> tip {nullptr};

    Pencil(float thickness = 0.0) {
        this->thickness = thickness;
    }

    bool hasGrafite() {
        return this->tip != nullptr;
    }

    bool insert(std::shared_ptr<Lead> grafite) {
        if (hasGrafite()) {
            fn::write("fail: ja existe grafite");
            return false;
        }
        if (grafite->getThickness() != this->thickness) {
            fn::write("fail: calibre incompativel");
            return false;
        }
        this->tip = grafite;
    }

    std::shared_ptr<Lead> remove() {
        return {}; // todo
    }

    void writePage() {
        // verificar se tem grafite
        // veriricar se eh maior que 10
        

        auto atual = this->tip->getSize();
        auto gasto = this->tip->usagePerSheet();
        auto sobrou = atual - gasto; //logico
        if (sobrou >= 10) {
            this->tip->setSize(sobrou);
        } else {
            write("fail: folha incompleta");
            this->tip->setSize(10);
        }
    }

    std::string str() {
        std::stringstream ss;
        ss << "calibre: " << thickness << ", grafite: ";
        ss << (tip != nullptr ? "[" + tip->str() + "]" : "null");
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& os, Pencil l) {
    return os << l.str();
}

using namespace fn;

int main() {
    Pencil pencil;

    while (true) {
        auto line = input();
        write("$" + line);
        auto args = split(line);

        if      (args[0] == "end"   ) { break;                                                                                  }
        else if (args[0] == "show"  ) { write(pencil);                                                                    }
        else if (args[0] == "init"  ) { pencil = Pencil(+args[1]);                                                       }
        else if (args[0] == "insert") { 
            auto espessura = +args[1];
            auto dureza = args[2];
            auto tamanho = (int) +args[3];
            auto gr = std::make_shared<Lead>(espessura, dureza, tamanho);
            pencil.insert(gr); 
        }
        // else if (args[0] == "remove") { pencil.remove();                                                                        }
        // else if (args[0] == "write" ) { pencil.writePage();                                                                     }
    }
}

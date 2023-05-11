#include <fn.hpp>

class Time {
    int hora {0};
    int minuto {0};
    int segundo {0};

public:
    Time(int hora = 0, int minuto = 0, int segundo = 0) {
        this->setHora(hora);
        this->minuto = minuto;
        this->segundo = segundo;
    }

    int getHora() {
        return hora;
    }
    void setHora(int hora) {
        if (hora >=0 && hora <= 23)
            this->hora = hora;
        else
            fn::write("fail: hora invalida");
    }
    void setMinuto(int value) {
        this->minuto = value;
    }
    void setSegundo(int value) {
        this->segundo = value;
    }

    void nextSecond() {
        
    }

    std::string str() {
        return fn::format("{%02d}:{%02d}:{%02d}", hora, minuto, segundo);
    }
};


int main() {
    Time time(0, 0, 0);
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line);
        fn::write("$" + line);

        if (args[0] == "end") {
            break;
        } else if (args[0] == "show") {
            fn::write(time.str());
        } else if (args[0] == "set") {
            time.setHora(+args[1]);
            time.setMinuto(+args[2]);
            time.setSegundo(+args[3]);
        } else {
            fn::write("fail: comando invalido\n");
        }
    }
}
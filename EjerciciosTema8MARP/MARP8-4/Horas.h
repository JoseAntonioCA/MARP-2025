#pragma once

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
class Horas
{

public:
    int hora, minuto, segundo;
    Horas() : hora(0), minuto(0), segundo(0) {}
    Horas(int h, int m, int s) : hora(h), minuto(m), segundo(s) {}

    bool operator<(const Horas& otra) const {
        if (hora < otra.hora) return true;
        else if (hora == otra.hora && minuto < otra.minuto) return true;
        else if (hora == otra.hora && minuto == otra.minuto && segundo < otra.segundo) return true;
        else
            return false;
    }

    bool operator>(const Horas& otra) const {
        return otra < *this;
    }

    bool operator<=(const Horas& otra) const {
        return !(otra < *this);
    }

    bool operator>=(const Horas& otra) const {
        return !(*this < otra);
    }

    bool operator==(const Horas& otra) const {
        if (hora == otra.hora && minuto == otra.minuto && segundo == otra.segundo) return true;
        else
            return false;
    }

    bool operator!=(const Horas& otra) const {
        return !(*this == otra);
    }

    Horas operator +(const Horas& otra) const {
        Horas h;

        h.segundo = segundo + otra.segundo;

        if (h.segundo > 59) {
            h.segundo -= 60;
            h.minuto = minuto + otra.minuto + 1;
        }
        else h.minuto = minuto + otra.minuto;

        if (h.minuto > 59) {
            h.minuto -= 60;
            h.hora = hora + otra.hora + 1;
        }
        else h.hora = hora + otra.hora;

        if (h.hora > 23) {
            h.hora = h.hora - 24;
        }

        return h;
    }

    Horas operator+(int minutosExtra) const {
        Horas h = *this;

        h.minuto += minutosExtra;

        // Convertimos minutos en horas si hace falta
        h.hora += h.minuto / 60;
        h.minuto = h.minuto % 60;

        // Ajustamos si pasa de 24 horas
        h.hora = h.hora % 24;

        return h;
    }


    friend ostream& operator<<(ostream& os, const Horas& hora) {
        os << setw(2) << setfill('0') << hora.hora << ":" << setw(2) << setfill('0') << hora.minuto << ":" << setw(2) << setfill('0') << hora.segundo;
        return os;
    }

    friend istream& operator>>(istream& is, Horas& hora) {
        char separador;
        int h, m;
        is >> h >> separador >> m;
        hora = Horas(h, m, 0); // Usa el constructor que valida
        return is;
    }
};


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Função para converter Ternário (base 3) para Decimal
long long ternarioParaDecimal(string ternario) {
    long long decimal = 0;
    for (char c : ternario) {
        int digito = c - '0';
        if (digito < 0 || digito >= 3) return -1; // Dígito inválido para base 3
        decimal = decimal * 3 + digito;
    }
    return decimal;
}


// Função para converter Decimal para Ternário (base 3)
string decimalParaTernario(long long decimal) {
    if (decimal == 0) return "0";
    string ternario = "";
    while (decimal > 0) {
        ternario = to_string(decimal % 3) + ternario;
        decimal /= 3;
    }
    return ternario;
}


// Função para converter Binário (string) para Decimal
long long binarioParaDecimal(string binario) {
    long long decimal = 0;
    for (char c : binario) {
        if (c != '0' && c != '1') return -1;
        decimal = decimal * 2 + (c - '0');
    }
    return decimal;
}

// Função para converter Decimal para Binário (string)
string decimalParaBinario(long long decimal) {
    if (decimal == 0) return "0";
    string binario = "";
    while (decimal > 0) {
        binario = to_string(decimal % 2) + binario;
        decimal /= 2;
    }
    return binario;
}

// Função para converter Octal (string) para Decimal
long long octalParaDecimal(string octal) {
    long long decimal = 0;
    for (char c : octal) {
        int digito = c - '0';
        if (digito < 0 || digito >= 8) return -1;
        decimal = decimal * 8 + digito;
    }
    return decimal;
}

// Função para converter Decimal para Octal (string)
string decimalParaOctal(long long decimal) {
    if (decimal == 0) return "0";
    string octal = "";
    while (decimal > 0) {
        octal = to_string(decimal % 8) + octal;
        decimal /= 8;
    }
    return octal;
}

// Função para converter Hexadecimal (string) para Decimal
long long hexadecimalParaDecimal(string hex) {
    if (!hex.empty()) {
        if (hex.front() == 'H' || hex.front() == 'h') {
            hex.erase(0, 1);
        } else if (hex.back() == 'H' || hex.back() == 'h') {
            hex.pop_back();
        }
    }

    long long decimal = 0;
    for (char c : hex) {
        int valor;
        c = toupper(c);
        if (c >= '0' && c <= '9') {
            valor = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            valor = 10 + (c - 'A');
        } else {
            return -1; // Caractere inválido
        }
        decimal = decimal * 16 + valor;
    }
    return decimal;
}

// Função para converter Decimal para Hexadecimal (string)
string decimalParaHexadecimal(long long decimal) {
    if (decimal == 0) return "0";
    string hex = "";
    while (decimal > 0) {
        int resto = decimal % 16;
        char c = (resto < 10) ? '0' + resto : 'A' + (resto - 10);
        hex = c + hex;
        decimal /= 16;
    }
    return hex;
}

// Função para mostrar o menu e processar a conversão
void menu() {
    int baseEntrada, baseSaida;
    string entrada;

    cout << "=== CONVERSOR DE BASES ===" << endl;
    cout << "1. Binario (base 2)" << endl;
    cout << "2. Ternaria (base 3)" << endl;
    cout << "3. Octal (base 8)" << endl;
    cout << "4. Decimal (base 10)" << endl;
    cout << "5. Hexadecimal (base 16)" << endl;

    cout << "\nEscolha a base de ENTRADA (1-5): ";
    cin >> baseEntrada;
    cout << "Digite o numero na base escolhida: ";
    cin >> entrada;

    cout << "\nEscolha a base de SAIDA (1-5): ";
    cin >> baseSaida;

    long long decimal;
    string resultado;

    // Converter entrada para decimal
    switch (baseEntrada) {
        case 1:
            decimal = binarioParaDecimal(entrada);
            break;
        case 2:
            decimal = ternarioParaDecimal(entrada);
            break;
        case 3:
            decimal = octalParaDecimal(entrada);
            break;
        case 4:
            try {
                decimal = stoll(entrada);
            } catch (...) {
                cout << "Erro: Número decimal inválido!" << endl;
                return;
            }
            break;
        case 5:
            decimal = hexadecimalParaDecimal(entrada);
            break;
        default:
            cout << "Opção de base de entrada inválida!" << endl;
            return;
    }

    if (decimal == -1) {
        cout << "Erro: Número inválido para a base de entrada!" << endl;
        return;
    }

    // Converter decimal para base de saída
    switch (baseSaida) {
        case 1:
            resultado = decimalParaBinario(decimal);
            break;
        case 2:
            resultado = decimalParaTernario(decimal);
            break;
        case 3:
            resultado = decimalParaOctal(decimal);
            break;
        case 4:
            resultado = to_string(decimal);
            break;
        case 5:
            resultado = decimalParaHexadecimal(decimal);
            break;
        default:
            cout << "Opção de base de saída inválida!" << endl;
            return;
    }

    cout << "\nResultado: " << resultado << endl;
}

int main() {
    char repetir;

    do {
        menu();

        cout << "\nDeseja fazer outra conversão? (S/N): ";
        cin >> repetir;
        repetir = toupper(repetir);
        cout << endl;

    } while (repetir == 'S');

    cout << "Programa encerrado.\n";
    return 0;
}
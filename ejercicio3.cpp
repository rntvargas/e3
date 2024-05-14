#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream archivo_entrada("C:/Users/renat/Desktop/ejercicio3/ejercicio3.txt");
    ofstream archivo_salida("C:/Users/renat/Desktop/ejercicio3/precios_soles.txt");

    if (!archivo_entrada.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    string producto;
    double precio_dolares;
    const double tasa_conversion = 3.85; // Tasa de conversión de dólares a soles

    while (archivo_entrada >> producto >> precio_dolares) {
        double precio_soles = precio_dolares * tasa_conversion;
        archivo_salida << producto << ", " << fixed << setprecision(2) << precio_soles << endl;
    }

    archivo_entrada.close();
    archivo_salida.close();
    cout << "Los precios en soles se han calculado y guardado en el archivo 'precios_soles.txt'." << endl;

    return 0;
}

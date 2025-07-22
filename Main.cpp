// main.cpp
#include <iostream>
#include <fstream>
#include "Orbita.h"

int main() {
    // Parametri orbitali
    double a = 7000.0;       // km (orbita bassa terrestre)
    double e = 0.1;          // eccentricità
    double mu = 398600.0;    // km^3/s^2 (Terra)
    double inclination = 30.0 * M_PI / 180.0; // 30 gradi convertiti in radianti

    double totalTime = 6000; // secondi (100 min)
    double timestep = 60;    // 1 minuto

    // Creo il simulatore con i parametri sopra
    OrbitSimulator sim(a, e, mu, inclination);
    
    // Genero la traiettoria come vettore di posizioni 3D
    auto path = sim.simulate(totalTime, timestep);

    // Apro (o creo) il file CSV per output
    std::ofstream file("orbita.csv");
    
    file << "x_km,y_km,z_km\n";
    for (const auto& p : path) {
        file << p.x << "," << p.y << "," << p.z << "\n";
    }
    
    file.close();

    std::cout << "Simulazione 3D completata. File salvato come 'orbita.csv'" << std::endl;
    return 0;
}
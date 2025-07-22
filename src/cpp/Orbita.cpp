#include "Orbita.h"

// Costruttore: inizializza i parametri orbitali (inclusa inclinazione per 3D)
OrbitSimulator::OrbitSimulator(double a, double e, double mu, double inclination)
    : a(a), e(e), mu(mu), i(inclination) {}

// Calcola l'anomalia media M = n * t, dove n = sqrt(mu / a^3)
double OrbitSimulator::getMeanAnomaly(double t) {
    double n = std::sqrt(mu / std::pow(a, 3));  // moto medio
    return n * t;
}

// Risolve l'equazione di Keplero M = E - e*sin(E) per trovare l'anomalia eccentrica E
// utilizzando il metodo iterativo di Newton-Raphson.
double OrbitSimulator::solveKepler(double M) {
    // Inizializza E (anomalia eccentrica [rad]) con M. (anomali media [rad]). Ricordiamo che e = 0.1
    double E = M;
    
    // Soglia di convergenza. Quando la correzione delta è minore di epsilon,l'iterazione si ferma
    const double epsilon = 1e-6;
    
    // Numero massimo di iterazioni 
    for (int i = 0; i < 100; ++i) {
        // Calcola il valore della funzione f(E) = E - e*sin(E) - M
        // Vogliamo trovare E tale che f(E) = 0
        double f = E - e * std::sin(E) - M;
        
        // Calcola la derivata f'(E) = 1 - e*cos(E)
        double fp = 1 - e * std::cos(E);
        
        // Calcola la correzione delta usando il metodo di Newton: delta = f(E)/f'(E)
        double delta = f / fp;
        
        // Applica la correzione per avvicinarsi alla soluzione
        E -= delta;
        
        // Criterio di arresto: se la correzione è molto piccola, abbiamo convergenza
        if (std::abs(delta) < epsilon) break;
    }
    
    // Restituisce l'anomalia eccentrica E trovata
    return E;
}

// Converte l'anomalia eccentrica E in anomalia vera theta
double OrbitSimulator::getTrueAnomaly(double E) {
    return 2 * std::atan2(std::sqrt(1 + e) * std::sin(E / 2),
                          std::sqrt(1 - e) * std::cos(E / 2));
}

// Ottiene posizione (x, y, z) al tempo t
Position OrbitSimulator::getPosition(double t) {
    double M = getMeanAnomaly(t);
    double E = solveKepler(M);
    double theta = getTrueAnomaly(E);
    double r = a * (1 - e * std::cos(E));
    
    // Coordinate nel piano orbitale
    double x_orbital = r * std::cos(theta);
    double y_orbital = r * std::sin(theta);
    
    // Orbita 3D: applica rotazione per inclinazione
    double x = x_orbital;
    double y = y_orbital * std::cos(i);
    double z = y_orbital * std::sin(i);
    
    return { x, y, z };
}

// Simula l'orbita generando posizioni da t=0 a totalTime con passo timestep
std::vector<Position> OrbitSimulator::simulate(double totalTime, double timestep) {
    std::vector<Position> path;
    for (double t = 0; t <= totalTime; t += timestep) {
        path.push_back(getPosition(t));
    }
    return path;
}
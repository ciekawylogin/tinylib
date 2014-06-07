#ifndef IP_H
#define IP_H

#include <string>

/**
 * @brief Klasa reprezentująca pojedynczy adres IP v4
 *
 * Udostępnia wygodne konstruktory (pobierające string lub liczbę) i zarządza
 * porządkiem bajtów (big/little endian) w zależności od platformy
 */
class IP
{
public:
    /// Właściwy adres trzymamy w postaci 4 bajtów ('ważniejsze' liczby idą jako pierwsze)
    char address[4];
    /**
     * Tworzy adres IP na podstawie napisu w standardowej postaci, np. "192.168.0.1"
     */
    IP(std::string);

    /**
     * Tworzy adres IP na podstawie int-a.
     * Kolejność bajtów (big/little endian) zależna od platformy na której działamy
     */
    IP(int);
};

#endif // IP_H

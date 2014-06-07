#ifndef IPRANGE_H
#define IPRANGE_H

#include <string>
#include "IP.h"

/**
 * @brief Klasa reprezentująca zakres adresów IP
 */
class IPRange
{
public:
    /**
     * Wczytuje opis tekstowy w postaci standardowej, np. "192.168.0.0/16"
     */
    IPRange(std::string);

    /**
     * Wczytuje opis w postaci "od adresu do adresu"
     */
    IPRange(IP from, IP to);
};

#endif // IPRANGE_H

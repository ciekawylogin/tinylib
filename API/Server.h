#ifndef SERVER_H
#define SERVER_H

#include "EventListener.h"
#include <sockets/Socket.h>
#include <thread>
#include <vector>
#include "IP.h"
#include <string>
#include "../API/SecurityPolicy.h"

class Server
{
    EventListener listener;
    Socket socket;
    std::vector<IP> blackList;
    std::vector<IP> whiteList;
	SecurityPolicy policy;


public:
    Server(int port);

    /**
     * @brief addToWhiteList
     * @param ip
     * Funkcja dodaje adres IP do bialej listy, na ktorej znajduje sie lista zaufanych adresow IP.
     */
    void addToWhiteList(std::string ip);

    /**
     * @brief addToBlackList
     * @param ip
     * Funckja dodaje adres IP do czarnej listy, na ktorej znajduje sie lista niezaufanych adresóœ IP.
     */
    void addToBlackList(std::string ip);
    /**
     * @brief checkBlackList
     * @param ip
     * @return Czy podane ip znajduje sie na bialej liscie
     */
    bool checkBlackList(std::string ip);
    /**
     * @brief checkWhiteList
     * @param ip
     * @return Czy podane ip znajduje sie na czarnej liscie
     */
    bool checkWhiteList(std::string ip);

	/**
	* @brief Ustawia tryb dzia�ania listy
	* @param policy
	*/
	void setSecurityPolicy(SecurityPolicy policy);

    void setConnectionListener(EventListener);
    void listenSync();
    void listenAsync();

};

#endif // SERVER_H

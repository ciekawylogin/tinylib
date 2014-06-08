#ifndef SERVER_H
#define SERVER_H

#include "EventListener.h"
#include <thread>
#include <vector>
#include "IP.h"
#include <string>
#include "../API/SecurityPolicy.h"

class ServerConnection; //forward
class Socket; //forward

class Server
{
    EventListener listener;
    std::shared_ptr<Socket> socket;
    std::vector<IP> blackList;
    std::vector<IP> whiteList;
	SecurityPolicy policy;

    std::vector<std::shared_ptr<ServerConnection> > connections;

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
     * Funckja dodaje adres IP do czarnej listy, na ktorej znajduje sie lista niezaufanych adresow IP.
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
	* @brief Ustawia tryb dzia³ania listy
	* @param policy
	*/
	void setSecurityPolicy(SecurityPolicy policy);

    void setConnectionListener(EventListener);
    void listenSync();
    void listenAsync();

    void registerConnection(std::shared_ptr<ServerConnection> connection)
    {
        connections.push_back(connection);
    }

};

#endif // SERVER_H

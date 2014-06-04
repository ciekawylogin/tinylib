#ifndef CONNECTION_H
#define CONNECTION_H

#include "EventListener.h"
#include "AsyncOperation.h"
#include "../sockets/Socket.h"

#include <thread>
#include <threads/ReadingThread.h>
#include <threads/WritingThread.h>
#include <threads/ListenerCallThread.h>

/**
 * @brief Klasa reprezentująca połączenie z innym komputerem (adresem IP)
 *
 * Posiada powiązany wątek oraz gniazdo TCP, którymi zarządza.
 */
class Connection
{
    /// Wątek do czytania asynchronicznego
    ReadingThread reading_thread;

    /// Wątek do pisania asynchronicznego
    WritingThread writing_thread;

    /// Wątek do wołania listenerów
    ListenerCallThread listener_call_thread;

    /// Gniazdo, za pomocą którego
    Socket socket;

protected:
    /// Obiekty tej klasy nie powinny być tworzone jawnie. Połączenia klienckie tworzymy
    /// za pomocą ClientConnection, zaś serwerowe są tworzone przez obiekt klasy Server.
    Connection();

public:

    /**
     * @brief Zleca wysłanie danych w trybie asynchronicznym
     *
     * Wysłanie danych w trybie asynchronicznym jest realizowane przez wątek zarządzany przez bibliotekę.
     * Wołąjący może mieć wgląd w proces wysyłania danych za pomocą obiektu klasy AsyncOperation, który jest
     * zwracany przez tę funkcję.
     *
     * @param data Bufor zawierający dane do wysłania
     * @param dataSize Rozmiar danych w buforze
     * @param success Listener (funkcja), który zostanie zawołany w przypadku udanego transferu
     * @param failure Listener (funkcja), który zostanie zawołany w przypadku błędu (niemożliwego do
     *        naprawienia przez bibliotekę)
     * @return Obiekt, który pozwala zarządzać operacją wysyłania (patrz opis klasy AsyncOperation)
     */
    AsyncOperation writeAsync(char *data, int dataSize, EventListener success, EventListener failure);

    /**
     * @brief readAsync Zleca odebranie danych w trybie asynchronicznym
     *
     * Wysłanie danych w trybie asynchronicznym jest realizowane przez wątek zarządzany przez bibliotekę.
     * Wołąjący może mieć wgląd w proces wysyłania danych za pomocą obiektu klasy AsyncOperation, który jest
     * zwracany przez tę funkcję.
     *
     * @param data Bufor zawierający dane do wysłania
     * @param maxDataSize Maksymalny rozmiar danych do odebrania
     * @param success Listener (funkcja), który zostanie zawołany w przypadku udanego transferu
     * @param failure Listener (funkcja), który zostanie zawołany w przypadku błędu (niemożliwego do
     *        naprawienia przez bibliotekę)
     * @return Obiekt, który pozwala zarządzać operacją odbierania (patrz opis klasy AsyncOperation)
     */
    AsyncOperation readAsync(char *data, int maxDataSize, EventListener success, EventListener failure);

    /**
     * @brief Wysyła dane przez gniazdo. Wątek wołający zostanie zawieszony w oczekiwaniu, aż dane zostaną
     * dostarczone i potwierdzone.
     *
     * @param data Bufor zawierający dane do wysłania
     * @param dataSize Rozmiar bufora
     */
    void writeSync(const char *data, int dataSize);
    /**
     * @brief Odbiera dane z gniazda, jeżeli wymaga to czekania, to wołający wątek zostanie zawieszony
     * w oczekiwaniuna nie.
     *
     * @param data Bufor na dane.
     * @param maxDataSize Maksymalny rozmiar danych (najlepiej rozmiar ww. bufora)
     */
    void readSync(char *data, int maxDataSize);

    /**
     * @brief Informuje, czy połączenie jest gotowe do wysyłania/odbierania danych
     *
     * Połączenie może być niegotowe, jeżeli trwa na nim operacja synchronicznego zapisu/odczytu danych.
     */
    bool isReady();

    friend class Server;
};

#endif // CONNECTION_H

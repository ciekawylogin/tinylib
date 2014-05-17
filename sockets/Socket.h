#ifndef SOCKET_H
#define SOCKET_H

/**
 * @brief Zapewnia abstrakcję dla gniazd TCP, opakowując gniazda linuksowe bądź windowsowe.
 *
 * Implementacja metod tej klasy jest zależna od systemu, na którym jest kompilowana.
 * Interfejs jest uniwersalny.
 */
class Socket
{
public:
    Socket();
};

#endif // SOCKET_H

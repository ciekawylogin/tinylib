#ifndef ASYNCOPERATION_H
#define ASYNCOPERATION_H

/**
 * @brief Klasa, której obiekty zarządzają operacjami asynchronicznymi
 *
 * Operacja asynchroniczna to taka, która jest wykonana równolegle z wykonaniem wątku wywołującego ją.
 * Innymi słowy: nie zawiesza ona wołającego, jest w pewnym stopniu niezależna.
 *
 * W momencie zawołania operacji asynchronicznej wołający otrzymuje obiekt klasy AsyncOperation, za pomocą
 * którego może:
 * - monitorować wykonanie operacji
 * - anulować wykonanie operacji
 */
class AsyncOperation
{
public:
    AsyncOperation();
    /**
     * @brief Informuje, czy operacja została zakończona.
     */
    void isFinished();
    /**
     * @brief Natychmiast anuluje wykonanie operacji.
     */
    void cancel();
};

#endif // ASYNCOPERATION_H

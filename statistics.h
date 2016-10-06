/**
* \file statistics.h
* \brief Plik nagłówkowy klasy "Statistics"
*/
#ifndef STATISTICS_H
#define STATISTICS_H
#include <array>

/** \brief Definicja statystyk zawodników
 */
class Statistics
{
    private:
        ///Atak
        int attack;

        ///Obrona
        int defense;

        ///Przyjęcie
        int receive;

        ///Rozegranie
        int setting;

    public:
        /** \brief Konstruktor statystyk
         * \param statistics tablica statystyk
         */
        Statistics(std::array<int,4> statistics);

        /** \brief Metoda pozyskania statystyki ataku
         * \return atack
         */
        int getattack();

        /** \brief Metoda pozyskania statystyki obrony
         * \return obrona
         */
        int getdefense();

        /** \brief Metoda pozyskania statystyki przyjęcia
         * \return przyjęcie
         */
        int getreceive();

        /** \brief Metoda pozyskania statystyki rozegrania
         * \return rozegranie
         */
        int getsetting();
};

#endif // STATISTICS_H

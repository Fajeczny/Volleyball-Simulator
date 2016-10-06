/**
* \file vposition.h
* \brief Plik nagłówkowy klasy "VPosition"
*/
#ifndef VPOSITION_H
#define VPOSITION_H
#include <utility>
#include "statistics.h"

/** \brief Definicja klasy zawierające
 */
class VPosition
{
    public:
        /** \brief Konstruktor pozycji siatkarskiej
         */
        VPosition();

        /** \brief Metoda określająca, czy atak się powiódł
         * \param position pozycja na boisku
         * \param stats statystyki zawodnika
         * \return czy się powiodło
         */
        bool attacking(std::pair<int,int> position, Statistics stats);

        /** \brief Metoda określająca, czy obrona się powiodła
         * \param position pozycja na boisku
         * \param stats statystyki zawodnika
         * \return czy się powiodło
         */
        bool defending(std::pair<int,int> position, Statistics stats);

        /** \brief Metoda określająca, czy przyjęcie się powiodło
         * \param position pozycja na boisku
         * \param stats statystyki zawodnika
         * \return czy się powiodło
         */
        bool receiving(std::pair<int,int> position, Statistics stats);

        /** \brief Metoda określająca, czy rozegranie się powiodło
         * \param position pozycja na boisku
         * \param stats statystyki zawodnika
         * \return czy się powiodło
         */
        bool setting(std::pair<int,int> position, Statistics stats);

        /** \brief Metoda wirtualna dziedziczona do klas pochodnych; źródło klasy abstrakcyjnej
         * \param position pozycja na boisku
         * \param stats statystyki zawodnika
         */
        virtual void doaction(std::pair<int,int>position, Statistics stats) =0;
};

#endif // VPOSITION_H

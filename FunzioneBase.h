/***************************************************************************************
****************************************************************************************
     _/_/_/     _/     _/_/       _/_/      Francesco Righini
    _/    _/   _/   _/         _/    _/    Università degli studi di Milano
   _/   _/    _/   _/         _/    _/    Dipartimento di Fisica
  _/_/       _/   _/  _/_/   _/    _/    Progetto "Mirrors"
 _/  _/     _/   _/    _/   _/    _/    creato il 5 marzo 2020 
_/    _/   _/     _/_/       _/_/      e-mail: francesco.righini.studenti.unimi.it
****************************************************************************************
****************************************************************************************/


//┌-------------------------------------------------------------------------------------------------------┐
//| In questo file vengono introdotte due classi: FunzioneBase e Conica.
//| La classe Conica è derivata dalla classe FunzioneBase.
//| La classe FunzioneBase è una classe virtuale. I suoi metodi sono Eval, DerivX, DerivY.
//| Ogni classe che implementa un tipo di funzione da R² in R, derivata da FunzioneBase, deve esplicitare
//| le tre funzioni:
//|
//| La funzione Eval ritorna il valore della funzione valutata nella posizione pos.
//|
//| La funzione DerivX ritorna il valore della derivata della funzione rispetto a x
//|   valutata nella posizione pos.
//|
//| La funzione DerivY ritorna il valore della derivata della funzione rispetto a y
//|   valutata nella posizione pos.
//|
//| 
//| La classe Conica ha come attributi 5 coefficienti. I punti che hanno Eval nulla descrivono una conica
//|   caratterizzata dai 5 coefficienti.
//└-------------------------------------------------------------------------------------------------------┘


#include "Posizione.h"

#ifndef __FunzioneBase__
#define __FunzioneBase__


class FunzioneBase {
	public:
		virtual double Eval(Posizione pos) = 0;	
		virtual double DerivX(Posizione pos) = 0;
		virtual double DerivY(Posizione pos) = 0; 
};


class Conica : public FunzioneBase {

	public:
		Conica(double A, double B, double C, double D, double E, double F);
		double Eval(Posizione pos);
		double DerivX(Posizione pos);
		double DerivY(Posizione pos);

	private:
		double m_A, m_B, m_C, m_D, m_E, m_F;

};

#endif


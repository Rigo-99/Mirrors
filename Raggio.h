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
//| In questo file viene introdotta la classe Raggio che modellizza un raggio di luce.
//| Ogni oggetto è caratterizzato da una posizione e una direzione (direzione della velocità istantanea).
//| I suoi metodi principali sono Passo, Proietta, Rimbalzo.
//|
//| La funzione Passo sposta il raggio di una distanza h in direzione m_dir.
//|
//| La funzione Proietta ritorna la posizione che avrebbe il raggio dopo uno spostamento h in direzione
//|   m_dir senza veramente effettuare lo spostamento.
//|
//| La funzione Rimbalzo ri-orienta il raggio simulando il rimbalzo contro una superficie con normale
//|   in direzione gamma.
//└-------------------------------------------------------------------------------------------------------┘


#include "Posizione.h"

#ifndef __raggio__
#define __raggio__

class Raggio {

	public:
		Raggio(Posizione pos, double theta);
		void Passo(double h);
		Posizione Proietta(Posizione init, double h);
		void Rimbalzo(double gamma);
		Posizione GetPos();
		void SetPos(Posizione pos);
		double GetDir();
		void SetDir(double dir);

	protected:
		Posizione m_pos;
		double m_dir;
};

#endif

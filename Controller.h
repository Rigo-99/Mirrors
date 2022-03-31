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
//| In questo file viene introdotta la classe Controller che gestisce l'interazione tra un raggio e uno
//|   specchio.
//| Ogni oggetto è caratterizzato da alcuni parametri di precisione e di lunghezza degli step.
//| Ogni oggetto possiede i puntatori a un oggetto della classe Specchio e ad un oggetto della classe
//|   Raggio.
//| I suoi metodi principali sono Oltrepassa, Intersezione, LimiteSenzaToccare e Collisione.
//|
//| La funzione Oltrepassa ritorna la posizione che il raggio avrebbe procedendo nella sua direzione
//|   finché non oltrepassa la superficie dello specchio.
//|
//| La funzione LimiteSenzaToccare ritorna la posizione che il raggio avrebbe procedendo nella sua
//|   direzione fino allo step precedente alla collisione con la superficie dello specchio.
//|
//| La funzione Intersezione ritorna la posizione in cui il raggio colliderebbe con lo specchio. Questa
//|   posizione ha una incertezza di m_prec.
//|
//| La funzione Collisione esegue effettivamente la collisione contro lo specchio, simulando il movimento
//|   del raggio e la riflessione. Il parametro mode ha valori 0 o 1 a seconda che si conceda o meno al
//|   raggio di entrare nello specchio (se è permesso 0, se non è permesso 1). Il parametro facoltativo
//|   volta indica quante volte attraversare lo specchio senza collidere prima di collidere.
//└-------------------------------------------------------------------------------------------------------┘


#include "Posizione.h"
#include "Mirror.h"
#include "Raggio.h"
#include "Posizione.h"

#ifndef __Controller__
#define __Controller__



class Controller {

	public:
		Controller(Mirror* specchio, Raggio* fotone);
		Controller(Mirror* specchio, Raggio* fotone, double h, double prec);
		Posizione Oltrepassa();
		Posizione Intersezione();
		Posizione LimiteSenzaToccare();
		void Collisione(int mode);
		void Collisione(int mode, int volta);
		void SetMirror (Mirror* specchio);
		void SetRaggio (Raggio* fotone);
		void Seth(double h);
		void SetPrec(double prec);

	protected:
		Mirror* m_mirror;
		Raggio* m_ray;
		int i_segno;
		double m_h, m_prec;
		double i_h;
};

#endif

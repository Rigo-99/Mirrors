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
//| In questo file viene introdotta la classe Mirror che modellizza uno specchio.
//| I suoi metodi sono Eval, DerivX, DerivY.
//| Ogni specchio è caratterizzato da un oggetto della classe FunzioneBase e da un valore sigma.
//| Ogni specchio ha anche un generatore di numeri casuali.
//|
//| La funzione Eval ritorna il valore della funzione che descrive lo specchio
//|   valutata nella posizione pos. Se Eval(pos) è nullo, allora pos è un punto della superficie dello
//|   specchio. ATTENZIONE: se si è lontani dallo specchio non ha senso!
//|
//| La funzione tangenteVera ritorna il valore della tangente allo specchio valutata nella posizione pos.
//|
//| La funzione tangenteApprox ritorna il valore della tangente allo specchio affetta da un errore 
//|   gaussiano con deviazione stantard sigma valutata nella posizione pos.
//|   ATTENZIONE: se si è lontani dallo specchio non ha senso!
//└-------------------------------------------------------------------------------------------------------┘


#include "FunzioneBase.h"
#include "Posizione.h"
#include "Random.h"

#ifndef __mirror__
#define __mirror__


class Mirror {

	public:
		Mirror(FunzioneBase* f);
		Mirror(FunzioneBase* f, RandomGen* generatore);
		Mirror(FunzioneBase* f, RandomGen* generatore, double sigma);
		double tangenteVera(Posizione pos);		// il risultato viene utilizzato solo da tangenteApprox, se si vuole quello vero porre m_sigma = 0
		double tangenteApprox(Posizione pos);
		double Eval(Posizione pos);
		void SetRandGen(RandomGen* generatore);
		void SetSigma(double sigma);

	protected:
		double m_sigma;
		FunzioneBase* m_f;
		RandomGen* caso;
};

#endif

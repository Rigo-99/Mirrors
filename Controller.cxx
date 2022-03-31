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

#include "Posizione.h"
#include "Mirror.h"
#include "Raggio.h"
#include "Controller.h"
#include "Posizione.h"

#include <cmath>


int GetSegno(double valore){
	if (valore <= 0)
		return -1;
	else
		return 1;
}


Controller::Controller(Mirror* specchio, Raggio* fotone){
	m_mirror = specchio;
	m_ray = fotone;

	i_segno = GetSegno(m_mirror->Eval(m_ray->GetPos()));
	
	i_h = 0.01;
	m_prec = 0.00001;
}

Controller::Controller(Mirror* specchio, Raggio* fotone, double h, double prec){
	m_mirror = specchio;
	m_ray = fotone;

	i_segno = GetSegno(m_mirror->Eval(m_ray->GetPos()));
	
	i_h = h;
	m_prec = prec;
}

Posizione Controller::Oltrepassa(){					// DA AGGIUNGERE UN CONTROLLO DI OVERFLOW (IL RAGGIO CHE SE NE VA ALL'INFINITO)
		
	int segno;
	Posizione pos = m_ray->GetPos();
	m_h = i_h;
	
	i_segno = GetSegno(m_mirror->Eval(pos));
	segno = i_segno;
	
	while (m_mirror->Eval(pos) * segno > 0){
		pos = m_ray->Proietta(pos, m_h);
//		cout << pos.x << " ; " << pos.y << endl;								
	}
	return pos;
}


Posizione Controller::Intersezione(){
	
	Posizione pos = Oltrepassa();

	int segno = -i_segno;
	m_h = -m_h;
	
	while (abs(m_h) > m_prec){					// LA PRECISIONE RAGGIUNTA CORRISPONDE ALLA LUNGHEZZA DELL'ULTIMO PASSO 
		m_h = m_h/2;
		pos = m_ray->Proietta(pos, m_h);
//		cout << pos.x << " ; " << pos.y << endl;							
/*		if (m_mirror->Eval(pos) == 0)				// SE PER CASO SI ARRIVA PROPIO A 0. MEGLIO EVITARE, NON SI SA PIÙ DA CHE PARTE SI STA!
			return pos;
*/		
		if (m_mirror->Eval(pos) * segno < 0){
			m_h = -m_h;
			segno = -segno;
		}
	}
	return pos;
}


Posizione Controller::LimiteSenzaToccare(){		// SE PER CASO È OLTRE, SI TORNA INDIETRO DI m_h
	
	Posizione consigliata = Intersezione();
	
	if (m_mirror->Eval(consigliata) * i_segno > 0){
		return consigliata;
	}
	else{
		return m_ray->Proietta(consigliata, -abs(m_h));
	}
}



void Controller::Collisione(int mode){
	
	Posizione pos;
	
	if (mode == 0){				// 0 = NON INPORTA SE TRAFIGGE LO SPECCHIO, MA E' PIU' PRECISO
		pos = Intersezione();
	}
	if (mode == 1){				// 1 = NON DEVE TRAFIGGERE LO SPECCHIO
		pos = LimiteSenzaToccare();
	}

	m_ray->SetPos(pos);
	m_ray->Rimbalzo(m_mirror->tangenteApprox(pos));
}


void Controller::Collisione(int mode, int volta){
	
	Posizione pos;
	
	int i = 1;

	while (i < volta){
		pos = Oltrepassa();
		m_ray->SetPos(pos);
		i++;
	}



	if (mode == 0){				// 0 = NON INPORTA SE TRAFIGGE LO SPECCHIO, MA E' PIU' PRECISO
		pos = Intersezione();
	}
	if (mode == 1){				// 1 = NON DEVE TRAFIGGERE LO SPECCHIO
		pos = LimiteSenzaToccare();
	}

	m_ray->SetPos(pos);
	m_ray->Rimbalzo(m_mirror->tangenteApprox(pos));
}



void Controller::SetMirror (Mirror* specchio){
	m_mirror = specchio;
	i_segno = GetSegno(m_mirror->Eval(m_ray->GetPos()));
}

void Controller::SetRaggio (Raggio* fotone){
	m_ray = fotone;
	i_segno = GetSegno(m_mirror->Eval(m_ray->GetPos()));
}

void Controller::Seth(double h){
	m_h = h;
}

void Controller::SetPrec(double prec){
	m_prec = prec;
}








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

#include "FunzioneBase.h"
#include "Posizione.h"
#include "Mirror.h"
#include "Random.h"
#include <cmath>


Mirror::Mirror(FunzioneBase* f){
	m_f = f;
	m_sigma = 0;
}

Mirror::Mirror(FunzioneBase* f, RandomGen* generatore){
	m_f = f;
	caso = generatore;
	m_sigma = 0;
}

Mirror::Mirror(FunzioneBase* f, RandomGen* generatore, double sigma){
	m_f = f;
	caso = generatore;
	m_sigma = sigma;
}

double Mirror::tangenteVera(Posizione pos){

	double Dx = m_f->DerivX(pos);
	double Dy = m_f->DerivY(pos);	

	return atan2(-Dx,Dy); // se Dy = 0 la funzione non dà errore e restituisce π/2
}

double Mirror::tangenteApprox(Posizione pos){
	
	double vero = tangenteVera(pos);
	
	double approx = caso->Gauss(vero, m_sigma);  // siamo sicuri che sia giusto fare una cosa del genere?
	
	while (abs(approx) > (M_PI/2)){
		approx = approx - copysign(M_PI,approx);
	}
	return approx;
}

double Mirror::Eval(Posizione pos){

	return m_f->Eval(pos);
}

void Mirror::SetRandGen(RandomGen* generatore){
	caso = generatore;
}

void Mirror::SetSigma(double sigma){
	m_sigma = sigma;
}


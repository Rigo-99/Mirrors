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

#include <cmath>
#include "Posizione.h"
#include "FunzioneBase.h"


Conica::Conica(double A, double B, double C, double D, double E, double F){
	m_A = A;
	m_B = B;
	m_C = C;
	m_D = D;
	m_E = E;
	m_F = F;
}

double Conica::Eval(Posizione pos){
	double x = pos.x;
	double y = pos.y;
	return (m_A*x*x + m_B*x*y + m_C*y*y + m_D*x + m_E*y + m_F);
}

double Conica::DerivX(Posizione pos){
	double x = pos.x;
	double y = pos.y;
	return (2*m_A*x + m_B*y + m_D);
}

double Conica::DerivY(Posizione pos){
	double x = pos.x;
	double y = pos.y;
	return (2*m_C*y + m_B*x + m_E);
}



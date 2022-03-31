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
#include "Raggio.h"
#include <cmath>

Raggio::Raggio(Posizione pos, double theta){
	m_pos = pos;
	m_dir = theta;
}


void Raggio::Passo(double h){
	m_pos.x = m_pos.x + h*cos(m_dir);
	m_pos.y = m_pos.y + h*sin(m_dir);
}

Posizione Raggio::Proietta(Posizione init, double h){
	return {init.x + h*cos(m_dir) , init.y + h*sin(m_dir)};
}

void Raggio::Rimbalzo(double gamma){
	m_dir = 2*gamma - m_dir;
}		


Posizione Raggio::GetPos(){
	return m_pos;
}

double Raggio::GetDir(){
	return m_dir;
}


void Raggio::SetPos(Posizione pos){
	m_pos = pos;
}

void Raggio::SetDir(double dir){
	m_dir = dir;
}

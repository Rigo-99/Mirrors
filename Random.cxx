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

#include "Random.h"
#include <cmath>

/**************************************************/
/* COSTRUTTORE (SET SEED E INIZIALIZZA PARAMETRI) */
/**************************************************/

RandomGen::RandomGen(unsigned int seed){
	m_a = 1664525;
	m_c = 1013904223;
	m_m = pow(2,31); 
	m_seed = seed;
}


/*************************************************/
/* GENERATORE DI NUMERI DOUBLE CASUALI TRA 0 E 1 */
/*************************************************/

double RandomGen::Rand(){
	m_seed = (m_a*m_seed + m_c) % m_m;
	return double(m_seed) / double(m_m);
}


/*************************************************/
/*  GENERATORE DI DOUBLE CASUALI TRA DUE NUMERI  */
/*************************************************/

double RandomGen::Unif(double x_min, double x_max){
	return x_min + (Rand() * (x_max - x_min));
}


/*************************************************/
/*    GENERATORE A DISTRIBUZIONE ESPONENZIALE    */
/*************************************************/

double RandomGen::Exp(double k){
	return - log(1-Rand()) / k;
}


/*************************************************/
/*     GENERATORE A DISTRIBUZIONE GAUSSIANA      */
/*************************************************/

double RandomGen::Gauss(double mean, double sigma){
	double x = sqrt(-2.*log(Rand())) * cos (2.*M_PI*Rand());
	return mean + x*sigma;
}



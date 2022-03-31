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
//| In questo file viene introdotta la struttura Posizione che descrive un punto nel piano.
//└-------------------------------------------------------------------------------------------------------┘

#ifndef __Posizione__
#define __Posizione__

#include<iostream>

using namespace std;


struct Posizione {
	double x;
	double y;
};

/*
void PrintPos(Posizione pos){
	cout << pos.x << " ; " << pos.y << endl;
}
*/

#endif

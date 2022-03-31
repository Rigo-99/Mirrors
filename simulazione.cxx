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
#include <cstdlib>
#include <iostream>
#include "Mirror.h"
#include "FunzioneBase.h"
#include "Raggio.h"
#include "Posizione.h"
#include "Controller.h"
#include "Random.h"


using namespace std;

int main(int argc, char** argv) {

//┌-------------------------------------------------------------------------------------------------------┐
//| Qui vengono definite alcune costanti di lunghezza dei passi e precisione.
//└-------------------------------------------------------------------------------------------------------┘


	float passo = 0.01;
	float precisione = 1E-9;
	float theta_iniziale = 2.5;
	Posizione origine = {0,0};

	double sigma = 0; // voglio gli specchi perfetti

	RandomGen random(1);

//┌-------------------------------------------------------------------------------------------------------┐
//| Qui vengono create le funzioni e di conseguenza gli specchi.
//└-------------------------------------------------------------------------------------------------------┘


	Conica* Ellisse   = new Conica (-8, 0,-9, 8, 0,16);
	Conica* Parabola1 = new Conica ( 1, 0, 0,-2,-2, 0);
	Conica* Parabola2 = new Conica ( 4, 0, 0,36,-8,77);
	Conica* Piano1    = new Conica ( 0, 0, 0, 1, 1,-4);
	Conica* Piano2    = new Conica ( 0, 0, 0, 2,-2,15);
	Conica* Iperbole  = new Conica ( 8, 0,-1,36, 0,36);

	Mirror* specchio1 = new Mirror(Ellisse, &random, sigma);
	Mirror* specchio2 = new Mirror(Parabola1, &random, sigma);
	Mirror* specchio3 = new Mirror(Piano1, &random, sigma);
	Mirror* specchio4 = new Mirror(Piano2, &random, sigma);
	Mirror* specchio5 = new Mirror(Parabola2, &random, sigma);
	Mirror* specchio6 = new Mirror(Iperbole, &random, sigma);

	Raggio* fotone = new Raggio(origine, theta_iniziale);

	sigma = 2E-3;

	specchio1->SetSigma(sigma);
	specchio2->SetSigma(sigma);
	specchio3->SetSigma(sigma);
	specchio4->SetSigma(sigma);
	specchio5->SetSigma(sigma);
	specchio6->SetSigma(sigma);

//┌-------------------------------------------------------------------------------------------------------┐
//| Qui viene creato il controller. Poi vengono definiti posizione ed orientamento iniziale del fotone.
//└-------------------------------------------------------------------------------------------------------┘

	Controller Collider(specchio1,fotone,passo,precisione);
	fotone->SetPos(origine);
	fotone->SetDir(theta_iniziale);

//┌-------------------------------------------------------------------------------------------------------┐
//| Per ogni specchio si associa il controller allo specchio, poi si esegue la collisione.
//└-------------------------------------------------------------------------------------------------------┘

	Collider.SetMirror(specchio1);	
	Collider.Collisione(1);
	//cout << fotone->GetPos().x << " ; " << fotone->GetPos().y << endl;

	Collider.SetMirror(specchio2);
	Collider.Collisione(1,2);
	//cout << fotone->GetPos().x << " ; " << fotone->GetPos().y << endl;
	
	Collider.SetMirror(specchio3);
	Collider.Collisione(1);
	//cout << fotone->GetPos().x << " ; " << fotone->GetPos().y << endl;
	
	Collider.SetMirror(specchio4);
	Collider.Collisione(1);
	//cout << fotone->GetPos().x << " ; " << fotone->GetPos().y << endl;
	
	Collider.SetMirror(specchio5);
	Collider.Collisione(1);
	//cout << fotone->GetPos().x << " ; " << fotone->GetPos().y << endl;
	
	Collider.SetMirror(specchio6);
	Collider.Collisione(1,2);
	//cout << fotone->GetPos().x << " ; " << fotone->GetPos().y << endl;

//┌-------------------------------------------------------------------------------------------------------┐
//| Si fa un passo finale lungo 2, giusto per allontanarsi dall'ultimo specchio e vedere come va.
//└-------------------------------------------------------------------------------------------------------┘

	fotone->Passo(2);
	//cout << fotone->GetPos().x << " ; " << fotone->GetPos().y << endl;


	return 0;
}

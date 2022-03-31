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
//| In questo file viene introdotta la classe Random che fornisce numeri pseudo-casuali.
//└-------------------------------------------------------------------------------------------------------┘

#ifndef _Random_
#define _Random_


class RandomGen {
	public:
		RandomGen(unsigned int);
		double Rand();
		double Unif(double x_min, double x_max);
		double Exp(double mean);
		double Gauss(double mean, double sigma);

	private:
		unsigned int m_a, m_c, m_m;
		unsigned int m_seed;
};

#endif


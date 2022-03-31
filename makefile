LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

simulazione : simulazione.o Mirror.o FunzioneBase.o Raggio.o Controller.o Random.o Posizione.h FunzioneBase.h
	g++ -o simulazione simulazione.o Mirror.o FunzioneBase.o Controller.o Random.o Raggio.o -std=c++11

simulazione.o : simulazione.cxx Mirror.h Raggio.h Controller.h Random.h FunzioneBase.h Posizione.h 
	g++ -c -o simulazione.o simulazione.cxx -std=c++11 -std=c++11		

Mirror.o : Mirror.cxx Mirror.h Random.h FunzioneBase.h Posizione.h
	g++ -c -o Mirror.o Mirror.cxx -std=c++11

Controller.o : Controller.cxx Controller.h Mirror.h Raggio.h Posizione.h
	g++ -c -o Controller.o Controller.cxx -std=c++11

FunzioneBase.o : FunzioneBase.cxx FunzioneBase.h Posizione.h
	g++ -c -o FunzioneBase.o FunzioneBase.cxx -std=c++11

Raggio.o : Raggio.cxx Raggio.h FunzioneBase.h
	g++ -c -o Raggio.o Raggio.cxx -std=c++11

Random.o : Random.cxx Random.h
	g++ -c -o Random.o Random.cxx

clean :
	rm *.o


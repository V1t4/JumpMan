TF = temp/
SFML = /home/vita/Programacion/SFML-2.5.1

jumpman: Arena.o Escena.o Hielo.o Llave.o Nivel.o Puerta.o Final.o Horizontal.o main.o Pasto.o Suelo.o Creditos.o GameOver.o Instrucciones.o Menu.o Personaje.o Vertical.o Enemigo.o Global.o Juego.o Movil.o Piedra.o VerTiempos.o
	g++ -o ./bin/jumpman $(TF)Arena.o $(TF)Escena.o $(TF)Hielo.o $(TF)Llave.o $(TF)Nivel.o $(TF)Puerta.o $(TF)Final.o $(TF)Horizontal.o $(TF)main.o $(TF)Pasto.o $(TF)Suelo.o $(TF)Creditos.o $(TF)GameOver.o $(TF)Instrucciones.o $(TF)Menu.o $(TF)Personaje.o $(TF)Vertical.o $(TF)Enemigo.o $(TF)Global.o $(TF)Juego.o $(TF)Movil.o $(TF)Piedra.o $(TF)VerTiempos.o -Llib -lsfml-graphics -lsfml-window -lsfml-system
	

Arena.o: src/Arena.h src/Arena.cpp
	g++ -Wall -g -c src/Arena.cpp -o $(TF)Arena.o -I$(SFML)/include

Escena.o: src/Escena.h src/Escena.cpp
	g++ -Wall -g -c src/Escena.cpp -o $(TF)Escena.o -I$(SFML)/include

Hielo.o: src/Hielo.h src/Hielo.cpp
	g++ -Wall -g -c src/Hielo.cpp -o $(TF)Hielo.o -I$(SFML)/include

Llave.o: src/Llave.h src/Llave.cpp
	g++ -Wall -g -c src/Llave.cpp -o $(TF)Llave.o -I$(SFML)/include

Nivel.o: src/Nivel.h src/Nivel.cpp
	g++ -Wall -g -c src/Nivel.cpp -o $(TF)Nivel.o -I$(SFML)/include

Puerta.o: src/Puerta.h src/Puerta.cpp
	g++ -Wall -g -c src/Puerta.cpp -o $(TF)Puerta.o -I$(SFML)/include

Final.o: src/Final.h src/Final.cpp src/InputBox.h
	g++ -Wall -g -c src/Final.cpp -o $(TF)Final.o -I$(SFML)/include

Horizontal.o: src/Horizontal.h src/Horizontal.cpp
	g++ -Wall -g -c src/Horizontal.cpp -o $(TF)Horizontal.o -I$(SFML)/include

main.o: src/main.cpp
	g++ -Wall -g -c src/main.cpp -o $(TF)main.o -I$(SFML)/include

Pasto.o: src/Pasto.h src/Pasto.cpp
	g++ -Wall -g -c src/Pasto.cpp -o $(TF)Pasto.o -I$(SFML)/include

Vertical.o: src/Vertical.h src/Vertical.cpp
	g++ -Wall -g -c src/Vertical.cpp -o $(TF)Vertical.o -I$(SFML)/include

Suelo.o: src/Suelo.h src/Suelo.cpp
	g++ -Wall -g -c src/Suelo.cpp -o $(TF)Suelo.o -I$(SFML)/include

Creditos.o: src/Creditos.h src/Creditos.cpp
	g++ -Wall -g -c src/Creditos.cpp -o $(TF)Creditos.o -I$(SFML)/include

GameOver.o: src/GameOver.h src/GameOver.cpp
	g++ -Wall -g -c src/GameOver.cpp -o $(TF)GameOver.o -I$(SFML)/include

Instrucciones.o: src/Instrucciones.h src/Instrucciones.cpp
	g++ -Wall -g -c src/Instrucciones.cpp -o $(TF)Instrucciones.o -I$(SFML)/include

Menu.o: src/Menu.h src/Menu.cpp
	g++ -Wall -g -c src/Menu.cpp -o $(TF)Menu.o -I$(SFML)/include

Personaje.o: src/Personaje.h src/Personaje.cpp
	g++ -Wall -g -c src/Personaje.cpp -o $(TF)Personaje.o -I$(SFML)/include

Enemigo.o: src/Enemigo.h src/Enemigo.cpp
	g++ -Wall -g -c src/Enemigo.cpp -o $(TF)Enemigo.o -I$(SFML)/include

Global.o: src/Global.h src/Global.cpp
	g++ -Wall -g -c src/Global.cpp -o $(TF)Global.o -I$(SFML)/include

Juego.o: src/Juego.h src/Juego.cpp
	g++ -Wall -g -c src/Juego.cpp -o $(TF)Juego.o -I$(SFML)/include

Movil.o: src/Movil.h src/Movil.cpp
	g++ -Wall -g -c src/Movil.cpp -o $(TF)Movil.o -I$(SFML)/include

Piedra.o: src/Piedra.h src/Piedra.cpp
	g++ -Wall -g -c src/Piedra.cpp -o $(TF)Piedra.o -I$(SFML)/include

VerTiempos.o: src/VerTiempos.h src/VerTiempos.cpp
	g++ -Wall -g -c src/VerTiempos.cpp -o $(TF)VerTiempos.o -I$(SFML)/include



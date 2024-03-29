#include "VerTiempos.h"

VerTiempos::VerTiempos() {
	
	tablaTiempos.setFont(Global::fuente);
	tablaTiempos.setFillColor(sf::Color::White);
	tablaTiempos.setCharacterSize(40);
	cargarTiempos();//Se cargan los tiempos desde el archivo
	
	//Se agrega un margen
	margen.setTexture(Global::t_margen);
}

void VerTiempos::procesarEvento (const sf::Event & evento) {
	
}

void VerTiempos::actualizar (Juego & j) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		//Con enter se regresa al menu
		j.cambiarEscena(new Menu());
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {//Si se presiona delete, se borra el archivo de tiempos
		borrarTiempos();
		//Luego de borrar, se refresca la escena
		j.cambiarEscena(new VerTiempos());
	}
}

void VerTiempos::dibujar (sf::RenderWindow & ventana) {
	ventana.clear(sf::Color::Black);
	ventana.draw(margen);
	for (sf::Text linea : Global::txt_verTiempos)
		ventana.draw(linea);
	
	ventana.draw(tablaTiempos);
}

void VerTiempos::cargarTiempos ( ) {
	//Se cargan los mejores tiempos desde un archivo
	ifstream archi("assets/scores/MejoresTiempos.ti",ios::binary);
	if(!archi.is_open()) std::cerr<<"No se encontro el archivo"<<std::endl;
	string str;
	stringstream s; 
	char aux[26];
	float f;
	int i=1;
	while (archi.read(aux,sizeof(aux))&&archi.read(reinterpret_cast<char*>(&f),sizeof(f))) {
		str=aux;
		s<<setfill(' ')<<setw(2)<<i<<"- "<<str<<setw(40-str.size())<<setfill('-')<<setprecision(5)<<f<<" seg"<<endl;
		s.clear();
		i++;
	}
	tablaTiempos.setString(s.str());
	//Se ubica aca para que quede centrado, ya que pide el ancho del texto
	tablaTiempos.setPosition(sf::Vector2f((Global::anchoVentana-tablaTiempos.getLocalBounds().width)/2.0, 130));
}

void VerTiempos::borrarTiempos ( ) {
	//Se borran los mejores tiempos, borrando el archivo y escribiendolo de nuevo
	ofstream archi("assets/scores/MejoresTiempos.ti",ios::binary | ios::trunc);
	char aux[26]="*******";
	float t=9999.9;
	for(int i=0;i<10;i++) { 
		archi.write(aux,sizeof(aux));
		archi.write(reinterpret_cast<char*>(&t),sizeof(t));
	}
	cargarTiempos();
	
}


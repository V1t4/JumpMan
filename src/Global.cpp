#include "Global.h"

//Global para pasaje entre niveles
int Global::cantNiv = 3;//Cuantos niveles tiene el juego
int Global::nivActual = 0;//Por defecto, comienza en 0, el menu no es un nivel

//Global de tamano de nivel
float Global::anchoVentana = 1250;
float Global::altoVentana = 700;
float Global::anchoMundo = 2500;
float Global::altoMundo = 1800;
float Global::tamanoCuadro = 50; //Tamano de los bloques del suelo

float Global::tiempoJugador = 0;//Tiempo registrado por el jugador al ganar la partida

std::string Global::jugador = "Player";//Nombre del jugador. Por defecto es "Player"

//Texturas utilizadas en todo el juego
sf::Texture Global::t_margen;
sf::Texture Global::t_pasto;
sf::Texture Global::t_arena;
sf::Texture Global::t_piedra;
sf::Texture Global::t_hielo;
sf::Texture Global::t_horizontal;
sf::Texture Global::t_vertical;
sf::Texture Global::t_enemigo;
sf::Texture Global::t_llave;
sf::Texture Global::t_puerta;
sf::Texture Global::t_personaje;

//Fuente utilizada en todo el juego
sf::Font Global::fuente;

//Textos a utilizar, configurables por idioma
std::vector<sf::Text> Global::txt_menu;
std::vector<sf::Text> Global::txt_instrucciones;
std::vector<sf::Text> Global::txt_verTiempos;
std::vector<sf::Text> Global::txt_creditos;
std::vector<sf::Text> Global::txt_final;
std::vector<sf::Text> Global::txt_gameOver;


void Global::CargarTexturas ( ) {
	//Se cargan todas las texturas del juego una vez, luego cada clase usa la que necesita
	t_margen.loadFromFile("assets/images/Margen.png");
	t_pasto.loadFromFile("assets/images/Pasto.png");
	t_arena.loadFromFile("assets/images/Arena.png");
	t_piedra.loadFromFile("assets/images/Piedra.png");
	t_hielo.loadFromFile("assets/images/Hielo.png");
	t_horizontal.loadFromFile("assets/images/Horizontal.png");
	t_vertical.loadFromFile("assets/images/Vertical.png");
	t_enemigo.loadFromFile("assets/images/Enemigo.png");
	t_llave.loadFromFile("assets/images/Llave.png");
	t_puerta.loadFromFile("assets/images/Puerta.png");
	t_personaje.loadFromFile("assets/images/Personaje.png");
	//Se carga la fuente utilizada en todo el juego. Todos los textos tienen la misma letra
	fuente.loadFromFile("assets/fonts/Shocking Headline DF.otf");
}

void Global::CargarTextos(std::string idioma){	
	std::ifstream archi;
	std::string str;
	std::stringstream archivoMenu, archivoInst;
	
	//Cargando menu
	archivoMenu << "assets/texts/" << idioma << "/Menu";
	txt_menu = LeerArchivo(archivoMenu.str());
	
	//Cargando instrucciones
	archivoInst << "assets/texts/" << idioma << "/Instrucciones";
	txt_instrucciones = LeerArchivo(archivoInst.str());
	
}

std::vector<sf::Text> Global::LeerArchivo (std::string archivo) {
	std::vector<sf::Text> texto;
	std::string linea;
	unsigned int tamanio;
	float xpos, ypos;
	std::ifstream archi;
	archi.open(archivo);
	sf::Text aux;
	while(std::getline(archi, linea) &&
		  archi>>tamanio &&
		  archi>>xpos &&
		  archi>>ypos &&
		  archi.ignore()){
		aux.setFont(Global::fuente);
		aux.setColor(sf::Color::White);
		aux.setString(linea);
		aux.setCharacterSize(tamanio);
		aux.setPosition(sf::Vector2f(xpos,ypos));
		texto.push_back(aux);
	}
	archi.close();
	return texto;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ninja
 *
 * Created on 14 gennaio 2018, 9.09
 */
#include <memory>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#include "orario.h"
#include "data.h"
#include "applicazione.h"
#include "etichetta.h"
#include "campo_numerico.h"
#include "pulsante.h"
#include "area_testo.h"
#include "pannello.h"
#include "campo_orario.h"
#include "campo_data.h"
#include "campo_menu.h"
#include "campo.h"
using namespace Utili;
using namespace GUI;

using namespace Grafica;

const size_t ID_1 = 1000;
const size_t ID_2 = 1001;
const size_t ID_3 = 1002;
const size_t ID_5 = 1003;
const size_t ID_4 = 1004;
const size_t ID_6 = 1005;
const size_t ID_7 = 1006;
const size_t ID_8 = 1007;
const size_t ID_9 = 1019;
const size_t ID_10 = 3000;
const size_t ID_11 = 3001;
const size_t ID_12 = 3011;
const size_t ID_13 = 3012;
const size_t ID_14 = 3013;
const size_t ID_15 = 3015;
const size_t ID_16 = 3016;
const size_t ID_17 = 3017;
const size_t ID_18 = 3018;
const size_t ID_19 = 3019;
const size_t ID_20 = 3020;

const size_t ID_21 = 4020;
const size_t ID_22 = 5020;
const size_t ID_23 = 6020;
const size_t ID_24 = 7020;
const size_t ID_25 = 7120;


int main(int argc, char* argv[]) {

    Applicazione app(argc,argv);

    /* test 1 */

    pVista vistaTest1 = Utili::crea<Vista>(
        "Test 1",
        Area{
            OrigineArea{25,25},
            DimensioneArea{500,500}
        }
    );

    pEtichetta etichettaTitolo1  = Oggetto::crea<Etichetta>(
    		vistaTest1,
			ID_1,
			"Questa è una bellissima vista",
			OrigineArea{200,0},
			ARANCIONE,
			TipoCarattere::TIMES_ROMAN_24
	);
    etichettaTitolo1->colora(ROSSO,ColoreComponente::BORDO);
    etichettaTitolo1->abilita(ColoreComponente::BORDO, true);

    etichettaTitolo1->colora(NERO,ColoreComponente::SFONDO);
    etichettaTitolo1->abilita(ColoreComponente::SFONDO,true);


    pEtichetta etichettaDescrizione1  = Oggetto::crea<Etichetta>(
        	vistaTest1,
    		ID_2,
    		"Teste sulla vista:\n "
    		"verifica la corretta implementazione delle barre laterali di scorrimento,\n"
    		"quando i componenti aggiunti sono fuori dal campo visivo predefinito della\n"
    		"finestra.",
    		OrigineArea{200,80},
    		ROSSO,
    		TipoCarattere::GENERICO_GRANDE,
			(size_t)15

    );

    etichettaDescrizione1->colora(BLU,ColoreComponente::SFONDO);
    etichettaDescrizione1->abilita(ColoreComponente::SFONDO,true);

    pCampo campo1  = Oggetto::crea<Campo>(vistaTest1,ID_3,OrigineArea{-100,-140},(size_t)15,Maschera{"**/**/****",'*'});
    pCampo campo2  = Oggetto::crea<Campo>(vistaTest1,ID_4,OrigineArea{600,700},(size_t)15);


    pAreaTesto area1 = Oggetto::crea<AreaTesto>(vistaTest1,ID_5,OrigineArea{-200,700},(size_t)30,(size_t)6);
    app.aggiungiVista(vistaTest1);


    /* test 2 */

    pVista vistaTest2 = Utili::crea<Vista>(
		"Test 2",
		Area{
			OrigineArea{150,50},
			DimensioneArea{500,800}
		},
		NERO,
		BIANCO
	);
    pEtichetta etichettaTitolo2  = Oggetto::crea<Etichetta>(
			vistaTest2,
			ID_6,
			"SOMMA 2 NUMERI",
			OrigineArea{200,0},
			BIANCO,
			TipoCarattere::TIMES_ROMAN_24
	);


    pEtichetta etichettaCampoNumero1 = Oggetto::crea<Etichetta>(
			vistaTest2,
			ID_7,
			"A = ",
			OrigineArea{50,150},
			BLU,
			TipoCarattere::TIMES_ROMAN_24
	);

    pCampoNumerico campoNumero1  = Oggetto::crea<CampoNumerico>(
    		vistaTest2,
			ID_8,
			OrigineArea{200,150},
			(size_t)15
	);

    pEtichetta etichettaCampoNumero2 = Oggetto::crea<Etichetta>(
			vistaTest2,
			ID_9,
			"B = ",
			OrigineArea{50,200},
			BLU,
			TipoCarattere::TIMES_ROMAN_24
	);

	pCampoNumerico campoNumero2 = Oggetto::crea<CampoNumerico>(
			vistaTest2,
			ID_10,
			OrigineArea{200,200},
			(size_t)15
	);

	pCampoNumerico campoNumero3 = Oggetto::crea<CampoNumerico>(
				vistaTest2,
				ID_13,
				OrigineArea{200,250},
				(size_t)15
		);
	app.aggiungiVista(vistaTest2);

	pPulsante pulsante = Oggetto::crea<Pulsante>(
			vistaTest2,
			ID_14,
			"Somma",
			OrigineArea{50,250}
    );

	CodiceAzione clic = [](pVista vista){
		pCampoNumerico operando1 = vista->componente<CampoNumerico>(ID_8);
		pCampoNumerico operando2 = vista->componente<CampoNumerico>(ID_10);

		pCampoNumerico risultato = vista->componente<CampoNumerico>(ID_13);
		double somma = operando1->valore() + operando2->valore();
		risultato->testo(std::to_string(somma));
	};

	pulsante->comportamentoClick(clic);

	/* test 3 */

	pVista vistaTest3 = Utili::crea<Vista>(
			"Test 3",
			Area{
				OrigineArea{250,150},
				DimensioneArea{500,800}
			},
			ARANCIONE,
			ROSSO
		);
	pEtichetta etichettaTitolo3  = Oggetto::crea<Etichetta>(
			vistaTest3,
			ID_11,
			"Vista Panello",
			OrigineArea{200,0},
			BLU,
			TipoCarattere::HELVETICA_18
	);


	pPannello pannello1 = Oggetto::crea<Pannello>(
			vistaTest3,
			"pannello test",
			Area{
				OrigineArea{90,150},
				DimensioneArea{100,150}
			}
	);

	pPannello pannello2 = Oggetto::crea<Pannello>(
				vistaTest3,
				"pannello test2",
				Area{
					OrigineArea{250,100},
					DimensioneArea{100,150}
				}
		);
// /*
	pEtichetta etichettaPannello  = Oggetto::crea<Etichetta>(
				pannello1,
				ID_12,
				"Pannello",
				OrigineArea{10,100},
				BLU,
				TipoCarattere::GENERICO_PICCOLO
		);
// */

	app.aggiungiVista(vistaTest3);



	/* test 4 */
	pVista vistaTest4 = Utili::crea<Vista>(
			"Test 4",
			Area{
				OrigineArea{350,250},
				DimensioneArea{500,800}
			},
			BLU,
			VERDE
		);

	pCampoOrario campoOrario1  = Oggetto::crea<CampoOrario>(
			vistaTest4,
			ID_15,
			OrigineArea{100,150}
	);

	pCampoOrario campoOrario2  = Oggetto::crea<CampoOrario>(
			vistaTest4,
			ID_16,
			OrigineArea{100,200}
	);

	pPulsante pulsante2 = Oggetto::crea<Pulsante>(
			vistaTest4,
			ID_18,
			string{"Differenza"},
			OrigineArea{100,250}
	);

	pCampoNumerico campoNumero4 = Oggetto::crea<CampoNumerico>(
			vistaTest4,
			ID_17,
			OrigineArea{100,300},
			(size_t)15
	);

	pCampoNumerico campoNumero5 = Oggetto::crea<CampoNumerico>(
			vistaTest4,
			ID_19,
			OrigineArea{100,350},
			(size_t)15
	);
	pCampoNumerico campoNumero6 = Oggetto::crea<CampoNumerico>(
			vistaTest4,
			ID_20,
			OrigineArea{100,400},
			(size_t)15
	);

	pulsante2->colora(ROSSO,ColoreComponente::TESTO);

	CodiceAzione clic2 = [](pVista vista){
		string s,s2,s3;
		pCampoOrario campo1 = vista->componente<CampoOrario>(ID_15);
		pCampoOrario campo2 = vista->componente<CampoOrario>(ID_16);
		if(campo1 != nullptr && campo2 != nullptr){
			if(campo1->orario() != nullptr && campo2->orario() != nullptr){
				s  = std::to_string( campo1->orario()->differenza( *campo2->orario(),UnitàTemporale::MINUTO) );
				s2 = std::to_string( campo1->orario()->differenza( *campo2->orario(),UnitàTemporale::ORA) );
				s3 = std::to_string( campo1->orario()->differenza( *campo2->orario(),UnitàTemporale::SECONDO) );

			}else{
				s3 = s2 = s = "?";
			}
			s +=" min";
			s2+=" h";
			s3+=" s";
			vista->componente<CampoNumerico>(ID_17)->testo(s3);
			vista->componente<CampoNumerico>(ID_19)->testo(s);
			vista->componente<CampoNumerico>(ID_20)->testo(s2);
		}
	};

	pulsante2->comportamentoClick(clic2);

	pPannello pannelloData = Oggetto::crea<Pannello>(vistaTest4,"calcola data",Area{300,100,300,500});

	pCampoData campoData  = Oggetto::crea<CampoData>(
			pannelloData,
			ID_21,
			OrigineArea{350,150}
	);

	pPulsante pulsante3 = Oggetto::crea<Pulsante>(
			pannelloData,
			ID_22,
			string{"Analizza"},
			OrigineArea{350,200}
	);

	pCampoNumerico campoNumero7 = Oggetto::crea<CampoNumerico>(
			pannelloData,
			ID_23,
			OrigineArea{350,250},
			(size_t)20
	);

	pCampoMenu campoMenuGiorni = Oggetto::crea<CampoMenu>(
			pannelloData,
			ID_25,
			OrigineArea{550,250},
			vector<string>()={"secondi","minuti","ore","giorni","mesi","anni"}
	);
	campoMenuGiorni->testo("secondi");


	pCampo campo = Oggetto::crea<Campo>(
			pannelloData,
			ID_24,
			OrigineArea{350,300},
			(size_t)15
	);

	CodiceAzione clic3 = [](pVista vista){

		string s,s2;
		pCampoData campo1 = vista->componente<CampoData>(ID_21);
		pCampoMenu campoMenu = vista->componente<CampoMenu>(ID_25);
		if(campo1 != nullptr){
			if(campo1->data() != nullptr){
				UnitàTemporale t = UnitàTemporale::SECONDO;

				if(campoMenu->testo() == "minuti") t = UnitàTemporale::MINUTO;
				else if(campoMenu->testo() == "ore") t = UnitàTemporale::ORA;
				else if(campoMenu->testo() == "giorni") t = UnitàTemporale::GIORNO;
				else if(campoMenu->testo() == "mesi") t = UnitàTemporale::MESE;
				else if(campoMenu->testo() == "anni") t = UnitàTemporale::ANNO;

				s  = std::to_string( campo1->data()->valore(t) );
				s2 = campo1->data()->giornoSettimana();
			}else{
				s = "?";
			}
			auto p = vista->componente<CampoNumerico>(ID_23);
			if(p != nullptr)
				p->testo(s);
			auto p2 = vista->componente<Campo>(ID_24);
			if(p2 != nullptr)
				p2->testo(s2);
		}

	};
/*
	ComportamentoMenu azione = [](int id){
		switch(id){
		case 901: cout << "ciaoooo"<<endl;
		};
	};

*/
	pulsante3->comportamentoClick(clic3);

/*	pMenu menu = Utili::crea<Menu>(azione);
	menu->aggiungiVoce((size_t)901,"ciaoooo");

	vistaTest4->aggiungi(menu);
*/
    app.aggiungiVista(vistaTest4);


    app.esegui();


    return 0;
}


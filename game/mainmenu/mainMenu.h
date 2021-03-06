#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

#include "../../scene.h"

enum MAIN_MENU_LAYERS {
	MAIN_MENU_LAYER_LOGO,
	MAIN_MENU_LAYER_WARNING,
	MAIN_MENU_LAYER_START,
	MAIN_MENU_LAYER_SEL,
	MAIN_MENU_LAYER_CONFIG
};

#define TOTAL_ENTRY 3

class mainMenu: public scene {
public:
	mainMenu();
	~mainMenu();

	virtual void stateMachine();
	virtual void start();

private:
	void checkInput();

	std::vector<nTexture*> textureList;
	std::vector<std::unique_ptr<soundChunk>> soundList;

	MAIN_MENU_LAYERS layers;

	bool inFlash;
	
	unsigned char arrow;
	bool pressed;
};

#endif
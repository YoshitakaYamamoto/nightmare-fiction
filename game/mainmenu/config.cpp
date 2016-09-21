#include "config.h"

menuConfig::menuConfig() {
	bg = nullptr;
	pressed = false;
	arrow = 0;
}


menuConfig::~menuConfig() {
	if (bg != nullptr) {
		bg->destroy();
		bg = nullptr;
	}
}

void menuConfig::checkInput() {
	// verify what input is pressed and verify if the state can change
	if (m_Input->getPad() & CORE_PAD_UP) {
		if (!pressed) {
			if (arrow > 0) arrow--; 
			pressed = true;
		}
	} else if (m_Input->getPad() & CORE_PAD_DOWN) {
		if (!pressed) {
			if (arrow < 2) arrow++;
			pressed = true;
		}
	} else if (m_Input->getPad() & CORE_PAD_OK) {
		if (!pressed) {
			switch (arrow) {
				case 0:

				break;

				case 1: 

				break;

				case 2:
					m_Utils->setupFadeEffect(0.007f, 0.0f, 0.0f, 0.0f, FADE_IN);
					layers = CONFIG_LAYER_END;
				break;
			}
		}
	} else {
		pressed = false;
	}
}


void menuConfig::start() {
	layers = CONFIG_LAYER_INIT;
	bg = m_Render->loadTexture("resource/ui/TITLE00.PNG");
}

void menuConfig::stateMachine() {
	switch (layers) {
		case CONFIG_LAYER_INIT:

			m_Utils->renderRectangle(bg->id, {1.0f, 1.0f, 1.0f, 1.0f});			
			if (!m_Utils->isInFade()) {
				layers = CONFIG_LAYER_RUN;
			}
		break;

		case CONFIG_LAYER_RUN:
			checkInput();
			m_Utils->renderRectangle(bg->id, {1.0f, 1.0f, 1.0f, 1.0f});			

			switch (arrow) {
				case 0:
					m_Utils->renderText("PLACEHOLDER 1", -0.5f, -0.5f, 0.0f, FONT_TYPE_BIG, {0.0f, 1.0f, 0.0f, 1.0f});
					m_Utils->renderText("PLACEHOLDER 2", -0.5f, -0.6f, 0.0f, FONT_TYPE_BIG, {1.0f, 1.0f, 1.0f, 1.0f});
					m_Utils->renderText("EXIT", -0.1f, -0.7f, 0.0f, FONT_TYPE_BIG, {1.0f, 1.0f, 1.0f, 1.0f});
				
				break;

				case 1:
					m_Utils->renderText("PLACEHOLDER 1", -0.5f, -0.5f, 0.0f, FONT_TYPE_BIG, {1.0f, 1.0f, 1.0f, 1.0f});
					m_Utils->renderText("PLACEHOLDER 2", -0.5f, -0.6f, 0.0f, FONT_TYPE_BIG, {0.0f, 1.0f, 0.0f, 1.0f});
					m_Utils->renderText("EXIT", -0.1f, -0.7f, 0.0f, FONT_TYPE_BIG, {1.0f, 1.0f, 1.0f, 1.0f});
				break;

				case 2:
					m_Utils->renderText("PLACEHOLDER 1", -0.5f, -0.5f, 0.0f, FONT_TYPE_BIG, {1.0f, 1.0f, 1.0f, 1.0f});
					m_Utils->renderText("PLACEHOLDER 2", -0.5f, -0.6f, 0.0f, FONT_TYPE_BIG, {1.0f, 1.0f, 1.0f, 1.0f});
					m_Utils->renderText("EXIT", -0.1f, -0.7f, 0.0f, FONT_TYPE_BIG,  {0.0f, 1.0f, 0.0f, 1.0f});
				break;

			}

		break;

		case CONFIG_LAYER_END: {
			m_Utils->renderRectangle(bg->id, {1.0f, 1.0f, 1.0f, 1.0f});			

			if (!m_Utils->isInFade()) {
				m_Utils->setupFadeEffect(0.007f, 0.0f, 0.0f, 0.0f, FADE_OUT);
				layers     = CONFIG_LAYER_INIT;
				sceneState = SCENE_STATE_SLEEP;
				nextScene  = 0;
			}			
		}
		break;

		default:

		break;
	}
}



#include<sstream>
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Sonar
{
	MainMenuState::MainMenuState( GameDataRef data):_data(data)
	{
		
	}
	//Aca va a cargar la textura de fondo
	void MainMenuState::Init()
	{
		_data->assets.LoadTexture("Main Menu Background",MAIN_MENU_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Title",GAME_TITLE_FILEPATH);
		_data->assets.LoadTexture("Play Button",PLAY_BUTTON_FILEPATH);
		
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
	}
	void MainMenuState::HandleInput()
	{
		sf::Event event;
		
		while(_data->window.pollEvent( event ))
		{
			if (sf::Event::Closed== event.type)
			{
				_data->window.close( );
			}
		}
	}
	void MainMenuState::Update(float dt)
	{
		
	}
	void MainMenuState::Draw( float dt ) 
	{
		_data->window.clear( );
		
		_data->window.draw( _background );
		_data->window.draw( _title );
		_data->window.draw( _playButton );
		
		_data->window.display( );
	}
};


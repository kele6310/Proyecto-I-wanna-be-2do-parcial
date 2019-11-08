#include<sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"


#include <iostream>

namespace Sonar
{
	GameState::GameState( GameDataRef data):_data(data)
	{
		
	}
	//Aca va a cargar la textura de fondo
	void GameState::Init()
	{
		_data->assets.LoadTexture("Game Background",GAME_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Pipe",PIPE_UP_FILEPATH);
		_data->assets.LoadTexture("Bird 1",BIRD_FRAME_1_FILEPATH);
		_data->assets.LoadTexture("Bird 2",BIRD_FRAME_2_FILEPATH);
		_data->assets.LoadTexture("Bird 3",BIRD_FRAME_3_FILEPATH);
		
		
		pipe = new Pipe(_data);
		bird = new Bird(_data);
		
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	}
	void GameState::HandleInput()
	{
		sf::Event event;
		
		while(_data->window.pollEvent( event ))
		{
			if (sf::Event::Closed== event.type)
			{
				_data->window.close( );
			}
			
			if(_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
			
			}
		}
	}
	void GameState::Update(float dt)
	{
		pipe->MovePipes(dt);
		if(clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY){
		
			pipe->RandomisePipeOffset();
			
			pipe->SpawnInvisiblePipe();
			pipe->SpawnBottomPipe();
			pipe->SpawnTopPipe();
			clock.restart();
			
		}
		
		bird->Animate(dt);
	}
	void GameState::Draw( float dt ) 
	{
		_data->window.clear( );
		
		_data->window.draw( _background );
		pipe->DrawPipes();
		bird->Draw();
		_data->window.display( );
	}
};

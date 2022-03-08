#include "UILives.h"

CUILives::CUILives ( )
{
	m_iCounter = 0;

	//Setting the X position on the bottom left part of the screen 
	m_fXPosition = k_iScreenWidth * 0.04;
}

CUILives::~CUILives ( )
{

}

void CUILives::Initialize ( int iLives )
{ 
	//Adding the Heart.png sprite into the m_vLivesSpriteArray vector based on the iLives number each one with 100px difference 
  	for ( m_iCounter = 0; m_iCounter < iLives; m_iCounter++ )
	{
		
		m_vLivesSpriteArray.push_back ( cocos2d::Sprite::create("Heart.png") );
		m_vLivesSpriteArray[m_iCounter]->setPosition(Point(m_fXPosition,200));
		m_fXPosition = m_fXPosition + 100;
		addChild ( m_vLivesSpriteArray[m_iCounter], 1 );
	}
}

void CUILives::GainLife ( std::vector<Sprite*> array)
{
	//Adding a sprite to the vector  
	array.push_back ( cocos2d::Sprite::create("Heart.png") );
}

void CUILives::LoseLife ( )
{
	//Removing the last member of the vector 
	removeChild ( m_vLivesSpriteArray[m_vLivesSpriteArray.size()-1] );
	m_vLivesSpriteArray.pop_back ( );
}

void CUILives::update ( float fDeltaTime )
{

}

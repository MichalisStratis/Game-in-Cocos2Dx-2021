#ifndef UILIVES_H
#define UILIVES_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"

USING_NS_CC;

class CUILives : public cocos2d::Node
{
private:

	int								m_iCounter;																	// Integer that is used for counter
	float							m_fXPosition;																// Float that keeps the X positio of the sprites 
	std::vector<Sprite*>			m_vLivesSpriteArray;														// Vector of the live sprites 
	void                            update   ( float fDeltaTime );												// Executes every frame - calls private functions

public:

	inline void						setVector ( std::vector<Sprite*> array ){m_vLivesSpriteArray = array;}		// Setter that sets the m_vLivesSpriteArray array 
	inline std::vector<Sprite*>		getVector ( ){return m_vLivesSpriteArray;}									// Getter that returns the m_vLivesSpriteArray array
	void							GainLife ( std::vector<Sprite*> array );									// Public function that is executed to add lives 
	void							LoseLife (  );																// Public function that is executed to deduct lives 

    CUILives	(  );																							// CUILives' constructor 
		
	~CUILives	( );																							// CUILives' constructor

	void Initialize ( int iLives );																				// Initalizes the member variables and sprite properites 


};

#endif // End of "#ifndef UISLIDERBAR_H"
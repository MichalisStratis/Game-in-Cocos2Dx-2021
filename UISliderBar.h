#ifndef UISLIDERBAR_H
#define UISLIDERBAR_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class CUISliderBar : public cocos2d::Node
{
private:
	cocos2d::Sprite*	m_pcBarSprite;															 // Bar Sprite variable 
	cocos2d::Sprite*	m_pcKnobSprite;															 // Knob Sprite variable 
	float				m_fSliderPercent;														 // Float that holds the percentage of the slider 
	float				m_fMouseXPosition;														 // Float that holds the mouse's X position on the screen 
	bool				m_bMouseIsDownAndIn;													 // Boolean that is set to true when mouse is down and in the slider 
	bool				m_bIsActive;															 // Boolean that is set to true when the slider is active 

	void KnobVisualUpdate ( );

public:

	CUISliderBar	( );

	~CUISliderBar	( );

	inline float GetSliderPercent	( ) { return m_fSliderPercent; }							// Getter that returns the slider percentage 
																								   
	inline void SetSliderPercent	( float value ) { m_fSliderPercent = value; }				// Setter thag sets the slider percentage 
																								   
	inline bool GetIsActive			( ) { return m_bIsActive; }									// Getter that returns the boolean if the slider is active 
																								   
	inline void SetIsActive			( bool bIsActive ) { m_bIsActive = bIsActive; }				// Setter that sets if the slider is active or not 

	void Initialize ( );																		// Initalizes the member variables and sprite properites 

	void update ( float fDeltaTime );															// Executes every frame - calls private functions

	void onMouseDown (cocos2d::Event *event );													// Executes the slider actions when the mouse is down 

	void onMouseUp (cocos2d::Event *event );													// Executes the slider events when the mouse is up  

	void onMouseMove (cocos2d::Event *event );													// Executes the slider actions when the mouse is on the move 

};

#endif // End of "#ifndef UISLIDERBAR_H"
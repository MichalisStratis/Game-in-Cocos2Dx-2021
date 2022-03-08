#ifndef UIPROGRESSBAR_H
#define UIPROGRESSBAR_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"
#include "GameManager.h"
#include "GameOverScene.h"
#include "EventListener.h"

USING_NS_CC;
class CUIProgressBar : public cocos2d::Node, public IEventListener
{
private:
    float                                    m_fStartPercentage;             // Float that holds the start time percentage 
    float                                    m_fMaximumPercentage;           // Float that holds the maximum percentage of the bar 
    float                                    m_fCurrentTime;                 // Float that holds the current time percentage 
    bool                                     m_bTimer;                       // Boolean that indicates if the progress bar is a timer or not 
    bool                                     m_bUpdateTimer;				 // Boolean to update timer check	
    cocos2d::ui::LoadingBar*                 m_pcProgressBar;                // Loading bar variable used for the visual progress 
    void update                              (float fDeltaTime);             // Executes every frame - calls private functions
    void updateProgress                      ( float dt );                   // Private funciton for updating the progress bar every frame 
    void updateTime                          (float dt);                     // Private funciton for updating the timer bar every frame    
    void endGame                             (float fTime);                  // Private funciton for ending the game when the timer reaches 0

    // Implements IEventListener to get notified on event raise
    virtual void OnEvent ( EEventType pEventType, void* pData ) override;

public:
    inline float getTime ( )                 {return m_fCurrentTime;}        // Getter that returns the current time 

	CUIProgressBar	( bool bTimer, float fTimer );                           // CUIPorgressBar's constructor 

	~CUIProgressBar	( );                                                     // CUIPorgressBar's destructor 

	void Initialize ( );                                                     // Initalizes the member variables and sprite properites 

};

#endif // End of "#ifndef UISLIDERBAR_H"
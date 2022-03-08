#include "UIProgressBar.h"
#include "GameManager.h"

CUIProgressBar::CUIProgressBar ( bool bTimer, float fTimer )
{
    m_bUpdateTimer = false;

    // Listen to event 
    CGameManager::getInstance ( ).getEventRegistery ( ).ListenToEvent ( EEventType::GamePause, this );

    if ( bTimer == true )
    {
        // Setting the start percentage, current time and maximum percentage for the levels 
        m_bTimer = bTimer;
        m_fStartPercentage = 100.0f;
        m_fMaximumPercentage = fTimer;
        m_fCurrentTime = m_fMaximumPercentage;
        
    }
    else 
    {
        // Setting the start percentage, current time and maximum percentage for the levels 
        m_bTimer = bTimer;
        m_fStartPercentage = 0;
        m_fMaximumPercentage = fTimer;
        m_fCurrentTime = m_fMaximumPercentage;
    }
    
}

CUIProgressBar::~CUIProgressBar ( )
{
    // Unsubscribe to event 
    CGameManager::getInstance ( ).getEventRegistery ( ).UnsubscribeToEvent ( EEventType::GamePause, this );
}

void CUIProgressBar::Initialize ( )
{
    // Setting the sprite and the sprite's scale for the behind bar 
    auto mySprite = Sprite::create("RedRectangle.PNG");
    mySprite->setScaleY ( 0.15 );
    mySprite->setScaleX ( 0.52 );
    addChild ( mySprite );

    //Setting the progress bar's sprite, sprite colour, scale and start percentage 
    m_pcProgressBar = ui::LoadingBar::create("RedRectangle.PNG");
    auto tintBy = TintBy::create ( 2.0f, 120.0f, 232.0f, 254.0f );
    m_pcProgressBar->runAction (tintBy);
    m_pcProgressBar->setScaleY ( 0.1 );
    m_pcProgressBar->setScaleX ( 0.5 );
    m_pcProgressBar->setPercent(m_fStartPercentage);
    addChild(m_pcProgressBar);

    // Updating the progress back with update callback 
    schedule(CC_SCHEDULE_SELECTOR(CUIProgressBar::update,0.1f));
   
}

void CUIProgressBar::update ( float fDeltaTime )
{
    if ( m_bUpdateTimer )
    {
        updateTime ( fDeltaTime );
    }
}

// Implements IEventListener to get notified on event raise
void CUIProgressBar::OnEvent ( EEventType pEventType, void* pData )
{	
    int iValue = *( ( int* ) pData );

    if ( pEventType == EEventType::GamePause )
    {
        m_bUpdateTimer = !iValue;
    }
}

void CUIProgressBar::updateTime ( float dt )
{
    // Abstracting dt from the current time every frame so the progress decreases to the - until it reaches 0
    m_fCurrentTime -= dt;
    float percent = m_pcProgressBar->getPercent();
    percent = 100.0f * ( m_fCurrentTime / m_fMaximumPercentage );
    m_pcProgressBar->setPercent(percent);

}
void CUIProgressBar::updateProgress ( float dt )
{
    // Addind dt to the start percentage every frame so the progress increases to the +
    m_fStartPercentage += dt;
    float percent = m_pcProgressBar->getPercent();
    percent = 100.0f * ( m_fStartPercentage / m_fMaximumPercentage );
    m_pcProgressBar->setPercent(percent);
}

void CUIProgressBar::endGame ( float fTime )
{
    // Ending the game on condition that time is less than 0
    if ( time < 0 )
    {
        CGameManager::getInstance ( ).TransitionScene ( EGameScenes::GameOver );
    }
}
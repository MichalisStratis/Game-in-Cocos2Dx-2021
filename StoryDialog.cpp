#include "StoryDialog.h"
#include "GameManager.h"
#include "LevelEvents.h"
#include "LevelScene.h"
#include "DialogManager.h"

USING_NS_CC;

// CStoryDialog's constructor - empty
CStoryDialog::CStoryDialog ( )
{
}

CStoryDialog::CStoryDialog(  int iLevelIndex )
{
    CBaseDialog::CBaseDialog ( );

    m_lStoryLabel = nullptr;
    m_pcDialogBase = nullptr;
    m_iLevelID = iLevelIndex;
}

CStoryDialog::CStoryDialog ( cocos2d::Scene* scene )
{
    CBaseDialog::CBaseDialog ( scene );
}
    
// CStoryDialog's destructor - empty
CStoryDialog::~CStoryDialog()
{
    CBaseDialog::~CBaseDialog ( );

}

// Inherited from CBaseDialog - Open dialog view
void CStoryDialog::Show ( cocos2d::Scene* scene )
{
    CBaseDialog::Show ( scene );

    // Label heading
    auto lHeadingLabel = Label::createWithSystemFont( "LEVEL " + std::to_string(CLevel::getLevelID()), "Helvetica", 150.0f );
    lHeadingLabel->Label::setColor( Color3B::WHITE );
    lHeadingLabel->setPosition ( Vec2 ( m_pcDialogBase->getContentSize ( ).width / 2, ( m_pcDialogBase->getContentSize ( ).height / 2 ) + 30 ) );
    lHeadingLabel->setScale( 0.7f * m_fScaleWidth, 0.7f * m_fScaleHeight );
    m_pcDialogBase->addChild( lHeadingLabel );

    // Story Text
    m_lStoryLabel = Label::createWithSystemFont( "", "Helvetica", 30.0f );
    m_lStoryLabel->Label::setColor( Color3B::WHITE );
    m_lStoryLabel->setPosition ( Vec2 ( m_pcDialogBase->getContentSize ( ).width / 2, ( m_pcDialogBase->getContentSize ( ).height / 2 ) ) );
    m_lStoryLabel->setScale( 0.7f * m_fScaleWidth, 0.7f * m_fScaleHeight );
    AddLevelStory(m_iLevelID);
    m_pcDialogBase->addChild( m_lStoryLabel );


}


// Inherited from CBaseDialog - Hide dialog view
void CStoryDialog::Hide()
{
    CBaseDialog::Hide ( );
    setVisible ( false );
    cocos2d::Director::getInstance ( )->resume();
}

// Inherited from CBaseDialog - calls CBaseDialog's Reset() method
void CStoryDialog::Reset()
{
    cocos2d::Director::getInstance ( )->pause ( );
    setVisible  ( true );
    //Show( );

}

//Adds the label text based on iLevel
void CStoryDialog::AddLevelStory ( int iLevel )
{
    iLevel = CLevel::getLevelID();

    if ( iLevel == 1 )
    {
        m_lStoryLabel->setString ( "You play as TRONE (TRUSTWORTHY DRONE), a drone's AI that hacks in \n a prison's mainframe in order to rescue his master and creator who has been \n captured and placed behind bars. TRONE faces the challenge \n of collecting all the keys and beating every level in order to crash the system and \n free his master." );
    }
    if ( iLevel == 2 )
    {
        m_lStoryLabel->setString ( "TRONE: Wow the security system is far more difficult to break than \n I expected. If i dont be careful i may end up getting deleted as well." );
    }
    if ( iLevel == 3 )
    {
        m_lStoryLabel->setString ( "TRONE: These ghost-like firewalls are indeed very \n dangerous. One wrong step and i won't be able to rescue my \n master, or myself..." );
    }
    if ( iLevel == 4 )
    {
        m_lStoryLabel->setString ( "TTRONE: Getting here has not been easy at \n all. But i still have some more to go. If I had a human body I would be in \n so much pain right now..." );
    }
    if ( iLevel == 5 )
    {
        m_lStoryLabel->setString ( "TRONE: Ok this is the final stage I have to beat in \n order to save him. I need to be strong, i need to be calm and \n I need to be smart. Thanks to my master I'm all these things. \n HANG IN THERE MASTER I AM COMING!" );
    }

}
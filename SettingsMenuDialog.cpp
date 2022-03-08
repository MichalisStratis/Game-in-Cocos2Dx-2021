#include "SettingsMenuDialog.h"
#include "GameManager.h"
#include "Definitions.h"

USING_NS_CC;

CSettingsMenuDialog::CSettingsMenuDialog ( )
{
    m_lSettingsLabel        = nullptr;
    m_lSFXLabel             = nullptr;
    m_lBackgroundMusicLabel = nullptr;
    m_pcSFXSliderBar        = nullptr;
    m_pcMusicSliderBar      = nullptr;
    m_udSaveData            = cocos2d::UserDefault::getInstance();
}

CSettingsMenuDialog::CSettingsMenuDialog ( cocos2d::Scene* scene )
{
    CBaseDialog::CBaseDialog ( scene );
}

CSettingsMenuDialog::~CSettingsMenuDialog ( )
{

}

void CSettingsMenuDialog::update ( float fDeltaTime )
{
    CGameManager::getInstance ( ).getAudioManager ( ).SetSFXVolume ( m_pcSFXSliderBar->GetSliderPercent ( ) ); 
    m_udSaveData->setFloatForKey ( "SFXVOLUME", m_pcSFXSliderBar->GetSliderPercent ( ) );

    CGameManager::getInstance ( ).getAudioManager ( ).SetMusicVolume ( m_pcMusicSliderBar->GetSliderPercent ( ) ); 
    m_udSaveData->setFloatForKey ( "MUSICVOLUME", m_pcMusicSliderBar->GetSliderPercent ( ) );

    CCLOG ( "MUSIC %d", m_udSaveData->getFloatForKey ( "MUSICVOLUME" ));
    CCLOG ( "SFX %d"  , m_udSaveData->getFloatForKey ( "SFXVOLUME" ));
}

void CSettingsMenuDialog::Show ( cocos2d::Scene* scene )
{
    CBaseDialog::Show(scene);

    m_udSaveData            = cocos2d::UserDefault::getInstance();

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 screenCentre = Vec2 ( visibleSize.width / 2, visibleSize.height / 2 );
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //SETTINGS LABEL WITH COLOUR RED AT THE CENTRE OF THE WINDOW
    m_lSettingsLabel = Label::createWithSystemFont("SETTINGS", "Helvetica", 100);
    m_lSettingsLabel->Label::setColor(Color3B::WHITE);
    m_lSettingsLabel->setPosition ( Vec2 ( screenCentre.x , screenCentre.y + 180 ) );
    addChild( m_lSettingsLabel , 45 );

    //SFX VOLUME LABEL WITH COLOUR RED AT THE CENTRE OF THE WINDOW
    m_lSFXLabel = Label::createWithSystemFont("SFX VOLUME", "Helvetica", 25);
    m_lSFXLabel->Label::setColor(Color3B::RED);
    m_lSFXLabel->setAnchorPoint ( Vec2 ( 0, 0.5f ) );
    m_lSFXLabel->setPosition ( Vec2 ( screenCentre.x - 370, screenCentre.y + 70 ) );
    addChild( m_lSFXLabel , 45 );

    //BACKGROUND MUSIC LABEL WITH COLOUR RED AT THE CENTRE OF THE WINDOW
    m_lBackgroundMusicLabel = Label::createWithSystemFont("MUSIC VOLUME", "Helvetica", 25);
    m_lBackgroundMusicLabel->Label::setColor(Color3B::RED);
    m_lBackgroundMusicLabel->setAnchorPoint ( Vec2 ( 0, 0.5f ) );
    m_lBackgroundMusicLabel->setPosition ( Vec2 ( screenCentre.x - 370, screenCentre.y - 40 ) );
    addChild( m_lBackgroundMusicLabel , 45 );

    // Adds SFX volume slider
    m_pcSFXSliderBar = new CUISliderBar();
    m_pcSFXSliderBar->Initialize( );
    m_pcSFXSliderBar->setPosition ( Vec2 ( screenCentre.x - 190, screenCentre.y + 30 ) );
    m_pcSFXSliderBar->SetSliderPercent (m_udSaveData->getFloatForKey ( "SFXVOLUME", 1 ) );
    addChild ( m_pcSFXSliderBar , 45 );

    // Adds music volume slider
    m_pcMusicSliderBar = new CUISliderBar();
    m_pcMusicSliderBar->Initialize( );
    m_pcMusicSliderBar->setPosition ( Vec2 ( screenCentre.x - 190, screenCentre.y - 80 ) );
    m_pcMusicSliderBar->SetSliderPercent (m_udSaveData->getFloatForKey ( "MUSICVOLUME", 1 ) );
    addChild ( m_pcMusicSliderBar , 45 );

    // actives the volume sliders
    m_pcSFXSliderBar->SetIsActive   ( true );
    m_pcMusicSliderBar->SetIsActive ( true );

    scheduleUpdate ( );
}

void CSettingsMenuDialog::Hide ( )
{
    CBaseDialog::Hide();

    //m_pcSFXSliderBar->SetIsActive   ( false );
    //m_pcMusicSliderBar->SetIsActive ( false );

}

// Inherited from CBaseDialog - calls CBaseDialog's Reset() method
void CSettingsMenuDialog::Reset()
{
    CBaseDialog::Reset();
}

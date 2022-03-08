#include "ShinigamiLogoScene.h"
#include "GameManager.h"



USING_NS_CC;

Scene* ShinigamiLogo::createScene()
{
    return ShinigamiLogo::create();
}

bool ShinigamiLogo::init()
{
    if (!Scene::init())
    {
        return false;
    }

    // Remove default debug statements
    Director::getInstance ( )->setDisplayStats ( false );

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //Plays Apple bite sound
    cocos2d::AudioEngine::play2d ( "Audio/Apple_Bite.ogg", false, 1 );

    //Adding the logo sprite at the center of the screen 
    auto sprite = Sprite::create("logo.png");
    sprite->setPosition(Vec2(k_fHalfWidth + origin.x, k_fHalfHeight + origin.y));
    addChild(sprite, 0);

    // Opens the main menu scene after two seconds with gamemanager
    scheduleOnce(CC_SCHEDULE_SELECTOR(ShinigamiLogo::OpenMainMenu), 8);
    return true;
}

void ShinigamiLogo::menuCloseCallback ( cocos2d::Ref* pSender )
{

}

void ShinigamiLogo::OpenMainMenu (float fDeltaTime)
{
    // Transition to menu scene
    CGameManager::getInstance ( ).TransitionScene ( EGameScenes::MainMenu );
}
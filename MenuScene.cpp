#include "MenuScene.h"
#include "GameManager.h"

USING_NS_CC;

//CMenuScene's Constructor  
CMenuScene::CMenuScene()
{
    m_pcSettingDialog   = nullptr;
    m_pcMenuLabel       = nullptr;
}

//CMenuScene's Destructor 
CMenuScene::~CMenuScene()
{
    if (m_pcSettingDialog)
    {
        delete m_pcSettingDialog;
        m_pcSettingDialog = nullptr;
    }

    if (m_pcMenuLabel)
    {
        delete m_pcMenuLabel;
        m_pcMenuLabel = nullptr;
    }
}

Scene* CMenuScene::createScene()
{
    return CMenuScene::create();
}

bool CMenuScene::init()
{

    if (!Scene::initWithPhysics())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //Adding the background music in the scene 
    CGameManager::getInstance ( ).getAudioManager ( ).playBackgroundMusic ( EBackgroundMusicType::BackgroundMusic );

    //CENTRE OF THE SCREEN DECLARATION 
    float fHalfWidth = visibleSize.width * 0.5f;
    float fHalfHeight = visibleSize.height * 0.5f;

#pragma region Enemy Creation
    int enemyLayer = 1;
    //ADDING BACKGROUND ANS SCALING IT UP
    auto background = Sprite::create("background.png");
    background->setPosition(Point(fHalfWidth + origin.x, fHalfHeight + origin.y));
    background->setScale(3.5);
    addChild(background);

    Vec2 fScale = Vec2 ( 2, 2 );

    //GHOSTS ANIMATION FROM LEFT TOP
    CEnemy* AnimationLT1 = new CEnemy();
    AnimationLT1->Initialize(cocos2d::Vec2(100, 950), cocos2d::Vec2(1850, 950), 0.8f, getEnemyAnimationSize(), getEnemyAnimationPath(), Rect(0, 0, 50, 50), 1, fScale );
    addChild ( AnimationLT1 );

    CEnemy* AnimationLT2 = new CEnemy();
    AnimationLT2->Initialize(cocos2d::Vec2(100, 950), cocos2d::Vec2(100, 100), 0.8f, getEnemyAnimationSize(), getEnemyAnimationPath(), Rect(0, 0, 50, 50), 1, fScale );;
    addChild(AnimationLT2 );

    //GHOSTS ANIMATION FROM RIGHT BOTTOM
    CEnemy* AnimationRB1 = new CEnemy();
    AnimationRB1->Initialize(cocos2d::Vec2(1850, 100), cocos2d::Vec2(100, 100), 0.8f, getEnemyAnimationSize(), getEnemyAnimationPath(), Rect(0, 0, 50, 50), 1, fScale );
    addChild(AnimationRB1 );

    CEnemy* AnimationRB2 = new CEnemy();
    AnimationRB2->Initialize(cocos2d::Vec2(1850, 100), cocos2d::Vec2(1850, 950), 0.8f, getEnemyAnimationSize(), getEnemyAnimationPath(), Rect(0, 0, 50, 50), 1, fScale );
    addChild(AnimationRB2 );

    //GHOSTS ANIMATION FROM LEFT BOTTOM
    CEnemy* AnimationLB1 = new CEnemy();
    AnimationLB1->Initialize(cocos2d::Vec2(100, 100), cocos2d::Vec2(1850, 100), 0.8f, getEnemyAnimationSize(), getEnemyAnimationPath(), Rect(0, 0, 50, 50), 1, fScale );
    addChild(AnimationLB1 );

    CEnemy* AnimationLB2 = new CEnemy();
    AnimationLB2->Initialize(cocos2d::Vec2(100, 100), cocos2d::Vec2(100, 950), 0.8f, getEnemyAnimationSize(), getEnemyAnimationPath(), Rect(0, 0, 50, 50), 1, fScale );
    addChild(AnimationLB2 );

    //GHOSTS ANIMATION FROM RIGHT TOP
    CEnemy* AnimationRT1 = new CEnemy();
    AnimationRT1->Initialize(cocos2d::Vec2(1850, 950), cocos2d::Vec2(1850, 100), 0.8f, getEnemyAnimationSize(), getEnemyAnimationPath(), Rect(0, 0, 50, 50), 1, fScale );
    addChild(AnimationRT1 );

    CEnemy* AnimationRT2 = new CEnemy();
    AnimationRT2->Initialize(cocos2d::Vec2(1850, 950), cocos2d::Vec2(100, 950), 0.8f, getEnemyAnimationSize(), getEnemyAnimationPath(), Rect(0, 0, 50, 50), 1, fScale );
    addChild(AnimationRT2 );
    

    //CREATE IMPOSSIBLE RESCUE TITLE LABEL
    m_pcMenuLabel = Label::createWithSystemFont("Impossible Rescue", "Helvetica", 150.0f);
    m_pcMenuLabel->Label::setColor(Color3B::RED);
    m_pcMenuLabel->setPosition(Point(fHalfWidth, fHalfHeight * 0.5f * 3));
    addChild(m_pcMenuLabel);
#pragma endregion

    //CREATE MENU OPTIONS PLAY,SETTINGS,QUIT
    auto menuOption_1 = MenuItemFont::create("Play",    CC_CALLBACK_1   (CMenuScene::Play,       this));
    auto menuOption_2 = MenuItemFont::create("Settings",CC_CALLBACK_1   (CMenuScene::Settings,   this));
    auto menuOption_3 = MenuItemFont::create("Quit",    CC_CALLBACK_1   (CMenuScene::Quit,       this));

    //PLACING OPTIONS ON SCREEN AND SCALING IT 
    menuOption_1->setPosition(Point(fHalfWidth, fHalfHeight * 0.5f * 2.25));
    menuOption_1->setScale(2.0f);
    menuOption_2->setPosition(Point(fHalfWidth, fHalfHeight * 0.5f * 1.5));
    menuOption_2->setScale(2.0f);
    menuOption_3->setPosition(Point(fHalfWidth, fHalfHeight * 0.5f * 0.75));
    menuOption_3->setScale(2.0f);

    auto* menu = Menu::create(menuOption_1, menuOption_2, menuOption_3, NULL);
    menu->setPosition(Point(0, 0));
    addChild(menu);

    return true;
}

void CMenuScene::menuCloseCallback ( cocos2d::Ref* pSender )
{

}

void CMenuScene::Play(cocos2d::Ref* pSender)
{
    CCLOG("PLAY");

    //Adding UI select sound
    CGameManager::getInstance ( ).getAudioManager ( ).playSFX ( ESFXType::UISelect );       

#if defined ( LEVEL_CREATION_ACTIVE )  // Create Level Scene                                                      

    CGameManager::getInstance ( ).TransitionScene ( EGameScenes::LevelCreation );

#elif defined ( CHEATS_ACTIVE )   // Open Directly to Level ID                                                           

    CGameManager::getInstance ( ).TransitionScene ( EGameScenes::Level, OPEN_LEVEL );

#else // Actual Gameplay
    
    CGameManager::getInstance ( ).TransitionScene ( EGameScenes::Level );

#endif
}

void CMenuScene::Settings(cocos2d::Ref* pSender)
{
    CCLOG("SETTINGS"); 

    //Adding UI select sound
    CGameManager::getInstance ( ).getAudioManager ( ).playSFX ( ESFXType::UISelect );                                                        

    //Getting instance of the setting's m_pcDialog box 
    m_pcSettingDialog = CGameManager::getInstance ( ).getDialogManager ( ).GetViewDialog<CSettingsMenuDialog> ( m_pcSettingDialog, this );   
}

void CMenuScene::Quit(cocos2d::Ref* pSender)
{
    CCLOG("QUIT");

    //Adding UI select sound
    CGameManager::getInstance ( ).getAudioManager ( ).playSFX ( ESFXType::UISelect );

    //TERMINATING PROGRAM
    Director::getInstance()->end();                                                                                                      
}
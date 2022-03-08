#include "GameOverScene.h"
#include "GameManager.h"
#include "UILives.h"

USING_NS_CC;
bool bWin;
Scene* GameOverScene::createScene(bool bJustWon)
{
    bWin = bJustWon;
    return GameOverScene::create();
}

bool GameOverScene::init()
{

    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //CREATING AND ADDING THE BACKGROUND
    auto background = Sprite::create("background.png");
    background->setPosition(Point(k_fHalfWidth + origin.x, k_fHalfHeight + origin.y));
    background->setScale(3.5);
    addChild(background);

    //WIN OR LOSE LABEL WITH COLOUR RED AT THE CENTRE OF THE WINDOW
    m_WinOrLoseLabel = Label::createWithSystemFont("", "Helvetica", 150.0f);
    m_WinOrLoseLabel->Label::setColor(Color3B::RED);
    m_WinOrLoseLabel->setPosition(Point(k_fHalfWidth, k_fHalfHeight * 0.5f * 3));
    addChild(m_WinOrLoseLabel);

    //CREATING THE PLAY AGAIN BUTTON WITH TWO ITTERATING IMAGES
    auto PlayAgainButton = ui::Button::create("Button1.png", "Button2.png");

    PlayAgainButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            AudioEngine::resumeAll ( );
            //Adding UI Select sound
            CGameManager::getInstance ( ).getAudioManager ( ).playSFX ( ESFXType::UISelect );
            CGameManager::getInstance ( ).TransitionScene ( EGameScenes::Level );
            break;
        }
        });
    PlayAgainButton->setPosition(Vec2(k_fHalfWidth * 0.5f, k_fHalfHeight - 100));
    PlayAgainButton->setScale(3.0);
    addChild(PlayAgainButton);

    //CREATING THE EXIT BUTTON WITH TWO ITTERATING IMAGES
    auto ExitButton = ui::Button::create("ExitButton.png", "ExitButton2.png");

    ExitButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            //ENDING WINDOW
            Director::getInstance()->end();
            //Adding UI Select sound
            CGameManager::getInstance ( ).getAudioManager ( ).playSFX ( ESFXType::UISelect );
        }
        });
    ExitButton->setPosition(Vec2(k_fHalfWidth * 0.5f + 1000, k_fHalfHeight - 100));
    ExitButton->setScale(3.0);
    addChild(ExitButton);


    if (bWin == false)
    {
        //Adding the cruing animation on the screen 
        m_sAnimate = new CAnimationSystem ( EAnimationType::CryBaby );
        m_sAnimate->AnimateOn ( 0.3 );
        m_sAnimate->setPosition ( k_fHalfWidth, k_fHalfHeight-250 );
        addChild ( m_sAnimate ,0 );

    }


    schedule(CC_SCHEDULE_SELECTOR(GameOverScene::update));

    return true;
}

void GameOverScene::update(float fDeltaTime)
{
    //Calling the win or lose check function every frame 
    WinOrLose(fDeltaTime, bWin);
}

void GameOverScene::menuCloseCallback ( cocos2d::Ref* pSender )
{
}

void GameOverScene::WinOrLose(float dt, bool bWin)
{
    //SETTING DIFFERENT STRINGS FOR DIFFERENT OUTCOMES 
    if (bWin == true)
    {
        m_WinOrLoseLabel->setString("YOU WIN");
    }
    else
    {
        m_WinOrLoseLabel->setString("GAME OVER");

    }
}
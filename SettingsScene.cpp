#include "SettingsScene.h"


USING_NS_CC;

Scene* SettingsScene::createScene()
{
    return SettingsScene::create();
}


bool SettingsScene::init()
{
    if ( !Scene::init() )
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

    //SETTINGS LABEL WITH COLOUR RED AT THE CENTRE OF THE WINDOW
    m_lSettingsLabel = Label::createWithSystemFont("SETTINGS", "Helvetica", 150.0f);
    m_lSettingsLabel->Label::setColor(Color3B::RED);
    m_lSettingsLabel->setPosition(Point(k_fHalfWidth, k_fHalfHeight * 0.5f * 3));
    addChild(m_lSettingsLabel);

    //CREATING THE BACK BUTTON WITH TWO ITTERATING IMAGES
    auto GoBackButton = ui::Button::create("BackButton1.png", "BackButton.png");

    GoBackButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;

            case ui::Widget::TouchEventType::ENDED:
                break;

            default:
                break;

        }
        });
    GoBackButton->setPosition(Vec2(k_fHalfWidth, k_fHalfHeight - 300));
    GoBackButton->setScale(3.0);
    addChild(GoBackButton);


    return true; 
}

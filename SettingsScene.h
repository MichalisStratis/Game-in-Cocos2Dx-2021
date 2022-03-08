#ifndef SETTINGS_SCENE_SCENE
#define SETTINGS_SCENE_SCENE

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"

class SettingsScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    cocos2d::Label* customTFFLabel;
    cocos2d::Label* m_lSettingsLabel;

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(SettingsScene);    
};

#endif // end of "ifndef SETTINGS_SCENE_SCENE"

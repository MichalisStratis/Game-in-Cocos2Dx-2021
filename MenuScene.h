#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "Definitions.h"
#include "Enemy.h"
#include "SettingsMenuDialog.h"
#include "PauseMenuDialog.h"
#include "GameManager.h"
#include "Cheats.h"
#include "StoryDialog.h"
#include "AnimationSystem.h"



class CMenuScene : public cocos2d::Scene
{
private:
    CSettingsMenuDialog* m_pcSettingDialog;                  // A pointer to the setting's dialog
    cocos2d::Label*      m_pcMenuLabel;                      // A pointer to the menu label 
    CPauseMenu*          m_pcDialog;                             // A pointer to the pause menu dialog
    CAnimationSystem*    m_sAnimate;                         // A pointer to animation system 


public:

    CMenuScene();                                            // CMenuScene's constructor 

    ~CMenuScene();                                           // CMenuScene's destructor 
    
    static cocos2d::Scene* createScene();                    

    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);              // a selector callback

    CREATE_FUNC(CMenuScene);                                    // implement the "static create()" method manually

    void Play       (Ref* pSender);                             // Public function that transitions to the game 

    void Settings   (Ref* pSender);                             // Public function that calls the settings's dialog box 

    void Quit       (Ref* pSender);                             // Public function that terminates the program 

};



#endif // __MENU_SCENE_H__

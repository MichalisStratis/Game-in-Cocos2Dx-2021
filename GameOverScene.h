#ifndef GAMEOVER_SCENE_H
#define GAMEOVER_SCENE_H

#include "cocos2d.h"
#include "Definitions.h"
#include "ui/CocosGUI.h"
#include "AnimationSystem.h"
#include "AudioEngine.h"

class GameOverScene : public cocos2d::Scene
{
private:
    CAnimationSystem*       m_sAnimate;                                  // Pointer to animation system 
    cocos2d::Label*         m_pcLabel;                                   // Label pointer 
    cocos2d::Label*         m_WinOrLoseLabel;                            // Pointer to win or lose label 
    bool                    m_bWin;                                      // Boolean which shows if the game was won or lost 
                                                                        
    void                    WinOrLose(float dt, bool m_bWin);            // Private function which sets different text for different outcomes- win or lose 
                                                                        
public:                                                                 
                                                                        
    CREATE_FUNC(GameOverScene);                                         
                                                                        
    static cocos2d::Scene* createScene(bool bJustWon);                       
                                                                        
    virtual bool           init();                                      
                                                                        
    void                   update(float fDeltaTime);                    // Executes every frame - calls private functions

    void                   menuCloseCallback(cocos2d::Ref* pSender);    

};

#endif // __GAMEOVER_SCENE_H__
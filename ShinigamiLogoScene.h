#ifndef SHINIGAMILOGO_SCENE
#define SHINIGAMILOGO_SCENE

#include "cocos2d.h"
#include "Definitions.h"


class ShinigamiLogo : public cocos2d::Scene
{
private:

public:

    static cocos2d::Scene* createScene();               

    virtual bool init();                                // Virtual bool initalizes the member variables and the sprites on the scene 
    
    void menuCloseCallback(cocos2d::Ref* pSender);      // a selector callback
    
    CREATE_FUNC(ShinigamiLogo);                         // implement the "static create()" method manually

    void OpenMainMenu (float fDeltaTime );              // Open main menu method

};

#endif // end of "ifndef SHINIGAMILOGO_SCENE"

#ifndef ANIMATIONSYSTEM_H
#define ANIMATIONSYSTEM_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"

USING_NS_CC;

//Setting the animation types 
enum class EAnimationType
{
	None,
	Enemy,
	CryBaby
};
class CAnimationSystem : public cocos2d::Node
{
private:
	cocos2d::Sprite*				animSprite;          // Sprite variable which stores the main spritesheet
	Vector<SpriteFrame*>			animFrames;          // Vector of sprites which stores all the different sprite images
	const std::string*				m_cAnimPath;         // String which stores the animation path 
	int						        m_iAnimSize;         // Integer which holds the number of animating sprites 
	Animation*						animation;           // Animation type which creates animation with sprite frames 
	Animate*						animate;             // Stores and creates animation sequence 
	cocos2d::Rect					cFrameSize;          // The size of the sprite frames 
	Vec2							fScale;              // Scale of the animation


public:

	CAnimationSystem	( EAnimationType AnimType);		

	~CAnimationSystem	( );							// CAnimationSystem's constructor

	void Initialize (  );								// CAnimationSystem's destructor 

	void AnimateOn ( float fAnimationSpeed );			// Creates and executes the animation action 

	void update ( float fDeltaTime );					// Executes every frame - calls private functions


};

#endif // End of "#ifndef UISLIDERBAR_H"
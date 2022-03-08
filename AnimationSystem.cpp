#include "AnimationSystem.h"



CAnimationSystem::CAnimationSystem ( EAnimationType AnimType )
{
	fScale = cocos2d::Vec2::ONE;

	//Setting the parameters for each animation based on their type 
	if ( AnimType == EAnimationType::Enemy)
	{
		animSprite = Sprite::create("ghostFRONT.png");

		//Getting the animation's path and size
		m_cAnimPath = getEnemyAnimationPath ( );
		m_iAnimSize = getEnemyAnimationSize ( );

		cFrameSize = Rect ( 0, 0, 50, 50 );
	}

	if ( AnimType == EAnimationType::CryBaby)
	{
		animSprite = Sprite::create("crySprite.png");

		//Getting the animation's path and size
		m_cAnimPath = getCryAnimationPath ( );
		m_iAnimSize = getCryAnimationSize ( );

		cFrameSize = Rect ( 0, 0, 300, 300 );
	}
}

CAnimationSystem::~CAnimationSystem ( )
{

}

void CAnimationSystem::AnimateOn ( float fAnimationSpeed )
{ 

	animFrames.reserve( m_iAnimSize );

	//Loop which iterates through the sprite images
	for ( int iLoop = 0; iLoop < m_iAnimSize; iLoop++ )
	{
		animFrames.pushBack ( SpriteFrame::create ( *( m_cAnimPath + iLoop ), cFrameSize ) );
	}

	//Creating an animation action and making it repeat endlessly 
	animation = Animation::createWithSpriteFrames ( animFrames, fAnimationSpeed );
	animate = Animate::create ( animation );
	animSprite->runAction ( RepeatForever::create ( animate ) );
	addChild ( animSprite );

	scheduleUpdate ( );

}

void CAnimationSystem::update ( float fDeltaTime )
{

}
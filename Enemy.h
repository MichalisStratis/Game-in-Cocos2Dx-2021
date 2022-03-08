#ifndef ENEMY_H
#define ENEMY_H

#include "cocos2d.h"
#include "LevelEvents.h"
#include "Definitions.h"
#include "AnimationSystem.h"
#include "EventListener.h"

USING_NS_CC;

class CEnemy : public cocos2d::Sprite, public IEventListener
{
private:

	float	m_fSpeed;												// Float that indicates the speed of the enemy  
	Vec2	m_v2StartPosition;										// Vec2 that holds the starting position of the enemy 
	Vec2	m_v2EndPosition;										// Vec2 that holds the ending position of the enemy 
	float	m_fJourneyPecrent;										// Float that holds the journey percenatge of the enemy 
	bool	m_bIsPositiveLerpDirection;								// Boolean that checks the lerp direction of the enemy 	
	bool    m_bIsActive;											// Boolean that checks if the enemy is active or not 
	bool    m_bIsAnimated;											// Boolean that checks if the enemy is animated 
	bool    m_bUpdateMovement;										// Boolean to check if game is paused
	float	m_fAnimationSpeed;										// Float that indicates the animation speed of the enemy's animation 
	Vec2	m_fScale;												// Scale of te enemy 
	CAnimationSystem* m_sAnimate;									// Pounter to the animation system 

	void Movement( float fDeltaTime );								// Private fucntion that execute's the enemy's lerp movement

	// Implements IEventListener to get notified on event raise
	virtual void OnEvent ( EEventType pEventType, void* pData ) override;

public:

	
	CEnemy	();														//CEnemy's constructor 
	
	~CEnemy	();														//CEnemy's destructor

	inline bool GetIsActive		() { return m_bIsActive; }			//Getter that returns m_bIsActive
	inline bool GetIsAnimated	() { return m_bIsAnimated; }	    //Getter that returns m_bIsAnimated

	// Initalizes the member variables and sprite properites 
	void Initialize			( Vec2 v2StartPosition, Vec2 v2EndPosition, float fSpeed, std::string cSpriteName, Vec2 fScale );
	void Initialize			( Vec2 v2StartPosition, Vec2 v2EndPosition, float fSpeed, int iAnimationSize, const std::string* pAnimationPath, Rect cFrameSize, float fAnimationSpeed, Vec2 fScale );

	//Resets the enemies' position 
	void Reset				();

	// Executes every frame - calls private functions
	void update				( float fDeltaTime );

	// Called once for each physics contact when contact begins - Returns a physics contact
	bool OnContactBegin			( cocos2d::PhysicsContact& rcContact );

	// Called once for each physics contact when contact ends - Returns a physics contact
	bool OnContactSeparate		( cocos2d::PhysicsContact& rcContact );	
};

#endif // End of "ifndef ENEMY_H"
#include "Enemy.h"
#include "GameManager.h"

USING_NS_CC;

void CEnemy::Movement(float fDeltaTime)
{
	//LERP MOVEMENT 
	if (m_bIsPositiveLerpDirection)
	{
		if (m_fJourneyPecrent > 1)
		{
			//CHANGING THE LERP DIRECTION 
			m_bIsPositiveLerpDirection = false;
			m_fJourneyPecrent = 1;
		}
		else
		{
			//CHANGING POSITION ON THE LERP ON POSITIVE DIRECTION
			m_fJourneyPecrent += m_fSpeed * fDeltaTime;
		}
	}
	else
	{
		if (m_fJourneyPecrent < 0)
		{
			//CHANGING THE LERP DIRECTION 
			m_bIsPositiveLerpDirection = true;
			m_fJourneyPecrent = 0;
		}
		else
		{
			//CHANGING POSITION ON THE LERP ON NEGATIVE DIRECTION
			m_fJourneyPecrent -= m_fSpeed * fDeltaTime;
		}
	}

	//CHANGING THE X AND Y POSITION OF THE ENEMY 
	setPositionX(m_v2StartPosition.x + (m_v2EndPosition.x - m_v2StartPosition.x) * m_fJourneyPecrent);
	setPositionY(m_v2StartPosition.y + (m_v2EndPosition.y - m_v2StartPosition.y) * m_fJourneyPecrent);
}

CEnemy::CEnemy()
{
	m_fSpeed					= 0;
	m_v2StartPosition			= Vec2( 0, 0 );
	m_v2EndPosition				= Vec2( 0, 0 );
	m_fJourneyPecrent			= 0;
	m_bIsPositiveLerpDirection	= true;
	m_bIsActive					= false;
	m_bIsAnimated				= false;
	m_bUpdateMovement			= true;
	m_fAnimationSpeed			= 0.0f;

	// Subscribe to event
	CGameManager::getInstance ( ).getEventRegistery ( ).ListenToEvent ( EEventType::GamePause, this );
}

CEnemy::~CEnemy()
{
	// Unsubscribe to event
	CGameManager::getInstance ( ).getEventRegistery ( ).UnsubscribeToEvent ( EEventType::GamePause, this );
}

void CEnemy::Initialize( Vec2 v2StartPosition, Vec2 v2EndPosition, float fSpeed, std::string cSpriteName, Vec2 fScale )
{
	m_bIsActive			= true;
	m_bIsAnimated		= false;
	m_fSpeed			= fSpeed;
	m_v2StartPosition	= v2StartPosition;
	m_v2EndPosition		= v2EndPosition;
	m_fAnimationSpeed	= fSpeed;
	m_fScale			= fScale;
	
	setTexture		( cSpriteName );
	setAnchorPoint	( cocos2d::Vec2( 0.5f, 0.5f ) );
	setPosition		( m_v2StartPosition );
	setScale		( m_fScale.x, m_fScale.y ); 
	scheduleUpdate	();

	// Initializes and adds a physics body
	auto physicsBody = cocos2d::PhysicsBody::create();
	physicsBody->setDynamic ( false );
	physicsBody->setGravityEnable ( false );
	addComponent ( physicsBody );

	// Creates the contact detection listener
	auto contactListenerBegin = cocos2d::EventListenerPhysicsContact::create();
	// Assigns onContactBegin callback function and adds the event listener to the event dispactcher
	contactListenerBegin->onContactBegin = CC_CALLBACK_1(CEnemy::OnContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListenerBegin, this);

}

void CEnemy::Initialize ( Vec2 v2StartPosition, Vec2 v2EndPosition, float fSpeed, int iAnimationSize, const std::string* pAnimationPath, Rect cFrameSize, float fAnimationSpeed, Vec2 fScale )
{
	m_bIsActive			= true;
	m_bIsAnimated		= true;
	m_fSpeed			= fSpeed;
	m_v2StartPosition	= v2StartPosition;
	m_v2EndPosition		= v2EndPosition;
	m_fAnimationSpeed	= fAnimationSpeed;
	m_fScale			= fScale;

	// Saves the screen dimensions
	auto					visibleSize = cocos2d::Director::getInstance ( )->getVisibleSize ( );
	cocos2d::Vec2			origin = cocos2d::Director::getInstance ( )->getVisibleOrigin ( );

	//Adding the animation of the enemy 
	m_sAnimate = new CAnimationSystem ( EAnimationType::Enemy );
	m_sAnimate->AnimateOn ( 0.5 );
	addChild ( m_sAnimate );
	
	//Setting the scale, acnhor point and position 
	setAnchorPoint	( cocos2d::Vec2 ( 0.5f, 0.5f ) );
	setPosition		( m_v2StartPosition );
	setScale		( m_fScale.x, m_fScale.y ); 
	scheduleUpdate	( );

	// Initializes and adds a physics body
	auto physicsBody = cocos2d::PhysicsBody::create();
	physicsBody->setDynamic ( false );
	physicsBody->setGravityEnable ( false );
	addComponent ( physicsBody );

	// Creates the contact detection listener
	auto contactListenerBegin = cocos2d::EventListenerPhysicsContact::create();
	// Assigns onContactBegin callback function and adds the event listener to the event dispactcher
	contactListenerBegin->onContactBegin = CC_CALLBACK_1(CEnemy::OnContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListenerBegin, this);

}

//RESETING VALUES
void CEnemy::Reset()
{
	setPosition(m_v2StartPosition);
	m_fJourneyPecrent = 0;
}

void CEnemy::update(float fDeltaTime)
{
	if ( m_bUpdateMovement )
	{
		Movement ( fDeltaTime );
	}
}

// Implements IEventListener to get notified on event raise
void CEnemy::OnEvent ( EEventType pEventType, void* pData )
{
	int iValue = *( ( int* ) pData );

	if ( pEventType == EEventType::GamePause )
	{
		m_bUpdateMovement = !iValue;
	}
}


bool CEnemy::OnContactBegin ( cocos2d::PhysicsContact& rcContact )
{
	// Gets a pointer to both bodies in the collision
	cocos2d::PhysicsBody* pcBodyA = rcContact.getShapeA()->getBody();
	cocos2d::PhysicsBody* pcBodyB = rcContact.getShapeB()->getBody();

	// Compares the bitmasks of the bodies to determine if one of them is the player and the other is a grounded enabled surface
	if ( ( pcBodyA == getPhysicsBody() && pcBodyB->getCategoryBitmask ( ) == 1 ) || ( pcBodyA->getCategoryBitmask ( ) == 1 && pcBodyB == getPhysicsBody() ) )
	{
		// Send event for Player has Collided
		int iValue = 1;
		CGameManager::getInstance ( ).getEventRegistery ( ).SendEvent ( EEventType::PlayerHasCollided, &iValue );
		return true;
	}

	return false;
}



#include "UISliderBar.h"

void CUISliderBar::KnobVisualUpdate ( )
{
    //Calculating knobs distance from the left and right side to find the percentage  
    float leftSide  = ( getPositionX ( ) - ( m_pcBarSprite->getBoundingBox ( ).size.width / 2 ) ) + ( m_pcKnobSprite->getBoundingBox ( ).size.width / 2 );
    float rightSide = ( getPositionX ( ) + ( m_pcBarSprite->getBoundingBox ( ).size.width / 2 ) ) - ( m_pcKnobSprite->getBoundingBox ( ).size.width / 2 );

    if ( m_bMouseIsDownAndIn )
    {
        //Percentage of knobs progress in the slider 
        float percent = ( m_fMouseXPosition - leftSide ) / ( rightSide - leftSide );

        //If the knob exceeds the boundaries 0 and 1 then it's set back to the recuring numbers 
        if ( percent > 1 )
        {
            m_fSliderPercent = 1;
        }

        else if ( percent < 0 )
        {
            m_fSliderPercent = 0;
        }

        else
        {
            m_fSliderPercent = percent;
        }
    }

    //Seeting the knobs position on the slider 
    cocos2d::Vec2 localPos = convertToNodeSpace ( cocos2d::Vec2 ( leftSide + ( rightSide - leftSide ) * m_fSliderPercent, 0 ) );
    m_pcKnobSprite->setPositionX (localPos.x);
}

CUISliderBar::CUISliderBar ( )
{
    //Setting the knob's and slider visual sprite 
	m_pcBarSprite	= cocos2d::Sprite::create ( "Player.png" );
	m_pcKnobSprite	= cocos2d::Sprite::create ( "Player.png" );

    //Seeting the bar sprite colour to white and larger scale with ancor point the middle of the sprite  
    m_pcBarSprite->setColor ( cocos2d::Color3B::WHITE );
    m_pcBarSprite->setAnchorPoint ( cocos2d::Vec2 ( 0.5f, 0.5f ) );
    m_pcBarSprite->setScaleX ( 8 );

    //Seeting the knob sprite colour to black with ancor point the middle of sprite 
	m_pcKnobSprite->setColor ( cocos2d::Color3B::BLACK );
    m_pcKnobSprite->setAnchorPoint ( cocos2d::Vec2 ( 0.5f, 0.5f ) );

    m_fSliderPercent    = 0;
    m_fMouseXPosition   = 0;
    m_bMouseIsDownAndIn = false;
    m_bIsActive         = false;
}

CUISliderBar::~CUISliderBar ( )
{

}

void CUISliderBar::Initialize ( )
{
    //Creating event listener for mouse actions  
    auto mouseListener = cocos2d::EventListenerMouse::create();
   
    // Function callbacks for the different mouse events  
    mouseListener->onMouseDown  = CC_CALLBACK_1 ( CUISliderBar::onMouseDown, this );
    mouseListener->onMouseUp    = CC_CALLBACK_1 ( CUISliderBar::onMouseUp, this );
    mouseListener->onMouseMove  = CC_CALLBACK_1 ( CUISliderBar::onMouseMove, this );
    _eventDispatcher->addEventListenerWithSceneGraphPriority ( mouseListener, this );

    addChild ( m_pcBarSprite );
    addChild ( m_pcKnobSprite );

    scheduleUpdate ( );
}

void CUISliderBar::update ( float fDeltaTime )
{
    if ( m_bIsActive )
    {
        //Updating the knob
        KnobVisualUpdate ( );
    }
}

void CUISliderBar::onMouseDown ( cocos2d::Event* event )
{
    cocos2d::EventMouse* e = ( cocos2d::EventMouse* ) event;

    if ( m_bIsActive )
    {
        if ( e->getMouseButton ( ) == cocos2d::EventMouse::MouseButton::BUTTON_LEFT )
        {
            //when the mouse is down within the sprite the get the X position of the mouse 
            if ( e->getLocationInView ( ).x < getPositionX ( ) + ( m_pcBarSprite->getBoundingBox ( ).size.width / 2 ) && e->getLocationInView ( ).x > getPositionX ( ) - ( m_pcBarSprite->getBoundingBox ( ).size.width / 2 ) &&
                 e->getLocationInView ( ).y < getPositionY ( ) + ( m_pcBarSprite->getBoundingBox ( ).size.height / 2 ) && e->getLocationInView ( ).y > getPositionY ( ) - ( m_pcBarSprite->getBoundingBox ( ).size.height / 2 ) )
            {
                m_bMouseIsDownAndIn = true;
                m_fMouseXPosition = e->getLocationInView ( ).x;
            }
        }
    }
}

void CUISliderBar::onMouseUp ( cocos2d::Event* event )
{
    cocos2d::EventMouse* e = ( cocos2d::EventMouse* ) event;

    if ( m_bIsActive )
    {
        if ( e->getMouseButton ( ) == cocos2d::EventMouse::MouseButton::BUTTON_LEFT )
        {
            m_bMouseIsDownAndIn = false;
        }
    }
}

void CUISliderBar::onMouseMove ( cocos2d::Event* event )
{
    cocos2d::EventMouse* e = ( cocos2d::EventMouse* ) event;

    if ( m_bIsActive )
    {
        //when the mouse is down within the sprite then change the X position of the mouse and move the knob 
        if ( e->getLocationInView ( ).x < getPositionX ( ) + ( m_pcBarSprite->getBoundingBox ( ).size.width / 2 ) && e->getLocationInView ( ).x > getPositionX ( ) - ( m_pcBarSprite->getBoundingBox ( ).size.width / 2 ) &&
             e->getLocationInView ( ).y < getPositionY ( ) + ( m_pcBarSprite->getBoundingBox ( ).size.height / 2 ) && e->getLocationInView ( ).y > getPositionY ( ) - ( m_pcBarSprite->getBoundingBox ( ).size.height / 2 ) )
        {
            if ( m_bMouseIsDownAndIn )
            {
                m_fMouseXPosition = e->getLocationInView ( ).x;
            }
        }
    }
}
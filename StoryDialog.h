#ifndef STORYDIALOG_H
#define STORYDIALOG_H

#include "cocos2d.h"
//#include "LevelData.h"
//#include "Cheats.h"
#include "BaseDialog.h"


// CPauseMenu class - Dialog box for pause menu, pauses the game
class CStoryDialog : public CBaseDialog
{

private:
	cocos2d::Label*				 m_lStoryLabel;							// Label for the written story of each level 
	int							 m_iLevelID;							// Integer to declare the level ID 
	void AddLevelStory           ( int iLevelIndex );					// Private function that adds the label text for each level 


public:
	
	CStoryDialog(  );													// CPauseMenu's constructor
	
	CStoryDialog( int iLevelIndex );									
	
	CStoryDialog ( cocos2d::Scene* scene );								

	~CStoryDialog();													// CPauseMenu's destructor

	virtual void Show ( cocos2d::Scene* scene ) override;				// Inherited from CStoryDialog - calls CStoryDialog's Show() method

	virtual void Hide() override;										// Inherited from CStoryDialog - calls CStoryDialog's Hide() method

	virtual void Reset ( ) override;									// Inherited from CStoryDialog - calls CStoryDialog's Reset() method

};

#endif // End of "#ifndef PAUSEMENUDIALOG_H"
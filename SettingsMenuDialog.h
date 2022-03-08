#ifndef SETTINGSMENUDIALOG_H
#define SETTINGSMENUDIALOG_H

#include "cocos2d.h"
#include "UISliderBar.h"
#include "BaseDialog.h"



class CSettingsMenuDialog : public CBaseDialog
{
private:
    cocos2d::Label*          m_lSettingsLabel;
    cocos2d::Label*          m_lSFXLabel;
    cocos2d::Label*          m_lBackgroundMusicLabel;
    CUISliderBar*            m_pcSFXSliderBar; 
    CUISliderBar*            m_pcMusicSliderBar; 
    cocos2d::UserDefault*    m_udSaveData;

public:

    CSettingsMenuDialog ( );

    CSettingsMenuDialog ( cocos2d::Scene* scene );

    ~CSettingsMenuDialog ( );

    void update ( float fDeltaTime );

    // Inherited from CBaseDialog - calls CBaseDialog's Show() method
    virtual void Show ( cocos2d::Scene* scene ) override;

    // Inherited from CBaseDialog - calls CBaseDialog's Hide() method
    virtual void Hide() override;

    // Inherited from CBaseDialog - calls CBaseDialog's Reset() method
    virtual void Reset() override;
 
};

#endif // end of "ifndef SETTINGSMENUDIALOG_H"

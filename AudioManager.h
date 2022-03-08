#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include "cocos2d.h"
#include "AudioEngine.h"
#include "Definitions.h"

struct SSFXClip
{
	int			AudioID = -1;
	bool		Active = false;
};

enum class ESFXType
{
	None,
	KeyPickup,															//Sound of picking up a key 
	HitObstacle,														//Sound of hitting an obstacle 
	HitEnemy,															//Sound of hitting an enemy 
	Jump,																//Sound of jumping  
	UISelect,															//Sound of UI button selection (click)
	OpenDoor,															//Sound of opening door 
	AppleBite															//Sound of apple bite 
};

enum class EBackgroundMusicType
{
	None,
	BackgroundMusic,													 //Background music 
	GameOver,															 //Game Over music 
	WinMusic,															 //Win Music 
	FinalMusic															 //Final Music 

};

class CAudioManager
{
private:
	EBackgroundMusicType	m_eCurrentBackgroundMusicPlayed;			//Backgroung music types 
	int						m_iCurrentBackgroundMusicID;                //Integer that holds background music id's
	std::vector<SSFXClip>	m_caSFXClips;								// Vector of sound effects 
	float					m_fSFXVolume;                               //Float that holds the SFX volume 
	float					m_fMusicVolume;								//Float that holds the Background music volume 

public:

	CAudioManager	( );
	~CAudioManager	( );

	void playSFX				( ESFXType eSfxType );
	void playBackgroundMusic	( EBackgroundMusicType eBackgroundMusicType );

	void SetSFXVolume ( float fSFXVolume );
	void SetMusicVolume ( float fMusicVolume );
};

#endif // End of "#ifndef AUDIOMANAGER_H"
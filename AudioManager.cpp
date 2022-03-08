#include "AudioManager.h"

CAudioManager::CAudioManager ( )
{
	m_eCurrentBackgroundMusicPlayed			= EBackgroundMusicType::None ;
	m_iCurrentBackgroundMusicID				= 0;
	m_fSFXVolume							= 1;
	m_fMusicVolume							= 1;
	m_caSFXClips.resize ( 100 );
}

CAudioManager::~CAudioManager ( )
{

}

void CAudioManager::playSFX( ESFXType eSfxType )
{	
	int iAudioID = 0;

	//Playing the sounds based on the type declared and the volume assigned by the SFX volume slider
	switch ( eSfxType )
	{
		case ESFXType::None:
			break;
			
		case ESFXType::KeyPickup:
			iAudioID = cocos2d::AudioEngine::play2d ( "Audio/CoinPickUp2.ogg", false, m_fSFXVolume );			
			break;

		case ESFXType::UISelect:
			iAudioID = cocos2d::AudioEngine::play2d ( "Audio/GuiSelectSound.ogg", false, m_fSFXVolume );
			break;

		case ESFXType::HitObstacle:
			iAudioID = cocos2d::AudioEngine::play2d ( "Audio/HitObstacle.ogg", false, m_fSFXVolume );
			break;

		case ESFXType::HitEnemy:
			iAudioID = cocos2d::AudioEngine::play2d ( "Audio/HitEnemy.ogg", false, m_fSFXVolume );
			break;

		case ESFXType::Jump:
			iAudioID = cocos2d::AudioEngine::play2d ( "Audio/LongJump.ogg", false, m_fSFXVolume );
			break;

		case ESFXType::OpenDoor:
			iAudioID = cocos2d::AudioEngine::play2d ( "Audio/ExitDoor.ogg", false, m_fSFXVolume );
			break;

		case ESFXType::AppleBite:
			iAudioID = cocos2d::AudioEngine::play2d ( "Audio/Apple_Bite.ogg", false, m_fSFXVolume );
			break;

		default:
			break;
	}

	if(iAudioID != 0)
	{
		//Assigning the SFX ID into the sound effects vector 
		SSFXClip clip = { iAudioID, true };

		m_caSFXClips.push_back ( clip );
	}	
}

void CAudioManager::playBackgroundMusic( EBackgroundMusicType eBackgroundMusicType )
{
	int iAudioID = -1;

	//Playing the background music based on the type declared and the volume assigned by the background music volume sliders
	switch ( eBackgroundMusicType )
	{
		case EBackgroundMusicType::None:
			break;

		case EBackgroundMusicType::BackgroundMusic:
			iAudioID = cocos2d::AudioEngine::play2d ( "Audio/bgmusic.mp3", true, m_fMusicVolume );
			break;
		case EBackgroundMusicType::GameOver:
			iAudioID = cocos2d::AudioEngine::play2d ( "Audio/GameOver.mp3", false, m_fMusicVolume );
			break;
		case EBackgroundMusicType::WinMusic:
			iAudioID = cocos2d::AudioEngine::play2d ( "Audio/win_music.mp3", false, m_fMusicVolume );
			break;
		case EBackgroundMusicType::FinalMusic:
			iAudioID = cocos2d::AudioEngine::play2d ( "Audio/finalmusic.mp3", false, m_fMusicVolume );
			break;

		default:
			break;
	}

	if ( iAudioID != -1 )
	{
		//Seeting the current background music and ID while playing 
		m_eCurrentBackgroundMusicPlayed = eBackgroundMusicType;
		m_iCurrentBackgroundMusicID = iAudioID;
	}
}

void CAudioManager::SetSFXVolume ( float fSFXVolume )
{
	//Setting the volume of the sound effects 
	m_fSFXVolume = fSFXVolume;

	for ( auto& SFXClip : m_caSFXClips )
	{
		if ( SFXClip.Active && SFXClip.AudioID != -1 )
		{
			cocos2d::AudioEngine::setVolume ( SFXClip.AudioID, m_fSFXVolume );
		}
	}
}

void CAudioManager::SetMusicVolume ( float fMusicVolume )
{
	//Setting the volume of the background music 
	m_fMusicVolume = fMusicVolume;
	cocos2d::AudioEngine::setVolume ( m_iCurrentBackgroundMusicID, m_fMusicVolume );
}

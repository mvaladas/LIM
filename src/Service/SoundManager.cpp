/**
 * @file SoundManager.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief
 * @version 0.1
 * @date 02-04-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "SoundManager.h"
#include <DFMiniMp3.h>
#include <SoftwareSerial.h>
#include "Constants.h"

/**
 * @brief Construct a new Sound Manager:: Sound Manager object
 * 
 */
SoundManager::SoundManager() : mySoftwareSerial(DFMINIMP3_RX, DFMINIMP3_TX),
                               dfmp3(mySoftwareSerial)
{
}

/**
 * @brief return a singleton instance of SoundManager
 * 
 * @return SoundManager instance.
 */
SoundManager &SoundManager::getInstance()
{
    // Singleton Instance
    static SoundManager instance;
    return instance;
}

/**
 * @brief initializes sound manager. Must be called once.
 */
void SoundManager::Begin()
{
    dfmp3.begin();
    // The DFMini needs a while to start up.
    delay(2000);
}

/**
 * @brief sets the volume of the DFMini
 * 
 * @param volume volume to set. From 0 to 100.
 */
void SoundManager::setVolume(uint8_t volume)
{
    dfmp3.setVolume(volume);
}

/**
 * @brief Play a track in the MP3 folder of the DFMini.
 * 
 * @param track track number in the MP3 Folder.
 */
void SoundManager::playMp3FolderTrack(uint16_t track)
{
    dfmp3.playMp3FolderTrack(track);
}
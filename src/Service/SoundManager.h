/**
 * @file SoundManager.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief
 * @version 0.1
 * @date 02-04-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _H_SOUNDMANAGER
#define _H_SOUNDMANAGER

#include <Arduino.h>
#include <DFMiniMp3.h>
#include <SoftwareSerial.h>

/**
 * @brief Singleton instance to playback sounds via DFMiniMp3
 * 
 */
class SoundManager
{

private:
  SoundManager();
  SoundManager(SoundManager const &) = delete;
  void operator=(SoundManager const &) = delete;
/** instance of SoftwareSerial **/
  SoftwareSerial mySoftwareSerial;
  /** Instance of DFMiniMp3 used to playback sounds **/
  DFMiniMp3<SoftwareSerial, SoundManager> dfmp3;

public:
  static SoundManager &getInstance();
  virtual void Begin();
  virtual void setVolume(uint8_t volume);
  virtual void playMp3FolderTrack(uint16_t track);


 // REVIEW: The code below was copy pasted and needs review and refactoring
  static void PrintlnSourceAction(DfMp3_PlaySources source, const char *action)
  {
    if (source & DfMp3_PlaySources_Sd)
    {
      Serial.print("SD Card, ");
    }
    if (source & DfMp3_PlaySources_Usb)
    {
      Serial.print("USB Disk, ");
    }
    if (source & DfMp3_PlaySources_Flash)
    {
      Serial.print("Flash, ");
    }
    Serial.println(action);
  }
  static void OnError(DFMiniMp3<SoftwareSerial, SoundManager> &mp3, uint16_t errorCode)
  {
    // see DfMp3_Error for code meaning
    Serial.println();
    Serial.print("Com Error ");
    Serial.println(errorCode);
  }
  static void OnPlayFinished(DFMiniMp3<SoftwareSerial, SoundManager> &mp3, DfMp3_PlaySources source, uint16_t track)
  {
    Serial.print("Play finished for #");
    Serial.println(track);
  }
  static void OnPlaySourceOnline(DFMiniMp3<SoftwareSerial, SoundManager> &mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "online");
  }
  static void OnPlaySourceInserted(DFMiniMp3<SoftwareSerial, SoundManager> &mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "inserted");
  }
  static void OnPlaySourceRemoved(DFMiniMp3<SoftwareSerial, SoundManager> &mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "removed");
  }
};

#endif
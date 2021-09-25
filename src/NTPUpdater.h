/**
 * @file NTPUpdater.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @date 25-09-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_NTPUPDATER
#define _H_NTPUPDATER
#include <TimeLib.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// NTP Servers:
static const char ntpServerName[] = "pool.ntp.org";
const int timeZone = 1; // Central European Time

time_t getNtpTime();
void sendNTPpacket(WiFiUDP Udp, IPAddress &address);
void printDigits(int digits);

void NTPSetup()
{
  // NTP Time Sync
  setSyncProvider(getNtpTime);
  setSyncInterval(60 * 60); // Update every hour.
}
void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(".");
  Serial.print(month());
  Serial.print(".");
  Serial.print(year());
  Serial.println();
}

void printDigits(int digits)
{
  // utility for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
time_t getNtpTimeSimple()
{
  time_t now;                         // this is the epoch
  tm tm;
  time(&now);
  localtime_r(&now, &tm);
  return now;
}


/*-------- NTP code ----------*/

const int NTP_PACKET_SIZE = 48;     // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets

time_t getNtpTime()
{
  unsigned long nowmillis = millis();
  WiFiUDP Udp;
  unsigned int localPort = 8888; // local port to listen for UDP packets

  Udp.begin(localPort);

  IPAddress ntpServerIP; // NTP server's ip address

  while (Udp.parsePacket() > 0)
    ; // discard any previously received packets
  Serial.println("Transmit NTP Request");
  // get a random server from the pool
  WiFi.hostByName(ntpServerName, ntpServerIP);
  Serial.print(ntpServerName);
  Serial.print(": ");
  Serial.println(ntpServerIP);
  sendNTPpacket(Udp,ntpServerIP);
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500)
  {
    int size = Udp.parsePacket();
    if (size >= NTP_PACKET_SIZE)
    {
      Serial.println("Receive NTP Response");
      Udp.read(packetBuffer, NTP_PACKET_SIZE); // read packet into the buffer
      unsigned long secsSince1900;
      // convert four bytes starting at location 40 to a long integer
      secsSince1900 = (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      Udp.stop();
      return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
    }
  }
  Serial.println("No NTP Response :-(");
  Udp.stop();
  return 0; // return 0 if unable to get the time
}

// send an NTP request to the time server at the given address
void sendNTPpacket(WiFiUDP Udp, IPAddress &address)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011; // LI, Version, Mode
  packetBuffer[1] = 0;          // Stratum, or type of clock
  packetBuffer[2] = 6;          // Polling Interval
  packetBuffer[3] = 0xEC;       // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;
  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}

#endif
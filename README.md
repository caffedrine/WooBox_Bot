# WooBox Bot

Just another C++ app which you can use to send a bunch of likes to pictures published on WooBox. With a good internet connection and a list of proxies you may send hundreds of likes per minute.

Notes:
  * It require LibCURL and boost;
  * Adjust MAX number of threads for speed;
  
# How to use 

It was made fast fast. So a lot of things are hardcoded. 

  1. Fill **proxy.txt** file with your proxies list. One per line IP:PORT;
  2. In **HTTPDownloader.cpp** add your picture ID on line **175**;

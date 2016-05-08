USBprint
==========
#####A Library for fast convenient ```printf```-style printing with TI Tiva C (Stellaris) series microcontrollers
######Version 1.1, 5-8-16######

Features and benefits of ```printf```-style functions vs. the default ```Serial.print```
 - The ability to convert and transmit multiple values all at once results in faster communication.
 - Better floating point conversions.
 - More data types and conversions are supported.
 - More readable code.
 
Current limitations
 - Examples and testing needed.
 - Optimize performance by using lower level functions 

Installation
 1. Quit the Energia IDE application.
 2. Download and expand the ZIP archive of the USBprint repository. Rename the resultant folder *USBprint*.
 3. Locate the *libraries* folder for the Energia IDE and place the *USBprint* folder there. On OS X, this folder is in *Documents/Energia/*. On Windows, it is located at *Documents\Energia\* (or possibly *My Documents\Energia\*).
 4. Relaunch the Energia IDE. "USBprint" should now appear under *File > Examples* and *Sketch > Import Library...*.

--------

How to write from Tiva C series microcontrollers to PC via USB at high speed
 - Minimize number of individual USB serial write operations.
 - Use the fast print functions in USBprint.
 - Increase baud rate between microcontroller and computer.
 - Reduce the [USB latency time](http://robosavvy.com/forum/viewtopic.php?p=8967#p8967) (Windows).
 - Send encoded (compressed) data and decompress later on PC.
 
--------

Copyright &copy; 2016, Andrew D. Horchler  
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of Case Western Reserve University nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL ANDREW D. HORCHLER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
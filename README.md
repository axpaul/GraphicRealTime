<h1>GraphicRealTime</h1>
        
<h2>GraphicRealTime : Class to create real-time graphics on Qt using QThread technology</h2>

*Copyright (c) CNES and contributors. All rights reserved.*

<p>To be able to control a measuring bench using the GRBL system, I wrote a serial class that allows to send commands to manage the movement. 
        Attention, I do not manage the reading, being messages of non-fixed sizes it would be necessary to remodel the whole code to be able to read.</p>
        
        - Branch AxisTime : Graph plotting the points received by another thread as a function of time.
        - Branch TwoAxes : Graph created from two data sets, they are transmitted using another thread.


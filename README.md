<h1>GraphicRealTime</h1>
        
<h2>GraphicRealTime : Class to create real-time graphics on Qt using QThread technology</h2>

*Copyright (c) CNES and contributors. All rights reserved.*

<p>For different Qt projects, it is interesting to be able to create and use graphs when we want to do monitoring. 
 Here in the different codes I provide you can find some examples of graphs. 
 Usually it works thanks to a second thread that generates the points, this allows integrating it easily in any single thread or multithreaded project.</p>
        
        - Branch AxisTime : Graph plotting the points received by another thread as a function of time.
        - Branch TwoAxes : Graph created from two data sets, they are transmitted using another thread.

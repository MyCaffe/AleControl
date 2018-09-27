# AleControl
The <b>AleControl</b> gives Windows C# developers easy access to the Arcade-Learning-Environment (ALE)[1].  ALE is a modification of the Atari-2600 Emulator[2] from the Stella Team that provides access to numerous ATARI 
games (such as Pong, Space Invaders, etc) for Reinforcement Learning.  The games run actions provided by the user and produce their overall game visualizations and game state.

For more information on ALE, please see https://github.com/mgbellemare/Arcade-Learning-Environment

For more information on Stella, please see https://github.com/stella-emu/stella

The <b>AleControl</b> uses the 'atari_win64' source tree which is a fork off the ALE Github tree that has been modified to run as a Windows 64-bit DLL and is licensed under the <a href="https://github.com/MyCaffe/AleControl/blob/master/atari_win64/License.txt">GNU license</a>. 

The 'atari_win64' project uses the Simple DirectMedia Layer (SDL for short) which is a cross-platform library designed to make it easy to write multi-media software such as games and emulators. 

The Simple DirectMedia Layer library source code is available from: http://www.libsdl.org, and the SDL library is distributed under the terms of
the <a href="http://www.gnu.org/copyleft/lesser.html">GNU LGPL License</a>.

The <b>AleControl</b>, written by <a href="https://www.signalpop.com">SignalPop LLC</a>, is a Windows 64-bit COM control that gives any OLE Automation enabled language (C#, Visual Basic, etc.) easy access to the ALE environment via OLE Automation and is licensed under the <a href="https://github.com/MyCaffe/AleControl/blob/master/LICENSE">Apache 2.0 license</a>.  An extensive list of ATARI game ROM files is provided by OpenAI on Github at <a href="https://github.com/openai/atari-py/tree/master/atari_py/atari_roms">openai/atari-py/atari_roms</a> and are distributed under the <a href="https://github.com/openai/atari-py/blob/master/License.txt">GNU GPL License</a>.
You can also use Nuget to get the <a href="https://www.nuget.org/packages?q=AleControl">AleControl</a>.

When used in combination with <a href="https://github.com/mycaffe">MyCaffe</a> (A complete C# re-write of CAFFE[3]) the AleControl can be used to solve 
Reinforcement Learning related problems via the <a href="https://www.signalpop.com/wp-content/uploads/2018/09/myCaffe_with_RL_paper.v0.9.pdf">MyCaffeTrainerRL</a> control.
You can also use Nuget to get <a href="https://www.nuget.org/packages?q=MyCaffe">MyCaffe</a>.

The <a href="https://www.signalpop.com">SignalPop AI Designer</a> provides a development environment allows you to quickly pull all of these parts together to visually
design MyCaffe based models that are both compatible with native CAFFE and support Reinforcement Learning for the Arcade-Learning-Envrionment.

<h3>Supported Development Environments:</h3>
* Visual Studio 2017</br>
* Visual Studio 2015</br>
</br>
<h3>References</h3>
[1] [The Arcade Learning Environment: An Evaluation Platform for General Agents](https://arxiv.org/abs/1207.4708) by Marc G. Bellemare, 
Yavar Naddaf, Joel Veness and Michael Bowling, 2012-2013.  Source code available on GitHub at <a href="https://github.com/mgbellemare/Arcade-Learning-Environment">mgbellemare/Arcade-Learning-Envrionment</a>
</br></br>
[2] [Stella - A multi-platform Atari 2600 VCS emulator](https://stella-emu.github.io/) by Bradford W. Mott, Stephen Anthony and The Stella Team, 1995-2018
Source code available on GitHub at <a href="https://github.com/stella-emu/stella">stella-emu/stella</a>
</br></br>
[3] [CAFFE: Convolutional Architecture for Fast Feature Embedding](https://arxiv.org/abs/1408.5093) by Yangqing Jai, Evan Shelhamer, Jeff Donahue, 
Sergey Karayev, Jonathan Long, Ross Girshick, Sergio Guadarrama, and Trevor Darrell, 2014.  Source code available on Github at <a href="https://github.com/BVLC/caffe">BVLC/caffe</a>


# Maze
My solution files to LiveOverflow's game hacking challenge called "Maze".  

The hack's main functionality is entirely implemented as function hooks and does not require anything other than the running game.  
However, to plot coordinates using the position hooks `server.py` must be executed seperately. The hooks will communicate with the renderer using UDP packets. The interesting code can be found in "MazeHooks", the "Maze" project is only the DLL injector.  

In this version all hooks are installed using EasyHook which can be automatically installed by restoring the Nuget packages in Visual Studio.  

All other files like IDA/Binja databases and ReClass.NET structures can be found in the "misc" folder.
# World Builder CPP

This project is a simple Windows Forms application written in C++/CLI. It demonstrates an entity system and a basic form for a resource management game.

## Building
Open a *Developer Command Prompt for Visual Studio* and compile `Program.cpp`
with the C++/CLI compiler:

```cmd
cl /clr /FeWorldBuilder.exe WorldBuilderCPP\Program.cpp
```

This produces `WorldBuilder.exe`, which starts the Windows Forms application.

## Running
Execute `WorldBuilder.exe` after compiling. The main form displays a
placeholder status label that updates every second.

Future development can expand on this skeleton to implement the full game
mechanics.


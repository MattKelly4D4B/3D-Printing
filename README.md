# 3D-Printing
3D Printing firmware and projects. It's probably my favorite hobby.

I currently have three 3D printers running on Klipper firmware.

The Klipper firmware is special because it uses a raspberry pi to act as a processor for some of the 
computations a 3D printer has to make, thus lightening the load on the printer's actual motherboard.  
In turn you see much better quality and faster print speeds. There is a fork of the klipper repository
in my repositories, and I will also upload a copy of the current version as of 6/28/2022 here.

The Raspberry pi is also resposible for hosting a web server that runs the Mainsail UI front end this provides the user with an interface to control their printers and modify firmware settings, and many other things that would normally have to be done manually.  Being on a web server allows the host to be accessed anywhere on my home network.  The moonraker firmware is the backend for the web server, and KIAUH stands for Klipper Install and Update Helper, which is a life saver when trying to get some of these programs set up.

These are my pritners and the modifications i've done to them.

  Creality Ender 3 Pro (Cartesian printer) -- Biqu H2 500c extruder, dual z axis kit, 4x 2208 stepper motor drivers, MKS Gen L motherboard, upgraded bed springs. 

  Voxelab Aquila (Cartesian printer) -- 3D Printed direct drive mount in pa6-gf nylon, upgraded bed springs and leveling knobs.

  FLSun QQS Pro (Delta Printer) -- BMG extruder, 3D printed mount to mount the extruder lower (Shortens length of bowden tube).

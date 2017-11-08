# AHXR ScreenLock - Screen Lock Builder

<p align="center">
	<img src="https://i.imgur.com/UzyOWNK.png" />
	<a href="https://i.imgur.com/HQhESds.jpg">Web Builder</a> | <a href="https://i.imgur.com/ieYpNPN.png">.net Builder</a> | <a href="https://i.imgur.com/fWVGHxN.png">.net Listener</a>
</p>

---

This is a very simple screen lock application. As of right now, it is only compatible with Windows. The builder allows you to generate an .exe file that when ran, will lock the client's computer until they
enter the password you provided in the builder. The screen lock cannot be closed by normal means (ALT+F4), will kill Task Manager, will minimize all your windows and will prevent you from switching between
different applications.

The person who runs the lock will simply only be able to read the message provided and enter a password. This program was not made for malicious intent, but for educational purposes. If this is used for
another intent, there is a high chance an anti-virus software will detect it. The password and message are stored in the .exe file. The password is encrypted in SHA256. If you plan on using this for
whatever reason, it will be best to encrypt the .exe with an encrypter software. 

Starting from the 1.1 update, you are now allowed to pack an .exe file into the locker. This means you can basically attach and run any program you would like in the background as the screen is locked.
Basically, it will pack the other .exe file into the locker and extract it when the locker is run. Then the extracted executable will be run in the background. If the executable closes on it's own or
if the client enters their password, the extracted file will be deleted. This will prevent any backtracing of what was run. (Not available on web version atm)

In the releases, I've included the builder, the empty screenlock exe (don't run) and a test file. The password to the test executable is "test". Use this at your own risk.

---

# Trojan.Win32.Lockdown - Shutdown 2017

<p align="center">
	<img src="https://i.imgur.com/aaClNNk.png" />
</p>

---

This is Shutdown 2017. A malware that works with AHXRScreenlock. This software only works on Windows and requires .net framework to be run. This program was not made for malicious intent, but for educational purposes.
If you choose to use this f or another intent, you're on your own with the legal action that may occur. 

When run, this software will hint the user that their computer requires scanning. If the user attempts to close the GUI, it will still automatically run in the background like a bug. It will
then scan on it's own. This process is somewhat silent, but it does begin to hog up memory and CPU as it gets deeper in the scan. If the GUI is somehow closed from another source, it will
automatically open itself back up again. 

The scanning is where the damage is done. This software will go through every system file and run AHXRBuilder.exe on that file and attach the .exe to the screenlock. Then it will DELETE your old
and clean system file. Meaning, whenever you try to run a file found inside of "Windows", it will run the .exe, however it will lock your screen meanwhile. For the sake of security and educational
purposes, I set the password to simply "hi". If you want to change the password for whatever reason, you will need to recompile the code.

The scan also goes through your System32 and SysWOW64 folder. It will forcibly take ownership of your files. I have included the malware in a separate download. Run it at your own risk. 

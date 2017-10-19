# AXHR ScreenLock - Screen Lock Builder

<p align="center">
	<img src="https://i.imgur.com/UzyOWNK.png" />
	[Web Builder](https://i.imgur.com/HQhESds.jpg) | [.net Builder](https://i.imgur.com/EqihWFg.png)
</p>

---

This is a very simple screen lock application. As of right now, it is only compatible with Windows. The builder allows you to generate an .exe file that when ran, will lock the client's computer until they
enter the password you provided in the builder. The screen lock cannot be closed by normal means (ALT+F4), will kill Task Manager, will minimize all your windows and will prevent you from switching between
different applications.

The person who runs the lock will simply only be able to read the message provided and enter a password. This program was not made for malicious intent, but for educational purposes. If this is used for
another intent, there is a high chance an anti-virus software will detect it. The password and message are stored in the .exe file. The password is encrypted in SHA256. If you plan on using this for
whatever reason, it will be best to encrypt the .exe with an encrypter software. 

In the releases, I've included the builder, the empty screenlock exe (don't run) and a test file. The password to the test executable is "test". Use this at your own risk.
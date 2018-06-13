# Is0bel-Server
UPDATE: 13/06/2018
Pruned repository of .o files
Features this week: Read carefully.

All within Is0bel. Now multi threaded.
Except web browser setting. (on a long todo list :3)
Is0bel has functionality. 
Activities within program will trigger a firewall response.


Web server

Date & time server + test client

Echo server + Test client.




Web server now working. Read below to test
Yet to add stop. 
 

Web server on
<a href="https://imgur.com/EyoGukP"><img src="https://i.imgur.com/EyoGukP.jpg" title="source: imgur.com" /></a>

Web browser test.
<a href="https://imgur.com/kgThRdo"><img src="https://i.imgur.com/kgThRdo.jpg" title="source: imgur.com" /></a>

TO TEST

Copy Index.html to C:\
or add a path to a "Index.html" directories only no file name WIP.
Start Is0bel.server

Click play under Web server tab

open a preferred web browser (Internet explorer, chrome ect)

type or copy paste 127.0.0.1 into the address bar and press enter.

You should now see the content of Index.html.

Close Is0bel.server to stop web server listening.

 

Echo server test:

Started
<a href="https://imgur.com/qhiU8o4"><img src="https://i.imgur.com/qhiU8o4.jpg" title="source: imgur.com" /></a>



Talking & reply.
<a href="https://imgur.com/bZm43eM"><img src="https://i.imgur.com/bZm43eM.jpg" title="source: imgur.com" /></a>



Multiple port listening.
<a href="https://imgur.com/PVfMMEd"><img src="https://i.imgur.com/PVfMMEd.jpg" title="source: imgur.com" /></a>



loads of code to be moved / altered.
UI make over. still not happy. My check boxes :( :(.
//////////////////////////////////////////////////

Is0bel Server -ISO- -This is NOT a toy program

 

Read carefully.

Info:

NOT for commercial use. Hobbyists ONLY. 

Intended for the purpose of learning tcp/ip communication protocols.  
And being used for home server requirements.

When Is0bel Server [program] is running your server is running. 
This is not serviced based however this may change.

HOWEVER i will add argv for command line boot options.
e.g Is0bel.Server.exe -web -ftp -echo

Will start the program and automatically start the services requested.
Using last known saved settings. 

So you can add Is0bel server to startup settings in windows. 

That is the ONLY time Is0bel Server will start a service without you clicking
a play button or start button. By default Is0bel server is inert. <- Reread


Closing Is0bel will stop the ports being listened to which was started in Is0bel.
 

Click "?" <-For detailed information within the program.

have everything built and tested! now to program =) .

Using:

boost ASIO. MySQL ++. [Others to be added]  


Includes ALL necessary .dlls for windows sockets ws2_32.dll, wsock2.dll.
Includes ALL necessary .dlls for boost & linkers. <- More may be added


Will be made fully functional as it is needed to test my in program web browser.
It will do this by listening in on 127.0.0.1:80 "loop-back address".
Whenever you try to make a connection to this IP,
the computer loops the request back to your computer.
Attempts to locate a server on the specified port.
That way, you can have the server and client running on the same computer.

I then point web server to the basic web-page to be received by the client.

I can do the same for FTP server setup as well.

To access the server once programming is complete just enable port forwarding
from your routers IP:PORT settings to point at your servers IP:PORT.
Generally a 192.168.0.2 static IP with a port of your choice.

  
What functionality is intended:

- Asynchronous server
Shown in examples.

- TCP:IP 4 & 6 support
Again shown in examples.

- Internal network services
Intranet webpage hosting. E - Book library.

- Web server		
Now working within Is0bel. yet to add stop.
- FTP server		
Login, mkdir,del dir, upload & down, permissions.
 
- IRC server		
server/admin bot. setup within Is0bel server

- Teamspeak server	
Basic Voip - looking into an SDK.
 
- MySQL remote database (For testing)	
Add dummy dataset, use a client to receive it.
Have MySQL Pre built check dependences.

- Wake and sleep server remotely
Doable. Pause/start (pause and resume)
	
- Log forwarding
Check failed login requests,ip logging, Downloads & uploads

- Other server side tools.
Echo server now working. yet to add stop.

Dependences:

For programming
- boost 1.67 
- MySQL++ for mingw64 Dev++

check my dependences repository for download links to pre built binaries.


As always check source for details & program resources.txt.


Is0bel server was named after a gifted young women. =) 
The shadows will never be the same.

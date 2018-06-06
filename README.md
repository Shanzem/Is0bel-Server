# Is0bel-Server
Hobbyist\ Is0bel Server

UPDATE: 05/06/2018

Frame work in place.

Tested boost:asio last night got the A-sync server running.
Console program only.

Going to work through the tutorials this weekend.

Get a GUI HTTP 1.0 server up and running.


Is0bel Server -ISO- -This is NOT a toy program


Read carefully.

Info:

NOT for commercial use. Hobbyists ONLY. 

it is intended for the purpose of learning tcp/ip communication protocols.  
And being used for home server requirements.

When Is0bel Server [program] is running your server is running. 
This is not serviced based.
 
HOWEVER i will add argv for command line boot options.

e.g Is0bel.Server.exe -web -ftp -echo 

Will start the program and automatically start the services requested.
Using last known saved settings. 

So you can add Is0bel server to startup settings in windows. 

That is the ONLY time Is0bel Server will start a service without you clicking

a checkbox or start button. By default Is0bel server is inert. <- Reread

Click "?" <-For detailed information within the program.

have everything built and tested! now to program =) .

Using:

boost ASIO. MySQL ++. [Others to be added]  


Includes ALL necessary .dlls for windows sockets ws2_32.dll, wsock2.dll.

Includes ALL necessary .dlls for boost & linkers. <- More may be added

libws2_32.a

libwsock32.a

libboost_coroutine-mgw49-mt-x32-1_67.dll.a

libboost_date_time-mgw49-mt-x32-1_67.dll.a

libboost_exception-mgw49-mt-x32-1_67.a

libboost_serialization-mgw49-mt-x32-1_67.dll.a

libboost_signals-mgw49-mt-x32-1_67.dll.a

libboost_system-mgw49-mt-x32-1_67.a

libboost_system-mgw49-mt-x32-1_67.dll.a

libboost_thread-mgw49-mt-x32-1_67.dll.a


[name]-[target compiler]-[Multi Threading]-[Architecture]-[Version]


Will be made fully functional as it is needed to test my in program web browser.
It will do this by broadcasting on 127.0.0.1:80 "loop-back address".
Whenever you try to make a connection to this IP,
the computer loops the request back to you computer.
Attempts to locate a server on the specified port.
That way, you can have the server and client running on the same computer.

I then point web server to the basic web-page to be received by the client.

I can do the same for FTP server setup as well.

To access the server once programming is complete just enable port forwarding
from your routers IP:PORT settings to point at your servers IP:PORT.
Generally a static 192.168.0.2 static IP with a port of your choice.

 
What functionality is intended:

- Asynchronous server
Shown in examples.

- TCP:IP 4 & 6 support
Again shown in examples.

- Internal network services
Intranet webpage hosting.

- Web server		
Display a webpage. Shown in examples only console based and HTTP 1.0.

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


Dependences:

For programming
- boost 1.67 
- MySQL++ for mingw64 Dev++

check my dependences repository for download links to pre built binaries.


As always check source for details & program resources.txt.


Is0bel server was named after a gifted young women. =) 
The shadows will never be the same.

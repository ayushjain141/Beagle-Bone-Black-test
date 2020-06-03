
//#include <stdio.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h> //for the hostent stucture
#include <strings.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
//#include "network/SocketClient.h"
#include "socket_client.h"
using namespace std;
using namespace exploringBB;
//#define LDR_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"


int main(){
ostringstream head, data;
cout << "Starting EBB Thing Speak Example" << endl;
SocketClient sc("thingspeak.com",80);
// comment by me data << "field1=" << getTemperature(readAnalog(0)) << endl;
data << "field1=" << 137 << endl;
sc.connectToServer();
head << "POST /update HTTP/1.1\n"
<< "Host: api.thingspeak.com\n"
<< "Connection: close\n"
// This key is available from the API keys tab in Figure 10-7
<< "X-THINGSPEAKAPIKEY: K2H8ROK87TMTMPRU \n" // channel API key
<< "Content-Type: application/x-www-form-urlencoded\n"
<< "Content-Length:" << string(data.str()).length() << "\n\n";
sc.send(string(head.str()));
sc.send(string(data.str()));
string rec = sc.receive(1024);
cout << "[" << rec << "]" << endl;
cout << "End of EBB Thing Speak Example" << endl;
}




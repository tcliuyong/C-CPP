#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
static void
bail(const char * on_what)
{
	perror(on_what);
	exit(1);
}
int main(int argc,char * argv[])
{
	int z;//return status
	int sck_unix;//socket
	struct sockaddr_un adr_unix;//AF_UNIX
	int len_unix;//length
	const char pth_unix[]="/tmp/mysock";
	sck_unix=socket(AF_UNIX,SOCK_STREAM,0);
	if(sck_unix==-1)
	{
		bail("socket()");
	}
	unlink(pth_unix);
	
	//create AF_UNIX addr
	memset(&adr_unix,0,sizeof(adr_unix));
	adr_unix.sun_family=AF_UNIX;
	
	strncpy(adr_unix.sun_path,pth_unix,sizeof(adr_unix.sun_path-1))[sizeof (adr_unix.sun_path-1)]=0;
	 len_unix=SUN_LEN(&adr_unix);
	 
	 z=bind(sck_unix,(struct sockaddr *)&adr_unix,len_unix);
	 if(z==-1)
	 {
		 bail("bind()");
	 }
		 system("netstat -pa ---unix 2>/dev/null""sed -n '/^Active  UNIX/,/^Proto/p;""/af_unix/p'");
	 close(sck_unix);
	 unlink(pth_unix);
	 return 0;
		
}

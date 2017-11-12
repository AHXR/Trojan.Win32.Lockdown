#include							<Windows.h>
#include							<string>

void onClientInstallShutdown( const char * path ) {
	printf("Shutdown 2017 installed (\"%s\")\r\n", path);
}
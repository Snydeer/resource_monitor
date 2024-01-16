#include <stdlib.h>
#include <Windows.h>


double Netusage() {

	const char* script = "powershell -File C:\\Users\\AverySnyder\\source\\repos\\C_resource_Manager\\C_resource_Manager\\NetworkThroughput.ps1";

	system(script);

	//string fileContent = File.ReadAllText(filePath);

	//printf("%c does this work?", output);

	return 0;

}
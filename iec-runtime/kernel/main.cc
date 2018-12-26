//#include <sys/mman.h>	/* required for mlockall() */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#include "../include/loader.h"
#include "../include/vm.h"

#include "../../include/logger.h"

#include <fstream>
std::ofstream outfile;                  /* for debug */

#define MAX_OBJNAME	50
char objname[MAX_OBJNAME] = "exec.obj";

TaskList plc_task;

void sig_handler(int signo){
	LOGGER_DBG(DFLAG_SHORT, "PLC Kernel Recieved Signal: %d",(int)signo);
	if(signo == SIGINT){
		plc_task_delete(&plc_task);
		exit(0);
	}
	//outfile.close();
}

int main(int argc, char* argv[]){
	//mlockall(MCL_CURRENT|MCL_FUTURE);

	outfile.open("C:\\Users\\wenjie\\Desktop\\Unit\\plcloginfo.txt");
    outfile << "logfile" << std::endl;
	if(signal(SIGINT, &sig_handler) == SIG_ERR){
		LOGGER_ERR(E_SIG_PLCKILL,"");
	}
	
	load_task_list(objname, &plc_task);
	//plc_task_init(&plc_task);
	plc_task_start(&plc_task);
	//pause();
	system("pause");//for log wenjie
}
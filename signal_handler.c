#include "main.h"

void signal_handler(int num)
{

	signal(SIGINT,SIG_DFL);

}

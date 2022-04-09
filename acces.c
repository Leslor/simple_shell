#include"main.h"

int _access(char **av){
   int rt_value;
//   if(ac < 2)
  // {
    //  printf("Usage:%s filename\n",av[0]);
      //exit(1);
  // }
 
   rt_value=access(av[0],X_OK);
   if(rt_value==0)
         printf("File:%s can execute   rt_value=%d\n",av[0],rt_value);
    else
           printf("File:%s can't execute  rt_value=%d \n",av[0],rt_value);
 
   rt_value=access(av[0],F_OK);
   if(rt_value==0)
         printf("File:%s   exist   rt_value=%d\n",av[0],rt_value);
    else
         printf("File:%s not exist  rt_value=%d \n",av[0],rt_value);
 
  return 0;
}

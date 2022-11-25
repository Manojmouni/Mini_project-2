/* ----------------------------  Function Description   ---------------------------------- */
/***
 * Name of the module:   delete.c 
 -----------------------------------------
 * Name of the Function:  delete_data function
 *  
 * Date of creation:      16/11/2022
 *
 * Author of module:      Nikhil K
 *
 * Description of module: 
 *                      In main menu,when delete_data selected the user will ask for employee id, delete employee details 
 	 But user can’t delete employee details in excel sheet.

 * Different functions supported in the module: No

 * Global variables accessed or modified by the module: Access Structure pointer, TS_India_Employee_DB

 * Revision/Modification History:25/11/2022
 ***/



#include"header.h"

void delete_data(employee_database **emp)
{
	char num[15];
	char check=0;
	printf("Enter the Delete Employee Id\n");
	scanf("%s",num);
	employee_database *temp= *emp, *last = *emp;
	while(temp!=0)
	{
		if(*emp == NULL)
		{
			printf("Database is Empty !!!\n");
			return;
		}
			else if((strcmp((*emp)->emp_id,num))==0)
		{
			printf("|***************Warning****************|\n");
			printf("If you delete employee detials once's you can not recovery it....\nPress Yes|No \n");
			scanf(" %c",&check);
			if((check == 'y')||(check == 'Y'))
			{
				database_delete(temp);
				*emp = temp->link;
				free(temp);
				return ;
			}
			else
				return ;
		}
		else if((strcmp(temp->emp_id,num))==0)
		{
			printf("|***************Warning****************|\n");
                        printf("If you delete employee detials once's you can not recovery it....\nPress Yes|No \n");
                        scanf(" %c",&check);
			if((check == 'y')||(check == 'Y'))
                        {
				printf("deleted\n");
				database_delete(temp);
				last->link = temp->link;
				free(temp);
				sleep(3);
				return ;
			}
			else
				return;
		}
		last = temp;
		temp = temp->link;
	}
}
